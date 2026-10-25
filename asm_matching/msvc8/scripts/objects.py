#!/usr/bin/env python3
"""objects.py - functions the tree files apart from where the original has them.

    objects.py [--out evidence/objects.tsv]

VC8 passes arguments in registers of its own choosing (EAX, EBX, ESI, EDI)
only to a function it compiles together with every call to it: a static
function and its callers in one object (or, under /GL, one link; the Rich
header counts 12 /GL objects in all of Game.exe). So when the original passes
such arguments to a function, the function and all its callers were one
object. Where the tree has a caller in another TU, the tree's files part
where Blizzard's did not - the generator files a function by its Ghidra
namespace - and neither function can match until they share a TU:
D2Client/UI/Draw calls UI_ShowMonsterNameBar (00452be0, D2Client/UI/ui) with
its argument in ESI, and the original's ui.cpp runs on into Draw's range.

A function whose original receives only ECX (and EDX) beyond what its
declaration passes is a different case: its declared convention is wrong
(__thiscall or __fastcall, not __cdecl/__stdcall), wherever it is filed.

One row per such function (tab-separated, by address):
  start  name  tu  kind (object | convention)  live-in registers
  foreign caller TUs (tu:count, ...)  its @sourcefile  callers' @sourcefile
The @sourcefile columns are the generator's own annotations (the original
file a function's __FILE__ strings name), where it wrote one.
"""
import argparse
import collections
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit            # noqa: E402
import classify         # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE, REPO  # noqa: E402

# Registers a convention passes arguments in, by its letter in a mangled name.
CONV_ARGS = {'A': set(), 'G': set(), 'I': {'ecx', 'edx'}, 'E': {'ecx'}}   # cdecl stdcall fastcall thiscall
SOURCEFILE = re.compile(r'^//\s*@sourcefile\S*\s+(\S+)')


def convention_args(sym):
    """Registers the declared convention passes arguments in, from the
    mangled name: a free function (Y) or static member (S, K, C) has its
    convention letter right after, a member function after access and
    `this` qualifier (QAE: public, __thiscall). None when unknown."""
    if not sym.startswith('?') or '@@' not in sym:
        return None
    rest = sym[sym.index('@@') + 2:]
    letter = rest[1:2] if rest[:1] in ('Y', 'S', 'K', 'C') else rest[2:3]
    return CONV_ARGS.get(letter)


class SourceFiles:
    """The @sourcefile annotation above a function's definition, by TU and line."""

    def __init__(self):
        self.text = {}

    def at(self, tu, line):
        if line is None:
            return ''
        if tu not in self.text:
            p = os.path.join(REPO, tu + '.cpp')
            self.text[tu] = open(p, encoding='utf-8', errors='replace').read().split('\n') if os.path.exists(p) else []
        lines = self.text[tu]
        # The definition is at or just above the first line with code; its
        # comment block is the run of // lines right above that.
        k = min(line, len(lines)) - 1
        while k > 0 and not lines[k].startswith('//') and line - k < 4:
            k -= 1
        while k >= 0 and lines[k].startswith('//'):
            m = SOURCEFILE.match(lines[k])
            if m:
                return m.group(1)
            k -= 1
        return ''


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('--out', default=os.path.join(ORACLE, 'evidence', 'objects.tsv'))
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    _ref, model = audit.load_context()
    fns = {f.key: f for f in ourslib.load_all(os.path.join(BUILD, 'obj'))}
    by_start = {r[0]: r for r in rows}
    callers = collections.defaultdict(list)
    for s, (_dec, refs) in model.items():
        for _a, _o, _n, k, t in refs:
            if k == 'call':
                callers[t].append(s)
    files = SourceFiles()

    def label(start):
        r = by_start.get(start)
        if r is None:
            return ''
        f = fns.get(r[3] + '|' + r[4])
        return files.at(r[3], f.source_line) if f is not None else ''

    out = []
    for s, _e, name, tu, sym, _m, _d in rows:
        args_in = convention_args(sym)
        if args_in is None:
            continue
        extra = classify.live_in(model[s][0]) - args_in
        if not extra:
            continue
        kind = 'convention' if extra <= {'ecx', 'edx'} else 'object'
        foreign = collections.Counter(by_start[c][3] for c in callers.get(s, ()) if c in by_start and by_start[c][3] != tu)
        if kind == 'object' and not foreign:
            continue                      # all callers in its TU: static is enough (fix_static.py)
        theirs = sorted({label(c) for c in callers.get(s, ()) if c in by_start and by_start[c][3] != tu} - {''})
        out.append((s, name, tu, kind, '+'.join(sorted(extra)),
                    ', '.join('%s:%d' % kv for kv in sorted(foreign.items())), label(s), ', '.join(theirs)))
    with open(args.out, 'w') as fh:
        fh.write('start\tname\ttu\tkind\tlive_in\tforeign_callers\tsourcefile\tcaller_sourcefiles\n')
        for r in out:
            fh.write('%08x\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n' % r)
    kinds = collections.Counter(r[3] for r in out)
    print('%s: %s' % (os.path.relpath(args.out), ', '.join('%s %d' % kv for kv in sorted(kinds.items()))))


if __name__ == '__main__':
    main()
