#!/usr/bin/env python3
"""fix_assert.py - put assertions back in front of the code they guard.

    fix_assert.py [--apply] [PATTERN ...]

Blizzard's assertion is `if (!(cond)) { ERROR_UnrecoverableInternalError_Halt(
...); exit(-1); }` followed by the code it guards. The decompiler often hands
it back turned inside out when the guarded code returns:

    if (cond) {                          if (!(cond)) {
      return x;                   ->       ERROR_..._Halt(...);
    }                                      exit(-1);
    ERROR_..._Halt(...);                 }
    exit(-1);                            return x;

VC8 lays the two out differently: the original jumps over the halt call when
cond holds (ASYNCDATA_GetReadSize, 0040aa40: `je` over `push 0x272; jmp`),
the inside-out form jumps to it when it does not. The two are the same code
only when the guarded block cannot fall through into the halt: its last
statement returns or otherwise leaves (break, continue, goto, exit, a halt).
This rewrites every such shape in a function that does not match yet; the number of lines stays the
same, so the /Z7 line tables of everything after it stay valid. With --apply,
per TU through fixlib: kept only where nothing that matched stops matching
and the function gets no less similar.
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

SHAPE = re.compile(
    r'^(?P<ind>[ \t]*)if \((?P<cond>.*)\) \{\n'
    r'(?P<body>(?:(?P=ind)[ \t][^\n]*\n|\n){1,400})'      # deeper than ind, or empty; one way to match a line
    r'(?P=ind)\}\n'
    r'(?P<blank>(?:[ \t]*\n)?)'
    r'(?P<halt>(?P=ind)[^\n]*ERROR_UnrecoverableInternalError_Halt\([^\n]*\);\n)'
    r'(?P<exit>(?P=ind)exit\(-1\);\n)', re.M)


LEAVES = re.compile(r'^\s*(?:return\b[^;]*|break|continue|goto\s+\w+|exit\([^;]*\)|'
                    r'[\w:]*ERROR_UnrecoverableInternalError_Halt\([^\n]*\)|throw\b[^;]*);\s*$')
POSTFIX = re.compile(r'^[A-Za-z_]\w*(?:(?:\.|->)[A-Za-z_]\w*|\[[^\[\]]*\]|\((?:[^()]|\([^()]*\))*\))*$')
EQUALITY = re.compile(r'^[^&|^?,=<>]*(==|!=)[^&|^?,=<>]*$')


def top_text(expr):
    """`expr` with every parenthesised or bracketed group, string and
    character literal emptied, and `->` made `.`: what is left is the
    expression's top level."""
    out, depth, q, i = [], 0, None, 0
    while i < len(expr):
        c = expr[i]
        if q:
            if c == '\\':
                i += 1
            elif c == q:
                q = None
        elif c in '"\'':
            q = c
        elif c in '([':
            if depth == 0:
                out.append(c)
            depth += 1
        elif c in ')]':
            depth -= 1
            if depth == 0:
                out.append(c)
        elif depth == 0:
            out.append(c)
        i += 1
    return ''.join(out).replace('->', '.')


def is_unary(expr):
    """True if `expr` is one unary expression - prefix operators, casts,
    calls, subscripts, member access - with no binary operator at its top."""
    t = top_text(expr).strip().lstrip('!~*&-+ ')
    return re.fullmatch(r'(?:\(\)|\[\]|[\w.]|\s)*', t) is not None


def negate(cond):
    """!(cond), written as the generator would: a negation dropped, a single
    equality flipped, otherwise wrapped."""
    c = cond.strip()
    if c.startswith('!') and not c.startswith('!='):
        x = c[1:].strip()
        if x.startswith('(') and x.endswith(')') and top_text(x) == '()':
            return x[1:-1]
        if is_unary(x):
            return x
    if is_unary(c) and not c.startswith(('-', '+')):
        return '!' + c
    m = EQUALITY.match(top_text(c))
    if m:
        op = m.group(1)
        # The one top-level equality operator: find it in the original text.
        t, depth, q = c, 0, None
        for i, ch in enumerate(t):
            if q:
                if ch == q and t[i - 1] != '\\':
                    q = None
            elif ch in '"\'':
                q = ch
            elif ch in '([':
                depth += 1
            elif ch in ')]':
                depth -= 1
            elif depth == 0 and t.startswith(op, i):
                return t[:i] + ('!=' if op == '==' else '==') + t[i + 2:]
    return '!(%s)' % c


def rewrite(m):
    ind = m.group('ind')
    body = m.group('body').split('\n')[:-1]
    first = next(b for b in body if b.strip())
    step = len(first) - len(first.lstrip())
    sub = first[len(ind):step] if step > len(ind) else '  '
    out = '%sif (%s) {\n' % (ind, negate(m.group('cond')))
    out += ind + sub + m.group('halt').lstrip()
    out += ind + sub + m.group('exit').lstrip()
    out += ind + '}\n'
    out += m.group('blank')
    for b in body:
        out += (ind + b[step:] + '\n') if b.strip() else '\n'
    return out


def functions_by_line(tu):
    """[(first line, last line, our function)] of the TU's .cpp, from /Z7."""
    out = []
    own = tu.lower() + '.cpp'
    for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj'):
        lines = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
        if lines:
            out.append((min(lines), max(lines), f))
    return out


def candidates(rows, status, pats):
    """tu -> [(original start, line number, old text, new text)]."""
    by_sym = {(r[3], r[4]): r[0] for r in rows}
    out = collections.defaultdict(list)
    for tu in sorted({r[3] for r in rows}):
        if pats and not any(p in tu for p in pats):
            continue
        cpp = os.path.join(REPO, tu + '.cpp')
        if not os.path.exists(cpp) or not os.path.exists(os.path.join(BUILD, 'obj', tu + '.obj')):
            continue
        text = fixlib.read(cpp)
        spans = None
        for m in SHAPE.finditer(text):
            ln = text.count('\n', 0, m.start()) + 1
            if spans is None:
                spans = functions_by_line(tu)
            owner = [f for lo, hi, f in spans if lo <= ln <= hi]
            if len(owner) != 1:
                continue
            s = by_sym.get((tu, owner[0].symbol))
            if s is None or status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING'):
                continue
            last = [l for l in m.group('body').split('\n') if l.strip()][-1]
            if not LEAVES.match(last):
                continue                     # the block could fall through into the halt
            new = rewrite(m)
            if new.count('\n') == m.group(0).count('\n'):
                out[tu].append((s, ln, m.group(0), new))
    return out


def block_edit(cpp, ln, old, new):
    def fn(texts):
        t = texts[cpp]
        at = 0
        for _ in range(ln - 1):
            at = t.index('\n', at) + 1
        if not t.startswith(old, at):
            return None
        return {cpp: t[:at] + new + t[at + len(old):]}
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
            for s, ln, old, new in cands[tu]:
                print('%s:%d  %08x\n%s---\n%s' % (tu, ln, s, old, new))
        return 0
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    ctx = (rows, model, syms, quarantined)
    groups = {}
    for tu in sorted(cands):
        cpp = os.path.join(REPO, tu + '.cpp')
        groups[tu] = ([fixlib.Edit('%s:%d' % (tu, ln), [s], [s], block_edit(cpp, ln, old, new))
                       for s, ln, old, new in cands[tu]], [cpp])
    kept, gained = fixlib.apply_batch(groups, ctx, jobs=args.jobs, log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, total, gained))
    fixlib.record('fix_assert', total, kept, gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
