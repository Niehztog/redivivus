#!/usr/bin/env python3
"""fix_gsbuffer.py - keep /GS from protecting buffers the original did not protect.

    fix_gsbuffer.py [--apply] [PATTERN ...]

Under /GS VC8 gives a function a stack cookie when a local is an array of
one- or two-byte elements - also inside a struct - and orders such buffers
next to the cookie. The tree keeps packets and other byte runs as
`uint8_t aPacket[9]`; the original, built with /GS too, has no cookie in
those functions, so its locals were no such arrays (packet structs of scalar
fields: NET_D2GS_SERVER_Send_0x0C_UNITCHANGE, 0053b430). Where ours has a
cookie and the original none, each byte or word array of the function -
up to MAX_ELEMENTS - becomes a struct of as many scalar fields, read and
written through a pointer to its first byte:

    uint8_t aPacket[9];      ->  struct { uint8_t e0, e1, ..., e8; } aPacket;
    aPacket[1] = x;          ->  ((uint8_t*)&aPacket)[1] = x;
    Send(aPacket, 9);        ->  Send(((uint8_t*)&aPacket), 9);

- the same bytes, the same size, no array for /GS to see. Kept, through
fixlib's batch loop, only where the function comes out more similar.

With --members the same is done to a struct type's members: VC8 protects a
local struct that holds a byte array, and the generator writes padding as
one (D2DamageStrc's `uint8_t nReserved66[2]`, local in SetUninterruptableState,
005544b0, and 78 more functions that have a cookie the original lacks). A
member array of a struct that is local in such a function becomes a struct
of scalar fields, and every use of the member anywhere in the tree goes
through a pointer to its first byte:

    uint8_t nReserved66[2];         ->  struct { uint8_t e0, e1; } nReserved66;
    pDamage->nReserved66 + n        ->  ((uint8_t*)&pDamage->nReserved66) + n

The type is shared, so the edit is judged over the whole tree: kept only if
every TU compiles, nothing that matched stops matching and the functions with
a local of the type come out more similar.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import check            # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_ifelse import match_close  # noqa: E402
from fix_static import COMMENTS, def_pattern, strip_comments, tree_files  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

MAX_ELEMENTS = 128
ARRAY = re.compile(r'^(?P<ind>[ \t]*)(?P<t>uint8_t|int8_t|char|unsigned char|BYTE|uint16_t|int16_t|wchar_t|WORD|'
                   r'short|unsigned short)\s+(?P<n>\w+)\[(?P<k>0x[0-9a-fA-F]+|\d+)\];[ \t]*$', re.M)
COOKIE_LOAD = 'eax, dword ptr [0x749de0]'          # mov eax, [___security_cookie] in the original


def gs_off_prefixes():
    out = []
    for line in open(os.path.join(ORACLE, 'flags.tsv')):
        p = line.rstrip('\n').split('\t')
        if not line.startswith('#') and len(p) > 1:
            out.append((p[0], '/GS-' in p[1]))
    return sorted(out, key=lambda r: -len(r[0]))


def under_gs(tu, prefixes):
    for prefix, off in prefixes:
        if (tu + '.cpp').startswith(prefix):
            return not off
    return True


def rewrite_body(body):
    """The body with its byte/word arrays made scalar structs; None if none."""
    arrays = [m for m in ARRAY.finditer(body) if 0 < int(m.group('k'), 0) <= MAX_ELEMENTS]
    if not arrays:
        return None
    for m in sorted(arrays, key=lambda m: -m.start()):
        t, n, k = m.group('t'), m.group('n'), int(m.group('k'), 0)
        fields = ', '.join('e%d' % i for i in range(k))
        decl = '%sstruct { %s %s; } %s;' % (m.group('ind'), t, fields, n)
        head, tail = body[:m.start()], body[m.end():]
        ptr = '((%s*)&%s)' % (t, n)
        # Uses after the declaration: subscripts and decays go through a
        # pointer to the first element; &name and sizeof(name) stay.
        use = re.compile(r'(?<![\w.>])\b%s\b' % re.escape(n))

        def repl(u, t=t, n=n, ptr=ptr):
            before = u.string[max(0, u.start() - 7):u.start()]
            subscript = re.match(r'\s*\[', u.string[u.end():]) is not None
            if re.search(r'sizeof\s*\(?\s*$', before) and not subscript:
                return n                      # sizeof(name): the struct is as large as the array was
            if re.search(r'&\s*$', before) and not subscript:
                return n                      # &name: the struct's address, which is the bytes'
            return ptr
        body = head + decl + use.sub(repl, tail)
    return body


SMALL = (r'uint8_t|int8_t|char|unsigned char|BYTE|uint16_t|int16_t|wchar_t|WORD|short|unsigned short')
STRUCT = re.compile(r'^struct\s+(?P<name>\w+)\s*\{', re.M)
MEMBER_ARRAY = re.compile(r'^(?P<ind>[ \t]*(?:/\*[^*\n]*\*/[ \t]*)?)(?P<t>%s)\s+(?P<n>\w+)\[(?P<k>0x[0-9a-fA-F]+|\d+)\];'
                          r'(?P<tail>[ \t]*(?://[^\n]*)?)$' % SMALL, re.M)
MEMBER = re.compile(r'^[ \t]*(?:/\*[^*\n]*\*/[ \t]*)?(?:struct\s+)?(?P<t>[\w:]+)\s+(?P<n>\w+)\s*(?:\[[^\]\n]*\])?\s*;', re.M)
LOCAL = re.compile(r'^[ \t]+(?:struct\s+)?(?P<t>[\w:]+)\s+(?P<n>\w+)\s*(?:\[[^\]\n]+\])?\s*(?:=[^;\n]*)?;', re.M)


def struct_defs():
    """name -> (path, offset of the body, end of the body) for each struct
    the tree's headers define once."""
    seen = collections.defaultdict(list)
    for p in tree_files():
        if not p.endswith('.h'):
            continue
        t = fixlib.read(p)
        for m in STRUCT.finditer(t):
            close = match_close(t, m.end() - 1, '{', '}')
            if close is not None:
                seen[m.group('name')].append((p, m.end(), close))
    return {k: v[0] for k, v in seen.items() if len(v) == 1}


def reached(defs, texts, name, depth=0):
    """The struct `name` and every struct it holds as a member, nested."""
    out = {name}
    if name in defs and depth < 8:
        p, a, b = defs[name]
        for m in MEMBER.finditer(strip_comments(texts[p][a:b])):
            t = m.group('t').rsplit('::', 1)[-1]
            if t in defs and t not in out:
                out |= reached(defs, texts, t, depth + 1)
    return out


def chain_start(text, i):
    """Start of the postfix expression whose member access begins at text[i]
    (the `.` or `->`): `pCtx->pDamage` for `pCtx->pDamage->nReserved66`."""
    j = i
    while True:
        k = j
        while k > 0 and (text[k - 1].isalnum() or text[k - 1] == '_'):
            k -= 1
        if k == j:                            # no identifier: a bracketed primary or call
            if j > 0 and text[j - 1] in ')]':
                depth, k = 0, j - 1
                while k >= 0:
                    depth += {')': 1, ']': 1, '(': -1, '[': -1}.get(text[k], 0)
                    if depth == 0:
                        break
                    k -= 1
                if k < 0:
                    return None
                j = k
                continue                      # what is before the group may belong to the chain
            return j
        j = k
        before = text[:j].rstrip()
        if before.endswith('->') or before.endswith('.') or before.endswith('::'):
            j = len(before) - (1 if before.endswith('.') else 2)
            j = len(text[:j].rstrip())
            continue
        return j


def rewrite_member(texts, member, t):
    """The texts with every `X.member` / `X->member` read through a pointer
    to its first element; None if a use cannot be rewritten."""
    use = re.compile(r'(?:\.|->)\s*%s\b' % re.escape(member))
    out = {}
    for p, text in texts.items():
        comments = [c.span() for c in COMMENTS.finditer(text)]
        hits = [m for m in use.finditer(text) if not any(a <= m.start() < b for a, b in comments)]
        if not hits:
            continue
        pieces, last = [], 0
        for m in hits:
            start = chain_start(text, m.start())
            if start is None or start < last:
                return None
            subscript = re.match(r'\s*\[', text[m.end():]) is not None
            before = text[max(0, start - 8):start]
            if not subscript and (re.search(r'sizeof\s*\(?\s*$', before) or re.search(r'&\s*$', before)):
                continue                      # sizeof and the address stay as they are
            pieces.append(text[last:start] + '((%s*)&%s)' % (t, text[start:m.end()]))
            last = m.end()
        out[p] = ''.join(pieces) + text[last:]
    return out


def member_candidates(rows, model, status):
    """[(struct, member line match)] for the byte arrays of struct types local
    in functions that have a stack cookie the original does not."""
    prefixes = gs_off_prefixes()
    defs = struct_defs()
    texts = {p: fixlib.read(p) for p in {d[0] for d in defs.values()}}
    objs, srcs = {}, {}
    hit = collections.Counter()
    for s, _e, name, tu, sym, _m, _d in rows:
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING') or not under_gs(tu, prefixes):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
            cpp = os.path.join(REPO, tu + '.cpp')
            srcs[tu] = fixlib.read(cpp) if os.path.exists(cpp) else ''
        f = objs[tu].get(sym)
        if f is None or not any(t == '___security_cookie' for _o, k, t in f.refs if k == 'data'):
            continue
        if any(i.mnemonic == 'mov' and i.op_str == COOKIE_LOAD for i in model[s][0].insns[:16]):
            continue
        m = re.search(def_pattern(name.rsplit('::', 1)[-1]), srcs[tu], re.M)
        close = match_close(srcs[tu], m.end() - 1, '{', '}') if m else None
        if close is None:
            continue
        for lm in LOCAL.finditer(strip_comments(srcs[tu][m.end():close])):
            for t in reached(defs, texts, lm.group('t').rsplit('::', 1)[-1]):
                if t in defs:
                    hit[t] += 1
    # A member name declared in one struct only: its uses are this member's.
    declared = collections.Counter(m.group('n') for p, a, b in defs.values()
                                   for m in MEMBER.finditer(strip_comments(texts[p][a:b])))
    out = []
    for t in sorted(hit, key=lambda k: -hit[k]):
        p, a, b = defs[t]
        for m in MEMBER_ARRAY.finditer(texts[p], a, b):
            if 0 < int(m.group('k'), 0) <= MAX_ELEMENTS and declared[m.group('n')] == 1:
                out.append((t, p, m.group('n'), hit[t]))
    return out


def users(rows, struct, defs, texts):
    """Original starts of the functions with a local that holds `struct`."""
    out, srcs = set(), {}
    holders = {t for t in defs if struct in reached(defs, texts, t)}
    for s, _e, name, tu, _sym, _m, _d in rows:
        if tu not in srcs:
            cpp = os.path.join(REPO, tu + '.cpp')
            srcs[tu] = strip_comments(fixlib.read(cpp)) if os.path.exists(cpp) else ''
        m = re.search(def_pattern(name.rsplit('::', 1)[-1]), srcs[tu], re.M)
        close = match_close(srcs[tu], m.end() - 1, '{', '}') if m else None
        if close is not None and any(lm.group('t').rsplit('::', 1)[-1] in holders
                                     for lm in LOCAL.finditer(srcs[tu][m.end():close])):
            out.add(s)
    return out


def apply_members(rows, model, syms, cands, log=print):
    """Each struct member edit on its own, judged over the whole tree."""
    all_tus = sorted({r[3] for r in rows})
    qpath = os.path.join(BUILD, 'quarantine.tsv')
    fixlib.build_many(set(all_tus), 4)
    quarantined = audit.load_quarantine(qpath)
    base = check.judge(rows, [''], model, syms, quarantined)
    defs = struct_defs()
    kept = gained = 0
    for struct, path, member, n in cands:
        files = [p for p in tree_files() if re.search(r'(?:\.|->)\s*%s\b' % re.escape(member), fixlib.read(p))]
        pristine = {p: fixlib.read(p) for p in set(files) | {path}}
        text = pristine[path]
        _p, a, b = defs[struct]
        m = next(x for x in MEMBER_ARRAY.finditer(text, a, b) if x.group('n') == member)
        k = int(m.group('k'), 0)
        decl = '%sstruct { %s %s; } %s;%s' % (m.group('ind'), m.group('t'), ', '.join('e%d' % i for i in range(k)),
                                              member, m.group('tail'))
        new = dict(pristine)
        new[path] = text[:m.start()] + decl + text[m.end():]
        uses = rewrite_member({p: new[p] for p in files}, member, m.group('t'))
        if uses is None:
            log('%s::%s: a use that cannot be rewritten' % (struct, member))
            continue
        new.update(uses)
        for p, t in new.items():
            fixlib.write(p, t)
        built = fixlib.build_many(set(all_tus), 4)
        q2 = audit.load_quarantine(qpath)
        state = check.judge(rows, [''], model, syms, q2)
        mine = users(rows, struct, defs, {p: fixlib.read(p) for p in {d[0] for d in defs.values()}})
        lost = (fixlib.matches(base) - fixlib.matches(state)) | fixlib.vanished(base, state)
        before = sum(base[s][1] for s in mine if s in base)
        after = sum(state[s][1] if state[s][0] != 'MATCH' else 1.0 for s in mine if s in state)
        g = len(fixlib.matches(state) - fixlib.matches(base))
        ok = len(built) == len(all_tus) and set(q2) <= set(quarantined) and not lost and \
            (g > 0 or after > before + fixlib.SIM_EPS)
        log('%s::%s (%d uses in %d files, %d functions hold it): MATCH %+d, similarity %+.3f, %s' % (
            struct, member, sum(len(re.findall(r'(?:\.|->)\s*%s\b' % re.escape(member), new[p])) for p in files),
            len(files), len(mine), g, after - before,
            'kept' if ok else 'reverted (%d lost, %d TUs failed)' % (len(lost), len(all_tus) - len(built))))
        if ok:
            check.update_rows(state)
            base, kept, gained = state, kept + 1, gained + g
        else:
            for p, t in pristine.items():
                fixlib.write(p, t)
            fixlib.build_many(set(all_tus), 4)
    return kept, gained


def candidates(rows, model, status, pats):
    """tu -> [(original start, leaf)] for functions with a cookie only on our side."""
    prefixes = gs_off_prefixes()
    out = collections.defaultdict(list)
    objs = {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING') or not under_gs(tu, prefixes):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
        f = objs[tu].get(sym)
        if f is None or not any(t == '___security_cookie' for _o, k, t in f.refs if k == 'data'):
            continue
        if any(i.mnemonic == 'mov' and i.op_str == COOKIE_LOAD for i in model[s][0].insns[:16]):
            continue                          # the original has one too
        out[tu].append((s, name.rsplit('::', 1)[-1]))
    return out


def edit(cpp, leaf):
    def fn(texts):
        src = texts[cpp]
        m = re.search(def_pattern(leaf), src, re.M)
        if not m:
            return None
        close = match_close(src, m.end() - 1, '{', '}')
        if close is None:
            return None
        body = rewrite_body(src[m.end():close])
        if body is None:
            return None
        return {cpp: src[:m.end()] + body + src[close:]}
    return fn


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--members', action='store_true', help='struct members instead of locals')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    _ref, model = audit.load_context()
    if args.members:
        cands = member_candidates(rows, model, status)
        print('%d struct members' % len(cands))
        if not args.apply:
            for struct, path, member, n in cands:
                print('%s::%s  (%s; local in %d functions with a cookie the original lacks)' % (
                    struct, member, os.path.relpath(path, REPO), n))
            return 0
        kept, gained = apply_members(rows, model, audit.sym_map(rows), cands, log=lambda m: print(m, flush=True))
        print('kept %d of %d edits, MATCH %+d' % (kept, len(cands), gained))
        fixlib.record('fix_gsbuffer --members', len(cands), kept, gained)
        return 0
    cands = candidates(rows, model, status, args.patterns)
    # Only functions with an array to change.
    for tu in list(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        texts = {cpp: fixlib.read(cpp)}
        cands[tu] = [(s, leaf) for s, leaf in cands[tu] if edit(cpp, leaf)(texts) is not None]
        if not cands[tu]:
            del cands[tu]
    total = sum(len(v) for v in cands.values())
    print('%d functions in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            print(tu, ', '.join(leaf for _s, leaf in cands[tu]))
        return 0
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit(leaf, [s], [s], edit(cpp, leaf), require_gain=True) for s, leaf in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_gsbuffer', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
