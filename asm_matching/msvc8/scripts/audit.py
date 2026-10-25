#!/usr/bin/env python3
"""audit.py - compare every mapped function with the original.

    audit.py [--funcmap evidence/funcmap.tsv] [--out evidence/audit.tsv]

One row per mapped function, sorted by original address:

  start end name tu method ref_insns our_insns byte_diffs similarity status notes

`method` is the funcmap tier that paired the two (an 'align' row is a
similarity guess, a 'string' row strong evidence). `similarity` is the
difflib ratio of the two normalised instruction listings, the progress
measure for a function that does not match yet. Status classes: see
compare.py. A function whose body build.py quarantined (the compiler could not build it,
and blanking it let the rest of its TU compile) is reported as QUARANTINE
with the compiler's message. A summary goes to <out>.summary.

Never quote counts from this file in prose; they go stale. Read the file.
"""
import argparse
import collections
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import compare       # noqa: E402
import ours as ourslib  # noqa: E402
import refimage      # noqa: E402

from oracle_config import ORACLE, REPO, BUILD, REFCACHE, EXPERIMENT, VC, CFLAGS  # noqa: E402


def load_funcmap(path):
    rows = []
    for line in open(path):
        if line.startswith('start\t'):
            continue
        s, e, name, tu, sym, method, detail = line.rstrip('\n').split('\t')
        rows.append((int(s, 16), int(e, 16), name, tu, sym, method, detail))
    return rows


def embedded_address(name):
    """The address a Ghidra-derived name ends in (FOO_00512340, FOO_512340), if any."""
    import re
    m = re.search(r'_(00[4-9a-f][0-9a-f]{5}|[4-9a-f][0-9a-f]{5})(?:@|$)', name)
    return int(m.group(1), 16) if m else None


def load_quarantine(path):
    """(tu, function name) -> the compile error that quarantined it."""
    out = {}
    if os.path.exists(path):
        for line in open(path):
            parts = line.rstrip('\n').split('\t')
            if len(parts) >= 5 and parts[0] != 'file':
                tu = parts[0][:-4] if parts[0].endswith('.cpp') else parts[0]
                out[(tu, parts[3].rsplit('::', 1)[-1])] = parts[4]
    return out


def load_context():
    ref = refimage.Reference(os.path.join(ORACLE, 'reference', 'Game.exe'))
    ref.load(os.path.join(REFCACHE, 'functions.tsv'))
    model = ref.model(os.path.join(REFCACHE, 'model.pkl'))
    return ref, model


class SymMap(dict):
    """Our symbol -> original start: the funcmap's unambiguous symbols, and,
    for a symbol defined in no object of ours, the CRT function crtmap.tsv
    names (so a call to _toupper is checked against the original's)."""

    def __init__(self, base, crt):
        super().__init__(base)
        self.crt = crt

    def __missing__(self, sym):
        import objfuncs
        return self.crt.get(objfuncs.qualified(sym))

    def get(self, sym, default=None):
        v = self[sym]
        return default if v is None else v


def sym_map(rows):
    """Our symbol -> original start, for symbols that are unambiguous."""
    import funcmap
    seen = collections.defaultdict(set)
    for s, _e, _n, _tu, sym, _m, _d in rows:
        seen[sym].add(s)
    base = {k: next(iter(v)) for k, v in seen.items() if len(v) == 1}
    return SymMap(base, funcmap.load_crtmap(os.path.join(ORACLE, 'evidence', 'crtmap.tsv')))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--funcmap', default=os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    ap.add_argument('--out', default=None)
    args = ap.parse_args()
    if args.out is None:
        # An experiment is audited with the baseline's pairs, and never into evidence/.
        args.out = os.path.join(BUILD, 'audit.tsv') if EXPERIMENT else os.path.join(ORACLE, 'evidence', 'audit.tsv')
    elif EXPERIMENT and os.path.realpath(os.path.dirname(args.out)) == os.path.realpath(os.path.join(ORACLE, 'evidence')):
        sys.exit('refusing to write an experiment audit into evidence/')

    ref, model = load_context()
    rows = load_funcmap(args.funcmap)
    fns = {f.key: f for f in ourslib.load_all(os.path.join(BUILD, 'obj'))}
    syms = sym_map(rows)
    quarantined = load_quarantine(os.path.join(BUILD, 'quarantine.tsv'))
    out = []
    statuses = collections.Counter()
    wiring = collections.defaultdict(collections.Counter)   # our global -> implied original address
    for s, e, name, tu, sym, method, _d in rows:
        f = fns.get(tu + '|' + sym)
        if f is None or s not in model:
            out.append((s, e, name, tu, method, 0, 0, 0, 0.0, 'MISSING', 'object not compiled'))
            statuses['MISSING'] += 1
            continue
        q = quarantined.get((tu, name.rsplit('::', 1)[-1]))
        if q is not None:
            # Its body was blanked so that the rest of its TU compiles: nothing to judge.
            out.append((s, e, name, tu, method, len(model[s][0].insns), 0, 0, 0.0, 'QUARANTINE', q))
            statuses['QUARANTINE'] += 1
            continue
        r = compare.compare(compare.our_view(f, syms), compare.ref_view(s, model[s]))
        for sym, addr in r.wiring:
            wiring[sym][addr] += 1
        notes = []
        if r.ref_diffs:
            notes.append('%d refs differ' % r.ref_diffs)
        if r.unverified:
            notes.append('%d refs unverified' % r.unverified)
        out.append((s, e, name, tu, method, r.ref_insns, r.our_insns, r.byte_diffs, r.similarity, r.status,
                    '; '.join(notes)))
        statuses[r.status if not r.status.startswith('OUR') else 'OUR+-N'] += 1
    out.sort()
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, 'w') as fh:
        fh.write('start\tend\tname\ttu\tmethod\tref_insns\tour_insns\tbyte_diffs\tsimilarity\tstatus\tnotes\n')
        for row in out:
            fh.write('%08x\t%08x\t%s\t%s\t%s\t%d\t%d\t%d\t%.3f\t%s\t%s\n' % row)
    total_ref = len(model)
    ref_bytes = sum(model[s][0].end - s for s in model)
    match_bytes = sum(r[1] - r[0] for r in out if r[9] == 'MATCH')
    import subprocess
    tree = subprocess.run(['git', '-C', REPO, 'describe', '--always', '--dirty', '--tags'],
                          capture_output=True, text=True).stdout.strip() or 'unknown'
    table = [l.split('\t')[:2] for l in open(os.path.join(ORACLE, 'flags.tsv'))
             if l.strip() and not l.startswith('#')] if os.path.exists(os.path.join(ORACLE, 'flags.tsv')) else []
    lines = ['tree %s; compiler %s; flags %s%s' % (tree, VC, CFLAGS,
                                                 ''.join('; %s %s' % (p, f) for p, f in table)),
             'original functions: %d (%d bytes of code)' % (total_ref, ref_bytes),
             'mapped and compared: %d' % len(out)]
    for k in ('MATCH', 'REF_DIFF', 'INSN_MATCH', 'INSN_COUNT_MATCH', 'OUR+-N', 'QUARANTINE', 'MISSING'):
        lines.append('  %-17s %6d' % (k, statuses.get(k, 0)))
    lines.append('matched code: %d bytes (%.2f%% of the original)' % (match_bytes, 100.0 * match_bytes / ref_bytes))
    by_method = collections.Counter(r[4] for r in out)
    lines.append('pairings by funcmap tier: ' + ', '.join('%s %d' % kv for kv in by_method.most_common()))
    # Globals: each of ours must imply one original address wherever it is used.
    dm = os.path.join(os.path.dirname(args.out), 'datamap.tsv')
    consistent = 0
    with open(dm, 'w') as fh:
        fh.write('symbol\taddress\tuses\tother_addresses\n')
        for sym in sorted(wiring):
            (addr, n), = wiring[sym].most_common(1)
            others = ['%08x:%d' % (a, k) for a, k in wiring[sym].most_common() if a != addr]
            consistent += not others
            fh.write('%s\t%08x\t%d\t%s\n' % (sym, addr, n, ','.join(others)))
    lines.append('globals seen at aligned instructions: %d, of which consistent %d (%s)' % (
        len(wiring), consistent, os.path.basename(dm)))
    # Self-check: a generated name that carries its Ghidra address must land there.
    agree, disagree = 0, []
    for s0, _e, name, _tu, _m, *_rest in out:
        a = embedded_address(name)
        if a is not None and 0x401000 <= a < 0x6cc000:
            if a == s0:
                agree += 1
            else:
                disagree.append('%s at %08x' % (name, s0))
    for sym in wiring:
        a = embedded_address(sym)
        if a is not None and a >= 0x6cc000:
            if wiring[sym].most_common(1)[0][0] == a:
                agree += 1
            else:
                disagree.append('%s at %08x' % (sym, wiring[sym].most_common(1)[0][0]))
    # A disagreement is a place to look, not necessarily a wrong map: a global
    # is implied by its position, so code laid out differently around it (an
    # if/else in the other order) moves it as surely as a wrong global does.
    lines.append('self-check, names carrying their own address: %d agree, %d elsewhere%s' % (
        agree, len(disagree), ''.join('\n  look at: ' + d for d in disagree[:20])))
    with open(args.out + '.summary', 'w') as fh:
        fh.write('\n'.join(lines) + '\n')
    print('\n'.join(lines))


if __name__ == '__main__':
    main()
