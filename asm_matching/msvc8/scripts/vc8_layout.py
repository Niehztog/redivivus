#!/usr/bin/env python3
"""vc8_layout.py - lay out a VC8 toolchain from installer cabinet members.

    vc8_layout.py <paths.tsv> <keyed-dir> <dest>

<paths.tsv> is msi_paths.py output (file key -> install path) and <keyed-dir>
holds cabinet members named by file key (cabextract output). Every member whose
install path is a compiler, header, library or PDB-support file is copied to

    <dest>/bin       VC/bin (+1033 resources), Common7/IDE's mspdb80 family
    <dest>/include   VC/include, recursively
    <dest>/lib       VC/lib, x86 only (no amd64/ia64 subdirectories)

Members missing from <keyed-dir> are skipped, which is what makes the same
script serve as the overlay for a service pack: run it again over the SP1
cabinet and only the files SP1 replaces are rewritten.

The tools' own CRT (msvcr80/msvcp80) is not laid out here: they bind it
through WinSxS, which setup_toolchain.sh installs.
"""
import os
import shutil
import sys

VS = 'Program Files/Microsoft Visual Studio 8/'
PDB_FAMILY = {'mspdb80.dll', 'msobj80.dll', 'mspdbcore.dll', 'mspdbsrv.exe'}


def target(path):
    if path.startswith(VS + 'VC/bin/'):
        rest = path[len(VS + 'VC/bin/'):]
        if '/' not in rest or rest.startswith('1033/'):
            return 'bin/' + rest
    elif path.startswith(VS + 'VC/include/'):
        return 'include/' + path[len(VS + 'VC/include/'):]
    elif path.startswith(VS + 'VC/lib/'):
        rest = path[len(VS + 'VC/lib/'):]
        if '/' not in rest:
            return 'lib/' + rest
    elif path.startswith(VS + 'Common7/IDE/') and path.rsplit('/', 1)[1] in PDB_FAMILY:
        return 'bin/' + path.rsplit('/', 1)[1]
    return None


def main(argv):
    if len(argv) != 4:
        sys.exit(__doc__)
    paths, keyed, dest = argv[1], argv[2], argv[3]
    placed = 0
    for line in open(paths, encoding='latin1'):
        key, path = line.rstrip('\n').split('\t')
        t = target(path)
        src = os.path.join(keyed, key)
        if t is None or not os.path.isfile(src):
            continue
        out = os.path.join(dest, t)
        os.makedirs(os.path.dirname(out), exist_ok=True)
        shutil.copyfile(src, out)
        placed += 1
    print('%s: %d files' % (dest, placed))


if __name__ == '__main__':
    main(sys.argv)
