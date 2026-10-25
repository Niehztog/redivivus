#!/usr/bin/env python3
"""commit.py - commit the way this branch keeps its history (CLAUDE.md, "Commits").

    commit.py [--base main] [--tooling LINE] [-m MESSAGE]

The oracle branch is one commit holding all of the ASM-matching tooling -
asm_matching/, CLAUDE.md, the CMakeLists.txt line that keeps the oracle out of
the game's build - followed by commits that change the Diablo II source. So
the working tree's changes are split:

  * changes to the tooling paths are amended into the branch's first commit
    (the first after BASE); --tooling LINE adds `- LINE` to its message;
  * the later commits are re-created on top unchanged, except that the
    tooling paths now come from the new first commit;
  * the remaining changes, the source, become a new commit with MESSAGE
    (required if there are any).

Only refs and indexes are written, never the working tree; the branch moves
to the new tip, and the old one stays in the reflog. Nothing is pushed.
"""
import argparse
import os
import subprocess
import sys
import tempfile

TOOLING = ['asm_matching', 'CLAUDE.md', 'CMakeLists.txt']


def git(*args, env=None, inp=None):
    p = subprocess.run(['git'] + list(args), capture_output=True, text=True, env=env, input=inp)
    if p.returncode != 0:
        sys.exit('git %s: %s' % (' '.join(args), p.stderr.strip()))
    return p.stdout.strip()


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--base', default='main')
    ap.add_argument('--tooling', action='append', default=[], help='a line for the first commit\'s message')
    ap.add_argument('-m', '--message', help='message of the new source commit')
    args = ap.parse_args()
    os.chdir(git('rev-parse', '--show-toplevel'))
    head = git('rev-parse', 'HEAD')
    commits = git('rev-list', '--reverse', '%s..HEAD' % args.base).split()
    if not commits:
        sys.exit('no commits after %s' % args.base)
    first, later = commits[0], commits[1:]
    with tempfile.TemporaryDirectory() as tmp:
        env = dict(os.environ, GIT_INDEX_FILE=os.path.join(tmp, 'index'))
        # The first commit, with the working tree's tooling paths.
        git('read-tree', first, env=env)
        git('add', '-A', '--', *TOOLING, env=env)
        tree = git('write-tree', env=env)
        msg = git('log', '-1', '--format=%B', first)
        if args.tooling:
            msg = msg.rstrip('\n') + '\n' + ''.join('- %s\n' % l for l in args.tooling)
        tip = git('commit-tree', tree, '-p', git('rev-parse', '%s^' % first), '-F', '-', inp=msg)
        tooling = git('ls-tree', '-r', tip, '--', *TOOLING)
        # The later commits, re-parented, their tooling paths from the new first commit.
        for c in later:
            git('read-tree', c, env=env)
            git('rm', '-r', '--cached', '--quiet', '--ignore-unmatch', '--', *TOOLING, env=env)
            git('update-index', '--index-info', env=env, inp=tooling + '\n')
            tip = git('commit-tree', git('write-tree', env=env), '-p', tip, '-F', '-',
                      inp=git('log', '-1', '--format=%B', c))
        # What is left in the working tree is source: a new commit.
        git('read-tree', tip, env=env)
        git('add', '-A', '.', env=env)
        tree = git('write-tree', env=env)
        if tree != git('rev-parse', '%s^{tree}' % tip):
            if not args.message:
                sys.exit('source changes in the working tree: give -m MESSAGE')
            tip = git('commit-tree', tree, '-p', tip, '-F', '-', inp=args.message)
    git('update-ref', '-m', 'commit.py', 'HEAD', tip, head)
    git('read-tree', 'HEAD')
    print(git('log', '--oneline', '%s..HEAD' % args.base))
    return 0


if __name__ == '__main__':
    sys.exit(main())
