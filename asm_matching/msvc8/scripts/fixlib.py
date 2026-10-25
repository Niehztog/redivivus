"""fixlib.py - apply source edits to a TU, keep only what the oracle confirms.

The loop the fixers (fix_static.py, fix_compare.py) share. An edit is a pure
function from the texts of the files it touches to their new texts, plus the
original functions it is for (`owners`) and whose code it can change
(`affects`: the owners, and for a calling-convention change their callers).
The files are always rewritten from their pristine text with the edits still
in play applied in order, so dropping one edit never disturbs another.

Per TU: judge the object as it is (the baseline), apply every edit, rebuild,
judge again. An edit is dropped when a function it affects stops matching or
disappears from the object (an unreferenced static function), or when one of
its owners comes out less similar to the original than before.
Repeat with the edits left, a few rounds at most; if the TU still regresses,
it keeps nothing. Kept results are written into evidence/audit.tsv.

apply_tu does one TU at a time, for edits that reach beyond their TU (a
header the precompiled header includes). apply_batch does the same for many
TUs at once, each round one parallel build: for edits confined to their .cpp.
"""
import os
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import check            # noqa: E402

ROUNDS = 4
SIM_EPS = 0.0005


class Edit:
    def __init__(self, label, owners, affects, fn, require_gain=False, check=None, neutral=False,
                 excused_by_match=False):
        self.label = label
        self.owners = set(owners)            # original starts the edit is for
        self.affects = set(affects) | self.owners
        self.fn = fn                         # {path: text} -> {path: text}, or None if it does not apply
        # An edit whose meaning holds only if the code comes out as the
        # original's (`x == 0` -> `x <= 0`, exact for an unsigned x only)
        # must make an owner more similar, not merely no less.
        self.require_gain = require_gain
        # A test of the edit's own site after the rebuild (the fixer knows
        # what the line must compile to); False drops the edit. The function
        # coming out more similar is not enough for an edit that changes what
        # the code does: deleting code can raise the similarity too.
        self.check = check
        # An edit that removes what the original provably does not have (a
        # statement standing for code the compiler emits by itself) is kept
        # however the similarity moves - the registers may shuffle on the
        # way - unless a function stops matching or disappears.
        self.neutral = neutral
        # An edit whose correctness other functions show - a static promotion,
        # whose convention the callers' code depends on - may leave an owner
        # less similar when one of the functions it affects comes to match.
        self.excused_by_match = excused_by_match


def read(path):
    return open(path, encoding='utf-8', errors='surrogateescape').read()


def write(path, text):
    with open(path, 'w', encoding='utf-8', errors='surrogateescape') as fh:
        fh.write(text)


def compose(pristine, edits):
    """The texts with `edits` applied in order; edits that no longer apply are
    skipped (and returned, so they are not counted as kept)."""
    texts = dict(pristine)
    applied, skipped = [], []
    for e in edits:
        new = e.fn(dict(texts))
        if new is None:
            skipped.append(e)
            continue
        texts.update(new)
        applied.append(e)
    return texts, applied, skipped


def materialise(pristine, edits):
    texts, applied, _skipped = compose(pristine, edits)
    for path, text in texts.items():
        if read(path) != text:
            write(path, text)
    return applied


def build(tu):
    p = subprocess.run([sys.executable, '-I', os.path.join(HERE, 'build.py'), '-j1', tu + '.cpp'],
                       capture_output=True, text=True)
    return 'compiled 1/1 TUs OK' in p.stdout


def matches(state):
    return {s for s, v in state.items() if v[0] == 'MATCH'}


def vanished(base, state):
    """Functions the edits made disappear: compiled before, MISSING or
    QUARANTINE now - an unreferenced static function VC8 drops, a body that
    no longer compiles."""
    gone = ('MISSING', 'QUARANTINE')
    return {s for s, v in state.items() if v[0] in gone and s in base and base[s][0] not in gone}


def worse(base, state, owners, require_gain=False):
    """An owner that does not match and came out less similar than before -
    or, with require_gain, no owner that came out more similar."""
    if require_gain:
        return not any(s in state and s in base and (state[s][0] == 'MATCH' or state[s][1] > base[s][1] + SIM_EPS)
                       for s in owners)
    return any(s in state and s in base and state[s][0] != 'MATCH' and state[s][1] < base[s][1] - SIM_EPS
               for s in owners)


def apply_tu(tu, edits, paths, ctx, log=print):
    """Apply `edits` to the files `paths` of `tu`; keep the confirmed ones.
    ctx: (rows, model, syms, quarantined). Returns (kept edits, MATCH gained)."""
    rows, model, syms, quarantined = ctx
    base = check.judge(rows, [tu], model, syms, quarantined)
    base_match = matches(base)
    pristine = {p: read(p) for p in paths if os.path.exists(p)}
    active = materialise(pristine, edits)
    state = None
    for _round in range(ROUNDS):
        if not active:
            break
        state = check.judge(rows, [tu], model, syms, quarantined) if build(tu) else None
        if state is None:
            break
        lost = (base_match - matches(state)) | vanished(base, state)
        won = matches(state) - base_match
        bad = [e for e in active if e.affects & lost
               or (not e.neutral and worse(base, state, e.owners, e.require_gain)
                   and not (e.excused_by_match and e.affects & won))
               or (e.check is not None and not e.check())]
        if not bad:
            break
        active = materialise(pristine, [e for e in active if e not in bad])
        state = None
    if state is None or base_match - matches(state) or vanished(base, state):
        materialise(pristine, [])
        build(tu)
        log('%-50s kept 0 of %d' % (tu, len(edits)))
        return [], 0
    gained = len(matches(state) - base_match)
    check.update_rows(state)
    log('%-50s kept %d of %d, MATCH %+d' % (tu, len(active), len(edits), gained))
    return active, gained


def build_many(tus, jobs):
    """Rebuild `tus` in one parallel build. Returns the TUs that compiled."""
    if not tus:
        return set()
    p = subprocess.run([sys.executable, '-I', os.path.join(HERE, 'build.py'), '-j%d' % jobs] +
                       [tu + '.cpp' for tu in sorted(tus)], capture_output=True, text=True)
    ok = set()
    for line in p.stdout.splitlines():
        parts = line.split()
        if len(parts) >= 4 and parts[0].startswith('[') and parts[1] == 'ok':
            ok.add(parts[-1][:-4])
    # Up-to-date TUs are not listed: they compiled before.
    return {tu for tu in tus if tu in ok or tu + '.cpp' not in p.stdout}


def apply_batch(groups, ctx, jobs=4, log=print):
    """groups: {tu: (edits, paths)}. Every TU through the same rounds as
    apply_tu, all TUs of a round in one build. Returns (kept edits, MATCH
    gained) over all TUs."""
    rows, model, syms, quarantined = ctx
    base, pristine, active = {}, {}, {}
    build_many(set(groups), jobs)                       # the baseline must be current
    for tu, (edits, paths) in groups.items():
        base[tu] = check.judge(rows, [tu], model, syms, quarantined)
        pristine[tu] = {p: read(p) for p in paths if os.path.exists(p)}
        active[tu] = materialise(pristine[tu], edits)
    pending = {tu for tu in groups if active[tu]}
    final = {}
    for _round in range(ROUNDS):
        if not pending:
            break
        built = build_many(pending, jobs)
        again = set()
        for tu in sorted(pending):
            if tu not in built:
                active[tu] = []
                continue
            state = check.judge(rows, [tu], model, syms, quarantined)
            lost = (matches(base[tu]) - matches(state)) | vanished(base[tu], state)
            won = matches(state) - matches(base[tu])
            bad = [e for e in active[tu] if e.affects & lost
                   or (not e.neutral and worse(base[tu], state, e.owners, e.require_gain)
                       and not (e.excused_by_match and e.affects & won))
                   or (e.check is not None and not e.check())]
            if lost and not any(e.affects & lost for e in bad):
                # A loss no edit claims: the TU keeps nothing.
                active[tu] = materialise(pristine[tu], [])
                continue
            if not bad:
                final[tu] = state
                continue
            active[tu] = materialise(pristine[tu], [e for e in active[tu] if e not in bad])
            if active[tu]:
                again.add(tu)
        pending = again
    # Whatever did not settle keeps nothing.
    revert = {tu for tu in groups if tu not in final}
    for tu in revert:
        active[tu] = []
        materialise(pristine[tu], [])
    build_many(revert, jobs)
    kept = gained = 0
    for tu in sorted(groups):
        if tu in final and active[tu]:
            g = len(matches(final[tu]) - matches(base[tu]))
            check.update_rows(final[tu])
            kept += len(active[tu])
            gained += g
            log('%-50s kept %d of %d, MATCH %+d' % (tu, len(active[tu]), len(groups[tu][0]), g))
        else:
            log('%-50s kept 0 of %d' % (tu, len(groups[tu][0])))
    return kept, gained


FIXES = os.path.join(os.path.dirname(HERE), 'evidence', 'fixes.tsv')


def record(fixer, candidates, kept, gained, note=''):
    """One row in evidence/fixes.tsv: what a fixer's --apply run proposed,
    kept and gained, on top of which commit (its edits are not committed yet).
    MATCH counts are the run's own judgement, TU by TU; the next audit's
    totals are the measure."""
    rev = subprocess.run(['git', '-C', os.path.dirname(HERE), 'rev-parse', '--short', 'HEAD'],
                         capture_output=True, text=True).stdout.strip() or '?'
    new = not os.path.exists(FIXES)
    with open(FIXES, 'a') as fh:
        if new:
            fh.write('fixer\ton\tcandidates\tkept\tmatch_gained\tnote\n')
        fh.write('%s\t%s\t%d\t%d\t%d\t%s\n' % (fixer, rev, candidates, kept, gained, note))

