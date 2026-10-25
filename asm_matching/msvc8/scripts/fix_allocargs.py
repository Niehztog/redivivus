#!/usr/bin/env python3
"""fix_allocargs.py - give Fog's allocator calls back the source location the original passes.

    fix_allocargs.py [--apply] [PATTERN ...]

Fog's allocator takes the caller's source file and line for its leak and
corruption reports, and the original passes Blizzard's: FOG_FreeModuleList
(0040b660) frees with `push 0x1f7; mov edx, ".\\Src\\Exceptions.cpp"`. Upstream
writes these calls as macros - D2_FREE(p), D2_ALLOC(n), D2_NEW(T), their
_POOL forms and D2_REALLOC_POOL - that pass the reconstruction's own __FILE__ and __LINE__, so
every such call pushes another line and another string than the original,
and a function that matched no longer does (1b24c75: most of the functions
it stopped matching differ in nothing else).

The original's values are in the original's code: aligned with ours, the
instruction that pushes our __LINE__ pushes the original's line, the one
that loads our __FILE__ loads the original's file name (or, where the
scheduling moved that load out of line, the one source file the original
function names, if it names only one). Each macro call
whose line and file can be read off that way is written as the call it
stands for, with those values:

  D2_FREE(p)              Fog::Memory::FreeClientMemory(p, ".\\Src\\X.cpp", 0x1f7, 0)
  D2_ALLOC(n)             Fog::Memory::AllocClientMemory(n, "...", line, 0)
  D2_NEW(T)               (T*)Fog::Memory::AllocClientMemory(sizeof(T), "...", line, 0)
  D2_FREE_POOL(m, p)      Fog::Memory::FreeServerMemory(m, p, "...", line, 0)
  D2_ALLOC_POOL(m, n)     Fog::Memory::AllocServerMemory(m, n, "...", line, 0)
  D2_NEW_POOL(m, T)       (T*)Fog::Memory::AllocServerMemory(m, sizeof(T), "...", line, 0)
  D2_REALLOC_POOL(m, p, n) Fog::Memory::ReAllocServerMemory(m, p, n, "...", line, 0)

- the same call, with the arguments the original passes. One edit per
function, kept through fixlib's batch loop only where it comes out more
similar.
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
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

MACROS = {
    'D2_FREE': ('Fog::Memory::FreeClientMemory(%s, %s, %s, 0)', 1, None),
    'D2_ALLOC': ('Fog::Memory::AllocClientMemory(%s, %s, %s, 0)', 1, None),
    'D2_NEW': ('(%s*)Fog::Memory::AllocClientMemory(sizeof(%s), %s, %s, 0)', 1, 'type'),
    'D2_FREE_POOL': ('Fog::Memory::FreeServerMemory(%s, %s, %s, %s, 0)', 2, None),
    'D2_ALLOC_POOL': ('Fog::Memory::AllocServerMemory(%s, %s, %s, %s, 0)', 2, None),
    'D2_NEW_POOL': ('(%s*)Fog::Memory::AllocServerMemory(%s, sizeof(%s), %s, %s, 0)', 2, 'type'),
    'D2_REALLOC_POOL': ('Fog::Memory::ReAllocServerMemory(%s, %s, %s, %s, %s, 0)', 3, None),
}
CALL = re.compile(r'\b(D2_(?:FREE|ALLOC|NEW)(?:_POOL)?|D2_REALLOC_POOL)\(')
PUSH_IMM = re.compile(r'^push (0x[0-9a-f]+|\d+)$')
SOURCE_FILE = re.compile(rb'\.(?:cpp|c|h)\0?$', re.I)


def args_at(text, open_at):
    """([arguments], index after the closing paren) of the call opening at text[open_at]."""
    depth, cur, out = 0, '', []
    for k in range(open_at, len(text)):
        c = text[k]
        if c == '(':
            depth += 1
            if depth == 1:
                continue
        elif c == ')':
            depth -= 1
            if depth == 0:
                out.append(cur.strip())
                return out, k + 1
        elif c == ',' and depth == 1:
            out.append(cur.strip())
            cur = ''
            continue
        cur += c
    return None, None


def c_string(raw):
    s = raw[:-1] if raw.endswith(b'\0') else raw
    return '"%s"' % s.decode('latin1').replace('\\', '\\\\').replace('"', '\\"')


def locations(ours, ref):
    """{our source line: (file literal, line literal)} read off the original at
    the places where ours pushes its own __LINE__ and loads its own __FILE__."""
    sm = difflib.SequenceMatcher(None, [x.key for x in ours], [y.key for y in ref], autojunk=False)
    pairs = []
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == 'equal' or (op == 'replace' and i2 - i1 == j2 - j1):
            pairs += list(zip(range(i1, i2), range(j1, j2)))
        elif op == 'replace':
            # Rescheduled: the one push of a line on our side, the one
            # pushed number on the original's.
            mine = [i for i in range(i1, i2) if PUSH_IMM.match(ours[i].text)
                    and ours[i].line and int(PUSH_IMM.match(ours[i].text).group(1), 0) == ours[i].line]
            theirs = [j for j in range(j1, j2) if PUSH_IMM.match(ref[j].text)]
            if len(mine) == 1 and len(theirs) == 1:
                pairs.append((mine[0], theirs[0]))
    lines, files = collections.defaultdict(set), collections.defaultdict(set)
    for i, j in pairs:
        x, y = ours[i], ref[j]
        if not x.line:
            continue
        m = PUSH_IMM.match(x.text)
        if m and int(m.group(1), 0) == x.line:
            n = PUSH_IMM.match(y.text)
            if n:
                lines[x.line].add(int(n.group(1), 0))
        for ta, tb in zip(x.tokens, y.tokens):
            if ta[0] == 'str' and b'asm_matching' in ta[1] and tb[0] == 'str':
                files[x.line].add(tb[1])
    # A file name the scheduling moved out of line with ours: the original
    # function's, if it names only one source file.
    named = {t[1] for y in ref for t in y.tokens if t[0] == 'str' and SOURCE_FILE.search(t[1])}
    ours_named = {x.line for x in ours if any(t[0] == 'str' and b'asm_matching' in t[1] for t in x.tokens)}
    if len(named) == 1:
        for ln in set(lines) - set(files):
            if ln in ours_named:
                files[ln] = set(named)
    out = {}
    for ln in set(lines) & set(files):
        if len(lines[ln]) == 1 and len(files[ln]) == 1:
            out[ln] = (c_string(next(iter(files[ln]))), '0x%x' % next(iter(lines[ln])))
    return out


def rewrite(line, loc):
    """The line with its one allocator macro call written out, or None."""
    calls = list(CALL.finditer(line))
    if len(calls) != 1:
        return None
    m = calls[0]
    name = m.group(1)
    tmpl, nargs, kind = MACROS[name]
    args, end = args_at(line, m.end() - 1)
    if not args or len(args) != nargs:
        return None
    f, n = loc
    if name == 'D2_NEW':
        text = tmpl % (args[0], args[0], f, n)
    elif name == 'D2_NEW_POOL':
        text = tmpl % (args[1], args[0], args[1], f, n)
    elif nargs == 1:
        text = tmpl % (args[0], f, n)
    elif nargs == 2:
        text = tmpl % (args[0], args[1], f, n)
    else:
        text = tmpl % (args[0], args[1], args[2], f, n)
    if kind == 'type':
        text = '(%s)' % text                    # a cast-expression where a macro call stood
    return line[:m.start()] + text + line[end:]


def candidates(rows, model, syms, status, pats):
    """tu -> [(original start, {line: (old, new)})]."""
    out = collections.defaultdict(list)
    for tu in sorted({r[3] for r in rows}):
        if pats and not any(p in tu for p in pats):
            continue
        cpp = os.path.join(REPO, tu + '.cpp')
        obj = os.path.join(BUILD, 'obj', tu + '.obj')
        if not os.path.exists(cpp) or not os.path.exists(obj):
            continue
        lines = fixlib.read(cpp).split('\n')
        if not any(CALL.search(l) for l in lines):
            continue
        by_sym = {r[4]: r[0] for r in rows if r[3] == tu}
        for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj'):
            s = by_sym.get(f.symbol)
            if s is None or status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
                continue
            locs = locations(compare.our_view(f, syms), compare.ref_view(s, model[s]))
            changes = {}
            for ln, loc in locs.items():
                if 0 < ln <= len(lines):
                    new = rewrite(lines[ln - 1], loc)
                    if new is not None:
                        changes[ln] = (lines[ln - 1], new)
            if changes:
                out[tu].append((s, changes))
    return out


def line_edits(cpp, changes):
    def fn(texts):
        lines = texts[cpp].split('\n')
        for ln, (old, new) in changes.items():
            if ln > len(lines) or lines[ln - 1] != old:
                return None
            lines[ln - 1] = new
        return {cpp: '\n'.join(lines)}
    return fn


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    syms = audit.sym_map(rows)
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    _ref, model = audit.load_context()
    cands = candidates(rows, model, syms, status, args.patterns)
    nlines = sum(len(c) for v in cands.values() for _s, c in v)
    print('%d calls in %d functions, %d TUs' % (nlines, sum(len(v) for v in cands.values()), len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, changes in cands[tu]:
                for ln, (old, new) in sorted(changes.items()):
                    print('%s:%d  %08x\n    - %s\n    + %s' % (tu, ln, s, old.strip()[:150], new.strip()[:170]))
        return 0
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, min(c)), [s], [s], line_edits(cpp, c), require_gain=True)
                       for s, c in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    n = sum(len(v) for v in cands.values())
    print('kept %d of %d edits, MATCH %+d' % (kept, n, gained))
    fixlib.record('fix_allocargs', n, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
