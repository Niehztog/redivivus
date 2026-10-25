#!/usr/bin/env python3
"""fix_forloop.py - put rotated loops back as the for loops they were.

    fix_forloop.py [--apply] [PATTERN ...]

VC8 compiles `for (i = 0; i < n; i++) { B }` as the initialisation, a test
of the condition, and a loop that tests at its bottom: `xor eax, eax; test
ecx, ecx; jle done; top: B; inc eax; cmp eax, ecx; jl top`. Ghidra hands it
back rotated - `if (0 < n) { i = 0; do { B; i++; } while (i < n); }` -
and compiled again that puts the test first and the initialisation inside
it (InitPal, 00476ea0: the original zeroes the counter before `jle`, the
tree after it; as a for loop it matches).

A site is exactly that shape: an `if` whose block holds nothing but one
initialisation of the loop variable and a do-while; the condition of the if
is the loop's condition with the initial value in place of the variable
(`if (X OP n)` or `if (n OP' X)` for `i = X; ... while (i OP n)`); the
do-while's body ends with the step (`i++`, `++i`, `i += k`, `i = i + k`,
and the decrements) and holds no `continue`, which in a for loop would run
the step. The for loop means the same: its condition is evaluated before
the first pass, which is the if - and where the initialisation is no
declaration, the variable must not be read after the loop (the for loop
assigns it even when it does not run). The rewrite keeps the line count: the for
loop stands on the if's line, the lines that held the initialisation, the
`do`, the step and the if's closing brace become empty, and the do-while's
`} while (...);` becomes the loop's closing brace.

Without --apply it lists the sites; with --apply they go through fixlib's
batch loop: kept only where nothing that matched stops matching and the
function gets no less similar.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_ifelse import match_close  # noqa: E402
from fix_order import function_body  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

IF_LINE = re.compile(r'^(?P<ind>[ \t]*)if \((?P<cond>.*)\) \{[ \t]*$')
INIT_LINE = re.compile(r'^[ \t]*(?P<decl>(?:[\w:]+[ \t]+(?:\*[ \t]*)*)?)(?P<var>[A-Za-z_]\w*)[ \t]*=[ \t]*(?P<val>[^;]+?);[ \t]*$')
DO_LINE = re.compile(r'^(?P<ind>[ \t]*)do \{[ \t]*$')
WHILE_LINE = re.compile(r'^(?P<ind>[ \t]*)\} while \((?P<var>[A-Za-z_]\w*) (?P<op><=|>=|<|>|!=) (?P<bound>.+)\);[ \t]*$')
FLIP = {'<': '>', '>': '<', '<=': '>=', '>=': '<=', '!=': '!='}


def step_of(line, var):
    """The step expression of a `var++;`-like line, or None."""
    s = line.strip()
    v = re.escape(var)
    for rx in (r'%s\+\+;' % v, r'\+\+%s;' % v, r'%s--;' % v, r'--%s;' % v,
               r'%s [+-]= [^;]+;' % v, r'%s = %s [+-] [^;]+;' % (v, v)):
        if re.fullmatch(rx, s):
            return s[:-1]
    return None


def same(a, b):
    return re.sub(r'\s+', ' ', a.strip()) == re.sub(r'\s+', ' ', b.strip())


def sites(lines):
    """[(if line, [(line, new text)])] for every rotated loop in the text."""
    out = []
    for k in range(len(lines) - 3):
        m = IF_LINE.match(lines[k])
        if not m:
            continue
        mi = INIT_LINE.match(lines[k + 1])
        md = DO_LINE.match(lines[k + 2])
        if not mi or not md:
            continue
        ind_do = md.group('ind')
        # the do-while's closing line: the brace matching the do's
        text = '\n'.join(lines[k + 2:])
        close = match_close(text, text.index('{'), '{', '}')
        if close is None:
            continue
        end = k + 2 + text.count('\n', 0, close)
        mw = WHILE_LINE.match(lines[end])
        if not mw or mw.group('ind') != ind_do or mw.group('var') != mi.group('var'):
            continue
        # the if's block ends right after the do-while
        if end + 1 >= len(lines) or lines[end + 1].rstrip() != m.group('ind') + '}':
            continue
        if end + 2 < len(lines) and re.match(r'^[ \t]*else\b', lines[end + 2]):
            continue
        var, val, op, bound = mi.group('var'), mi.group('val'), mw.group('op'), mw.group('bound')
        cond = m.group('cond')
        if not (same(cond, '%s %s %s' % (val, op, bound)) or same(cond, '%s %s %s' % (bound, FLIP[op], val))):
            continue
        body = list(range(k + 3, end))
        filled = [j for j in body if lines[j].strip()]
        if not filled:
            continue
        step = step_of(lines[filled[-1]], var)
        if step is None:
            continue
        text = '\n'.join(lines[j] for j in body)
        if re.search(r'\bcontinue\b', text) or re.search(r'\b%s\b' % re.escape(var), bound):
            continue
        if not mi.group('decl').strip() and any(re.search(r'\b%s\b' % re.escape(var), l) for l in lines[end + 2:]):
            continue                      # the for loop assigns it even when the loop does not run
        init = (mi.group('decl') + var).strip() + ' = ' + val.strip()
        new = [(k, '%sfor (%s; %s %s %s; %s) {' % (m.group('ind'), init, var, op, bound.strip(), step)),
               (k + 1, ''), (k + 2, ''), (filled[-1], ''), (end, m.group('ind') + '}'), (end + 1, '')]
        out.append((k + 1, new))
    return out


def candidates(rows, status, pats):
    """tu -> [(original start, if line, edits)]."""
    out = collections.defaultdict(list)
    objs, texts = {}, {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
            cpp = os.path.join(REPO, tu + '.cpp')
            texts[tu] = fixlib.read(cpp) if os.path.exists(cpp) else ''
        f = objs[tu].get(sym)
        if f is None or not texts[tu]:
            continue
        own = tu.lower() + '.cpp'
        mine = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
        body = function_body(texts[tu], name.rsplit('::', 1)[-1], mine)
        if body is None:
            continue
        first, blines = body
        lines = texts[tu].split('\n')
        for ln, new in sites(lines[first - 1:first - 1 + len(blines)]):
            out[tu].append((s, first - 1 + ln, [(first - 1 + j, t) for j, t in new]))
    return out


def file_edit(cpp, edits):
    def fn(texts):
        lines = texts[cpp].split('\n')
        for j, _t in edits:
            if j >= len(lines):
                return None
        mine = {j for j, _t in edits}
        # The site must still be there: recompute it on the current text.
        found = [new for ln, new in sites(lines) if {j for j, _t in new} == mine]
        if not found:
            return None
        for j, t in found[0]:
            lines[j] = t
        return {cpp: '\n'.join(lines)}
    return fn


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    cands = candidates(rows, status, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d loops in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, ln, edits in cands[tu]:
                print('%s:%d  %08x  %s' % (tu, ln, s, edits[0][1].strip()))
        return 0
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, ln), [s], [s], file_edit(cpp, edits))
                       for s, ln, edits in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_forloop', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
