#!/usr/bin/env python3
"""fix_permute.py - search the order a run of independent statements was written in.

    fix_permute.py [--apply] [--max-run N] [--max-trials N] [--min-sim S] [PATTERN ...]

fix_order.py puts a run of independent stores in one of two orders it can
derive: member order, or the order the original's stores come in. Neither is
the source order in general - the original's store order is VC8's schedule
of some source order - and the tree has them all: the three fields set after
`memset(&sGfxData, 0, 0x48)` stand in each of their six orders somewhere,
as Ghidra listed the original's stores (TEXT_DrawScrollBackground, 0049fa10,
differs from the original in nothing but where `pDC6`'s store lands). So
this searches. Every run of 2..N consecutive assignments that fix_order's
independence test lets go in any order (locals written directly - or, with
no line reading through a pointer, globals, static locals and by-value
parameters written by name - nothing read that another line writes, no
call, no side effect, no aliasing through a pointer) is tried in each of
its other orders - a longer run, or one with
a dependent line in it, in its independent windows. So is the order of the
array declarations in one block, which is their order in the frame: two
buffers can sit in each other's slot (SErrReportNamedResourceLeak, 0041d010),
and a declaration without initialiser means the same wherever it stands.
One trial per function per round, the trials of all functions of a TU in
one compile, each function judged on its own. Only runs with a line whose code differs from the original's are tried.
Per function, the trial that comes closest to the
original - MATCH first, then similarity - is then put through fixlib's batch
loop and kept only where it beats the written order; run again for the next
run in the same function.

Without --apply it lists the runs and the number of trials.
"""
import argparse
import collections
import itertools
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import check            # noqa: E402
import compare          # noqa: E402
import fixlib           # noqa: E402
import ours as ourslib  # noqa: E402
from fix_order import ASSIGN, function_body, independent  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

RANK = {'MATCH': 3, 'REF_DIFF': 2, 'INSN_MATCH': 1}


def score(v):
    return (RANK.get(v[0], 0), v[1])


ARRAY_DECL = re.compile(r'^(?P<ind>[ \t]*)(?:const\s+|static\s+)?(?:::)?[A-Za-z_][\w:]*(?:\s*\*)*\s+(?:\*\s*)*'
                        r'(?P<n>[A-Za-z_]\w*)\[[^\]]+\];[ \t]*$')


def runs_of(text, f, name, tu, max_run):
    """[(first line, block lines, positions)] in our function f whose lines at
    `positions` (indices into the block) may go in any order: runs of
    independent assignments - a longer or mixed run is tried in its
    independent windows - and the array declarations of one block, whose
    order is their order in the frame (SErrReportNamedResourceLeak, 0041d010:
    two buffers in each other's slot)."""
    own = tu.lower() + '.cpp'
    mine = [ln for _o, fn, ln in f.lines if fn.lower().replace('\\', '/').endswith(own)]
    body = function_body(text, name.rsplit('::', 1)[-1], mine)
    if body is None:
        return []
    first, blines = body
    lines = text.split('\n')
    out, run = [], []
    for k in range(len(blines) + 1):
        if k < len(blines) and ASSIGN.match(blines[k]) is not None:
            run.append(first + k)
            continue
        if len(run) >= 2:
            if len(run) <= max_run and independent(run, lines, body, globals_too=True):
                out.append((run[0], [lines[x - 1] for x in run], list(range(len(run)))))
            else:
                covered = 0
                for i in range(len(run) - 1):
                    for w in range(min(max_run, len(run) - i), 1, -1):
                        win = run[i:i + w]
                        if i + w > covered and independent(win, lines, body, globals_too=True):
                            out.append((win[0], [lines[x - 1] for x in win], list(range(w))))
                            covered = i + w
                            break
        run = []
    # Array declarations of one block: same indentation, no brace between, and
    # neither named on the lines between.
    decls = [(k, ARRAY_DECL.match(blines[k])) for k in range(len(blines))]
    decls = [(k, m) for k, m in decls if m]
    groups, cur = [], []
    for k, m in decls:
        if cur:
            k0, m0 = cur[-1]
            between = blines[k0 + 1:k]
            names = [mm.group('n') for _kk, mm in cur] + [m.group('n')]
            if m.group('ind') != m0.group('ind') or any(c in l for l in between for c in '{}') or \
                    any(re.search(r'\b%s\b' % re.escape(n), l) for l in between for n in names):
                if len(cur) >= 2:
                    groups.append(cur)
                cur = []
        cur.append((k, m))
    if len(cur) >= 2:
        groups.append(cur)
    for g in groups:
        g = g[:max_run]
        k0, k1 = g[0][0], g[-1][0]
        out.append((first + k0, [lines[first + x - 1] for x in range(k0, k1 + 1)], [k - k0 for k, _m in g]))
    return out


def candidates(rows, status, pats, max_run, max_trials, model=None, syms=None, sim=None, min_sim=0.0):
    """tu -> {original start: [(first line, old lines, new lines)]} - the trials:
    only runs with a line whose code differs from the original's."""
    out = collections.defaultdict(dict)
    objs, texts = {}, {}
    for s, _e, name, tu, sym, _m, _d in rows:
        if pats and not any(p in tu for p in pats):
            continue
        if status.get(s) in (None, 'MATCH', 'QUARANTINE', 'MISSING') or (sim and sim.get(s, 0) < min_sim):
            continue
        if tu not in objs:
            path = os.path.join(BUILD, 'obj', tu + '.obj')
            objs[tu] = {f.symbol: f for f in ourslib.load_object(os.path.join(BUILD, 'obj'), tu + '.obj')} \
                if os.path.exists(path) else {}
            cpp = os.path.join(REPO, tu + '.cpp')
            texts[tu] = fixlib.read(cpp) if os.path.exists(cpp) else ''
        f = objs[tu].get(sym)
        if f is None or not texts[tu]:
            continue
        trials = []
        runs = runs_of(texts[tu], f, name, tu, max_run)
        if runs and model is not None:
            differ = set(compare.differing_lines(compare.our_view(f, syms), compare.ref_view(s, model[s])))
            # The line after a run counts as its own: VC8 files a store it sinks
            # under the statement it lands in (SFILE_InitializeFileSystem, 00406870).
            runs = [r for r in runs if differ & set(range(r[0], r[0] + len(r[1]) + 1)) or
                    ARRAY_DECL.match(r[1][r[2][0]])]          # a declaration's line holds no code
        for first, old, pos in runs:
            for perm in itertools.permutations(pos):
                if list(perm) != list(pos):
                    new = list(old)
                    for dst, src in zip(pos, perm):
                        new[dst] = old[src]
                    trials.append((first, old, new))
        if trials:
            out[tu][s] = trials[:max_trials]
    return out


def compose(text, edits):
    lines = text.split('\n')
    for first, old, new in edits:
        if lines[first - 1:first - 1 + len(old)] != old:
            return None
        lines[first - 1:first - 1 + len(old)] = new
    return '\n'.join(lines)


def search(cands, rows, model, syms, quarantined, jobs, log):
    """{original start: (best score, best trial)} over all rounds."""
    pristine = {tu: fixlib.read(os.path.join(REPO, tu + '.cpp')) for tu in cands}
    best = {}
    rounds = max((len(t) for v in cands.values() for t in v.values()), default=0)
    try:
        for r in range(rounds):
            tus = set()
            for tu, fns in cands.items():
                edits = [(s, t[r]) for s, t in fns.items() if r < len(t)]
                if not edits:
                    continue
                text = compose(pristine[tu], [e for _s, e in edits])
                if text is None:
                    continue
                fixlib.write(os.path.join(REPO, tu + '.cpp'), text)
                tus.add(tu)
            built = fixlib.build_many(tus, jobs)
            for tu in sorted(tus & built):
                state = check.judge(rows, [tu], model, syms, quarantined)
                for s, t in cands[tu].items():
                    if r < len(t) and s in state:
                        sc = score(state[s])
                        if s not in best or sc > best[s][0]:
                            best[s] = (sc, t[r])
            log('round %d/%d: %d TUs' % (r + 1, rounds, len(tus)))
    finally:
        for tu, text in pristine.items():
            fixlib.write(os.path.join(REPO, tu + '.cpp'), text)
        fixlib.build_many(set(pristine), jobs)
    return best


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--apply', action='store_true')
    ap.add_argument('--max-run', type=int, default=4)
    ap.add_argument('--max-trials', type=int, default=30)
    ap.add_argument('--min-sim', type=float, default=0.9, help='only functions at least this similar')
    ap.add_argument('-j', '--jobs', type=int, default=4)
    ap.add_argument('patterns', nargs='*')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status, sim = {}, {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start' and len(p) > 9:
            status[int(p[0], 16)] = p[9]
            sim[int(p[0], 16)] = float(p[8])
    _ref, model = audit.load_context()
    syms = audit.sym_map(rows)
    cands = candidates(rows, status, args.patterns, args.max_run, args.max_trials, model, syms, sim, args.min_sim)
    nfun = sum(len(v) for v in cands.values())
    ntrial = sum(len(t) for v in cands.values() for t in v.values())
    print('%d trials in %d functions, %d TUs' % (ntrial, nfun, len(cands)), flush=True)
    if not args.apply:
        for tu in sorted(cands):
            for s, t in sorted(cands[tu].items()):
                runs = sorted({(first, len(old)) for first, old, _n in t})  # noqa: E501
                print('%s %08x  %s' % (tu, s, ', '.join('%d+%d' % r for r in runs)))
        return 0
    quarantined = audit.load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    best = search(cands, rows, model, syms, quarantined, args.jobs, lambda m: print(m, flush=True))
    groups = collections.defaultdict(lambda: ([], []))
    for tu, fns in cands.items():
        cpp = os.path.join(REPO, tu + '.cpp')
        for s in fns:
            if s in best and best[s][0] > (RANK.get(status[s], 0), sim[s]):
                first, old, new = best[s][1]
                groups[tu][0].append(fixlib.Edit('%s:%d' % (tu, first), [s], [s],
                                                 lambda texts, cpp=cpp, e=(first, old, new):
                                                 {cpp: compose(texts[cpp], [e])} if compose(texts[cpp], [e])
                                                 else None, require_gain=True))
        if groups[tu][0]:
            groups[tu][1].append(cpp)
    groups = {tu: g for tu, g in groups.items() if g[0]}
    n = sum(len(g[0]) for g in groups.values())
    print('%d functions with a better order' % n, flush=True)
    kept, gained = fixlib.apply_batch(groups, (rows, model, syms, quarantined), jobs=args.jobs,
                                      log=lambda m: print(m, flush=True))
    print('kept %d of %d edits, MATCH %+d' % (kept, n, gained))
    fixlib.record('fix_permute', n, kept, gained, 'max-run %d' % args.max_run)
    return 0


if __name__ == '__main__':
    sys.exit(main())
