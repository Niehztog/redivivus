#!/usr/bin/env python3
"""tidy_blanks.py - drop the empty lines fixers leave where a statement was.

    tidy_blanks.py [--rev REV] [--apply]

The fixers keep a file's line count while they work, so that the /Z7 line
tables of everything after a site stay valid between their builds: a
statement they remove becomes an empty line (fix_stringops, fix_nestcall,
fix_assert). Once the fixing is done the line numbers no longer matter, and
those lines are noise in the source. This removes every empty line that
stands where REV (default HEAD) had a non-empty one - lines the generator
left empty itself stay. Code-neutral by construction (whitespace only); a
rebuild and audit afterwards confirm it.
"""
import argparse
import difflib
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
from oracle_config import REPO  # noqa: E402


def changed_files(rev):
    out = subprocess.run(['git', '-C', REPO, 'diff', '--name-only', rev, '--', '*.cpp', '*.h'],
                         capture_output=True, text=True).stdout.split()
    return [f for f in out if not f.startswith('asm_matching/') and os.path.exists(os.path.join(REPO, f))]


def tidy(old, new):
    """`new` without the empty lines that replace non-empty lines of `old`."""
    a, b = old.split('\n'), new.split('\n')
    keep = [True] * len(b)
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op not in ('replace', 'insert'):
            continue
        olds_empty = sum(1 for l in a[i1:i2] if not l.strip())
        news = [j for j in range(j1, j2) if not b[j].strip()]
        # As many empty lines as the old block had stay; the rest go.
        for j in news[olds_empty:]:
            keep[j] = False
    return '\n'.join(l for l, k in zip(b, keep) if k)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--rev', default='HEAD')
    ap.add_argument('--apply', action='store_true')
    args = ap.parse_args()
    total = 0
    for f in changed_files(args.rev):
        old = subprocess.run(['git', '-C', REPO, 'show', '%s:%s' % (args.rev, f)], capture_output=True,
                             text=True, errors='surrogateescape').stdout
        path = os.path.join(REPO, f)
        new = open(path, encoding='utf-8', errors='surrogateescape').read()
        out = tidy(old, new)
        n = new.count('\n') - out.count('\n')
        if n:
            total += n
            print('%-60s %d lines' % (f, n))
            if args.apply:
                with open(path, 'w', encoding='utf-8', errors='surrogateescape') as fh:
                    fh.write(out)
    print('%d empty lines %s' % (total, 'removed' if args.apply else 'to remove'))
    return 0


if __name__ == '__main__':
    sys.exit(main())
