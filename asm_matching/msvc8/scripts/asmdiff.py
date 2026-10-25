#!/usr/bin/env python3
"""asmdiff.py - one function, ours beside the original.

    asmdiff.py [--funcmap FILE] <name | original address>
        e.g.  asmdiff.py DRLGENV_UpdateLightIntensity
              asmdiff.py 0045a2b0

Resolves through evidence/funcmap.tsv (a name may be given unqualified when it
is unique). Left: our object's code; right: the original's. Both columns are
the normalised view compare.py judges by: references are printed by what they
refer to (fn_<original address>, "string", __imp_Name, $+offset, globals by
our symbol / original address), so an address difference that is only layout
does not show, and a call to a different function does.

Markers between the columns: blank = identical; ! = identical bytes, but a
reference names something else; ~ = same instruction, different
bytes; | = different instruction; < only ours; > only the original's.
Rebuild the object first (build.py <tu>) - this reads what is on disk.
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit         # noqa: E402
import compare       # noqa: E402
import ours as ourslib  # noqa: E402

ORACLE = os.path.dirname(HERE)


def main(argv):
    funcmap = os.path.join(ORACLE, 'evidence', 'funcmap.tsv')
    if len(argv) == 4 and argv[1] == '--funcmap':
        funcmap, argv = argv[2], argv[:1] + argv[3:]
    if len(argv) != 2:
        sys.exit(__doc__)
    want = argv[1]
    rows = audit.load_funcmap(funcmap)
    hits = []
    for row in rows:
        s, _e, name = row[0], row[1], row[2]
        if want.lower().lstrip('0x').lstrip('0') == ('%x' % s) or name == want or name.endswith('::' + want):
            hits.append(row)
    if not hits:
        sys.exit('%s: not in the funcmap (unmapped functions are listed in evidence/funcmap.tsv.unmapped)' % want)
    if len(hits) > 1:
        sys.exit('%s is ambiguous:\n' % want + '\n'.join('  %08x %s (%s)' % (h[0], h[2], h[3]) for h in hits))
    s, e, name, tu, sym, method, detail = hits[0]
    _ref, model = audit.load_context()
    objdir = os.path.join(audit.BUILD, 'obj')
    fns = {f.key: f for f in ourslib.load_object(objdir, tu + '.obj')}
    f = fns.get(tu + '|' + sym)
    if f is None:
        sys.exit('%s not found in %s.obj - rebuild it' % (sym, tu))
    ours = compare.our_view(f, audit.sym_map(rows))
    ref = compare.ref_view(s, model[s])
    r = compare.compare(ours, ref)
    print('%s  [%s]  original %08x..%08x  paired by %s (%s)' % (name, tu, s, e, method, detail))
    print('status %s  insns ours %d / original %d  byte diffs %d  similarity %.3f  refs differ %d, unverified %d' % (
        r.status, r.our_insns, r.ref_insns, r.byte_diffs, r.similarity, r.ref_diffs, r.unverified))
    print('%-66s   %s' % ('ours (offset, source line, instruction)', 'original'))
    for line in compare.side_by_side(ours, ref):
        print(line)
    # The source lines the differences come from, as the tree has them (the
    # translation keeps line numbers, so these are the real file's lines).
    src = os.path.join(os.path.dirname(os.path.dirname(ORACLE)), tu + '.cpp')
    lines = compare.differing_lines(ours, ref)
    if lines and os.path.exists(src):
        text = open(src, encoding='utf-8', errors='replace').read().split('\n')
        print('\nsource lines with differing code (%s.cpp):' % tu)
        for ln in sorted(lines):
            if 0 < ln <= len(text):
                print('%6d  %s' % (ln, text[ln - 1].rstrip()[:150]))


if __name__ == '__main__':
    main(sys.argv)
