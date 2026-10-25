#!/usr/bin/env python3
"""fix_switch.py - write switch statements back where Ghidra made if-chains of them.

    fix_switch.py [--apply] [PATTERN ...]

VC8 lowers a switch over a few cases as successive subtractions - `sub eax,
1; je case1; sub eax, 3; je case4; ...` - and an if-chain as comparisons -
`cmp eax, 1; je; cmp eax, 4; je`. Ghidra hands the switch back as the chain
(ERRORMANAGER_ServiceControlHandler, 00406410, `switch (nServiceControl)`).
Where the original compares by subtraction and the tree has a clean chain on
one variable,

    if (v == A) { a } else if (v == B) { b } [else { c }]

becomes

    switch (v) { case A: { a break; } case B: { b break; } [default: { c break; }] }

- the same meaning, since v is a plain lvalue the chain reads unchanged
until a body runs. The decompiler also writes a switch whose cases all leave
the function as separate statements, `if (!v) { ...; return x; } if (v == 1)
{ ...; return y; } ...` (SFILE_ReadFileChecked, 004154b0: `sub ecx, 0; je;
sub ecx, 1; je; sub ecx, 1; jne`): consecutive ifs on one variable whose
bodies end by leaving (return, goto, exit, a halt) become the cases of one
switch, and what follows them runs after it as before (`!v` is case 0). A
chain whose bodies contain `break` is left alone (the switch would catch it).
Kept, through fixlib's batch loop, only where the function comes out more
similar.
"""
import argparse
import collections
import difflib
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import compare          # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_compare import norm  # noqa: E402
from fix_ifelse import match_close  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

HEAD = re.compile(r'(?P<ind>[ \t]*)if \((?:(?P<v>[\w.\->\[\]:]+) == (?P<k>[\w:]+|-?0x[0-9a-fA-F]+|-?\d+)|'
                  r'!(?P<z>[\w.\->\[\]:]+))\) \{\n')
ELSE_IF = r'\} else if \(%s == (?P<k>[\w:]+|-?0x[0-9a-fA-F]+|-?\d+)\) \{\n'
NEXT_IF = r'\}\n(?:[ \t]*\n)*(?P<ind2>[ \t]*)if \((?:%s == (?P<k>[\w:]+|-?0x[0-9a-fA-F]+|-?\d+)|!%s)\) \{\n'
LEAVES = re.compile(r'^\s*(?:return\b[^;]*|goto\s+\w+|exit\([^;]*\)|[\w:]*ERROR_UnrecoverableInternalError_Halt\([^\n]*\));\s*$')


def leaves(body):
    lines = [l for l in body.split('\n') if l.strip()]
    return bool(lines) and LEAVES.match(lines[-1]) is not None


def subtracts(ours, ref):
    """True if, aligned, the original subtracts where ours compares."""
    sm = difflib.SequenceMatcher(None, [norm(x) for x in ours], [norm(y) for y in ref], autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == 'replace' and any(x.mnemonic == 'cmp' for x in ours[i1:i2]) and \
                any(y.mnemonic in ('sub', 'dec', 'add') for y in ref[j1:j2]):
            return True
    return False


def chain_at(text, at):
    """(end, switch text) for a clean if-chain starting at `at`, or None."""
    m = HEAD.match(text, at)
    if not m:
        return None
    ind, v = m.group('ind'), m.group('v') or m.group('z')
    cases, default = [], None
    k, open_at = (m.group('k') if m.group('v') else '0'), m.end() - 2
    sequential = False
    while True:
        close = match_close(text, open_at, '{', '}')
        if close is None or text[text.rfind('\n', 0, close) + 1:close] != ind:
            return None
        body = text[open_at + 2:close - len(ind)]
        cases.append((k, body))
        rest = text[close:]
        nm = None if sequential else re.match(ELSE_IF % re.escape(v), rest)
        if nm:
            k, open_at = nm.group('k'), close + nm.end() - 2
            continue
        sm = re.match(NEXT_IF % (re.escape(v), re.escape(v)), rest)
        if (len(cases) == 1 or sequential) and sm and sm.group('ind2') == ind and leaves(body):
            sequential = True
            k, open_at = (sm.group('k') or '0'), close + sm.end() - 2
            continue
        if sequential:
            end = close + 1                      # the last case may fall out: so does its if
            break
        if rest.startswith('} else {\n'):
            d_open = close + len('} else ')
            d_close = match_close(text, d_open, '{', '}')
            if d_close is None or text[text.rfind('\n', 0, d_close) + 1:d_close] != ind:
                return None
            default = text[d_open + 2:d_close - len(ind)]
            end = d_close + 1
        else:
            end = close + 1
        break
    if len(cases) < 2:
        return None
    for _k, b in cases + ([('', default)] if default is not None else []):
        if re.search(r'\bbreak\s*;', b):
            return None
    out = ['%sswitch (%s) {' % (ind, v)]
    for k, b in cases:
        out.append('%scase %s: {' % (ind, k))
        out.append(b.rstrip('\n'))
        if not leaves(b):
            out.append('%s  break;' % ind)
        out.append('%s}' % ind)
    if default is not None:
        out.append('%sdefault: {' % ind)
        out.append(default.rstrip('\n'))
        if not leaves(default):
            out.append('%s  break;' % ind)
        out.append('%s}' % ind)
    out.append('%s}' % ind)
    return end, '\n'.join(l for l in out if l != '')


def candidates(rows, model, syms, status, pats):
    """tu -> [(original start, line, old text, new text)]."""
    out = collections.defaultdict(list)
    objs = {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
        f = objs[tu].get(sym)
        if f is None or not subtracts(compare.our_view(f, syms), compare.ref_view(s, model[s])):
            continue
        own = tu.lower() + '.cpp'
        mine = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
        if not mine:
            continue
        text = fixlib.read(os.path.join(REPO, tu + '.cpp'))
        starts = [0] + [k + 1 for k, c in enumerate(text) if c == '\n']
        for ln in range(min(mine), max(mine) + 1):
            if ln > len(starts) or not HEAD.match(text, starts[ln - 1]):
                continue
            r = chain_at(text, starts[ln - 1])
            if r:
                out[tu].append((s, ln, text[starts[ln - 1]:r[0]], r[1]))
    return out


def chain_edit(cpp, ln, old, new):
    def fn(texts):
        t = texts[cpp]
        starts = [0] + [k + 1 for k, c in enumerate(t) if c == '\n']
        if ln > len(starts) or not t.startswith(old, starts[ln - 1]):
            return None
        at = starts[ln - 1]
        return {cpp: t[:at] + new + t[at + len(old):]}
    return fn


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    syms = audit.sym_map(rows)
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    _ref, model = audit.load_context()
    cands = candidates(rows, model, syms, status, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d chains in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, ln, old, new in cands[tu]:
                print('%s:%d  %08x\n%s\n---\n%s\n' % (tu, ln, s, old.rstrip(), new))
        return 0
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        # Bottom-up: a chain that grows into a switch never moves another's line.
        order = sorted(cands[tu], key=lambda c: -c[1])
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, ln), [s], [s], chain_edit(cpp, ln, old, new), require_gain=True)
                       for s, ln, old, new in order], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_switch', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
