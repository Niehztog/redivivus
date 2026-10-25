#!/usr/bin/env python3
"""fix_return.py - give back the return value the database dropped.

    fix_return.py [--apply] [PATTERN ...]

A function the tree declares `void` whose original loads EAX with a constant
right before it returns - `mov eax, 1` ahead of the epilogue
(NET_SID_CLIENT_Send_0x3D_CreateAccount2, 0051a740), `xor eax, eax` - did
return a value: the database's signature lost it. Where the original returns
one value on every path the edit is mechanical: the return type becomes
`int`, every `return;` returns that value, and so does the end of the body;
the declaration in the TU's header follows. Every path is checked, not only
the loads ours lacks: EAX at each of the original's rets comes from a
constant propagation over its control flow (classify.eax_at_returns), and
all of them must hold the one constant. A path that returns 0 from the
`xor eax, eax` that zeroed a buffer (SKILLDESC_FormatSignedValue, 004e79e0),
or a callee's result (SKILLDESC_FormatMinMaxRange, 004e7f40), is a function
whose returns the database has to give one by one; it is left alone. A
constant in AL alone (`xor al, al`, `mov al, 1`) is a bool's return: the
function becomes `bool`. Callers did not use a value
before and do not now. Only free functions named nowhere but in calls,
their definition and their own header's declaration are taken (a function
whose address is taken would no longer fit its pointer type). The return
type is part of the mangled name; the judge finds the function by its name
until the next `oracle map`. Kept, through fixlib's batch loop, only where
the function comes out more similar.
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
import classify         # noqa: E402
import compare          # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_compare import norm  # noqa: E402
from fix_ifelse import match_close  # noqa: E402
from fix_static import Tree, def_pattern, strip_comments  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

EPILOGUE = ('pop ', 'mov esp', 'leave', 'ret', 'call ')
SET_EAX = re.compile(r'mov eax, (0x[0-9a-f]+|\d+)$|xor eax, eax$')
SET_AL = re.compile(r'mov al, (0x[0-9a-f]+|\d+)$|xor al, al$')


def returned_values(ours, ref, rx=SET_EAX):
    """The constants the original loads into EAX (rx=SET_AL: AL) just before
    returning, where ours loads nothing at the aligned place."""
    vals = set()
    sm = difflib.SequenceMatcher(None, [norm(x) for x in ours], [norm(y) for y in ref], autojunk=False)
    for op, _i1, _i2, j1, j2 in sm.get_opcodes():
        if op not in ('insert', 'replace'):
            continue
        for j in range(j1, j2):
            m = rx.match(ref[j].text)
            if m and j + 1 < len(ref) and ref[j + 1].text.startswith(EPILOGUE):
                vals.add(0 if m.group(1) is None else int(m.group(1), 0))
    return vals


def retyped(texts, cpp, hdr, leaf, value, rtype='int'):
    """The texts with `leaf` returning `value` as `rtype`, or None."""
    src = texts[cpp]
    m = re.search(def_pattern(leaf), src, re.M)
    if not m:
        return None
    head = m.group('head')
    hm = re.match(r'(static\s+)?void(\s)', head)
    if not hm:
        return None
    open_at = m.end() - 1
    close = match_close(src, open_at, '{', '}')
    if close is None:
        return None
    body = src[open_at + 1:close]
    v = str(value)
    body = re.sub(r'\breturn\s*;', 'return %s;' % v, body)
    lines = body.rstrip().split('\n')
    if not lines[-1].strip().startswith('return'):
        first = next((l for l in body.split('\n') if l.strip()), '    ')
        ind = first[:len(first) - len(first.lstrip())] or '    '
        body = body.rstrip() + '\n' + ind + 'return %s;\n' % v
    new_head = head[:hm.start()] + (hm.group(1) or '') + rtype + hm.group(2) + head[hm.end():]
    out_src = src[:m.start()] + new_head + src[m.start() + len(head):open_at + 1] + body + src[close:]
    # Forward declarations in the .cpp (a static promotion may have added one).
    decl = re.compile(r'^(?P<pre>[ \t]*(?:static\s+)?)void(?P<mid>\s+(?:__\w+\s+)?)%s(?=\s*\([^;{}]*\);)' % re.escape(leaf), re.M)
    out_src = decl.sub(lambda d: d.group('pre') + rtype + d.group('mid') + leaf, out_src)
    out = {cpp: out_src}
    if hdr in texts:
        out[hdr] = decl.sub(lambda d: d.group('pre') + rtype + d.group('mid') + leaf, texts[hdr])
    return out


def retype(cpp, hdr, leaf, value, rtype='int'):
    return lambda texts: retyped(texts, cpp, hdr, leaf, value, rtype)


def candidates(rows, model, syms, status, pats):
    """tu -> [(original start, leaf, value)]."""
    tree = Tree()
    out = collections.defaultdict(list)
    objs = {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING') or '@@' not in sym:
            continue
        rest = sym[sym.index('@@') + 2:]
        if rest[:1] != 'Y' or rest[2:3] != 'X':
            continue                         # a free function returning void, by its mangled name
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
        f = objs[tu].get(sym)
        if f is None:
            continue
        ours_v, ref_v = compare.our_view(f, syms), compare.ref_view(s, model[s])
        vals, rtype = returned_values(ours_v, ref_v), 'int'
        if len(vals) == 1:
            at_rets = {v for _a, v in classify.eax_at_returns(model[s][0])}
        else:
            # A bool comes back in AL: `xor al, al` / `mov al, 1` before the epilogue.
            vals, rtype = returned_values(ours_v, ref_v, SET_AL), 'bool'
            at_rets = {v for _a, v in classify.eax_at_returns(model[s][0], 'al')}
            if len(vals) == 1 and next(iter(vals)) not in (0, 1):
                rtype = 'uint8_t'
        if len(vals) != 1 or at_rets != {next(iter(vals)) & (0xff if rtype != 'int' else 0xffffffff)}:
            continue                         # not the one constant on every path
        leaf = name.rsplit('::', 1)[-1]
        cpp, hdr = os.path.join(REPO, tu + '.cpp'), os.path.join(REPO, tu + '.h')
        files = tree.where.get(leaf, set())
        if any(p.endswith('.h') and p != hdr for p in files):
            continue                         # declared in another header too
        bare = re.compile(r'\b%s\b(?!\s*\()' % re.escape(leaf))
        if any(bare.search(strip_comments(fixlib.read(p))) for p in files):
            continue                         # its address is taken somewhere
        v = vals.pop()
        out[tu].append((s, leaf, ('true' if v else 'false') if rtype == 'bool' else v, rtype))
    return out


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
    print('%d functions in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            print(tu, ', '.join('%s->%s %s' % (leaf, t, v) for _s, leaf, v, t in cands[tu]))
        return 0
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp, hdr = os.path.join(REPO, tu + '.cpp'), os.path.join(REPO, tu + '.h')
        groups[tu] = ([fixlib.Edit(leaf, [s], [s], retype(cpp, hdr, leaf, v, t), require_gain=True)
                       for s, leaf, v, t in cands[tu]], [cpp, hdr])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_return', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
