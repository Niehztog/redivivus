"""peimage.py - the parts of a PE32 image the oracle reads: sections, base
relocations, imports and exports. Standard library only.

Base relocations are what make the reference side exact: every absolute
address the original code embeds sits at a relocated field, so a byte compare
can mask exactly those four bytes instead of guessing from operand values
(Game.exe's image base is 0x400000, so addresses are indistinguishable from
ordinary constants by value).
"""
import struct


class Section:
    __slots__ = ('name', 'va', 'vsize', 'raw', 'rawsize', 'flags')

    def __init__(self, name, va, vsize, raw, rawsize, flags):
        self.name, self.va, self.vsize, self.raw, self.rawsize, self.flags = name, va, vsize, raw, rawsize, flags

    @property
    def end(self):
        return self.va + max(self.vsize, self.rawsize)


class PEImage:
    def __init__(self, path):
        self.path = path
        d = self.data = open(path, 'rb').read()
        pe = struct.unpack_from('<I', d, 0x3c)[0]
        if d[pe:pe + 4] != b'PE\0\0':
            raise ValueError('%s: not a PE image' % path)
        nsec = struct.unpack_from('<H', d, pe + 6)[0]
        self.timestamp = struct.unpack_from('<I', d, pe + 8)[0]
        optsize = struct.unpack_from('<H', d, pe + 20)[0]
        opt = pe + 24
        if struct.unpack_from('<H', d, opt)[0] != 0x10b:
            raise ValueError('%s: not PE32' % path)
        self.linker = (d[opt + 2], d[opt + 3])
        self.entry_rva = struct.unpack_from('<I', d, opt + 16)[0]
        self.base = struct.unpack_from('<I', d, opt + 28)[0]
        ndirs = struct.unpack_from('<I', d, opt + 92)[0]
        self.dirs = [struct.unpack_from('<II', d, opt + 96 + 8 * i) for i in range(min(ndirs, 16))]
        self.sections = []
        sh = opt + optsize
        for i in range(nsec):
            o = sh + 40 * i
            name = d[o:o + 8].rstrip(b'\0').decode('latin1')
            vsize, va, rawsize, raw = struct.unpack_from('<IIII', d, o + 8)
            flags = struct.unpack_from('<I', d, o + 36)[0]
            self.sections.append(Section(name, va, vsize, raw, rawsize, flags))
        self._relocs = None
        self._imports = None
        self._exports = None

    # -- addressing ---------------------------------------------------------
    def section(self, name):
        for s in self.sections:
            if s.name == name:
                return s
        raise KeyError(name)

    def section_at(self, va):
        rva = va - self.base
        for s in self.sections:
            if s.va <= rva < s.end:
                return s
        return None

    def offset(self, va):
        s = self.section_at(va)
        if s is None:
            raise ValueError('VA 0x%08x outside the image' % va)
        rva = va - self.base
        if rva - s.va >= s.rawsize:
            return None  # zero-fill tail of the section
        return s.raw + rva - s.va

    def read(self, va, n):
        out = bytearray()
        while n > 0:
            s = self.section_at(va)
            if s is None:
                raise ValueError('VA 0x%08x outside the image' % va)
            rva = va - self.base
            avail = s.va + max(s.vsize, s.rawsize) - rva
            take = min(n, avail)
            inraw = max(0, min(take, s.rawsize - (rva - s.va)))
            if inraw:
                o = s.raw + rva - s.va
                out += self.data[o:o + inraw]
            out += b'\0' * (take - inraw)
            va += take
            n -= take
        return bytes(out)

    def u32(self, va):
        return struct.unpack('<I', self.read(va, 4))[0]

    def cstring(self, va, limit=4096):
        s = self.section_at(va)
        if s is None:
            return None
        buf = self.read(va, min(limit, self.base + s.end - va))
        i = buf.find(b'\0')
        return buf if i < 0 else buf[:i]

    @property
    def text(self):
        return self.section('.text')

    # -- tables -------------------------------------------------------------
    @property
    def relocs(self):
        """VAs of every HIGHLOW (32-bit absolute) base relocation."""
        if self._relocs is None:
            rva, size = self.dirs[5]
            out = set()
            p = self.offset(self.base + rva)
            end = p + size
            d = self.data
            while p < end:
                page, block = struct.unpack_from('<II', d, p)
                if block < 8:
                    break
                for i in range((block - 8) // 2):
                    e = struct.unpack_from('<H', d, p + 8 + 2 * i)[0]
                    if e >> 12 == 3:
                        out.add(self.base + page + (e & 0xfff))
                    elif e >> 12 != 0:
                        raise ValueError('unexpected base relocation type %d' % (e >> 12))
                p += block
            self._relocs = out
        return self._relocs

    @property
    def imports(self):
        """IAT slot VA -> 'dll!name' (or 'dll!#ordinal')."""
        if self._imports is None:
            out = {}
            rva, size = self.dirs[1]
            if rva:
                p = self.base + rva
                while True:
                    olt, _, _, name_rva, iat = struct.unpack('<IIIII', self.read(p, 20))
                    if not name_rva:
                        break
                    dll = self.cstring(self.base + name_rva).decode('latin1')
                    lookup = olt or iat
                    i = 0
                    while True:
                        ent = self.u32(self.base + lookup + 4 * i)
                        if not ent:
                            break
                        if ent & 0x80000000:
                            nm = '#%d' % (ent & 0xffff)
                        else:
                            nm = self.cstring(self.base + ent + 2).decode('latin1')
                        out[self.base + iat + 4 * i] = '%s!%s' % (dll, nm)
                        i += 1
                    p += 20
            self._imports = out
        return self._imports

    @property
    def exports(self):
        """name -> VA for named exports."""
        if self._exports is None:
            out = {}
            rva, size = self.dirs[0]
            if rva:
                hdr = self.read(self.base + rva, 40)
                ordbase, nfun, nnames, afun, anames, aords = struct.unpack_from('<IIIIII', hdr, 16)
                for i in range(nnames):
                    nm = self.cstring(self.base + self.u32(self.base + anames + 4 * i)).decode('latin1')
                    o = struct.unpack('<H', self.read(self.base + aords + 2 * i, 2))[0]
                    out[nm] = self.base + self.u32(self.base + afun + 4 * o)
            self._exports = out
        return self._exports
