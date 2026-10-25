#!/usr/bin/env python3
"""fix_stringops.py - write the string instructions' fills and copies back as
the source the original compiled them from.

    fix_stringops.py [--apply] [PATTERN ...]

VC8 SP1 never expands memset inline beyond 32 bytes (measured: `memset(a, 0,
50)` and `memset(a, 0, 100)` call memset under /O2, with or without `#pragma
intrinsic`), yet the original zeroes 50-, 64- and 100-byte buffers inline:
twelve `mov dword ptr [ebp-N], eax` and a `mov word ptr`, or `mov ecx, 25;
rep stosd`. That is what VC8 makes of an index loop, `for (i = 0; i < 25;
i++) a[i] = 0;` on a uint16_t array (unrolled; 50 elements become `rep
stosd`). memcpy of a constant size, on the other hand, VC8 does expand to
`rep movsd`, as it does a struct assignment, and an index copy loop it does
not. Ghidra gives these back in three shapes, all rewritten here:

  memset     `memset(a, 0, 32 * sizeof(a[0]));` - the decompiler folded the
             unrolled stores into a call - becomes `for (int i = 0; i < 32;
             i++) a[i] = 0;`: the same bytes, element by element
             (SKILLDESC_FormatSignedValue, 004e79e0: the sixteen stores of
             the original, and EAX zeroed for them as the original has it).
             `memset(a + k, ...)` starts at k; a byte count instead of
             `N * sizeof` is divided by the size of the element type the
             function declares `a` with.
  rep stosd  `p = a; for (n = K; n; n--) { p[0] = 0; p[1] = 0; p += 2; }` -
             the string instruction as a pointer loop - becomes `for (int i
             = 0; i < 2K; i++) a[i] = 0;` (AUTOMAP_DrawGamePassword,
             00459e90, whose prologue then is the original's, stack layout
             included). `p = a` with no cast says p points at a's elements.
  rep movsd  `for (n = K; n; n--) { *d = *s; s++; d++; }` becomes `memcpy(d,
             s, K * sizeof(*d));`, where d and s are declared pointers to the
             same type (a bytewise copy then is the element-wise one).

A loop left its pointers past the end and its counter at zero; the rewrites
leave neither, so they are only made where those are dead after the loop:
every other mention of them in the function assigns them (or declares
them), or the next one after the loop does and the loop is in no other
loop. The loop rewrites are kept only where the function comes out more
similar.

The line count stays the same (a removed line becomes empty), so the /Z7
line tables of everything after a site stay valid. One edit per site,
through fixlib's batch loop.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

NUM = r'0x[0-9a-fA-F]+|\d+'
ZERO = r"(?:0|L'\\0'|'\\0')"
MEMSET = re.compile(r'^(?P<ind>[ \t]*)memset\((?P<arr>[A-Za-z_]\w*)(?: \+ (?P<off>%s))?, 0, '
                    r'(?:(?P<n>%s) \* sizeof\((?P=arr)\[0\]\)|(?P<bytes>%s))\);[ \t]*$' % (NUM, NUM, NUM))
SIZES = {'uint8_t': 1, 'int8_t': 1, 'char': 1, 'BYTE': 1, 'CHAR': 1, 'uint16_t': 2, 'int16_t': 2,
         'wchar_t': 2, 'WORD': 2, 'WCHAR': 2, 'short': 2, 'uint32_t': 4, 'int32_t': 4, 'int': 4, 'DWORD': 4,
         'BOOL': 4}
ASSIGN_PTR = re.compile(r'^(?P<ind>[ \t]*)(?P<decl>[A-Za-z_][\w ]*?\s*\*\s*)?(?P<p>[A-Za-z_]\w*) = '
                        r'(?P<arr>[A-Za-z_]\w*);[ \t]*$')
FOR_DOWN = re.compile(r'^[ \t]*for \((?P<n>[A-Za-z_]\w*) = (?P<k>%s); (?P=n); (?P=n)--\) \{[ \t]*$' % NUM)
LOOP_HEAD = re.compile(r'^\s*(?:for|while)\s*\(|^\s*do\s*\{')


def declared_size(lines, arr):
    """The element size of `T arr[...]` declared in `lines`, or None."""
    for line in lines:
        m = re.match(r'^\s*(?:static\s+)?(?P<t>[A-Za-z_][\w ]*?)\s+%s\[[^\]]+\];' % re.escape(arr), line)
        if m and m.group('t').split()[-1] in SIZES:
            return SIZES[m.group('t').split()[-1]]
    return None


def fmt(v, like):
    return ('0x%x' % v) if like.lower().startswith('0x') and v else str(v)


def memset_site(line, body):
    m = MEMSET.match(line)
    if not m:
        return None
    off = int(m.group('off'), 0) if m.group('off') else 0
    if m.group('n'):
        n, like = int(m.group('n'), 0), m.group('n')
    else:
        size = declared_size(body, m.group('arr'))
        nbytes = int(m.group('bytes'), 0)
        if not size or nbytes % size:
            return None
        n, like = nbytes // size, m.group('bytes')
    if n <= 0:
        return None
    return '%sfor (int i = %s; i < %s; i++) %s[i] = 0;' % (m.group('ind'), fmt(off, like), fmt(off + n, like),
                                                           m.group('arr'))


def mentions(name, line):
    return re.search(r'(?<![\w.>])%s\b' % re.escape(name), line) is not None


def writes_only(name, line):
    """True if `line` mentions `name` only to declare it or assign it whole."""
    s = line.strip()
    if re.match(r'^(?:for \()?%s = ' % re.escape(name), s) and not mentions(name, s.split('=', 1)[1]):
        return True
    return re.match(r'^(?:const\s+)?(?:::)?[A-Za-z_][\w:]*(?:[\s*]+)%s(?:\[[^\]]*\])?(?: = [^;]*)?;$'
                    % re.escape(name), s) is not None and \
        not mentions(name, s.split('=', 1)[1] if '=' in s else '')


def in_loop(lines, at):
    """True if line index `at` lies inside a loop body (brace nesting)."""
    depth = 0
    for k in range(at - 1, -1, -1):
        line = lines[k]
        depth += line.count('}') - line.count('{')
        if depth < 0:
            if LOOP_HEAD.match(line) or re.match(r'^\s*\}?\s*do\b', line):
                return True
            depth = 0
    return False


def pointee(lines, lo, hi, name):
    """The type `name` points to, from its declaration in lines[lo..hi]
    (a local or a parameter), or None."""
    rx = re.compile(r'(?:^|[(,])\s*(?:const\s+)?(?P<t>[A-Za-z_][\w:]*(?:\s*\*)*)\s*\*\s*%s\s*(?=[,)=;\[])'
                    % re.escape(name))
    for x in range(lo, hi + 1):
        m = rx.search(lines[x])
        if m:
            return re.sub(r'\s+', '', m.group('t'))
    return None


def dead_after(lines, lo, hi, first, last, names):
    """True if every name is dead after lines[first..last]: each other mention
    in the function only declares or assigns it whole, or - outside a loop -
    the next mention after the site does, or there is none."""
    if any(re.search(r'\bgoto\b', lines[x]) for x in range(lo, hi + 1)):
        return False
    looped = None
    for name in names:
        others = [(x, lines[x]) for x in range(lo + 1, hi + 1)
                  if not first <= x <= last and mentions(name, lines[x])]
        if all(writes_only(name, l) for _x, l in others):
            continue
        if looped is None:
            looped = in_loop(lines, first)
        if looped:
            return False
        after = [l for x, l in others if x > last]
        if after and not writes_only(name, after[0]):
            return False
    return True


def movsd_site(lines, k, lo, hi):
    """The rewrite of a pointer copy loop whose `for` is lines[k] (0-based), or None."""
    f = FOR_DOWN.match(lines[k])
    if not f or k + 4 >= len(lines):
        return None
    c = re.match(r'^\s*\*(?P<d>[A-Za-z_]\w*) = \*(?P<s>[A-Za-z_]\w*);\s*$', lines[k + 1])
    if not c:
        return None
    d, src, n = c.group('d'), c.group('s'), f.group('n')
    if len({d, src, n}) != 3:
        return None
    incs = {lines[k + 2].strip(), lines[k + 3].strip()}
    if incs != {'%s++;' % d, '%s++;' % src} or not re.match(r'^\s*\}\s*$', lines[k + 4]):
        return None
    td, ts = pointee(lines, lo, hi, d), pointee(lines, lo, hi, src)
    if td is None or td != ts:
        return None
    if not dead_after(lines, lo, hi, k, k + 4, (d, src, n)):
        return None
    ind = lines[k][:len(lines[k]) - len(lines[k].lstrip())]
    new = ['%smemcpy(%s, %s, %s * sizeof(*%s));' % (ind, d, src, f.group('k'), d), '', '', '', '']
    return k, k + 4, new


def stosd_site(lines, k, lo, hi):
    """The rewrite of a pointer zero-loop whose `for` is lines[k] (0-based), or
    None. lo/hi: the function's line range (0-based, inclusive)."""
    f = FOR_DOWN.match(lines[k])
    if not f or k - 1 < lo:
        return None
    a = ASSIGN_PTR.match(lines[k - 1])
    if not a:
        return None
    p, n, arr = a.group('p'), f.group('n'), a.group('arr')
    if p == n or arr in (p, n):
        return None
    # Body: p[0] = 0; ... p[m-1] = 0; p += m;   or   *p = 0; p++;
    stores, j = 0, k + 1
    one = re.match(r'^\s*\*%s = %s;\s*$' % (re.escape(p), ZERO), lines[j])
    if one and re.match(r'^\s*%s\+\+;\s*$' % re.escape(p), lines[j + 1]):
        stores, j = 1, j + 2
    else:
        while re.match(r'^\s*%s\[%d\] = %s;\s*$' % (re.escape(p), stores, ZERO), lines[j]):
            stores, j = stores + 1, j + 1
        if stores < 2 or not re.match(r'^\s*%s \+= %d;\s*$' % (re.escape(p), stores), lines[j]):
            return None
        j += 1
    if not re.match(r'^\s*\}\s*$', lines[j]):
        return None
    first, last = k - 1, j
    if not dead_after(lines, lo, hi, first, last, (p, n)):
        return None
    total = int(f.group('k'), 0) * stores
    new = []
    ind = a.group('ind')
    new.append(ind + a.group('decl').rstrip() + ' ' + p + ';' if a.group('decl') else '')
    new.append('%sfor (int i = 0; i < %s; i++) %s[i] = 0;' % (ind, fmt(total, f.group('k')), arr))
    new += [''] * (last - first + 1 - len(new))
    return first, last, new


def candidates(rows, status, pats):
    """tu -> [(original start, first line, old lines, new lines, needs gain)] (1-based lines)."""
    out = collections.defaultdict(list)
    for tu in sorted({r[3] for r in rows}):
        if pats and not any(p in tu for p in pats):
            continue
        cpp = os.path.join(REPO, tu + '.cpp')
        obj = os.path.join(BUILD, 'obj', tu + '.obj')
        if not os.path.exists(cpp) or not os.path.exists(obj):
            continue
        lines = fixlib.read(cpp).split('\n')
        if not any(MEMSET.match(l) or FOR_DOWN.match(l) for l in lines):
            continue
        own = tu.lower() + '.cpp'
        by_sym = {r[4]: r[0] for r in rows if r[3] == tu}
        for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj'):
            s = by_sym.get(f.symbol)
            if s is None or status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
                continue
            mine = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
            if not mine:
                continue
            lo, hi = min(mine) - 1, max(mine) - 1
            body = lines[lo:hi + 1]
            for k in range(lo, hi + 1):
                new = memset_site(lines[k], body)
                if new:
                    out[tu].append((s, k + 1, [lines[k]], [new], False))
                    continue
                site = stosd_site(lines, k, lo, hi) or movsd_site(lines, k, lo, hi)
                if site:
                    first, last, newl = site
                    out[tu].append((s, first + 1, lines[first:last + 1], newl, True))
    return out


def block_edit(cpp, ln, old, new):
    def fn(texts):
        lines = texts[cpp].split('\n')
        if lines[ln - 1:ln - 1 + len(old)] != old:
            return None
        lines[ln - 1:ln - 1 + len(old)] = new
        return {cpp: '\n'.join(lines)}
    return fn


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    cands = candidates(rows, status, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d sites in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, ln, old, new, _g in cands[tu]:
                print('%s:%d  %08x' % (tu, ln, s))
                for l in old:
                    print('    - ' + l.strip())
                for l in new:
                    if l.strip():
                        print('    + ' + l.strip())
        return 0
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, ln), [s], [s], block_edit(cpp, ln, old, new), require_gain=g)
                       for s, ln, old, new, g in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_stringops', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
