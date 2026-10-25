#!/usr/bin/env python3
"""fix_nestcall.py - put calls back inside the argument lists they were nested in.

    fix_nestcall.py [--apply] [--runs] [PATTERN ...]

VC8 evaluates stack arguments right to left. A nested call,
`HasQuestItem(GetGamePointer(pUnit), pUnit, 'bks ')`, therefore pushes the
arguments to the right of the inner call first and calls it afterwards: the
original's `push 0x20736b62; mov ecx, edi; call GetGamePointer` (Q04_ActiveFilter,
00592fb0). Ghidra hands the result back through a temporary,

    pGame = GetGamePointer(pUnit);
    pFoundItem = HasQuestItem(pGame, pUnit, dwItemCode);

which VC8 compiles as written: the call first, every push after it. The two
differ only in when the arguments right of the temporary are evaluated, so
the temporary is put back into the call where:

  - the temporary's line assigns it the result of one call and nothing else;
  - the next line names it exactly once, as a whole argument of a call;
  - the arguments to its right (those VC8 evaluates before the inner call)
    call nothing and change nothing;
  - it is dead after that line: every other mention of it in the function
    assigns or declares it, or the next one after does and the site is in no
    loop (a declaration with the call as its initialiser keeps the bare
    declaration).

With --runs, a run of two or more temporaries right above one call, each
used once in it, goes back in together (AUTOMAP_DrawGamePassword, 00459e90:
`bMultiLineCenter = 0; dwColor = 4; nY = AUTOMAP_TextHeightOffset; nTextWidth
= DRAW_text0(wsz); DRAW_text(wsz, WindowSizeX - nTextWidth - 0x10, nY,
dwColor, bMultiLineCenter);`, where the original pushes 0, 4 and the offset
before calling DRAW_text0). Temporaries holding a constant or a local whose
address is not taken may go anywhere; those that call or read memory must
stand in the order VC8 evaluates them, the earliest in the argument furthest
right, and the other arguments right of them must call and change nothing.

Kept only where the function comes out more similar: where the original
evaluated those arguments first. The line count stays the same.
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
from fix_stringops import dead_after, mentions  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

TEMP = re.compile(r'^(?P<ind>[ \t]*)(?P<decl>(?:const\s+)?[A-Za-z_][\w:]*(?:\s*\*)*\s+(?:\*\s*)*)?'
                  r'(?P<x>[A-Za-z_]\w*) = (?P<call>[A-Za-z_][\w:]*(?:(?:->|\.)[A-Za-z_]\w*)*\(.*\));[ \t]*$')
IMPURE = re.compile(r'\+\+|--|(?<![=!<>])=(?!=)|\b(?!sizeof\b)[A-Za-z_]\w*\s*\(')
COMMENT = re.compile(r'/\*.*?\*/')


def balanced_call(text):
    """True if `text` is one call: a callee and one argument list spanning to the end."""
    open_at = text.index('(')
    depth = 0
    for k in range(open_at, len(text)):
        if text[k] == '(':
            depth += 1
        elif text[k] == ')':
            depth -= 1
            if depth == 0:
                return k == len(text) - 1
    return False


def call_args(line):
    """[(start, end, [(arg start, arg end)])] for every argument list in `line`
    (string and character literals skipped)."""
    out, stack, q = [], [], None
    k = 0
    while k < len(line):
        c = line[k]
        if q:
            if c == '\\':
                k += 2
                continue
            if c == q:
                q = None
        elif c in '"\'':
            q = c
        elif c == '(':
            callish = k > 0 and (line[k - 1].isalnum() or line[k - 1] in '_>')
            stack.append([k, callish, [k + 1]])
        elif c == ',' and stack:
            stack[-1][2].append(k + 1)
        elif c == ')' and stack:
            start, callish, cuts = stack.pop()
            if callish:
                bounds = cuts + [k + 1]
                out.append((start, k, [(bounds[i], bounds[i + 1] - 1) for i in range(len(bounds) - 1)]))
        k += 1
    return out


def site(lines, k, lo, hi):
    """The rewrite of the temporary at lines[k] into lines[k+1], or None."""
    t = TEMP.match(COMMENT.sub('', lines[k]))
    if not t or k + 1 > hi or not balanced_call(t.group('call')):
        return None
    x, call = t.group('x'), t.group('call')
    nxt = lines[k + 1]
    hits = [m.start() for m in re.finditer(r'(?<![\w.>])%s\b' % re.escape(x), nxt)]
    if len(hits) != 1 or re.match(r'^\s*(?:[\w:*\s]+\s)?%s\s*=[^=]' % re.escape(x), nxt):
        return None
    at = hits[0]
    target = None
    for _s, _e, args in call_args(nxt):
        for i, (a, b) in enumerate(args):
            if nxt[a:b].strip() == x and a <= at < b:
                target = (args, i)
    if target is None:
        return None
    args, i = target
    for a, b in args[i + 1:]:
        if IMPURE.search(nxt[a:b]):
            return None
    if not dead_after(lines, lo, hi, k, k + 1, (x,)):
        return None
    others = [j for j in range(lo + 1, hi + 1) if j not in (k, k + 1) and mentions(x, lines[j])]
    a, b = args[i]
    lead = nxt[a:b][:len(nxt[a:b]) - len(nxt[a:b].lstrip())]
    new_next = nxt[:a] + lead + call + nxt[b:]
    first = ''
    if t.group('decl') and others:
        first = t.group('ind') + t.group('decl').rstrip() + ' ' + x + ';'
    notes = ' '.join(COMMENT.findall(lines[k]))
    if notes:
        first = (first + ' ' + notes) if first else t.group('ind') + notes
    return [lines[k], nxt], [first, new_next]


ANYTEMP = re.compile(r'^(?P<ind>[ \t]*)(?P<decl>(?:const\s+)?[A-Za-z_][\w:]*(?:\s*\*)*\s+(?:\*\s*)*)?'
                     r'(?P<x>[A-Za-z_]\w*) = (?P<e>[^;]+);[ \t]*$')
CONST = re.compile(r"^(?:\((?:[\w:]+\s*\**)\))?\(?(?:-?(?:0x[0-9a-fA-F]+|\d+)[uUlL]*|L?'(?:\\.|[^'])'|nullptr|true|false)\)?$")
DECL = re.compile(r'^\s*(?:const\s+)?(?:::)?[A-Za-z_][\w:]*(?:[\s*]+)(?P<n>[A-Za-z_]\w*)(?:\[[^\]]*\])?(?: = [^;]*)?;\s*$')
PRIMARY = re.compile(r'^(?:[A-Za-z_][\w:]*(?:(?:->|\.)[A-Za-z_]\w*)*(?:\(.*\))?|-?(?:0x[0-9a-fA-F]+|\d+)[uUlL]*|L?\'.*\')$')


def locals_of(lines, lo, hi):
    """Parameters and locals of the function at lines[lo..hi], less any whose
    address is taken."""
    names = set()
    sig = lines[lo]
    if '(' in sig:
        inner = sig[sig.index('(') + 1:sig.rindex(')')] if ')' in sig else ''
        for p in inner.split(','):
            m = re.search(r'([A-Za-z_]\w*)\s*$', p.strip())
            if m:
                names.add(m.group(1))
    for j in range(lo + 1, hi + 1):
        m = DECL.match(COMMENT.sub('', lines[j]))
        if m:
            names.add(m.group('n'))
    body = '\n'.join(lines[lo:hi + 1])
    return {n for n in names if not re.search(r'&\s*%s\b' % re.escape(n), body)}


def run_site(lines, b, lo, hi, pure_names):
    """A run of temporaries (two or more) right above lines[b], each used once
    in lines[b], put back into its argument list - or None. Temporaries that
    call something or read memory must be ordered as VC8 evaluates them in
    the call: the earliest in the argument furthest right."""
    nxt = lines[b]
    outer = None
    for start, end, args in call_args(nxt):
        if outer is None or start < outer[0]:
            outer = (start, end, args)
    if outer is None:
        return None
    temps = []
    j = b - 1
    while j > lo:
        t = ANYTEMP.match(COMMENT.sub('', lines[j]))
        if not t or t.group('e').count('(') != t.group('e').count(')'):
            break
        x, e = t.group('x'), t.group('e').strip()
        hits = [m.start() for m in re.finditer(r'(?<![\w.>])%s\b' % re.escape(x), nxt)]
        if len(hits) != 1 or any(x == u[1] for u in temps) or \
                any(mentions(x, u[2]) for u in temps) or re.search(r'\+\+|--|(?<![=!<>])=(?!=)', e):
            break
        idx = next((i for i, (a, z) in enumerate(outer[2]) if a <= hits[0] < z), None)
        before, after = nxt[:hits[0]].rstrip(), nxt[hits[0] + len(x):].lstrip()
        if idx is None or (before.endswith('&') and not before.endswith('&&')) or \
                re.match(r'(?:\+\+|--|[-+*/%&|^]?=(?!=)|\[)', after) or before.endswith(('++', '--')):
            break                                # its address, an lvalue: not a value
        temps.append((j, x, e, t, idx, hits[0]))
        j -= 1
    if len(temps) < 2:
        return None
    temps.reverse()                              # textual order, earliest first
    impure = [u for u in temps if not (CONST.match(u[2]) or u[2] in pure_names)]
    order = [u[4] for u in impure]
    if any(order[i] <= order[i + 1] for i in range(len(order) - 1)):
        return None
    if impure:
        used = {u[4] for u in temps}
        for i, (a, z) in enumerate(outer[2]):
            if i > min(order) and i not in used and IMPURE.search(nxt[a:z]):
                return None
    first, last = temps[0][0], b
    if not dead_after(lines, lo, hi, first, last, [u[1] for u in temps]):
        return None
    new_next = nxt
    for _j, x, e, _t, _i, at in sorted(temps, key=lambda u: -u[5]):
        whole = any(nxt[a:z].strip() == x for a, z in outer[2])
        rep = e if PRIMARY.match(e) or whole else '(%s)' % e
        new_next = new_next[:at] + rep + new_next[at + len(x):]
    new = []
    for j, x, _e, t, _i, _h in temps:
        keep = ''
        others = [q for q in range(lo + 1, hi + 1) if not first <= q <= last and mentions(x, lines[q])]
        if t.group('decl') and others:
            keep = t.group('ind') + t.group('decl').rstrip() + ' ' + x + ';'
        notes = ' '.join(COMMENT.findall(lines[j]))
        if notes:
            keep = (keep + ' ' + notes) if keep else t.group('ind') + notes
        new.append(keep)
    return lines[first:last + 1], new + [new_next], first


def candidates(rows, status, pats, runs=False):
    """tu -> [(original start, first line, old lines, new lines)] (1-based)."""
    out = collections.defaultdict(list)
    for tu in sorted({r[3] for r in rows}):
        if pats and not any(p in tu for p in pats):
            continue
        cpp = os.path.join(REPO, tu + '.cpp')
        obj = os.path.join(BUILD, 'obj', tu + '.obj')
        if not os.path.exists(cpp) or not os.path.exists(obj):
            continue
        lines = fixlib.read(cpp).split('\n')
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
            taken = set()
            if runs:
                pure = locals_of(lines, lo, hi)
                for b in range(hi, lo, -1):
                    if b in taken:
                        continue
                    r = run_site(lines, b, lo, hi, pure)
                    if r and not taken & set(range(r[2], b + 1)):
                        out[tu].append((s, r[2] + 1, r[0], r[1]))
                        taken |= set(range(r[2], b + 1))
                continue
            for k in range(lo, hi):
                if k in taken or k + 1 in taken:
                    continue
                r = site(lines, k, lo, hi)
                if r:
                    out[tu].append((s, k + 1, r[0], r[1]))
                    taken |= {k, k + 1}
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
    ap.add_argument('--runs', action='store_true', help='runs of two or more temporaries feeding one call')
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    cands = candidates(rows, status, args.patterns, runs=args.runs)
    total = sum(len(v) for v in cands.values())
    print('%d sites in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, ln, old, new in cands[tu]:
                print('%s:%d  %08x' % (tu, ln, s))
                for l in old:
                    print('    - ' + l.strip()[:160])
                for l in new:
                    print('    + ' + l.strip()[:160])
        return 0
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, ln), [s], [s], block_edit(cpp, ln, old, new), require_gain=True)
                       for s, ln, old, new in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_nestcall', total, kept, gained, 'runs' if args.runs else '')
    return 0


if __name__ == '__main__':
    sys.exit(main())
