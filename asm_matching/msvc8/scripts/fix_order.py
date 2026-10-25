#!/usr/bin/env python3
"""fix_order.py - put independent stores back in the order the original made them.

    fix_order.py [--apply] [PATTERN ...]

The decompiler lists a run of independent stores in an order of its own;
VC8 schedules stores from the order they are written in. A run of adjacent
source lines, each an assignment that is the only store to its stack slot in
the function, none calling anything or reading the object stored to, is
reordered when the source shows the reorder keeps the meaning:

  - each line writes a local of the function (not static, not volatile)
    directly - `s.f`, `a[2].f`, `((uint8_t*)&p)[k]`, a declaration - never
    through a pointer;
  - no two lines may write the same bytes: different objects, members or
    constant indices that differ, byte ranges apart - and the stores VC8
    made for them are apart in the frame too (a union would not be);
  - no line reads what another writes, calls anything or has a side effect,
    and no line uses a name another declares;
  - where a line reads through a pointer, none of the written locals has its
    address taken before the run - nor anywhere, if the run sits in a loop or
    the function has a goto.

The order:

  --by offset  (default) in ascending stack-slot order: a struct filled field
               by field, as Blizzard built packets (NET_D2GS_SERVER_Send_0x0C_UNITCHANGE,
               0053b430, matches once `aPacket[0] = nPacketId` and the other
               fields are written in member order - VC8 then schedules them
               exactly as the original does);
  --by store   in the order the original's stores come in.

Kept, through fixlib's batch loop, only where the function comes out more
similar.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import compare          # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_ifelse import match_close  # noqa: E402
from fix_static import def_pattern  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

STORE = re.compile(r'^mov (?P<w>byte|word|dword) ptr \[ebp - (?P<o>0x[0-9a-f]+|\d+)\], ')
WIDTH = {'byte': 1, 'word': 2, 'dword': 4}
ASSIGN = re.compile(r'^[ \t]*(?P<lhs>[^=;]+?)\s=\s(?P<rhs>[^;]+);[ \t]*$')
CALL = re.compile(r'\b(?!sizeof\b)[A-Za-z_]\w*\s*\(')
IDENT = re.compile(r'\b[A-Za-z_]\w*\b')
KEYWORDS = {'if', 'else', 'return', 'case', 'default', 'do', 'while', 'for', 'switch', 'goto', 'break',
            'continue', 'new', 'delete', 'throw', 'static', 'volatile', 'extern'}
COMMENTS = re.compile(r'//[^\n]*|/\*.*?\*/', re.S)


def stores(view):
    """[(index, frame offset, width)] of the stores into the frame."""
    out = []
    for k, i in enumerate(view):
        m = STORE.match(i.text)
        if m:
            out.append((k, int(m.group('o'), 0), WIDTH[m.group('w')]))
    return out


SIZES = {'uint8_t': 1, 'int8_t': 1, 'char': 1, 'BYTE': 1, 'uint16_t': 2, 'int16_t': 2, 'WORD': 2,
         'uint32_t': 4, 'int32_t': 4, 'int': 4, 'DWORD': 4}
LHS_FORMS = [
    # ((uint8_t*)&name)[k]
    (re.compile(r'^\s*\(\((?P<t>\w+)\*\)&(?P<n>\w+)\)\[(?P<k>0x[0-9a-fA-F]+|\d+)\]\s*$'), 'index'),
    # *(uint32_t*)((char*)&name + k)
    (re.compile(r'^\s*\*\((?P<t>\w+)\*\)\(\(char\*\)&(?P<n>\w+) \+ (?P<k>0x[0-9a-fA-F]+|\d+)\)\s*$'), 'byte'),
]


def slot(lhs):
    """(object, byte offset in it, width) an assignment's left side stores to, or None."""
    for rx, kind in LHS_FORMS:
        m = rx.match(lhs)
        if m and SIZES.get(m.group('t')):
            k, size = int(m.group('k'), 0), SIZES[m.group('t')]
            return m.group('n'), k * size if kind == 'index' else k, size
    return None


DECL = re.compile(r'^(?P<type>(?:[\w:]+\s+)*[\w:]+)\s*\**\s*(?<![\w:])(?P<n>[A-Za-z_]\w*)$')
PATH = re.compile(r'^(?P<n>[A-Za-z_]\w*)(?P<rest>(?:\.\w+|\[[^\[\]]+\])*)$')


def access(lhs):
    """What an assignment's left side writes, as far as the source says:
    (object, form, where, names an index reads) - form 'bytes' with where =
    (offset, width), 'path' with where = the chain of members and indices
    (None for an index not constant), 'decl' for a declaration. None for any
    other left side - a write through a pointer among them."""
    lhs = lhs.strip()
    sl = slot(lhs)
    if sl:
        return sl[0], 'bytes', (sl[1], sl[2]), set()
    m = DECL.match(lhs)
    if m:
        if KEYWORDS & set(m.group('type').split()):
            return None                       # `else x = 1;`: not a declaration
        return m.group('n'), 'decl', (), set()
    m = PATH.match(lhs)
    if not m or m.group('n') in KEYWORDS:
        return None
    chain, reads = [], set()
    for member, index in re.findall(r'\.(\w+)|\[([^\[\]]+)\]', m.group('rest')):
        if member:
            chain.append(('.', member))
        elif re.fullmatch(r'\s*(?:0x[0-9a-fA-F]+|\d+)\s*', index):
            chain.append(('[]', int(index, 0)))
        else:
            chain.append(('[]', None))
            reads |= set(IDENT.findall(index))
    return m.group('n'), 'path', tuple(chain), reads


def overlaps(a, b):
    """Whether two writes (from access) may touch the same bytes."""
    if a[0] != b[0]:
        return False
    if a[1] == b[1] == 'bytes':
        (oa, wa), (ob, wb) = a[2], b[2]
        return oa < ob + wb and ob < oa + wa
    if a[1] == b[1] == 'path':
        for x, y in zip(a[2], b[2]):
            if x[0] != y[0]:
                return True
            if x[1] is not None and y[1] is not None and x[1] != y[1]:
                return False
        return True                           # one chain contains the other
    return True


def declarations(body, n):
    """The declarations of `n` in the body, static and volatile ones too."""
    rx = re.compile(r'^[ \t]*(?P<spec>(?:struct\s*\{[^{}\n]*\}|[\w:]+(?:\s*<[^<>;\n]*>)?)(?:\s+[\w:]+)*?)'
                    r'(?P<stars>[\s\*&]*?)\s*\b%s\s*(?P<arr>(?:\[[^\]\n]*\])*)\s*(?:=[^;\n]*)?;' % re.escape(n), re.M)
    return [m for m in rx.finditer(body) if not KEYWORDS & set(m.group('spec').split()) - {'static', 'volatile'}]


def declaration(body, n):
    """(kind, line index) of the one declaration of local `n` in the body -
    kind 'value' or 'pointer' - else (None, None): a parameter, a global, a
    static or volatile local, a name declared twice."""
    found = declarations(body, n)
    if len(found) != 1 or re.search(r'\b(?:static|volatile|extern)\b', found[0].group('spec')):
        return None, None
    m = found[0]
    kind = 'value' if m.group('arr') or not re.search(r'[\*&]', m.group('stars')) else 'pointer'
    return kind, body.count('\n', 0, m.start())


def local_kind(body, n):
    return declaration(body, n)[0]


def derefs(rhs):
    """Whether an expression may read memory through a pointer."""
    return bool(re.search(r'->|\[|(?:^|[^\w\]\s])\s*\*', rhs.strip()))


def side_effects(rhs):
    return bool(re.search(r'\+\+|--|(?<![=!<>])=(?!=)', rhs)) or CALL.search(rhs) is not None


def blank_comments(text):
    """The text with its comments blanked, its lines where they were."""
    return COMMENTS.sub(lambda m: re.sub(r'[^\n]', ' ', m.group(0)), text)


def in_loop(body_lines, at):
    """Whether body line `at` (0-based) is inside a loop of the body."""
    openers = []
    for text in body_lines[:at]:
        for k, c in enumerate(text):
            if c == '{':
                openers.append(text[:k])
            elif c == '}' and openers:
                openers.pop()
    return any(re.search(r'\b(?:for|while|do)\b', t) for t in openers)


def outside(text, n):
    """Whether `n`, written as `n = …` or `n.f = …`, names an object of its
    own outside the function's locals: a global, a static local, or a
    parameter passed by value. Not a volatile, not a reference parameter
    (which may name any object), not a name declared twice."""
    found = declarations(text, n)
    if found:
        return len(found) == 1 and re.search(r'\bstatic\b', found[0].group('spec')) is not None \
            and not re.search(r'\bvolatile\b', found[0].group('spec'))
    sig = text.split('{', 1)[0]
    if '(' not in sig:
        return False                          # the parameter list starts on an earlier line
    return re.search(r'&\s*%s\b' % re.escape(n), sig) is None


def independent(run, lines, body, globals_too=False):
    """Whether the assignment lines `run` (TU line numbers) may be put in
    any order. body = (first line, comment-blanked lines) of the function.
    globals_too: a line may also write a global, a static local or a by-value
    parameter directly (`g = x`, `g.f = x`, never through an index), when no
    line of the run reads through a pointer, which might point at it: two
    distinct named objects never share bytes (SFILE_InitializeFileSystem,
    00406870, matches with `D2Ini_bUseDirect = bResult` written before
    `dwSysOptionBuf[0] = 0x8000`)."""
    first, blines = body
    if run[0] < first or run[-1] - first >= len(blines):
        return False
    parsed = []
    for x in run:
        m = ASSIGN.match(blines[x - first])
        a = access(m.group('lhs')) if m else None
        if a is None or side_effects(m.group('rhs')):
            return False
        parsed.append((a, m.group('rhs')))
    text = '\n'.join(blines)
    written = {a[0] for a, _r in parsed}
    for a, _r in parsed:
        kind = 'value' if a[1] == 'decl' else local_kind(text, a[0])
        if kind is None and globals_too and a[1] == 'path' and all(c[0] == '.' for c in a[2]) \
                and outside(text, a[0]) and not any(derefs(rhs) for _a, rhs in parsed):
            continue
        if kind is None or (kind == 'pointer' and a[1] == 'path' and a[2] and a[2][0][0] == '[]'):
            return False
    for i, (a, rhs) in enumerate(parsed):
        others = {b[0] for j, (b, _r) in enumerate(parsed) if j != i}
        if set(IDENT.findall(rhs)) & written or a[3] & others:
            return False                      # reads what the run writes
        if a[1] == 'decl' and any(re.search(r'\b%s\b' % re.escape(a[0]), blines[run[j] - first])
                                  for j in range(len(run)) if j != i):
            return False                      # another line names what this one declares
        for b, _r in parsed[i + 1:]:
            if overlaps(a, b):
                return False
    if any(derefs(rhs) for _a, rhs in parsed):
        # A pointer read could alias a written local only once its address is out.
        in_run = set(range(run[0] - first, run[-1] - first + 1))
        loops = in_loop(blines, run[0] - first) or re.search(r'\bgoto\b', text)
        for n in written:
            for k, t in enumerate(blines):
                if k in in_run or not re.search(r'\b%s\b' % re.escape(n), t):
                    continue
                if k > run[-1] - first and not loops:
                    continue
                m = ASSIGN.match(t)
                a = access(m.group('lhs')) if m else None
                if a and a[0] == n and not re.search(r'\b%s\b' % re.escape(n), m.group('rhs')):
                    continue                  # a plain write to it
                if k == declaration(text, n)[1]:
                    continue                  # its declaration
                return False
    return True


BY = 'offset'


def plan(f, ours, ref, lines, body):
    """[(first line, old lines, new lines)] for the runs to reorder. A line's
    stack slot comes from the instruction the line table gives it when that
    is its only store, else from the source - `((uint8_t*)&name)[k]` is the
    object's k-th byte - with the object's frame position taken from a line
    whose store is certain: VC8 reschedules stores across lines."""
    ours_st, ref_st = stores(ours), stores(ref)
    ocount = collections.Counter(o for _k, o, _w in ours_st)
    rcount = collections.Counter(o for _k, o, _w in ref_st)
    rpos = {o: k for k, o, _w in ref_st if rcount[o] == 1}
    wanted = (lambda o: True) if BY == 'offset' else (lambda o: o in rpos)
    line_of, width_of = {}, {}
    by_line = collections.defaultdict(list)
    for k, o, w in ours_st:
        if ocount[o] == 1 and ours[k].line:
            by_line[ours[k].line].append((o, w))
    base = {}
    for ln, offs in by_line.items():
        m = ASSIGN.match(lines[ln - 1]) if 0 < ln <= len(lines) else None
        sl = slot(m.group('lhs')) if m else None
        if len(offs) == 1 and sl:
            base.setdefault(sl[0], offs[0][0] + sl[1])
    lo, hi = min(by_line, default=0), max(by_line, default=0)
    fallback = {}
    for ln in range(lo, hi + 1):
        m = ASSIGN.match(lines[ln - 1]) if 0 < ln <= len(lines) else None
        if not m:
            continue                          # only assignments are reordered
        sl = slot(m.group('lhs'))
        if sl and sl[0] in base:
            o = base[sl[0]] - sl[1]
            if ocount.get(o) == 1 and wanted(o):
                line_of[ln], width_of[ln] = o, sl[2]
        elif len(by_line.get(ln, ())) == 1 and wanted(by_line[ln][0][0]):
            fallback[ln] = by_line[ln][0]
    claimed = set(line_of.values())
    for ln, (o, w) in fallback.items():
        if o not in claimed:
            line_of[ln], width_of[ln] = o, w
    out = []
    lns = sorted(line_of)
    run = []
    for ln in lns + [None]:
        if run and (ln is None or ln != run[-1] + 1):
            # The frame grows down: a field at a higher address is a smaller ebp offset.
            spans = sorted((-line_of[x], -line_of[x] + width_of[x]) for x in run)
            apart = all(a[1] <= b[0] for a, b in zip(spans, spans[1:]))
            if len(run) >= 2 and apart and independent(run, lines, body):
                key = (lambda x: -line_of[x]) if BY == 'offset' else (lambda x: rpos[line_of[x]])
                order = sorted(run, key=key)
                if order != run:
                    out.append((run[0], [lines[x - 1] for x in run], [lines[x - 1] for x in order]))
            run = []
        if ln is not None:
            run.append(ln)
    return out


def function_body(text, leaf, lines_used):
    """(first line, comment-blanked lines) of `leaf`'s definition in the TU,
    if it spans the lines the compiled function has; else None."""
    m = re.search(def_pattern(leaf), text, re.M)
    if not m:
        return None
    close = match_close(text, m.end() - 1, '{', '}')
    if close is None:
        return None
    first, last = text.count('\n', 0, m.end() - 1) + 1, text.count('\n', 0, close) + 1
    if lines_used and not (first <= min(lines_used) and max(lines_used) <= last):
        return None
    return first, blank_comments('\n'.join(text.split('\n')[first - 1:last])).split('\n')


def candidates(rows, model, syms, status, pats):
    out = collections.defaultdict(list)
    objs, texts = {}, {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
            texts[tu] = fixlib.read(os.path.join(REPO, tu + '.cpp')) \
                if os.path.exists(os.path.join(REPO, tu + '.cpp')) else ''
        f = objs[tu].get(sym)
        if f is None or not texts[tu]:
            continue
        own = tu.lower() + '.cpp'
        mine = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
        body = function_body(texts[tu], name.rsplit('::', 1)[-1], mine)
        if body is None:
            continue
        for first, old, new in plan(f, compare.our_view(f, syms), compare.ref_view(s, model[s]),
                                    texts[tu].split('\n'), body):
            out[tu].append((s, first, old, new))
    return out


def reorder(cpp, first, old, new):
    def fn(texts):
        lines = texts[cpp].split('\n')
        if lines[first - 1:first - 1 + len(old)] != old:
            return None
        lines[first - 1:first - 1 + len(old)] = new
        return {cpp: '\n'.join(lines)}
    return fn


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--by', choices=('offset', 'store'), default='offset')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    global BY
    BY = args.by
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    syms = audit.sym_map(rows)
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    _ref, model = audit.load_context()
    cands = candidates(rows, model, syms, status, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d runs in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, first, old, new in cands[tu]:
                print('%s:%d  %08x\n%s\n---\n%s\n' % (tu, first, s, '\n'.join(old), '\n'.join(new)))
        return 0
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, first), [s], [s], reorder(cpp, first, old, new), require_gain=True)
                       for s, first, old, new in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_order --by %s' % BY, total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
