#!/usr/bin/env python3
"""snippet.py - compile a variant of some code and compare it with the original.

    snippet.py FILE [--func NAME [--ref ADDR]] [--cflags FLAGS]

The experiment bench for a source hypothesis ("was it `if (a && b)` or a
ternary?"). FILE (inside the repository; build/scratch/ is the place) is
compiled with the baseline compiler, flags and context of every TU - the
same response file and precompiled header, so the tree's types and globals
are there - into build/scratch/, never into build/obj. FILE is passed as is:
write it in what VC8 accepts (a copy of the translated TU, build/src/<tu>.cpp,
is a ready start).

Without --func every function of the object is printed. With --func, that
function is printed beside the original - at ADDR, or where the function map
puts a function of that name - with the status the audit would give it.
The module's own flags (flags.tsv, e.g. D2Client's /GS-) are those of the TU
the function map files the function under, or of --tu. --cflags adds flags
after those (an experiment: not evidence).
"""
import argparse
import os
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import build            # noqa: E402
import compare          # noqa: E402
import objfuncs         # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE  # noqa: E402

SCRATCH = os.path.join(BUILD, 'scratch')


def compile_file(path, cflags=''):
    """Compile `path` in the tree's context. Returns (object path, log lines);
    the object is None when the compile failed."""
    os.makedirs(SCRATCH, exist_ok=True)
    obj = os.path.join(SCRATCH, os.path.splitext(os.path.basename(path))[0] + '.obj')
    if os.path.exists(obj):
        os.remove(obj)
    rsp = os.path.join(BUILD, 'cl.rsp')
    if not os.path.exists(rsp):
        sys.exit('no %s - run `oracle build` once first' % rsp)
    pch = []
    if build.USE_PCH:
        # A copy of the precompiled header: a build running alongside rewrites
        # (and locks) the original whenever a header it was made from changes.
        copy = os.path.join(SCRATCH, os.path.basename(build.PCH_FILE))
        for _try in range(60):
            if os.path.exists(copy) and os.path.getmtime(copy) >= os.path.getmtime(build.PCH_FILE):
                break
            # Only a header that stayed the same through the copy is complete.
            before = os.stat(build.PCH_FILE)
            shutil.copy2(build.PCH_FILE, copy + '.tmp')
            after = os.stat(build.PCH_FILE)
            if (before.st_mtime, before.st_size) == (after.st_mtime, after.st_size) == \
                    (after.st_mtime, os.path.getsize(copy + '.tmp')):
                os.replace(copy + '.tmp', copy)
                break
            time.sleep(5)
        pch = ['/Yu' + build.PCH_HEADER, '/Fp' + build.win(copy)]
    cmd = [os.path.join(HERE, 'vc8.sh'), 'cl', '@' + build.win(rsp)] + pch + cflags.split() + \
        ['/Fo' + build.win(obj), build.win(path)]
    p = subprocess.run(cmd, capture_output=True, text=True, encoding='latin1', timeout=build.COMPILE_TIMEOUT)
    log = [l for l in (p.stdout + p.stderr).splitlines() if l.strip()]
    # As in build.py: the exit status is not trusted under wine, the object is.
    ok = not any(build.ERROR.search(l) for l in log) and build.valid_object(obj)
    return (obj if ok else None), log


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('file')
    ap.add_argument('--func')
    ap.add_argument('--ref', type=lambda s: int(s, 16))
    ap.add_argument('--cflags', default='')
    ap.add_argument('--tu', help='the TU whose flags.tsv row applies (default: the function\'s, from the map)')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    tu_of = args.tu
    if tu_of is None and args.func:
        tus = {r[3] for r in rows if (args.ref is None or r[0] == args.ref) and
               (r[2] == args.func or r[2].endswith('::' + args.func))}
        tu_of = tus.pop() if len(tus) == 1 else None
    extra = build.extra_flags(tu_of) if tu_of else ''
    obj, log = compile_file(os.path.abspath(args.file), (extra + ' ' + args.cflags).strip())
    if obj is None:
        print('\n'.join(log))
        return 1
    syms = audit.sym_map(rows)
    tu = os.path.relpath(obj, BUILD)[:-4]
    fns = [ourslib.OurFunc(tu, k, f) for k, f in enumerate(objfuncs.functions(obj))]
    if not args.func:
        for f in fns:
            print('%s  (%d insns)' % (f.name, f.insns))
            for i in compare.our_view(f, syms):
                print('    %4x  %s' % (i.addr, i.text))
        return 0
    hits = [f for f in fns if f.name == args.func or f.name.endswith('::' + args.func)]
    if len(hits) != 1:
        sys.exit('%s: %d functions of that name in %s' % (args.func, len(hits), obj))
    f = hits[0]
    start = args.ref
    if start is None:
        cands = [r[0] for r in rows if r[2] == f.name or r[2].endswith('::' + args.func)]
        if len(cands) != 1:
            sys.exit('%s: give --ref, the function map has %d candidates' % (args.func, len(cands)))
        start = cands[0]
    _ref, model = audit.load_context()
    ours = compare.our_view(f, syms)
    ref = compare.ref_view(start, model[start])
    r = compare.compare(ours, ref)
    print('%s  vs original %08x' % (f.name, start))
    print('status %s  insns ours %d / original %d  byte diffs %d  similarity %.3f  refs differ %d, unverified %d' % (
        r.status, r.our_insns, r.ref_insns, r.byte_diffs, r.similarity, r.ref_diffs, r.unverified))
    for line in compare.side_by_side(ours, ref):
        print(line)
    return 0 if r.status == 'MATCH' else 2


if __name__ == '__main__':
    sys.exit(main())
