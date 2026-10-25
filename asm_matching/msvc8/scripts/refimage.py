#!/usr/bin/env python3
"""refimage.py - carve the original Game.exe into functions.

    refimage.py [--out build/ref/functions.tsv]

PE images carry no symbol sizes, so function extents are derived, from the
image alone:

  starts   every 16-aligned address after int3 padding (MSVC 8 aligns each
           function to 16 and pads with 0xCC), every direct call target (to a
           fixpoint: a new function's calls are followed too), the exports, the
           entry point, and every code address held in a run of two or more
           consecutive code pointers in a data section - vtables and function
           tables. A padded "start" that the previous function falls through
           into is an operand byte that happened to be 0xCC, and is dropped.
  roots    any other code address held in data (SEH scope tables, C++ EH
           unwind and catch maps) is an entry into the function that contains
           it - a filter, handler or funclet - and is decoded as part of it.
  extent   recursive descent from the start and its extra roots, bounded by
           the next start (funcdecode.py), so switch tables and padding are not
           mistaken for code.

Output columns: start, end (exclusive), instruction count, why it is a start
(pad / call / vtbl / export / entry, '+'-joined), extra roots (comma list).
"""
import argparse
import bisect
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import funcdecode  # noqa: E402
import peimage     # noqa: E402

ORACLE = os.path.dirname(HERE)


class Reference:
    """The original image, carved. functions: start -> (end, ninsns, why, roots)."""

    def __init__(self, exe):
        self.pe = pe = peimage.PEImage(exe)
        t = pe.text
        self.ts, self.te = pe.base + t.va, pe.base + t.va + t.vsize
        self.code = pe.read(self.ts, t.vsize)
        self.relocs = pe.relocs
        self.functions = {}

    def in_text(self, v):
        return self.ts <= v < self.te

    def reloc_at(self, addr):
        if addr in self.relocs:
            return struct.unpack_from('<I', self.code, addr - self.ts)[0] if self.in_text(addr) else self.pe.u32(addr)
        return None

    def decode(self, start, limit, roots=()):
        f = funcdecode.decode_function(self.code, self.ts, start, limit, self.reloc_at)
        if roots:
            # Extra entries (handlers, funclets) are decoded with the same limit and merged.
            for r in roots:
                g = funcdecode.decode_function(self.code, self.ts, r, limit, self.reloc_at)
                have = {i.addr for i in f.insns}
                f.insns += [i for i in g.insns if i.addr not in have]
                f.tables += g.tables
                f.index_tables += g.index_tables
                f.calls += g.calls
                f.end = max(f.end, g.end)
            f.insns.sort(key=lambda i: i.addr)
        return f

    def carve(self):
        why = {}

        def add(a, w):
            why.setdefault(a, set()).add(w)

        code, ts, te = self.code, self.ts, self.te
        add(ts, 'pad')
        for a in range(ts + 16, te, 16):
            if code[a - ts - 1] == 0xCC and code[a - ts] != 0xCC:
                add(a, 'pad')
        entry = self.pe.base + self.pe.entry_rva
        if self.in_text(entry):
            add(entry, 'entry')
        for v in self.pe.exports.values():
            if self.in_text(v):
                add(v, 'export')
        data_ptrs = {}
        for r in sorted(self.relocs):
            if self.in_text(r):
                continue
            v = self.pe.u32(r)
            if self.in_text(v):
                data_ptrs[r] = v
        for r, v in data_ptrs.items():
            if (r - 4) in data_ptrs or (r + 4) in data_ptrs:
                add(v, 'vtbl')
        others = set(data_ptrs.values())

        # Fixpoint: decode, collect call targets, repeat while new starts appear;
        # drop padded starts the previous function falls through into. Then
        # the addresses code takes: `push offset Filter`, `mov reg, offset
        # Callback` name a function too, one that is never called directly
        # and, when its predecessor ends on a 16-byte boundary, has no padding
        # to give it away (SetUnhandledExceptionFilter's filter at 00403e90),
        # or that is not on the 16-byte grid at all (an __ehhandler$ stub, CRT
        # assembly). Only immediates of decoded instructions count, and only
        # targets no function's decoding has reached: a label inside one is
        # part of it.
        while True:
            while True:
                starts = sorted(why)
                calls = set()
                fallthrough = set()
                for i, s in enumerate(starts):
                    limit = starts[i + 1] if i + 1 < len(starts) else te
                    f = funcdecode.decode_function(code, ts, s, limit, self.reloc_at)
                    calls.update(t for _a, t in f.calls if self.in_text(t))
                    if f.insns and i + 1 < len(starts):
                        last = f.insns[-1]
                        if last.addr + last.size == limit and not funcdecode_terminates(last):
                            fallthrough.add(limit)
                changed = False
                for t in calls:
                    if 'call' not in why.get(t, ()):
                        add(t, 'call')
                        changed = True
                for a in fallthrough:
                    if why.get(a) == {'pad'}:
                        del why[a]
                        changed = True
                if not changed:
                    break
            starts = sorted(why)
            reached, targets = set(), set()
            for i, s in enumerate(starts):
                limit = starts[i + 1] if i + 1 < len(starts) else te
                f = funcdecode.decode_function(code, ts, s, limit, self.reloc_at)
                for ins in f.insns:
                    reached.add(ins.addr)
                    if ins.size < 5 or (ins.addr + ins.size - 4) not in self.relocs:
                        continue
                    b0 = ins.bytes[0]
                    if b0 == 0x68 or 0xB8 <= b0 <= 0xBF or b0 == 0xC7:   # push imm32, mov r32/r/m32, imm32
                        v = struct.unpack_from('<I', ins.bytes, ins.size - 4)[0]
                        if self.in_text(v):
                            targets.add(v)
            new = targets - reached - set(why)
            for v in new:
                add(v, 'fptr')
            if not new:
                break

        starts = sorted(why)
        roots = {}
        for v in others - set(starts):
            i = bisect.bisect_right(starts, v) - 1
            if i >= 0:
                roots.setdefault(starts[i], []).append(v)
        for i, s in enumerate(starts):
            limit = starts[i + 1] if i + 1 < len(starts) else te
            f = self.decode(s, limit, sorted(roots.get(s, ())))
            self.functions[s] = (f.end, len(f.insns), '+'.join(sorted(why[s])), sorted(roots.get(s, ())))
        return self.functions

    # -- what each function refers to --------------------------------------
    def string_at(self, va):
        """A NUL-terminated string (ASCII or UTF-16) starting at va in a data
        section, as the bytes a literal would hold, else None."""
        s = self.pe.section_at(va)
        if s is None or s.name not in ('.rdata', '.data'):
            return None
        buf = self.pe.read(va, min(512, self.pe.base + s.end - va))
        k = buf.find(b'\0')
        if k >= 1 and all(32 <= c < 127 or c in (9, 10, 13) for c in buf[:k]):
            return buf[:k + 1]
        if len(buf) >= 4 and buf[1] == 0 and 32 <= buf[0] < 127:      # UTF-16
            for j in range(0, len(buf) - 1, 2):
                if buf[j] == 0 and buf[j + 1] == 0:
                    return buf[:j + 2] if j >= 2 else None
        return None

    def refs_of(self, start, f):
        """(insn addr, field offset, size, kind, target) for every reference a
        decoded function makes: base-relocated fields and branches/calls that
        leave it. kind: import / string / call / fptr / self / data."""
        end = f.end
        imports = self.pe.imports
        out = []
        for i in f.insns:
            for field in range(i.size - 3):
                a = i.addr + field
                if a in self.relocs:
                    v = struct.unpack_from('<I', i.bytes, field)[0]
                    if v in imports:
                        kind, tgt = 'import', imports[v]
                    elif start <= v < end:
                        kind, tgt = 'self', v - start
                    elif self.in_text(v):
                        kind, tgt = 'fptr', v
                    else:
                        st = self.string_at(v)
                        kind, tgt = ('string', st) if st is not None else ('data', v)
                    out.append((i.addr, field, 4, kind, tgt))
            # A call of the function's own entry is a call like any other (our
            # object relocates it against our symbol): FreeAnyStatList, 00626c00.
            if i.target is not None and (not (start <= i.target < end) or (i.bytes[0] == 0xE8 and i.target == start)):
                off = i.size - 4 if i.bytes[0] in (0xE8, 0xE9) or (i.bytes[0] == 0x0F and i.size >= 6) else i.size - 1
                out.append((i.addr, off, i.size - off, 'call', i.target))
        return out

    def model(self, cache=None):
        """start -> (decoded function, refs). Cached as a pickle: decoding every
        function takes minutes and the image never changes."""
        import pickle
        if cache and os.path.exists(cache):
            with open(cache, 'rb') as fh:
                return pickle.load(fh)
        starts = sorted(self.functions)
        out = {}
        for k, s in enumerate(starts):
            limit = starts[k + 1] if k + 1 < len(starts) else self.te
            f = self.decode(s, limit, self.functions[s][3])
            out[s] = (f, self.refs_of(s, f))
        if cache:
            with open(cache, 'wb') as fh:
                pickle.dump(out, fh, protocol=pickle.HIGHEST_PROTOCOL)
        return out

    def load(self, path):
        for line in open(path):
            if line.startswith('#') or line.startswith('start'):
                continue
            s, e, n, w, r = (line.rstrip('\n').split('\t') + [''])[:5]
            self.functions[int(s, 16)] = (int(e, 16), int(n), w, [int(x, 16) for x in r.split(',') if x])
        return self.functions

    def limit_of(self, start):
        starts = sorted(self.functions)
        i = bisect.bisect_right(starts, start)
        return starts[i] if i < len(starts) else self.te


def funcdecode_terminates(insn):
    m = insn.mnemonic
    return m.startswith('ret') or m in ('jmp', 'int3', 'ud2', 'hlt')


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--exe', default=os.path.join(ORACLE, 'reference', 'Game.exe'))
    ap.add_argument('--out', default=os.path.join(ORACLE, 'build', 'ref', 'functions.tsv'))
    args = ap.parse_args()
    ref = Reference(args.exe)
    fns = ref.carve()
    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, 'w') as f:
        f.write('start\tend\tinsns\twhy\troots\n')
        for s in sorted(fns):
            e, n, w, r = fns[s]
            f.write('%08x\t%08x\t%d\t%s\t%s\n' % (s, e, n, w, ','.join('%08x' % x for x in r)))
    kinds = {}
    for e, n, w, r in fns.values():
        kinds[w] = kinds.get(w, 0) + 1
    print('%d functions -> %s' % (len(fns), args.out))
    for k in sorted(kinds, key=lambda k: -kinds[k])[:12]:
        print('  %6d %s' % (kinds[k], k))


if __name__ == '__main__':
    main()
