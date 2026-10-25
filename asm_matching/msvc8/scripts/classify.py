#!/usr/bin/env python3
"""classify.py - why does each mapped function differ? Tags, counted.

    classify.py [--out build/classes.tsv] [--tag TAG] [--single]

For every mapped function that is not a MATCH, compares the two instruction
streams for the differences that have one cause in the source, and tags it:

  cleanup      `ret N` differs: calling convention or parameter count
  regargs      a different set of registers is live on entry (live_in: a
               data-flow over the function's control flow): arguments arrive
               in other registers (a lost __fastcall, a static function the
               original passed arguments to in EAX/ESI)
  frame        the stack frame (`sub esp, N`) differs: locals differ
  saved        other callee-saved registers are saved and restored (usually a
               consequence of the code using more or fewer registers)
  calls        a different number of calls, or different callees
  inverted     a conditional jump is the inverse of the original's at the same
               place: an if/else in the other order
  signedness   a signed jump where the original has an unsigned one, or back:
               a type's signedness
  regalloc     same instructions, registers differ only
  displacement same instructions, memory displacements differ only (field
               offsets, stack slots)
  immediate    same instructions, constants differ only
  shape        none of the above explains it

A function can carry several tags. The summary counts each tag, and how many
functions carry it alone - those are one fix away. --tag lists the functions
with a tag, most similar first.
"""
import argparse
import collections
import difflib
import os
import re
import sys

import capstone
from capstone import x86 as cx

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import audit           # noqa: E402
import compare         # noqa: E402
import ours as ourslib  # noqa: E402
from oracle_config import BUILD, ORACLE  # noqa: E402

_MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_MD.detail = True
GPR = {'eax', 'ecx', 'edx', 'ebx', 'esi', 'edi', 'ebp'}
SUB = {'al': 'eax', 'ah': 'eax', 'ax': 'eax', 'cl': 'ecx', 'ch': 'ecx', 'cx': 'ecx', 'dl': 'edx', 'dh': 'edx',
       'dx': 'edx', 'bl': 'ebx', 'bh': 'ebx', 'bx': 'ebx', 'si': 'esi', 'di': 'edi', 'bp': 'ebp'}
INVERSE = {'je': 'jne', 'jne': 'je', 'jl': 'jge', 'jge': 'jl', 'jle': 'jg', 'jg': 'jle', 'jb': 'jae', 'jae': 'jb',
           'jbe': 'ja', 'ja': 'jbe', 'js': 'jns', 'jns': 'js', 'jp': 'jnp', 'jnp': 'jp', 'jo': 'jno', 'jno': 'jo'}
SIGNED = {('jl', 'jb'), ('jge', 'jae'), ('jle', 'jbe'), ('jg', 'ja'), ('jb', 'jl'), ('jae', 'jge'), ('jbe', 'jle'),
          ('ja', 'jg'), ('jl', 'ja'), ('jg', 'jb'), ('jle', 'jae'), ('jge', 'jbe'), ('jb', 'jg'), ('ja', 'jl'),
          ('jae', 'jle'), ('jbe', 'jge')}


def _reg(name):
    name = SUB.get(name, name)
    return name if name in GPR else None


CALLER_SAVED = {'eax', 'ecx', 'edx'}
_JCC = {'jo', 'jno', 'jb', 'jae', 'je', 'jne', 'jbe', 'ja', 'js', 'jns', 'jp', 'jnp',
        'jl', 'jge', 'jle', 'jg', 'jecxz', 'jcxz', 'loop', 'loope', 'loopne'}
_UD = {}


def _use_def(i):
    """(registers read, registers written) by one instruction, for liveness:
    a call reads nothing and clobbers EAX/ECX/EDX; saving a callee-saved
    register (push ebx) is no read; `xor r, r`, `or r, -1`, `and r, 0` and
    kin read nothing; `cpuid` reads EAX only; padding no-ops (`lea r, [r]`)
    read and write nothing."""
    key = i.bytes
    if key in _UD:
        return _UD[key]
    ins = next(_MD.disasm(i.bytes, 0, 1), None)
    if ins is None:
        out = (frozenset(), frozenset())
    elif ins.mnemonic == 'call':
        out = (frozenset(), frozenset(CALLER_SAVED))
    elif ins.mnemonic.startswith('ret'):
        out = (frozenset(), frozenset())
    elif ins.mnemonic == 'cpuid':
        # ECX selects a subleaf only for the leaves that have them; the
        # tree's `cpuid` sites set EAX alone (DetectCpuVendor, 0040e250).
        out = (frozenset({'eax'}), frozenset({'eax', 'ebx', 'ecx', 'edx'}))
    elif ins.mnemonic == 'push' and ins.operands and ins.operands[0].type == cx.X86_OP_REG and \
            ins.reg_name(ins.operands[0].reg) in ('ebx', 'esi', 'edi', 'ebp'):
        out = (frozenset(), frozenset())
    else:
        try:
            rd, wr = ins.regs_access()
        except capstone.CsError:
            rd, wr = (), ()
        reads = {_reg(ins.reg_name(r)) for r in rd} - {None}
        writes = {_reg(ins.reg_name(r)) for r in wr} - {None}
        ops = ins.op_str.split(', ')
        if ins.mnemonic in ('xor', 'sub', 'sbb') and len(ops) == 2 and ops[0] == ops[1]:
            reads = set()
        elif len(ops) == 2 and ops[0] in GPR and ((ins.mnemonic == 'or' and ops[1] == '0xffffffff') or
                                                (ins.mnemonic == 'and' and ops[1] == '0')):
            # `or ecx, -1` (the inline strlen's count) and `and r, 0` set the
            # register whatever it held (SStrCopy, 004135d0: `or ebx, -1`).
            reads = reads - {ops[0]}
        elif (ins.mnemonic == 'mov' and len(ops) == 2 and ops[0] == ops[1]) or \
                (ins.mnemonic == 'lea' and len(ops) == 2 and ops[1] in ('[%s]' % ops[0], '[%s + 0]' % ops[0])):
            reads, writes = set(), set()      # a no-op of padding: `lea ebx, [ebx]`, `mov edi, edi`
        out = (frozenset(reads), frozenset(writes))
    _UD[key] = out
    return out


def _slot_pushes(insns):
    """Indices of the `push ecx` that reserve stack slots right after the
    frame is set up: VC8 makes a 4-byte local that way instead of `sub esp,
    4`, and the value pushed is whatever ECX held - no argument. A push whose
    slot is read before it is written (a `this` kept on the stack) is not
    one of them. Of the original's functions whose only extra live-in
    register was ECX through such a push, none reads the slot first."""
    def text(i):
        return '%s %s' % (i.mnemonic, i.op_str)
    if len(insns) < 3 or text(insns[0]) != 'push ebp' or text(insns[1]) != 'mov ebp, esp':
        return set()
    out, k = set(), 2
    while k < len(insns) and text(insns[k]) == 'push ecx':
        slot = '[ebp - %d]' % (4 * (k - 1))
        for i in insns[k + 1:]:
            if slot in i.op_str:
                ops = i.op_str.split(', ')
                if i.mnemonic != 'lea' and not (i.mnemonic == 'mov' and ops[0].endswith(slot)):
                    return out                # read first: the push carries a value
                break
        out.add(k)
        k += 1
    return out


def live_in(decoded):
    """Registers live at the function's entry: those it receives arguments
    in (beyond the stack). A backward data-flow over the instructions'
    control flow - branches, switch tables, fall-through - so a register
    first read after a call, in a loop, or in a block laid out after the one
    that writes it is judged by the paths, not by address order
    (SFILE_FindChunk, 0041b210: ESI, EBX, EDI). A `push ecx` that only
    reserves a stack slot reads nothing (_slot_pushes; DEBUG_CrashDumpRequestThreadProc,
    004027c0, receives no ECX). `decoded` is a funcdecode.DecodedFunction, or
    its instruction list (no switch tables)."""
    insns = getattr(decoded, 'insns', decoded)
    if not insns:
        return set()
    slots = _slot_pushes(insns)
    tables = {t: entries for t, entries in getattr(decoded, 'tables', ())}
    index = {i.addr: k for k, i in enumerate(insns)}
    succ = []
    for k, i in enumerate(insns):
        m = i.mnemonic
        nxt = index.get(i.addr + i.size)
        if m.startswith('ret') or m in ('int3', 'hlt', 'ud2'):
            out = []
        elif m == 'jmp':
            if i.target is not None:
                out = [index[i.target]] if i.target in index else []
            else:
                out = [index[t] for t in tables.get(i.table, ()) if t in index]
        elif m in _JCC:
            out = ([index[i.target]] if i.target in index else []) + ([nxt] if nxt is not None else [])
        else:
            out = [nxt] if nxt is not None else []
        succ.append(out)
    ud = [(frozenset(), frozenset()) if k in slots else _use_def(i) for k, i in enumerate(insns)]
    live = [frozenset()] * len(insns)
    changed = True
    while changed:
        changed = False
        for k in range(len(insns) - 1, -1, -1):
            after = frozenset().union(*(live[j] for j in succ[k])) if succ[k] else frozenset()
            use, df = ud[k]
            new = use | (after - df)
            if new != live[k]:
                live[k] = new
                changed = True
    return set(live[0]) - {'ebp', 'esp'}


_NUM = re.compile(r'-?(?:0x[0-9a-f]+|\d+)$')
_LEA = re.compile(r'\[(e[a-z]{2})(?: ([+-]) (0x[0-9a-f]+|\d+))?\]$')
# Calls that keep every register: __security_check_cookie, the /GS epilogue's.
NOCLOBBER = {0x00681a48}


def _const_step(i, st):
    """`st` (register -> constant, or None for unknown) after instruction `i`."""
    ins = next(_MD.disasm(i.bytes, i.addr, 1), None)
    st = dict(st)
    if ins is None:
        return {r: None for r in st}
    m = ins.mnemonic
    o = ins.op_str.split(', ') if ins.op_str else []
    if m == 'call':
        if getattr(i, 'target', None) not in NOCLOBBER:
            for r in CALLER_SAVED:
                st[r] = None
        return st
    known = None
    if len(o) == 2 and o[0] in st:
        a, b = o
        if m == 'mov' and _NUM.match(b):
            known = int(b, 0)
        elif m == 'mov' and b in st:
            known = st[b]
        elif m in ('xor', 'sub') and a == b:
            known = 0
        elif m == 'or' and b in ('0xffffffff', '-1'):
            known = -1
        elif m in ('add', 'sub') and st[a] is not None and (_NUM.match(b) or b in st):
            k = int(b, 0) if _NUM.match(b) else st[b]
            if k is not None:
                known = st[a] + k if m == 'add' else st[a] - k
        elif m == 'lea':
            x = _LEA.match(b)
            if x and x.group(1) in st and st[x.group(1)] is not None:
                k = int(x.group(3), 0) if x.group(3) else 0
                known = st[x.group(1)] + (k if x.group(2) != '-' else -k)
        if known is not None:
            st[a] = known & 0xffffffff
            return st
    try:
        _rd, wr = ins.regs_access()
        written = {_reg(ins.reg_name(r)) for r in wr}
    except capstone.CsError:
        written = set(st)
    for r in written:
        if r in st:
            st[r] = None
    return st


def _const_step_al(i, st):
    """_const_step, with AL followed as well: VC8 returns a bool in AL
    (`xor al, al`, `mov al, 1`), whatever the upper bits of EAX hold."""
    new = _const_step(i, st)
    ins = next(_MD.disasm(i.bytes, i.addr, 1), None)
    al = st.get('al')
    o = ins.op_str.split(', ') if ins is not None and ins.op_str else []
    m = ins.mnemonic if ins is not None else ''
    if m == 'mov' and len(o) == 2 and o[0] in ('al', 'ax') and _NUM.match(o[1]):
        al = int(o[1], 0) & 0xff
    elif m in ('xor', 'sub') and len(o) == 2 and o[0] == o[1] and o[0] in ('al', 'ax'):
        al = 0
    elif new.get('eax') is not None and (new['eax'] != st.get('eax') or al is None):
        al = new['eax'] & 0xff
    elif m == 'call':
        if getattr(i, 'target', None) not in NOCLOBBER:
            al = None
    elif ins is not None:
        try:
            _rd, wr = ins.regs_access()
            if any(ins.reg_name(r) in ('al', 'ax', 'eax') for r in wr):
                al = None
        except capstone.CsError:
            al = None
    new['al'] = al
    return new


_FLAGS_KEPT = {'mov', 'lea', 'push', 'pop', 'nop', 'movzx', 'movsx'}


def _tested_zero(insns, k):
    """The register a `test r, r` compared with zero for the branch insns[k]:
    found walking back over instructions that leave the flags alone, none of
    which may write r."""
    written = set()
    for j in range(k - 1, max(-1, k - 24), -1):
        ins = next(_MD.disasm(insns[j].bytes, insns[j].addr, 1), None)
        if ins is None:
            return None
        o = ins.op_str.split(', ') if ins.op_str else []
        if ins.mnemonic == 'test' and len(o) == 2 and o[0] == o[1] and _reg(o[0]) == o[0]:
            return None if o[0] in written else o[0]
        if ins.mnemonic not in _FLAGS_KEPT:
            return None
        try:
            _rd, wr = ins.regs_access()
            written |= {_reg(ins.reg_name(r)) for r in wr}
        except capstone.CsError:
            return None
    return None


def eax_at_returns(decoded, reg='eax'):
    """[(address of a ret, the constant EAX holds there, or None)]: a forward
    constant propagation over the function's control flow - every register,
    moves, `xor r, r`, `lea r, [s + k]`, calls clobbering EAX/ECX/EDX - with
    the zero a `test r, r` branch proves on each edge. VC8 materialises a
    returned constant from whatever register already holds it (`lea eax,
    [esi + 1]` where ESI is known zero), so EAX at the ret, not the last
    `mov eax, K`, is what the function returns (SEvtRegisterHandler,
    00426420: `mov eax, ebx` with EBX = 1). reg='al': AL instead, a bool's
    return register."""
    insns = getattr(decoded, 'insns', decoded)
    if not insns:
        return []
    tables = {t: entries for t, entries in getattr(decoded, 'tables', ())}
    index = {i.addr: k for k, i in enumerate(insns)}
    regs = ('eax', 'ecx', 'edx', 'ebx', 'esi', 'edi', 'al')
    step = _const_step_al if reg == 'al' else _const_step
    state = [None] * len(insns)
    state[0] = {r: None for r in regs}
    work = [0]
    while work:
        k = work.pop()
        i = insns[k]
        out = step(i, state[k])
        out.setdefault('al', None)
        m = i.mnemonic
        nxt = index.get(i.addr + i.size)
        if m.startswith('ret') or m in ('int3', 'hlt', 'ud2'):
            edges = []
        elif m == 'jmp':
            if i.target is not None:
                edges = [(index[i.target], out)] if i.target in index else []
            else:
                edges = [(index[t], out) for t in tables.get(i.table, ()) if t in index]
        elif m in _JCC:
            taken, fall = out, out
            z = _tested_zero(insns, k) if m in ('je', 'jne') else None
            if z:
                if m == 'je':
                    taken = dict(out, **{z: 0})
                else:
                    fall = dict(out, **{z: 0})
            edges = ([(index[i.target], taken)] if i.target in index else []) + \
                    ([(nxt, fall)] if nxt is not None else [])
        else:
            edges = [(nxt, out)] if nxt is not None else []
        for j, st in edges:
            old = state[j]
            new = dict(st) if old is None else {r: (old[r] if old[r] == st[r] else None) for r in regs}
            if new != old:
                state[j] = new
                work.append(j)
    return [(i.addr, state[k][reg]) for k, i in enumerate(insns)
            if i.mnemonic.startswith('ret') and state[k] is not None]


def ret_imm(raw_insns):
    vals = set()
    for i in raw_insns:
        if i.mnemonic.startswith('ret'):
            vals.add(int(i.op_str, 16) if i.op_str else 0)
    return vals


def frame_size(raw_insns):
    for i in raw_insns[:8]:
        if i.mnemonic == 'sub' and i.op_str.startswith('esp, '):
            return int(i.op_str[5:], 16)
    return 0


def saved(raw_insns):
    """The callee-saved registers the function restores before returning:
    the ones it saves, wherever in the prologue the save was scheduled."""
    return tuple(sorted({i.op_str for i in raw_insns if i.mnemonic == 'pop' and i.op_str in ('ebx', 'esi', 'edi')}))


OPERAND = re.compile(r'0x[0-9a-f]+|\b\d+\b')


def classify(f, s, model, syms):
    ours = compare.our_view(f, syms)
    ref = compare.ref_view(s, model[s])
    ro = f.decoded.insns
    rr = model[s][0].insns
    tags = []
    if ret_imm(ro) != ret_imm(rr):
        tags.append('cleanup')
    if live_in(f.decoded) != live_in(model[s][0]):
        tags.append('regargs')
    if frame_size(ro) != frame_size(rr):
        tags.append('frame')
    if saved(ro) != saved(rr):
        tags.append('saved')
    cal_o = [t for i in ours for t in i.tokens if t[0] in ('fn', 'fn?', 'import')]
    cal_r = [t for i in ref for t in i.tokens if t[0] in ('fn', 'import')]
    if len(cal_o) != len(cal_r) or any(a != b for a, b in zip(cal_o, cal_r) if a[0] != 'fn?'):
        tags.append('calls')
    sm = difflib.SequenceMatcher(None, [i.mnemonic for i in ours], [i.mnemonic for i in ref], autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        if op == 'replace' and i2 - i1 == j2 - j1:
            for x, y in zip(ours[i1:i2], ref[j1:j2]):
                if INVERSE.get(x.mnemonic) == y.mnemonic and 'inverted' not in tags:
                    tags.append('inverted')
                if (x.mnemonic, y.mnemonic) in SIGNED and 'signedness' not in tags:
                    tags.append('signedness')
    if len(ours) == len(ref) and all(x.mnemonic == y.mnemonic for x, y in zip(ours, ref)):
        kinds = set()
        for x, y in zip(ours, ref):
            if x.key == y.key:
                continue
            xo, yo = OPERAND.sub('N', x.key), OPERAND.sub('N', y.key)
            if xo != yo:
                kinds.add('regalloc')
            elif '[' in x.key and OPERAND.findall(x.key[x.key.find('['):]) != OPERAND.findall(y.key[y.key.find('['):]):
                kinds.add('displacement')
            else:
                kinds.add('immediate')
        tags.extend(sorted(kinds))
    if not tags:
        tags.append('shape')
    return tags, len(ours) - len(ref)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--out', default=os.path.join(BUILD, 'classes.tsv'))
    ap.add_argument('--tag', help='list the functions with this tag, most similar first')
    ap.add_argument('--single', action='store_true', help='with --tag: only functions carrying it alone')
    args = ap.parse_args()
    rows = audit.load_funcmap(os.path.join(ORACLE, 'evidence', 'funcmap.tsv'))
    status = {}
    for line in open(os.path.join(ORACLE, 'evidence', 'audit.tsv')):
        p = line.rstrip('\n').split('\t')
        if p[0] != 'start':
            status[int(p[0], 16)] = (p[9], float(p[8]))
    _ref, model = audit.load_context()
    fns = {f.key: f for f in ourslib.load_all(os.path.join(BUILD, 'obj'))}
    syms = audit.sym_map(rows)
    out = []
    for s, _e, name, tu, sym, _m, _d in rows:
        st, sim = status.get(s, ('?', 0.0))
        if st in ('MATCH', 'QUARANTINE', 'MISSING', '?'):
            continue
        f = fns.get(tu + '|' + sym)
        if f is None:
            continue
        tags, delta = classify(f, s, model, syms)
        out.append((s, name, tu, st, sim, delta, tags))
    with open(args.out, 'w') as fh:
        fh.write('start\tname\ttu\tstatus\tsimilarity\tdelta\ttags\n')
        for s, name, tu, st, sim, delta, tags in out:
            fh.write('%08x\t%s\t%s\t%s\t%.3f\t%d\t%s\n' % (s, name, tu, st, sim, delta, ','.join(tags)))
    if args.tag:
        sel = [r for r in out if args.tag in r[6] and (not args.single or r[6] == [args.tag])]
        for s, name, tu, st, sim, delta, tags in sorted(sel, key=lambda r: -r[4]):
            print('%08x %.3f %-16s %-60s %s' % (s, sim, st, name[:60], ','.join(tags)))
        return
    allc, alone = collections.Counter(), collections.Counter()
    for r in out:
        for t in r[6]:
            allc[t] += 1
        if len(r[6]) == 1:
            alone[r[6][0]] += 1
    print('%d mapped functions that do not match' % len(out))
    print('%-14s %7s %7s' % ('tag', 'with it', 'alone'))
    for t, n in allc.most_common():
        print('%-14s %7d %7d' % (t, n, alone[t]))


if __name__ == '__main__':
    main()
