#!/usr/bin/env python3
"""objdiff.py - do two builds contain the same code? Function by function.

    objdiff.py <objdir A> <objdir B> [PATTERN ...]

For every object present in both directories (or those whose path contains a
PATTERN): the same function symbols, the same code bytes, the same
relocations to the same symbols. The proof that a change claimed to be
codegen-neutral is - a precompiled header, a translator rewrite, a different
include order. Prints each difference and a total; exit status 1 if any.
"""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import objfuncs  # noqa: E402


def functions(path):
    return {f.symbol: (f.code, sorted(f.relocs.items())) for f in objfuncs.functions(path)}


def main(argv):
    if len(argv) < 3:
        sys.exit(__doc__)
    a_dir, b_dir, pats = argv[1], argv[2], argv[3:]
    objs = same = differ = 0
    for dirpath, _dirs, files in os.walk(a_dir):
        for f in sorted(files):
            if not f.endswith('.obj') or f[:-4] + '.d' not in files:
                continue
            rel = os.path.relpath(os.path.join(dirpath, f), a_dir)
            other = os.path.join(b_dir, rel)
            if pats and not any(p in rel for p in pats):
                continue
            if not os.path.exists(other):
                continue
            objs += 1
            fa, fb = functions(os.path.join(a_dir, rel)), functions(other)
            for sym in sorted(set(fa) | set(fb)):
                if sym not in fa or sym not in fb:
                    print('%s: %s only in %s' % (rel, sym, a_dir if sym in fa else b_dir))
                    differ += 1
                elif fa[sym] != fb[sym]:
                    print('%s: %s differs' % (rel, sym))
                    differ += 1
                else:
                    same += 1
    print('%d objects, %d functions identical, %d differ' % (objs, same, differ))
    return 1 if differ else 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
