#!/usr/bin/env python3
"""diffgrams.py - the most frequent local differences, over every pair.

    diffgrams.py [--top N] [--max-len K] [--examples]

For every mapped function that does not match, aligns our instructions with
the original's (by mnemonic) and collects each differing stretch of at most K
instructions on either side, with registers written R and numbers N: the
shape of the difference, e.g. `cmp R, -N ; jle N => test R, R ; jl N`. A
shape counts once per function. The most frequent shapes are the systematic
differences - a construct the generator writes another way than Blizzard did,
a flag, a convention - and so the next fix worth making for many functions at
once (the comparison forms of fix_compare.py and the /GS cookies of
evidence/flags.md were found this way).
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
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE  # noqa: E402

REG = re.compile(r'\b(e[abcd]x|e[sd]i|ebp|esp|[abcd][lh]|[abcd]x|si|di)\b')
NUM = re.compile(r'0x[0-9a-f]+|\b\d+\b')


def shape(insn):
    return NUM.sub('N', REG.sub('R', insn.key))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--top', type=int, default=60)
    ap.add_argument('--max-len', type=int, default=3)
    ap.add_argument('--examples', action='store_true', help='name three functions per shape')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    syms = audit.sym_map(rows)
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    _ref, model = audit.load_context()
    objs = {}
    grams = collections.Counter()
    examples = collections.defaultdict(list)
    n = 0
    for s, _e, name, tu, sym, _m, _d in rows:
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
        f = objs[tu].get(sym)
        if f is None:
            continue
        ours = compare.our_view(f, syms)
        ref = compare.ref_view(s, model[s])
        n += 1
        sm = difflib.SequenceMatcher(None, [x.mnemonic for x in ours], [y.mnemonic for y in ref], autojunk=False)
        seen = set()
        for op, i1, i2, j1, j2 in sm.get_opcodes():
            if op == 'equal' or i2 - i1 > args.max_len or j2 - j1 > args.max_len:
                continue
            g = (tuple(shape(x) for x in ours[i1:i2]), tuple(shape(y) for y in ref[j1:j2]))
            if g not in seen:
                seen.add(g)
                grams[g] += 1
                if len(examples[g]) < 3:
                    examples[g].append(name)
    print('%d functions that do not match; differing stretches by shape (ours => original):' % n)
    for g, c in grams.most_common(args.top):
        line = '%6d  %s  =>  %s' % (c, ' ; '.join(g[0]) or '-', ' ; '.join(g[1]) or '-')
        if args.examples:
            line += '\n          e.g. ' + ', '.join(examples[g])
        print(line)


if __name__ == '__main__':
    main()
