#!/usr/bin/env python3
"""mpq_extract.py - pull one file out of a Blizzard Diablo II patch installer.

    mpq_extract.py <LODPatch_114d.exe> <member-name> <out-file>

The 1.14d patch installer (LODPatch_114d.exe) is a stub executable with an MPQ
v0 archive appended. Every member is a 24-byte Blizzard PrePatch record plus a
payload; `Game.exe` is a *whole-file* record (kind 0x01xx, source size 0), so
the 1.14d image comes out without any base install to patch against.

Standard library only, read-only, and it never executes its input. Members are
FIX_KEY-encrypted and PKWARE-DCL-imploded; the key is derived from the member
name, and the DCL decoder is a port of zlib's contrib/blast/blast.c.

Exit status is 0 only if the member was found, decoded, and written.
"""
import struct
import sys
import zlib
import bz2

# ---- MPQ crypto -----------------------------------------------------------

def _crypt_table():
    t = [0] * 0x500
    seed = 0x00100001
    for i in range(0x100):
        idx = i
        for _ in range(5):
            seed = (seed * 125 + 3) % 0x2AAAAB
            hi = (seed & 0xFFFF) << 16
            seed = (seed * 125 + 3) % 0x2AAAAB
            t[idx] = hi | (seed & 0xFFFF)
            idx += 0x100
    return t


CRYPT = _crypt_table()


def hash_string(name, kind):
    s1, s2 = 0x7FED7FED, 0xEEEEEEEE
    for ch in name.upper().replace('/', '\\').encode('latin1'):
        s1 = (CRYPT[kind * 0x100 + ch] ^ (s1 + s2)) & 0xFFFFFFFF
        s2 = (ch + s1 + s2 + (s2 << 5) + 3) & 0xFFFFFFFF
    return s1


def decrypt(data, key):
    out = bytearray(data)
    s2 = 0xEEEEEEEE
    for i in range(len(data) // 4):
        s2 = (s2 + CRYPT[0x400 + (key & 0xFF)]) & 0xFFFFFFFF
        v = struct.unpack_from('<I', data, i * 4)[0] ^ ((key + s2) & 0xFFFFFFFF)
        key = ((((~key) << 0x15) + 0x11111111) & 0xFFFFFFFF) | (key >> 0x0B)
        s2 = (v + s2 + (s2 << 5) + 3) & 0xFFFFFFFF
        struct.pack_into('<I', out, i * 4, v)
    return bytes(out)

# ---- PKWARE DCL explode (zlib contrib/blast/blast.c) -----------------------

_LITLEN = bytes([
    11, 124, 8, 7, 28, 7, 188, 13, 76, 4, 10, 8, 12, 10, 12, 10, 8, 23, 8,
    9, 7, 6, 7, 8, 7, 6, 55, 8, 23, 24, 12, 11, 7, 9, 11, 12, 6, 7, 22, 5,
    7, 24, 6, 11, 9, 6, 7, 22, 7, 11, 38, 7, 9, 8, 25, 11, 8, 11, 9, 12,
    8, 12, 5, 38, 5, 38, 5, 11, 7, 5, 6, 21, 6, 10, 53, 8, 7, 24, 10, 27,
    44, 253, 253, 253, 252, 252, 252, 13, 12, 45, 12, 45, 12, 61, 12, 45,
    44, 173])
_LENLEN = bytes([2, 35, 36, 53, 38, 23])
_DISTLEN = bytes([2, 20, 53, 230, 247, 151, 248])
_BASE = [3, 2, 4, 5, 6, 7, 8, 9, 10, 12, 16, 24, 40, 72, 136, 264]
_EXTRA = [0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8]
_MAXBITS = 13


def _construct(rep):
    length = []
    for r in rep:
        length += [r & 15] * ((r >> 4) + 1)
    count = [0] * (_MAXBITS + 1)
    for n in length:
        count[n] += 1
    offs = [0] * (_MAXBITS + 2)
    for n in range(1, _MAXBITS):
        offs[n + 1] = offs[n] + count[n]
    symbol = [0] * len(length)
    for s, n in enumerate(length):
        if n:
            symbol[offs[n]] = s
            offs[n] += 1
    return count, symbol


_LIT, _LEN, _DIST = _construct(_LITLEN), _construct(_LENLEN), _construct(_DISTLEN)


def explode(src, want):
    pos = 16  # bit position; the first two bytes are the header

    def bits(k):
        nonlocal pos
        v = 0
        for i in range(k):
            v |= ((src[(pos + i) >> 3] >> ((pos + i) & 7)) & 1) << i
        pos += k
        return v

    def decode(table):
        nonlocal pos
        count, symbol = table
        code = first = index = 0
        for n in range(1, _MAXBITS + 1):
            code |= ((src[pos >> 3] >> (pos & 7)) & 1) ^ 1  # codes are stored inverted
            pos += 1
            c = count[n]
            if code < first + c:
                return symbol[index + (code - first)]
            index += c
            first = (first + c) << 1
            code <<= 1
        raise ValueError('bad DCL Huffman code')

    lit, dictbits = src[0], src[1]
    if lit > 1 or not 4 <= dictbits <= 6:
        raise ValueError('not a PKWARE DCL stream')
    out = bytearray()
    end = len(src) * 8
    while len(out) < want and pos < end:
        if bits(1):
            sym = decode(_LEN)
            length = _BASE[sym] + bits(_EXTRA[sym])
            if length == 519:
                break
            extra = 2 if length == 2 else dictbits
            dist = (decode(_DIST) << extra) + bits(extra) + 1
            if dist > len(out):
                raise ValueError('DCL distance before start of output')
            for _ in range(length):
                out.append(out[-dist])
        else:
            out.append(decode(_LIT) if lit else bits(8))
    return bytes(out[:want])

# ---- archive --------------------------------------------------------------

F_IMPLODE, F_COMPRESS, F_ENCRYPTED, F_FIX_KEY = 0x100, 0x200, 0x10000, 0x20000
F_SINGLE_UNIT, F_EXISTS = 0x1000000, 0x80000000


def _expand(chunk, want, flags):
    if len(chunk) >= want:
        return chunk[:want]
    if flags & F_COMPRESS:
        mask, body = chunk[0], chunk[1:]
        if mask == 0x02:
            return zlib.decompress(body)
        if mask == 0x08:
            return explode(body, want)
        if mask == 0x10:
            return bz2.decompress(body)
        raise ValueError('unsupported compression mask 0x%02x' % mask)
    if flags & F_IMPLODE:
        return explode(chunk, want)
    return chunk


class Archive:
    def __init__(self, data):
        off = data.find(b'MPQ\x1a')
        while off >= 0:
            hsz, asz = struct.unpack_from('<II', data, off + 4)
            if hsz == 32 and 0 < asz <= len(data) - off:
                break
            off = data.find(b'MPQ\x1a', off + 1)
        if off < 0:
            raise ValueError('no MPQ archive found')
        self.data, self.base = data, off
        (_, _, _, _, shift, htpos, btpos, htn, btn) = struct.unpack_from('<4sIIHHIIII', data, off)
        self.sector = 512 << shift
        ht = decrypt(data[off + htpos:off + htpos + htn * 16], hash_string('(hash table)', 3))
        bt = decrypt(data[off + btpos:off + btpos + btn * 16], hash_string('(block table)', 3))
        self.hashes = [struct.unpack_from('<IIHHI', ht, i * 16) for i in range(htn)]
        self.blocks = [struct.unpack_from('<IIII', bt, i * 16) for i in range(btn)]

    def lookup(self, name):
        a, b = hash_string(name, 1), hash_string(name, 2)
        n = len(self.hashes)
        i = hash_string(name, 0) % n
        for _ in range(n):
            ha, hb, _, _, block = self.hashes[i]
            if block == 0xFFFFFFFF:
                return None
            if ha == a and hb == b and block != 0xFFFFFFFE:
                return block
            i = (i + 1) % n
        return None

    def read(self, name):
        idx = self.lookup(name)
        if idx is None:
            raise KeyError(name)
        pos, csize, fsize, flags = self.blocks[idx]
        if not flags & F_EXISTS:
            raise KeyError(name)
        key = hash_string(name.replace('/', '\\').split('\\')[-1], 3)
        if flags & F_FIX_KEY:
            key = ((key + pos) ^ fsize) & 0xFFFFFFFF
        raw = self.data[self.base + pos:self.base + pos + csize]
        enc = bool(flags & F_ENCRYPTED)
        if flags & F_SINGLE_UNIT:
            return _expand(decrypt(raw, key) if enc else raw, fsize, flags)
        nsec = (fsize + self.sector - 1) // self.sector
        if not flags & (F_IMPLODE | F_COMPRESS):
            out = bytearray()
            for s in range(nsec):
                chunk = raw[s * self.sector:(s + 1) * self.sector]
                out += decrypt(chunk, (key + s) & 0xFFFFFFFF) if enc else chunk
            return bytes(out[:fsize])
        table = raw[:(nsec + 1) * 4]
        if enc:
            table = decrypt(table, (key - 1) & 0xFFFFFFFF)
        offs = struct.unpack_from('<%dI' % (nsec + 1), table)
        out = bytearray()
        for s in range(nsec):
            chunk = raw[offs[s]:offs[s + 1]]
            if enc:
                chunk = decrypt(chunk, (key + s) & 0xFFFFFFFF)
            out += _expand(chunk, min(self.sector, fsize - s * self.sector), flags)
        return bytes(out)


def prepatch_payload(record):
    """The file a PrePatch record carries. Only whole-file records are handled:
    a delta would need the retail file it applies to."""
    if record[:2] == b'MZ':
        return record  # BNUpdate.exe and friends ship unwrapped
    hsz, kind, _crc, src_size, tgt_size = struct.unpack_from('<HHIII', record, 0)
    if hsz != 0x18:
        raise ValueError('not a PrePatch record')
    if kind >> 8 != 1 or src_size != 0:
        raise ValueError('member is a delta (kind 0x%04x), not a whole file' % kind)
    return record[hsz:hsz + tgt_size]


def main(argv):
    if len(argv) != 4:
        sys.stderr.write(__doc__)
        return 2
    archive = Archive(open(argv[1], 'rb').read())
    body = prepatch_payload(archive.read(argv[2]))
    with open(argv[3], 'wb') as f:
        f.write(body)
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv))
