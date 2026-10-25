"""compare.py - compare one compiled function with its original, instruction by
instruction.

Both sides are reduced to the same view: per instruction, the bytes with every
reference field zeroed, and per reference a token naming what it refers to.

    ('fn', 0x00401090)    a call/jump/pointer to a function, by ORIGINAL address
                          (ours resolved through the funcmap; unmapped -> ('fn?', name))
    ('import', 'GetTickCount')
    ('str', b'...')       a string literal, by content
    ('self', 0x1c)        into the function itself (switch tables, handlers)
    ('data', ...)         a global: our symbol vs the original address. Not
                          comparable one by one; counted, and checked for
                          consistency across the whole image by audit.py.

A function MATCHES when the instruction streams have the same length, the
masked bytes are identical, and every comparable reference agrees. That is
stricter than masking alone: a call to the wrong function is a mismatch even
when the bytes around it are equal.

Status classes (shared with the sibling projects' audit TSVs):
  MATCH             as above
  REF_DIFF          bytes identical, some comparable reference differs
  INSN_MATCH        same instruction sequence, some bytes differ (registers,
                    displacements, encodings)
  INSN_COUNT_MATCH  same number of instructions, different instructions
  OUR+N / OUR-N     we have N more / fewer instructions
"""
import difflib
import struct

import capstone

_MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
SENTINEL = 0x7EA00000


class NInsn:
    __slots__ = ('addr', 'masked', 'mnemonic', 'text', 'key', 'tokens', 'line')

    def __init__(self, addr, masked, mnemonic, text, key, tokens, line=None):
        self.addr, self.masked, self.mnemonic, self.text, self.tokens = addr, masked, mnemonic, text, tokens
        self.key = key   # text with function and global references neutralised: what similarity compares
        self.line = line  # our side: the source line it came from (/Z7), else None


def _render(raw, addr, fields):
    """Disassemble `raw` with each reference field replaced by a unique
    sentinel, so the printed operand can be swapped for the reference's name.
    fields: (field offset, size, token, is_branch). Returns (display text,
    neutral key): the key prints every function as FN and every global as DATA,
    so two listings that differ only in what similarity cannot judge agree."""
    b = bytearray(raw)
    subs = []
    for k, (off, size, tok, branch) in enumerate(fields):
        if size != 4 or off + 4 > len(raw):
            continue
        val = SENTINEL + 16 * k
        if branch:
            rel = (val - (addr + len(raw))) & 0xffffffff
            struct.pack_into('<I', b, off, rel)
        else:
            struct.pack_into('<I', b, off, val)
        subs.append((val, tok))
    text = None
    for ins in _MD.disasm(bytes(b), addr, 1):
        text = ('%s %s' % (ins.mnemonic, ins.op_str)).strip()
    if text is None:
        text = '(bad)'
    key = text
    for val, tok in subs:
        text = text.replace('0x%x' % val, _label(tok))
        key = key.replace('0x%x' % val, _neutral(tok))
    return text, key


def _neutral(tok):
    if tok[0] in ('fn', 'fn?'):
        return 'FN'
    if tok[0] == 'data':
        return 'DATA'
    return _label(tok)


def _label(tok):
    kind, v = tok
    if kind == 'fn':
        return 'fn_%08x' % v
    if kind == 'fn?':
        return '<%s>' % v
    if kind == 'import':
        return '__imp_' + v
    if kind == 'str':
        s = v[:-1] if v.endswith(b'\0') else v
        txt = s.decode('latin1')
        return '"%s"' % (txt if len(txt) <= 28 else txt[:25] + '...')
    if kind == 'self':
        return '$+0x%x' % v
    if kind == 'straddle':
        return '<straddle %s>' % _label(v)
    if kind == 'data':
        if isinstance(v, tuple):
            sym, add = v
            return sym if not add else '%s%+#x' % (sym, add)
        return 'g_%08x' % v
    return '?%s' % kind


def _addend(f, off):
    """The value a DIR32 field holds in our object: the offset from its symbol."""
    for i in f.decoded.insns:
        if i.addr <= off < i.addr + i.size:
            v = struct.unpack_from('<i', i.bytes, off - i.addr)[0]
            return v
    return 0


def our_view(f, sym_to_start):
    """f: ours.OurFunc. sym_to_start: our symbol -> original start (funcmap)."""
    by_off = {}
    for off, kind, tgt in f.refs:
        if kind in ('call', 'fptr'):
            s = sym_to_start.get(tgt)
            tok = ('fn', s) if s is not None else ('fn?', tgt)
        elif kind == 'string':
            tok = ('str', tgt)
        elif kind == 'import':
            tok = ('import', tgt)
        elif kind == 'self':
            tok = ('self', tgt)
        else:
            tok = ('data', (tgt, _addend(f, off)))
        by_off[off] = (kind, tok)
    out = []
    for i in f.decoded.insns:
        fields, toks = [], []
        for off in range(i.addr - 3, i.addr + i.size):
            if off in by_off:
                kind, tok = by_off[off]
                if off < i.addr or off + 4 > i.addr + i.size:
                    # A relocation straddling an instruction boundary: these
                    # bytes are not code (an unrecognised table decoded as
                    # instructions). Mask what overlaps, and say so.
                    tok = ('straddle', tok)
                fields.append((max(off, i.addr) - i.addr, min(4, i.addr + i.size - max(off, i.addr)), tok,
                               kind == 'call'))
                toks.append(tok)
        masked = bytearray(i.bytes)
        for off, size, _l, _b in fields:
            masked[off:off + size] = b'\0' * size
        text, key = _render(i.bytes, i.addr, fields)
        at = f.line_at(i.addr) if hasattr(f, 'line_at') else None
        out.append(NInsn(i.addr, bytes(masked), i.mnemonic, text, key, toks, at[1] if at else None))
    return out


def ref_view(start, model_entry):
    """model_entry: (decoded function, refs) from refimage.Reference.model()."""
    dec, refs = model_entry
    per_insn = {}
    for a, off, size, kind, tgt in refs:
        if kind in ('call', 'fptr'):
            tok = ('fn', tgt)
        elif kind == 'string':
            tok = ('str', tgt)
        elif kind == 'import':
            tok = ('import', tgt.split('!', 1)[1])
        elif kind == 'self':
            tok = ('self', tgt)
        else:
            tok = ('data', tgt)
        per_insn.setdefault(a, []).append((off, size, tok, kind == 'call'))
    out = []
    for i in dec.insns:
        fields = sorted(per_insn.get(i.addr, ()))
        masked = bytearray(i.bytes)
        for off, size, _t, _b in fields:
            masked[off:off + size] = b'\0' * size
        # Rendered at its offset in the function, as our side is, so an internal
        # jump reads the same on both sides.
        text, key = _render(i.bytes, i.addr - start, fields)
        out.append(NInsn(i.addr - start, bytes(masked), i.mnemonic, text, key, [t for _o, _s, t, _b in fields]))
    return out


class Result:
    __slots__ = ('status', 'ref_insns', 'our_insns', 'byte_diffs', 'similarity', 'ref_diffs', 'unverified',
                 'notes', 'wiring')

    def __init__(self):
        self.byte_diffs = 0
        self.ref_diffs = 0
        self.unverified = 0
        self.notes = []
        self.wiring = []     # (our data symbol, original address it implies) at aligned positions


def _tokens_agree(a, b):
    """True/False when comparable, None when not (data, or an unmapped callee)."""
    if a[0] in ('data', 'fn?', 'straddle') or b[0] in ('data', 'fn?', 'straddle'):
        return None
    return a == b


def compare(ours, ref):
    r = Result()
    r.ref_insns, r.our_insns = len(ref), len(ours)
    a = [i.key for i in ours]
    b = [i.key for i in ref]
    r.similarity = difflib.SequenceMatcher(None, a, b, autojunk=False).ratio() if a or b else 1.0
    if len(ours) != len(ref):
        d = len(ours) - len(ref)
        r.status = 'OUR%+d' % d
        return r
    same_bytes = True
    same_mn = True
    for x, y in zip(ours, ref):
        if x.mnemonic != y.mnemonic:
            same_mn = False
        if x.masked != y.masked:
            same_bytes = False
            if len(x.masked) == len(y.masked):
                r.byte_diffs += sum(1 for p, q in zip(x.masked, y.masked) if p != q)
            else:
                r.byte_diffs += max(len(x.masked), len(y.masked))
        for ta, tb in zip(x.tokens, y.tokens):
            if ta[0] == 'data' and tb[0] == 'data' and isinstance(ta[1], tuple) and x.mnemonic == y.mnemonic:
                r.wiring.append((ta[1][0], (tb[1] - ta[1][1]) & 0xffffffff))
            ok = _tokens_agree(ta, tb)
            if ok is None:
                r.unverified += 1
            elif not ok:
                r.ref_diffs += 1
        if len(x.tokens) != len(y.tokens):
            r.ref_diffs += abs(len(x.tokens) - len(y.tokens))
    if same_bytes:
        r.status = 'MATCH' if r.ref_diffs == 0 else 'REF_DIFF'
    elif same_mn:
        r.status = 'INSN_MATCH'
    else:
        r.status = 'INSN_COUNT_MATCH'
    return r


def side_by_side(ours, ref, width=66):
    """Lines of a diff of the two listings, aligned on the neutral keys.
    Marker: ' ' same bytes and every comparable reference agrees; '!' same
    bytes, a reference names something else; '~' same instruction, other
    bytes; '|' different instructions; '<' only ours; '>' only the original's."""
    a = [i.key for i in ours]
    b = [i.key for i in ref]
    out = []
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        n = max(i2 - i1, j2 - j1)
        for k in range(n):
            x = ours[i1 + k] if i1 + k < i2 else None
            y = ref[j1 + k] if j1 + k < j2 else None
            if x is None:
                mark = '>'
            elif y is None:
                mark = '<'
            elif x.masked == y.masked:
                agree = [_tokens_agree(p, q) for p, q in zip(x.tokens, y.tokens)]
                mark = '!' if False in agree or len(x.tokens) != len(y.tokens) else ' '
            elif op == 'equal':
                mark = '~'
            else:
                mark = '|'
            left = ('%5x %5s %s' % (x.addr, x.line or '', x.text)) if x else ''
            right = '%5x  %s' % (y.addr, y.text) if y else ''
            out.append('%-*s %s %s' % (width, left[:width], mark, right))
    return out


def differing_lines(ours, ref):
    """Source lines (ours) of the instructions that differ, in order."""
    a = [i.key for i in ours]
    b = [i.key for i in ref]
    lines = []
    sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
    for op, i1, i2, j1, j2 in sm.get_opcodes():
        for k in range(i1, i2):
            x = ours[k]
            y = ref[j1 + (k - i1)] if op == 'equal' else None
            if op != 'equal' or x.masked != y.masked:
                if x.line and x.line not in lines:
                    lines.append(x.line)
        if op in ('insert',) and i1 > 0 and ours[i1 - 1].line and ours[i1 - 1].line not in lines:
            lines.append(ours[i1 - 1].line)
    return lines
