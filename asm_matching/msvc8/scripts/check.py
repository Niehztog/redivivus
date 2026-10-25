#!/usr/bin/env python3
"""check.py - re-judge some TUs' functions against the committed audit.

    check.py [--update] PATTERN ...      (PATTERN: a path substring, e.g. D2Game/PLAYER)

The inner loop and the regression gate. For every mapped function whose TU
path contains a PATTERN, compares the object on disk (rebuild it first) with
the original and with that function's row in evidence/audit.tsv, and prints
what changed: new MATCHes, regressions (a MATCH that no longer is), and
similarity moves. Exit status 1 if anything regressed.

--update writes the new rows into evidence/audit.tsv (the summary is only
rewritten by a full `oracle audit`).
"""
import argparse
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import compare          # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE  # noqa: E402

AUDIT = os.path.join(ORACLE, 'evidence', 'audit.tsv')


def judge(rows, pats, model, syms, quarantined):
    """start -> (status, similarity, ref_insns, our_insns, byte_diffs, notes) for the selected TUs."""
    tus = sorted({r[3] for r in rows if any(p in r[3] for p in pats)})
    fns, by_name = {}, {}
    for tu in tus:
        path = os.path.join(BUILD, 'obj', tu + '.obj')
        if os.path.exists(path) and os.path.exists(path[:-4] + '.d'):
            for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj'):
                fns[f.key] = f
                by_name.setdefault((tu, f.name), []).append(f)
    out = {}
    for s, e, name, tu, sym, method, _d in rows:
        if tu not in tus:
            continue
        f = fns.get(tu + '|' + sym)
        if f is None and len(by_name.get((tu, name), ())) == 1:
            f = by_name[(tu, name)][0]       # its signature changed since the map: same function, other mangling
        q = quarantined.get((tu, name.rsplit('::', 1)[-1]))
        if f is None:
            out[s] = ('MISSING', 0.0, 0, 0, 0, 'object not compiled', e, name, tu, method)
        elif q is not None:
            out[s] = ('QUARANTINE', 0.0, len(model[s][0].insns), 0, 0, q, e, name, tu, method)
        else:
            r = compare.compare(compare.our_view(f, syms), compare.ref_view(s, model[s]))
            notes = '; '.join(x for x in (('%d refs differ' % r.ref_diffs) if r.ref_diffs else '',
                                          ('%d refs unverified' % r.unverified) if r.unverified else '') if x)
            out[s] = (r.status, r.similarity, r.ref_insns, r.our_insns, r.byte_diffs, notes, e, name, tu, method)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--update', action='store_true')
    ap.add_argument('patterns', nargs='+')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    old = {}
    lines = open(AUDIT).read().split('\n')
    for line in lines[1:]:
        p = line.split('\t')
        if len(p) > 9:
            old[int(p[0], 16)] = (p[9], float(p[8]))
    new = judge(rows, args.patterns, model, syms, quarantined)
    gained = lost = 0
    up = down = 0.0
    for s in sorted(new):
        st, sim = new[s][0], new[s][1]
        ost, osim = old.get(s, ('?', 0.0))
        if st == 'MATCH' and ost != 'MATCH':
            gained += 1
            print('  + MATCH  %08x %s' % (s, new[s][7]))
        elif ost == 'MATCH' and st != 'MATCH':
            lost += 1
            print('  - LOST   %08x %s (%s)' % (s, new[s][7], st))
        elif abs(sim - osim) >= 0.001:
            up += max(0.0, sim - osim)
            down += max(0.0, osim - sim)
    match = sum(1 for v in new.values() if v[0] == 'MATCH')
    print('%d functions: %d MATCH (%+d, -%d), similarity +%.2f / -%.2f' % (len(new), match, gained, lost, up, down))
    if args.update:
        update_rows(new)
    return 1 if lost else 0


def update_rows(state):
    """Write the judged functions' rows into evidence/audit.tsv."""
    lines = open(AUDIT).read().split('\n')
    out = [lines[0]]
    for line in lines[1:]:
        p = line.split('\t')
        if len(p) > 9 and int(p[0], 16) in state:
            s = int(p[0], 16)
            st, sim, ri, oi, bd, notes, e, name, tu, method = state[s]
            line = '%08x\t%08x\t%s\t%s\t%s\t%d\t%d\t%d\t%.3f\t%s\t%s' % (s, e, name, tu, method, ri, oi, bd, sim, st, notes)
        out.append(line)
    open(AUDIT, 'w').write('\n'.join(out))


if __name__ == '__main__':
    sys.exit(main())
