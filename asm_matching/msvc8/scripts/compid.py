#!/usr/bin/env python3
"""compid.py - the @comp.id stamps of COFF objects and library members.

    compid.py <file.obj | file.lib> ...

Every object a Microsoft tool writes carries an @comp.id symbol: the product
id and build of the tool that made it - the same records the linker sums into
an image's Rich header (decode_rich_header.py). Prints, per file, how many
objects carry each stamp. Short import objects (one per imported function)
carry none and are skipped.
"""
import collections
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import coffobj               # noqa: E402
import decode_rich_header   # noqa: E402


def stamps(path):
    data = open(path, 'rb').read()
    members = coffobj.read_archive(data) if data[:8] == b'!<arch>\n' else [(path, data)]
    out = collections.Counter()
    for name, body in members:
        if body[:4] == b'\0\0\xff\xff' or len(body) < 20:
            continue
        try:
            cid = coffobj.CoffObject(body, name).comp_id()
        except ValueError:
            continue
        if cid is not None:
            out[cid] += 1
    return out


def main(argv):
    if len(argv) < 2:
        sys.exit(__doc__)
    for path in argv[1:]:
        c = stamps(path)
        print('%s: %s' % (os.path.basename(path), ', '.join(
            '%s/%d x%d' % (decode_rich_header.PRODID.get(cid >> 16, '0x%04x' % (cid >> 16)), cid & 0xffff, n)
            for cid, n in sorted(c.items())) or 'no stamps'))


if __name__ == '__main__':
    main(sys.argv)
