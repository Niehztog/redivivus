#!/usr/bin/env python3
"""fix_fastcall.py - __fastcall where the original passes the first arguments in ECX and EDX.

    fix_fastcall.py [--apply] [PATTERN ...]

A function the tree declares __cdecl or __stdcall whose original receives
its first argument in ECX (and its second in EDX) and pops the rest was
__fastcall: classify.live_in finds ECX/EDX live on the original's entry,
and its `ret N` is what __fastcall leaves on the stack for the declared
parameters, (n - 2) * 4 (LeaveCriticalSection_Safesock, 0040dde0: ECX, a
bare `ret`). Its callers differ too - they push what the original moves
into ECX and EDX - so the edit is judged on them as well.

A candidate: a mapped namespace function (mangled `@@YA`/`@@YG`) whose
original has ECX, or ECX and EDX, and nothing else live on entry beyond
the stack, n >= 1 dword-sized parameters (EDX needs n >= 2), a single
`ret` popping max(0, n - 2) * 4. A function popping (n - 1) * 4 with only
ECX was a member function (__thiscall), which VC8 does not allow on a free
function: those are left for the generator (UPSTREAM.md).

The edit: `__fastcall` in place of the definition's convention keyword (or
before its name), and the same in the declarations in its own header and
TU. A declaration elsewhere left as it was fails the build, which drops
the edit. All edits are made at once and the tree rebuilt (a header in the
precompiled header rebuilds every TU); every TU holding the function or one
of its callers is judged, with the new mangled name standing for the
original function. An edit is dropped when a function it affects stops
matching or no longer compiles, or when the function comes out less similar
and none of the functions it affects comes to match; the rest is tried
again, a few rounds at most.
"""
import argparse
import collections
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import check            # noqa: E402
import classify         # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_static import def_pattern  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

CONV = {'YA': '__cdecl', 'YG': '__stdcall'}
WIDE = re.compile(r'\b(?:double|float|int64_t|uint64_t|__int64|long long)\b')
ROUNDS = 3


def params_of(text):
    """The parameter list's entries, split at top-level commas."""
    out, depth, cur = [], 0, ''
    for c in text:
        if c in '(<[':
            depth += 1
        elif c in ')>]':
            depth -= 1
        if c == ',' and depth == 0:
            out.append(cur.strip())
            cur = ''
        else:
            cur += c
    if cur.strip() and cur.strip() != 'void':
        out.append(cur.strip())
    return out


def rets(f):
    return {int(i.op_str, 0) if i.op_str else 0 for i in f.insns if i.mnemonic == 'ret'}


def fastcall_sym(sym):
    k = sym.index('@@') + 2
    return sym[:k] + 'YI' + sym[k + 2:]


def retype(text, leaf, definition):
    """`text` with the definition (or the declarations) of `leaf` made
    __fastcall; None when there is nothing to change."""
    if definition:
        rx = re.compile(def_pattern(leaf), re.M)
    else:
        rx = re.compile(r'^(?P<head>[A-Za-z_][^;{}()\n]*?\b' + re.escape(leaf) + r'\s*\((?P<params>[^;{}]*)\)[ \t]*);',
                        re.M)
    out, last, changed = [], 0, False
    for m in rx.finditer(text):
        head = m.group('head')
        name_at = re.search(r'\b%s\s*\($' % re.escape(leaf), head[:head.index('(', head.rindex(leaf)) + 1])
        if name_at is None:
            continue
        before = head[:name_at.start()]
        if re.search(r'\b__fastcall\b', before):
            continue
        if re.search(r'\b(?:__stdcall|__cdecl)\b', before):
            new_before = re.sub(r'\b(?:__stdcall|__cdecl)\b', '__fastcall', before, count=1)
        else:
            new_before = before + '__fastcall '
        out.append(text[last:m.start()] + new_before)
        last = m.start() + name_at.start()
        changed = True
        if definition:
            break
    if not changed:
        return None
    out.append(text[last:])
    return ''.join(out)


def edit_fn(cpp, hdr, leaf):
    def fn(texts):
        new = retype(texts[cpp], leaf, True)
        if new is None:
            return None
        decl = retype(new, leaf, False)
        out = {cpp: decl if decl is not None else new}
        if hdr in texts:
            h = retype(texts[hdr], leaf, False)
            if h is not None:
                out[hdr] = h
        return out
    return fn


def candidates(rows, model, status, fns, pats):
    """[(original start, tu, leaf, our symbol, n parameters, live-in)]."""
    out = []
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'QUARANTINE', 'MISSING') or not sym.startswith('?') or '@@' not in sym:
            continue
        conv = sym[sym.index('@@') + 2:sym.index('@@') + 4]
        if conv not in CONV:
            continue
        theirs = classify.live_in(model[s][0])
        if not theirs or theirs - {'ecx', 'edx'}:
            continue
        f = fns.get(tu + '|' + sym)
        if f is None:
            continue
        cpp = os.path.join(REPO, tu + '.cpp')
        text = fixlib.read(cpp)
        leaf = name.rsplit('::', 1)[-1]
        m = re.search(def_pattern(leaf), text, re.M)
        if not m:
            continue
        plist = params_of(m.group('params'))
        n = len(plist)
        if n < 1 or ('edx' in theirs and n < 2) or any(WIDE.search(p) and '*' not in p for p in plist[:2]):
            continue
        r = rets(model[s][0])
        if r != {max(0, n - 2) * 4}:
            continue
        out.append((s, tu, leaf, sym, n, '+'.join(sorted(theirs))))
    return out


def callers_of(model, targets, mapped):
    """original start -> the mapped original functions that call it."""
    out = collections.defaultdict(set)
    for c, (f, _refs) in model.items():
        if c not in mapped:
            continue
        for i in f.insns:
            if i.mnemonic == 'call' and i.target in targets:
                out[i.target].add(c)
    return out


def build_all():
    p = subprocess.run([sys.executable, '-I', os.path.join(HERE, 'build.py'), '-j4'],
                       capture_output=True, text=True)
    if 'compiled ' not in p.stdout:
        raise SystemExit('build.py did not run: %s' % (p.stderr.strip()[-500:] or p.stdout.strip()[-500:]))
    failed = set()
    for line in p.stdout.splitlines():
        m = re.match(r'^\[\d+/\d+\] FAIL\s+[\d.]+s (\S+)\.cpp', line)
        if m:
            failed.add(m.group(1))
    return failed


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
    _ref, model = audit.load_context()
    fns = {}
    for tu in sorted({r[3] for r in rows}):
        path = os.path.join(BUILD, 'obj', tu + '.obj')
        if os.path.exists(path):
            for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj'):
                fns[f.key] = f
    cands = candidates(rows, model, status, fns, args.patterns)
    tu_of = {r[0]: r[3] for r in rows}
    callers = callers_of(model, {c[0] for c in cands}, set(tu_of))
    print('%d functions, %d call sites from mapped functions' % (len(cands), sum(len(v) for v in callers.values())))
    if not args.apply:
        for s, tu, leaf, sym, n, live in cands:
            print('  %08x %-40s %s  %d params, live-in %s, %d callers' % (s, tu, leaf, n, live, len(callers[s])))
        return 0
    syms = audit.sym_map(rows)
    for s, _tu, _leaf, sym, _n, _live in cands:
        syms[fastcall_sym(sym)] = s
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    edits, affected_tus = [], set()
    for s, tu, leaf, sym, _n, _live in cands:
        cpp, hdr = os.path.join(REPO, tu + '.cpp'), os.path.join(REPO, tu + '.h')
        aff = {s} | callers[s]
        edits.append((fixlib.Edit('%s:%s' % (tu, leaf), [s], aff, edit_fn(cpp, hdr, leaf), excused_by_match=True),
                      {tu_of[x] for x in aff}, [cpp, hdr]))
        affected_tus |= {tu_of[x] for x in aff}
    pats = sorted(affected_tus)
    failed_before = build_all()                 # the baseline must be current
    base = check.judge(rows, pats, model, syms, quarantined)
    paths = sorted({p for _e, _t, ps in edits for p in ps if os.path.exists(p)})
    pristine = {p: fixlib.read(p) for p in paths}
    active = [e for e, _t, _p in edits]
    tus_of = {e.label: t for e, t, _p in edits}
    state = None
    for rnd in range(ROUNDS):
        active = fixlib.materialise(pristine, active)
        if not active:
            break
        failed = build_all()
        state = check.judge(rows, pats, model, syms, quarantined)
        lost = (fixlib.matches(base) - fixlib.matches(state)) | fixlib.vanished(base, state)
        won = fixlib.matches(state) - fixlib.matches(base)
        failed -= failed_before
        bad = [e for e in active if tus_of[e.label] & failed or e.affects & lost
               or (fixlib.worse(base, state, e.owners) and not e.affects & won)]
        print('round %d: %d edits, %d TUs failed, %d lost, %d won, %d to drop' % (
            rnd + 1, len(active), len(failed), len(lost), len(won), len(bad)), flush=True)
        if lost and not any(e.affects & lost for e in bad):
            active = []                      # a loss no edit claims: keep nothing
        if not bad and not failed and active:
            break
        active = [e for e in active if e not in bad]
        state = None
    if state is None:
        fixlib.materialise(pristine, [])
        build_all()
        print('kept 0 of %d edits' % len(edits))
        fixlib.record('fix_fastcall', len(edits), 0, 0)
        return 0
    gained = len(fixlib.matches(state) - fixlib.matches(base))
    check.update_rows(state)
    for e in active:
        print('  kept %s' % e.label)
    print('kept %d of %d edits, MATCH %+d' % (len(active), len(edits), gained))
    fixlib.record('fix_fastcall', len(edits), len(active), gained)
    return 0


if __name__ == '__main__':
    sys.exit(main())
