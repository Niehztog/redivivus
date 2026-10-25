#!/usr/bin/env python3
"""msi_paths.py - map an MSI's File-table keys to install paths.

    msi_paths.py <package.msi>          prints "<file key>\t<relative path>" lines
    msi_paths.py --cabs <package.msi>   adds a third column: the cabinet holding
                                        the file (a leading '#' means a stream
                                        inside the .msi itself)

Cabinet members in a Windows Installer package (and in the cabinets inside a
.msp patch) are named by File-table key, not by file name. Resolving
File -> Component -> Directory chain gives the path the installer would have
written, so a toolchain can be laid out from Microsoft's own packages with
cabextract alone, without running an installer. Needs msiinfo (msitools).

Paths use each directory's long *target* name (DefaultDir is
"target[:source]", each part "short|long"); "." folds into the parent.
"""
import subprocess
import sys


def table(msi, name):
    out = subprocess.run(['msiinfo', 'export', msi, name], capture_output=True, text=True,
                         encoding='latin1').stdout
    rows = [line.split('\t') for line in out.split('\r\n' if '\r\n' in out else '\n') if line]
    return rows[3:]  # column names, column types, table name


def long_target(default_dir):
    target = default_dir.split(':')[0]
    return target.split('|')[-1]


def main(msi, with_cabs=False):
    dirs = {r[0]: (r[1], r[2]) for r in table(msi, 'Directory') if len(r) >= 3}
    comps = {r[0]: r[2] for r in table(msi, 'Component') if len(r) >= 3}
    # Media rows: a file belongs to the first medium whose LastSequence >= its Sequence.
    media = sorted((int(r[1]), r[3]) for r in table(msi, 'Media') if len(r) >= 4 and r[1].isdigit())
    cache = {}

    def cabinet(seq):
        for last, cab in media:
            if seq <= last:
                return cab
        return ''

    def path(d):
        if d in cache:
            return cache[d]
        parent, default = dirs.get(d, ('', d))
        name = long_target(default)
        if not parent or parent == d or d == 'TARGETDIR':
            p = '' if name in ('SourceDir', '.', 'SOURCEDIR') else name
        else:
            base = path(parent)
            p = base if name == '.' else (base + '/' + name if base else name)
        cache[d] = p
        return p

    for r in table(msi, 'File'):
        if len(r) < 8:
            continue
        key, comp, fname, seq = r[0], r[1], r[2], r[7]
        d = comps.get(comp)
        if d is None:
            continue
        base = path(d)
        line = '%s\t%s' % (key, (base + '/' if base else '') + fname.split('|')[-1])
        if with_cabs:
            line += '\t' + cabinet(int(seq) if seq.isdigit() else 0)
        print(line)


if __name__ == '__main__':
    args = sys.argv[1:]
    cabs = bool(args) and args[0] == '--cabs'
    if cabs:
        args = args[1:]
    if len(args) != 1:
        sys.exit(__doc__)
    main(args[0], cabs)
