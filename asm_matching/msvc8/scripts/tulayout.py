#!/usr/bin/env python3
"""tulayout.py - does each of our translation units correspond to one object
of the original?

    tulayout.py [--tu PATTERN] [--intruders]

The linker lays an object's functions out together, in the order the compiler
emitted them. So the functions of a TU that is one original object occupy one
address range of the original, in order, with nothing of another TU's inside.
Our order is the source line's (ours.OurFunc.layout_key): the generator writes
functions in address order, while our objects' COMDAT order moves callers of
later-defined functions to the end. Per TU this prints the range its mapped
functions span, how many of its mapped functions lie out of order, and how
many original functions inside the range the map assigns to OTHER TUs
(intruders). A TU with intruders is split or merged differently from the
original: functions belong elsewhere, which decides what may be static (only
static functions get VC8's register conventions) and what may be inlined.

--intruders lists, per TU, the foreign functions inside its range.
"""
import argparse
import bisect
import collections
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import funcmap          # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE  # noqa: E402


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--tu')
    ap.add_argument('--intruders', action='store_true')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    fns = {f.key: f for f in ourslib.load_all(os.path.join(BUILD, 'obj'))}
    by_tu = collections.defaultdict(list)
    owner = {}
    for s, e, name, tu, sym, m, d in rows:
        f = fns.get(tu + '|' + sym)
        if f is None:
            continue
        by_tu[tu].append((f.layout_key, s, name))
        owner[s] = (tu, name)
    starts = sorted(owner)
    report = []
    for tu, lst in by_tu.items():
        if args.tu and args.tu not in tu:
            continue
        lst.sort()
        chain = funcmap.longest_increasing([(o, s) for o, s, _n in lst])
        lo, hi = chain[0][1], chain[-1][1]
        inside = starts[bisect.bisect_left(starts, lo):bisect.bisect_right(starts, hi)]
        foreign = [(s, owner[s]) for s in inside if owner[s][0] != tu]
        report.append((len(foreign), tu, len(lst), len(lst) - len(chain), lo, hi, foreign))
    report.sort(key=lambda r: (-r[0], r[1]))
    print('%-44s %5s %8s %9s  %-17s' % ('tu', 'fns', 'disorder', 'intruders', 'original range'))
    for n, tu, cnt, dis, lo, hi, foreign in report:
        print('%-44s %5d %8d %9d  %08x-%08x' % (tu[:44], cnt, dis, n, lo, hi))
        if args.intruders:
            for s, (otu, oname) in foreign[:40]:
                print('      %08x  %s  (%s)' % (s, oname, otu))
    clean = sum(1 for r in report if r[0] == 0)
    print('%d TUs, %d with no intruder' % (len(report), clean))


if __name__ == '__main__':
    main()
