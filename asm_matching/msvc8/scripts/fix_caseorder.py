#!/usr/bin/env python3
"""fix_caseorder.py - put a switch's cases back in the order they were written.

    fix_caseorder.py [--apply] [PATTERN ...]

VC8 lays a switch's case bodies out in source order, and its jump table
names each body's address. The decompiler writes the cases in order of
their values instead, so where Blizzard wrote them in another order, the
two jump tables group the case values into the same bodies but place the
bodies in a different order (PLAYER_EndInteraction, 005350f0: the original
lays out UNIT_MONSTER, UNIT_OBJECT, UNIT_PLAYER, UNIT_ITEM; the tree has
them in value order, and every call lands in another case's body).

A site is a jump table of ours and the original's with the same length and
the same partition of case values into bodies, in another order. The jump's
source line is the `switch`; each body's first instruction names the case
group it belongs to (a group: one or more `case`/`default` labels and the
statements up to the next label at the same depth). The groups the table
reaches are put in the order of the original's bodies; the others keep
their places. A group that falls through into the next is left where it is
(the switch is not touched); the last group, which may end without a
`break`, gets one appended to its last line when it moves, so the line
count stays the same.

Without --apply it lists the sites; with --apply they go through fixlib's
batch loop: kept only where nothing that matched stops matching and the
function gets no less similar.
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
from fix_ifelse import match_close, skip_literal  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

LABEL = re.compile(r'^[ \t]*(?:case\b[^:]*(?:::[^:]*)*:|default\s*:)')
TERMINATOR = re.compile(r'(?:^|[;{}]\s*)(?:break|continue|return\b[^;]*|goto\s+\w+|exit\s*\([^;]*\))\s*;\s*$')


def label_end(line):
    """Whether `line` is a case/default label line, and its text after the
    label's colon (a `case A::B:` label has colons inside)."""
    s = line.strip()
    if s.startswith('default'):
        m = re.match(r'default\s*:', s)
        return (True, s[m.end():]) if m else (False, '')
    if not s.startswith('case ') and not s.startswith('case('):
        return False, ''
    # The label's colon: the first ':' not part of '::', outside parentheses/literals.
    depth, i = 0, 4
    while i < len(s):
        c = s[i]
        if c in '"\'':
            i = skip_literal(s, i)
            continue
        if c == '(':
            depth += 1
        elif c == ')':
            depth -= 1
        elif c == ':' and depth == 0:
            if s.startswith('::', i):
                i += 2
                continue
            return True, s[i + 1:]
        i += 1
    return False, ''


def depth_changes(line):
    """The net brace depth change across `line`, literals and comments skipped."""
    d, i = 0, 0
    while i < len(line):
        c = line[i]
        if c in '"\'':
            i = skip_literal(line, i)
            continue
        if line.startswith('//', i):
            break
        if c == '{':
            d += 1
        elif c == '}':
            d -= 1
        i += 1
    return d


def switch_body(lines, ln):
    """(first body line, last body line) - 1-based, inclusive - of the switch
    whose `switch (` is on line `ln`, the braces on their own lines' ends; or None."""
    text = '\n'.join(lines)
    starts = [0]
    for line in lines:
        starts.append(starts[-1] + len(line) + 1)
    line = lines[ln - 1]
    k = line.find('switch (')
    if k < 0:
        return None
    at = starts[ln - 1] + k + len('switch ')
    close = match_close(text, at, '(', ')')
    if close is None or not text.startswith(') {\n', close):
        return None
    body_open = close + 2
    body_close = match_close(text, body_open, '{', '}')
    if body_close is None:
        return None
    first = text.count('\n', 0, body_open) + 2
    last = text.count('\n', 0, body_close)          # the line before the closing brace's line
    if text[text.rfind('\n', 0, body_close) + 1:body_close].strip():
        return None                                 # the closing brace shares its line
    return first, last


def groups_of(lines, first, last):
    """[(first line, last line)] of the case groups of a switch body, or None
    when the body holds anything but groups at its top level."""
    out = []
    depth = 0
    prev_label = False
    for ln in range(first, last + 1):
        line = lines[ln - 1]
        is_label, rest = label_end(line) if depth == 0 else (False, '')
        if is_label:
            if not (prev_label and out):
                out.append([ln, ln])
            else:
                out[-1][1] = ln
            prev_label = not rest.strip()
        else:
            if not out:
                if line.strip():
                    return None
                continue
            out[-1][1] = ln
            if line.strip():
                prev_label = False
        depth += depth_changes(line)
        if depth < 0:
            return None
    if depth != 0:
        return None
    return [tuple(g) for g in out]


def ends_closed(lines, g):
    """Whether the case group's code cannot run into the next group."""
    body = [lines[k - 1] for k in range(g[0], g[1] + 1) if lines[k - 1].strip()]
    if not body:
        return False
    last = body[-1].strip()
    if TERMINATOR.search(last):
        return True
    if last == '}' and len(body) >= 2:
        # `case X: {` ... `break; }`: the label opened the block.
        is_label, rest = label_end(body[0])
        if is_label and rest.strip() == '{' and TERMINATOR.search(body[-2].strip()):
            return True
    return False


def plan(f, ref_fn, lines, own):
    """[(first body line, old body lines, new body lines)] for our function's
    switches whose case bodies the original lays out in another order."""
    out = []
    rt = ref_fn.tables
    ot = f.decoded.tables
    if not ot or len(ot) != len(rt):
        return out
    jumps = {i.table: i.addr for i in f.decoded.insns if getattr(i, 'table', None) is not None}
    for (otbl, oe), (_rtbl, re_) in zip(ot, rt):
        if len(oe) != len(re_):
            continue
        ours_blocks = collections.OrderedDict()
        for k, t in enumerate(oe):
            ours_blocks.setdefault(t, []).append(k)
        ref_blocks = collections.OrderedDict()
        for k, t in enumerate(re_):
            ref_blocks.setdefault(t, []).append(k)
        if sorted(map(tuple, ours_blocks.values())) != sorted(map(tuple, ref_blocks.values())):
            continue
        order_ours = [tuple(v) for _t, v in sorted(ours_blocks.items())]
        order_ref = [tuple(v) for _t, v in sorted(ref_blocks.items())]
        if order_ours == order_ref:
            continue
        if otbl not in jumps:
            continue
        at = f.line_at(jumps[otbl])
        if not at or not at[0].lower().replace('\\', '/').endswith(own):
            continue
        body = switch_body(lines, at[1])
        if body is None:
            continue
        groups = groups_of(lines, *body)
        if not groups:
            continue
        ref_addr = {tuple(v): t for t, v in ref_blocks.items()}
        mapped = {}                                  # group index -> original body address
        ok = True
        for t, ks in ours_blocks.items():
            la = f.line_at(t)
            if not la or not la[0].lower().replace('\\', '/').endswith(own):
                ok = False
                break
            hit = [gi for gi, g in enumerate(groups) if g[0] <= la[1] <= g[1]]
            if not hit:
                if body[0] <= la[1] <= body[1]:
                    ok = False                       # inside the body but in no group
                    break
                continue                             # the switch's exit: no group
            gi = hit[0]
            if gi in mapped and mapped[gi] != ref_addr[tuple(ks)]:
                ok = False                           # one group, two bodies apart in the original
                break
            mapped[gi] = ref_addr[tuple(ks)]
        if not ok or len(mapped) < 2:
            continue
        slots = sorted(mapped)
        new_order = sorted(slots, key=lambda gi: mapped[gi])
        if new_order == slots:
            continue
        # Only groups that cannot fall into the next may move; the last may lack its break.
        last_gi = len(groups) - 1
        if any(not ends_closed(lines, groups[gi]) and gi != last_gi for gi in slots):
            continue
        order = list(range(len(groups)))
        for slot, gi in zip(slots, new_order):
            order[slot] = gi
        new = []
        for pos, gi in enumerate(order):
            g = groups[gi]
            chunk = [lines[k - 1] for k in range(g[0], g[1] + 1)]
            if pos != last_gi and not ends_closed(lines, g):
                k = max(i for i, l in enumerate(chunk) if l.strip())
                chunk[k] = chunk[k].rstrip() + ' break;'
            new.extend(chunk)
        old = lines[body[0] - 1:body[1]]
        if len(new) != len(old) or new == old:
            continue
        out.append((body[0], old, new))
    return out


def candidates(rows, model, status, pats):
    """tu -> [(original start, first body line, old lines, new lines)]."""
    out = collections.defaultdict(list)
    objs, texts = {}, {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
            continue
        if not model[s][0].tables:
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
            cpp = os.path.join(REPO, tu + '.cpp')
            texts[tu] = fixlib.read(cpp).split('\n') if os.path.exists(cpp) else []
        f = objs[tu].get(sym)
        if f is None or not texts[tu]:
            continue
        for first, old, new in plan(f, model[s][0], texts[tu], tu.lower() + '.cpp'):
            out[tu].append((s, first, old, new))
    return out


def file_edit(cpp, first, old, new):
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
    cands = candidates(rows, model, status, args.patterns)
    total = sum(len(v) for v in cands.values())
    print('%d switches in %d TUs' % (total, len(cands)))
    if not args.apply:
        for tu in sorted(cands):
            for s, first, old, new in cands[tu]:
                print('%s:%d  %08x\n%s\n---\n%s\n' % (tu, first, s, '\n'.join(old), '\n'.join(new)))
        return 0
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, first), [s], [s], file_edit(cpp, first, old, new))
                       for s, first, old, new in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_caseorder', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
