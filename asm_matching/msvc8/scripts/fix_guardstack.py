#!/usr/bin/env python3
"""fix_guardstack.py - drop the decompiler's stack-cookie checks.

    fix_guardstack.py [--apply] [PATTERN ...]

Under /GS VC8 ends a function that has a char buffer with `mov ecx, [ebp-4];
xor ecx, ebp; call __security_check_cookie`. Ghidra hands that check back as
a call, and the generator writes it as a statement, `Fog::Debug::GuardStack();`
(GuardStack is the tree's name for __security_check_cookie, 00681a48, and its
body is empty). Compiled by VC8 with /GS the function then has the check
twice: the compiler's own and the statement's call, which the original does
not have (NET_D2GS_SERVER_Send_0x95, 0053c320: one call more, nothing else
different). Every such statement in a function that does not match yet is
removed, one edit per function, through fixlib's batch loop. The statement
stands for nothing the source had, so the edit is neutral: kept even where
the registers then shuffle and the similarity dips (GetSystemTimeZone,
00517e60, goes from four instructions too many to the original's sequence),
unless a function stops matching.
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
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

STATEMENT = re.compile(r'^[ \t]*(?:(?:Fog::)?Debug::)?GuardStack\(\);[ \t]*$')


def candidates(rows, status, pats):
    """tu -> [(original start, [line numbers, descending])]."""
    out = collections.defaultdict(list)
    for tu in sorted({r[3] for r in rows}):
        if pats and not any(p in tu for p in pats):
            continue
        cpp = os.path.join(REPO, tu + '.cpp')
        obj = os.path.join(BUILD, 'obj', tu + '.obj')
        if not os.path.exists(cpp) or not os.path.exists(obj):
            continue
        lines = fixlib.read(cpp).split('\n')
        if not any(STATEMENT.match(l) for l in lines):
            continue
        own = tu.lower() + '.cpp'
        by_sym = {r[4]: r[0] for r in rows if r[3] == tu}
        for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj'):
            s = by_sym.get(f.symbol)
            if s is None or status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
                continue
            mine = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
            if not mine:
                continue
            hits = [ln for ln in range(min(mine), max(mine) + 1) if STATEMENT.match(lines[ln - 1])]
            if hits:
                out[tu].append((s, sorted(hits, reverse=True)))
    return out


def deletion(cpp, hits):
    def fn(texts):
        lines = texts[cpp].split('\n')
        for ln in hits:
            if ln > len(lines) or not STATEMENT.match(lines[ln - 1]):
                return None
            del lines[ln - 1]
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
    total = sum(len(h) for v in cands.values() for _s, h in v)
    print('%d statements in %d functions, %d TUs' % (total, sum(len(v) for v in cands.values()), len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            print(tu, ' '.join('%08x:%s' % (s, ','.join(map(str, h))) for s, h in cands[tu]))
        return 0
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        # Bottom-up: a deletion never moves the lines of the edits after it.
        order = sorted(cands[tu], key=lambda c: -c[1][0])
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, h[0]), [s], [s], deletion(cpp, h), neutral=True)
                       for s, h in order], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    n = sum(len(v) for v in cands.values())
    print('kept %d of %d edits, MATCH %+d' % (kept, n, gained))
    fixlib.record('fix_guardstack', n, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
