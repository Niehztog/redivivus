"""coffobj.py - read MSVC i386 COFF objects: sections, symbols, relocations.
Standard library only.

Our side of every comparison is a COFF object straight out of cl.exe, never a
linked image: each relocation names the symbol it binds, so a call compares as
"calls X" and a global load as "loads Y" rather than as an opaque address.
"""
import struct

# i386 relocation types
DIR32, DIR32NB, SECTION, SECREL, TOKEN, SECREL7, REL32 = 0x06, 0x07, 0x0A, 0x0B, 0x0C, 0x0D, 0x14
RELOC_SIZE = {DIR32: 4, DIR32NB: 4, SECREL: 4, TOKEN: 4, REL32: 4, SECTION: 2, SECREL7: 1}

SCN_CNT_CODE = 0x20
SCN_LNK_COMDAT = 0x1000
SCN_MEM_EXECUTE = 0x20000000

C_EXTERNAL, C_STATIC, C_LABEL, C_FUNCTION, C_FILE = 2, 3, 6, 101, 103


class Reloc:
    __slots__ = ('offset', 'symbol', 'type')

    def __init__(self, offset, symbol, rtype):
        self.offset, self.symbol, self.type = offset, symbol, rtype


class Symbol:
    __slots__ = ('index', 'name', 'value', 'section', 'type', 'storage', 'aux')

    def __init__(self, index, name, value, section, stype, storage, aux):
        self.index, self.name, self.value, self.section = index, name, value, section
        self.type, self.storage, self.aux = stype, storage, aux

    @property
    def is_function(self):
        return (self.type >> 4) & 0xf == 2  # DTYPE_FUNCTION in the derived-type nibble


class Section:
    __slots__ = ('number', 'name', 'data', 'size', 'flags', 'relocs', 'comdat', 'comdat_assoc')

    def __init__(self, number, name, data, size, flags, relocs):
        self.number, self.name, self.data, self.size, self.flags, self.relocs = number, name, data, size, flags, relocs
        self.comdat = None        # COMDAT selection kind, when SCN_LNK_COMDAT
        self.comdat_assoc = 0     # associated section number (selection 5)

    @property
    def is_code(self):
        return bool(self.flags & SCN_CNT_CODE)


class CoffObject:
    def __init__(self, data, name='<obj>'):
        self.name = name
        d = self.data = data
        machine, nsec, _stamp, symptr, nsym, optsize, _chars = struct.unpack_from('<HHIIIHH', d, 0)
        if machine == 0 and nsec == 0xffff:
            raise ValueError('%s: /bigobj objects are not supported' % name)
        if machine != 0x14c:
            raise ValueError('%s: not an i386 COFF object (machine 0x%x)' % (name, machine))
        strtab_off = symptr + 18 * nsym
        if nsym and strtab_off + 4 > len(d):
            raise ValueError('%s: truncated symbol table' % name)
        strtab_len = struct.unpack_from('<I', d, strtab_off)[0] if nsym else 0
        if strtab_off + strtab_len > len(d):
            raise ValueError('%s: truncated string table' % name)
        self._strtab = d[strtab_off:strtab_off + strtab_len] if nsym else b''

        self.symbols = []           # by symbol-table index (aux slots hold None)
        i = 0
        while i < nsym:
            o = symptr + 18 * i
            raw = d[o:o + 8]
            if raw[:4] == b'\0\0\0\0':
                nm = self._string(struct.unpack_from('<I', raw, 4)[0])
            else:
                nm = raw.rstrip(b'\0').decode('latin1')
            value, secnum, stype, storage, naux = struct.unpack_from('<IhHBB', d, o + 8)
            aux = [d[symptr + 18 * (i + 1 + k):symptr + 18 * (i + 2 + k)] for k in range(naux)]
            self.symbols.append(Symbol(i, nm, value, secnum, stype, storage, aux))
            self.symbols.extend([None] * naux)
            i += 1 + naux

        self.sections = [None]      # 1-based like COFF
        for n in range(nsec):
            o = 20 + optsize + 40 * n
            raw = d[o:o + 8].rstrip(b'\0').decode('latin1')
            name = self._string(int(raw[1:])) if raw.startswith('/') else raw
            _vs, _va, size, ptr, relptr, _lnptr, nrel, _nln, flags = struct.unpack_from('<IIIIIIHHI', d, o + 8)
            if ptr and ptr + size > len(d) or relptr + 10 * nrel > len(d):
                raise ValueError('%s: truncated section %s' % (name, raw))
            body = d[ptr:ptr + size] if ptr else b'\0' * size
            relocs = []
            for k in range(nrel):
                roff, rsym, rtype = struct.unpack_from('<IIH', d, relptr + 10 * k)
                relocs.append(Reloc(roff, rsym, rtype))
            self.sections.append(Section(n + 1, name, body, size, flags, relocs))

        # COMDAT selection lives in the section symbol's aux record.
        for s in self.symbols:
            if s is None or s.storage != C_STATIC or s.section <= 0 or not s.aux:
                continue
            sec = self.sections[s.section]
            if sec.flags & SCN_LNK_COMDAT and s.name == sec.name and s.value == 0:
                _len, _nrel, _nln, _chk, assoc, sel = struct.unpack_from('<IHHIHB', s.aux[0], 0)
                sec.comdat, sec.comdat_assoc = sel, assoc

    def _string(self, off):
        end = self._strtab.index(b'\0', off)
        return self._strtab[off:end].decode('latin1')

    def symbol(self, index):
        return self.symbols[index]

    def functions(self):
        """(symbol, section, start, end) for every function defined here.
        The end is the next function symbol in the same section, or the
        section end; trailing padding and jump tables are the caller's job."""
        by_sec = {}
        for s in self.symbols:
            if s is None or s.section <= 0 or not s.is_function:
                continue
            if s.storage not in (C_EXTERNAL, C_STATIC):
                continue
            by_sec.setdefault(s.section, []).append(s)
        out = []
        for secnum, syms in by_sec.items():
            sec = self.sections[secnum]
            syms.sort(key=lambda s: s.value)
            for k, s in enumerate(syms):
                end = syms[k + 1].value if k + 1 < len(syms) else sec.size
                out.append((s, sec, s.value, end))
        out.sort(key=lambda t: (t[1].number, t[2]))
        return out

    def comp_id(self):
        """The @comp.id stamp (product id << 16 | build) of the compiler."""
        for s in self.symbols:
            if s is not None and s.name == '@comp.id':
                return s.value
        return None


def read_archive(data):
    """Members of a COFF import/static library as (name, bytes). Long names
    resolve through the '//' member; the two linker members are skipped."""
    if data[:8] != b'!<arch>\n':
        raise ValueError('not an archive')
    p = 8
    longnames = b''
    out = []
    while p + 60 <= len(data):
        hdr = data[p:p + 60]
        name = hdr[:16].decode('latin1').rstrip()
        size = int(hdr[48:58].decode('latin1').strip())
        body = data[p + 60:p + 60 + size]
        if name == '//':
            longnames = body
        elif name == '/':
            pass
        elif name.startswith('/') and name[1:].isdigit():
            off = int(name[1:])
            end = longnames.find(b'\0', off)
            out.append((longnames[off:end if end >= 0 else None].decode('latin1').rstrip('/'), body))
        else:
            out.append((name.rstrip('/'), body))
        p += 60 + size + (size & 1)
    return out
