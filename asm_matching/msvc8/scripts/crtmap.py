#!/usr/bin/env python3
"""crtmap.py - find the statically linked VC8 runtime in the original, by bytes.

    crtmap.py [--out evidence/crtmap.tsv]

Game.exe links the CRT statically (/MT: libcmt.lib, libcpmt.lib). Every
function of those libraries, as shipped with VS2005 RTM and with SP1, is
reduced to the same masked view the audit uses (compare.py) and looked up
among the original's functions. An identical masked instruction stream is a
hit. Two things come out of it:

  * names for the original's CRT functions, so that a call from our code to
    _toupper or memset can be checked against the address it calls there
    (the funcmap consumes evidence/crtmap.tsv);
  * the library version: a function SP1 changed matches only the build that
    was linked. The per-version totals go to <out>.summary.

A hit must be unique on the original side to name it; small stubs that occur
in several places are counted but left unnamed.
"""
import argparse
import collections
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit      # noqa: E402
import coffobj    # noqa: E402
import compare    # noqa: E402
import objfuncs   # noqa: E402
import ours as ourslib  # noqa: E402

ORACLE = os.path.dirname(HERE)
LIBS = ('libcmt.lib', 'libcpmt.lib')


def lib_functions(path):
    data = open(path, 'rb').read()
    for member, body in coffobj.read_archive(data):
        if body[:4] == b'\0\0\xff\xff' or len(body) < 20:
            continue
        try:
            fns = objfuncs.functions(member, body)
        except Exception:
            continue
        for k, f in enumerate(fns):
            yield member, ourslib.OurFunc(member, k, f)


def key_of(view):
    return (len(view), b''.join(i.masked for i in view))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default=os.path.join(ORACLE, 'evidence', 'crtmap.tsv'))
    args = ap.parse_args()
    _ref, model = audit.load_context()
    index = collections.defaultdict(list)
    for s, entry in model.items():
        v = compare.ref_view(s, entry)
        if len(v) >= 3:
            index[key_of(v)].append(s)

    prefix = os.path.join(os.environ.get('VC8_WINEPREFIX', os.path.expanduser(
        '~/q2-dev/asm-matching-toolchain/wine-vc8')), 'drive_c', 'vc8')
    hits = {}          # (version) -> {start: set(names)}
    totals = {}
    for version in ('rtm', 'sp1'):
        found = collections.defaultdict(set)
        n = 0
        for lib in LIBS:
            for member, f in lib_functions(os.path.join(prefix, version, 'lib', lib)):
                n += 1
                v = compare.our_view(f, {})
                if len(v) < 3:
                    continue
                for s in index.get(key_of(v), ()):
                    found[s].add('%s(%s)' % (f.name, member.rsplit('\\', 1)[-1]))
        hits[version] = found
        totals[version] = n
    starts = sorted(set(hits['rtm']) | set(hits['sp1']))
    only = collections.Counter()
    with open(args.out, 'w') as fh:
        fh.write('start\tend\tname\tmatches\n')
        for s in starts:
            r, p = hits['rtm'].get(s, set()), hits['sp1'].get(s, set())
            which = 'rtm+sp1' if r and p else ('rtm' if r else 'sp1')
            only[which] += 1
            names = sorted(r | p)
            short = sorted({n.split('(')[0] for n in names})
            fh.write('%08x\t%08x\t%s\t%s\n' % (s, model[s][0].end, short[0] if len(short) == 1 else '?' + '|'.join(short),
                                              which))
    lines = ['libcmt.lib + libcpmt.lib functions: rtm %d, sp1 %d' % (totals['rtm'], totals['sp1']),
             'original functions identical to a library function: %d' % len(starts)]
    for k in ('rtm+sp1', 'rtm', 'sp1'):
        lines.append('  matched by %-8s %5d' % (k, only.get(k, 0)))
    with open(args.out + '.summary', 'w') as fh:
        fh.write('\n'.join(lines) + '\n')
    print('\n'.join(lines))


if __name__ == '__main__':
    main()
