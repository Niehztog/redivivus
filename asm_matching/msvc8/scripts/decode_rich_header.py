#!/usr/bin/env python3
"""decode_rich_header.py - list the toolchain records a PE's Rich header carries.

    decode_rich_header.py <image.exe|dll>

Every object the MSVC linker consumes carries an @comp.id (product id << 16 |
build number) of the tool that produced it; the linker counts them into the
"Rich" header in the DOS stub. It is the authoritative fingerprint of the
toolchain that built an image -- see ../README.md "Toolchain identification".

The build number is only the third component of the tool version, so it
cannot tell service packs apart that share one: VS2005 RTM is 14.00.50727.42
and VS2005 SP1 is 14.00.50727.762, and both stamp 50727. That question needs
codegen A/B evidence, not this script.

Product-id names are saferwall/pe's prodIDtoStrMap (MIT), copied verbatim.
"""
import datetime
import struct
import sys

PRODID = {
    0x0000: 'Unknown', 0x0001: 'Import0', 0x0002: 'Linker510', 0x0003: 'Cvtomf510',
    0x0004: 'Linker600', 0x0005: 'Cvtomf600', 0x0006: 'Cvtres500', 0x0007: 'Utc11_Basic',
    0x0008: 'Utc11_C', 0x0009: 'Utc12_Basic', 0x000a: 'Utc12_C', 0x000b: 'Utc12_CPP',
    0x000c: 'AliasObj60', 0x000d: 'VisualBasic60', 0x000e: 'Masm613', 0x000f: 'Masm710',
    0x0010: 'Linker511', 0x0011: 'Cvtomf511', 0x0012: 'Masm614', 0x0013: 'Linker512',
    0x0014: 'Cvtomf512', 0x0015: 'Utc12_C_Std', 0x0016: 'Utc12_CPP_Std',
    0x0017: 'Utc12_C_Book', 0x0018: 'Utc12_CPP_Book', 0x0019: 'Implib700', 0x001a: 'Cvtomf700',
    0x001b: 'Utc13_Basic', 0x001c: 'Utc13_C', 0x001d: 'Utc13_CPP', 0x001e: 'Linker610',
    0x001f: 'Cvtomf610', 0x0020: 'Linker601', 0x0021: 'Cvtomf601', 0x0022: 'Utc12_1_Basic',
    0x0023: 'Utc12_1_C', 0x0024: 'Utc12_1_CPP', 0x0025: 'Linker620', 0x0026: 'Cvtomf620',
    0x0027: 'AliasObj70', 0x0028: 'Linker621', 0x0029: 'Cvtomf621', 0x002a: 'Masm615',
    0x002b: 'Utc13_LTCG_C', 0x002c: 'Utc13_LTCG_CPP', 0x002d: 'Masm620', 0x002e: 'ILAsm100',
    0x002f: 'Utc12_2_Basic', 0x0030: 'Utc12_2_C', 0x0031: 'Utc12_2_CPP',
    0x0032: 'Utc12_2_C_Std', 0x0033: 'Utc12_2_CPP_Std', 0x0034: 'Utc12_2_C_Book',
    0x0035: 'Utc12_2_CPP_Book', 0x0036: 'Implib622', 0x0037: 'Cvtomf622', 0x0038: 'Cvtres501',
    0x0039: 'Utc13_C_Std', 0x003a: 'Utc13_CPP_Std', 0x003b: 'Cvtpgd1300', 0x003c: 'Linker622',
    0x003d: 'Linker700', 0x003e: 'Export622', 0x003f: 'Export700', 0x0040: 'Masm700',
    0x0041: 'Utc13_POGO_I_C', 0x0042: 'Utc13_POGO_I_CPP', 0x0043: 'Utc13_POGO_O_C',
    0x0044: 'Utc13_POGO_O_CPP', 0x0045: 'Cvtres700', 0x0046: 'Cvtres710p',
    0x0047: 'Linker710p', 0x0048: 'Cvtomf710p', 0x0049: 'Export710p', 0x004a: 'Implib710p',
    0x004b: 'Masm710p', 0x004c: 'Utc1310p_C', 0x004d: 'Utc1310p_CPP', 0x004e: 'Utc1310p_C_Std',
    0x004f: 'Utc1310p_CPP_Std', 0x0050: 'Utc1310p_LTCG_C', 0x0051: 'Utc1310p_LTCG_CPP',
    0x0052: 'Utc1310p_POGO_I_C', 0x0053: 'Utc1310p_POGO_I_CPP', 0x0054: 'Utc1310p_POGO_O_C',
    0x0055: 'Utc1310p_POGO_O_CPP', 0x0056: 'Linker624', 0x0057: 'Cvtomf624',
    0x0058: 'Export624', 0x0059: 'Implib624', 0x005a: 'Linker710', 0x005b: 'Cvtomf710',
    0x005c: 'Export710', 0x005d: 'Implib710', 0x005e: 'Cvtres710', 0x005f: 'Utc1310_C',
    0x0060: 'Utc1310_CPP', 0x0061: 'Utc1310_C_Std', 0x0062: 'Utc1310_CPP_Std',
    0x0063: 'Utc1310_LTCG_C', 0x0064: 'Utc1310_LTCG_CPP', 0x0065: 'Utc1310_POGO_I_C',
    0x0066: 'Utc1310_POGO_I_CPP', 0x0067: 'Utc1310_POGO_O_C', 0x0068: 'Utc1310_POGO_O_CPP',
    0x0069: 'AliasObj710', 0x006a: 'AliasObj710p', 0x006b: 'Cvtpgd1310', 0x006c: 'Cvtpgd1310p',
    0x006d: 'Utc1400_C', 0x006e: 'Utc1400_CPP', 0x006f: 'Utc1400_C_Std',
    0x0070: 'Utc1400_CPP_Std', 0x0071: 'Utc1400_LTCG_C', 0x0072: 'Utc1400_LTCG_CPP',
    0x0073: 'Utc1400_POGO_I_C', 0x0074: 'Utc1400_POGO_I_CPP', 0x0075: 'Utc1400_POGO_O_C',
    0x0076: 'Utc1400_POGO_O_CPP', 0x0077: 'Cvtpgd1400', 0x0078: 'Linker800',
    0x0079: 'Cvtomf800', 0x007a: 'Export800', 0x007b: 'Implib800', 0x007c: 'Cvtres800',
    0x007d: 'Masm800', 0x007e: 'AliasObj800', 0x007f: 'PhoenixPrerelease',
    0x0080: 'Utc1400_CVTCIL_C', 0x0081: 'Utc1400_CVTCIL_CPP', 0x0082: 'Utc1400_LTCG_MSIL',
    0x0083: 'Utc1500_C', 0x0084: 'Utc1500_CPP', 0x0085: 'Utc1500_C_Std',
    0x0086: 'Utc1500_CPP_Std', 0x0087: 'Utc1500_CVTCIL_C', 0x0088: 'Utc1500_CVTCIL_CPP',
    0x0089: 'Utc1500_LTCG_C', 0x008a: 'Utc1500_LTCG_CPP', 0x008b: 'Utc1500_LTCG_MSIL',
    0x008c: 'Utc1500_POGO_I_C', 0x008d: 'Utc1500_POGO_I_CPP', 0x008e: 'Utc1500_POGO_O_C',
    0x008f: 'Utc1500_POGO_O_CPP', 0x0090: 'Cvtpgd1500', 0x0091: 'Linker900',
    0x0092: 'Export900', 0x0093: 'Implib900', 0x0094: 'Cvtres900', 0x0095: 'Masm900',
    0x0096: 'AliasObj900', 0x0097: 'Resource', 0x0098: 'AliasObj1000', 0x0099: 'Cvtpgd1600',
    0x009a: 'Cvtres1000', 0x009b: 'Export1000', 0x009c: 'Implib1000', 0x009d: 'Linker1000',
    0x009e: 'Masm1000', 0x009f: 'Phx1600_C', 0x00a0: 'Phx1600_CPP', 0x00a1: 'Phx1600_CVTCIL_C',
    0x00a2: 'Phx1600_CVTCIL_CPP', 0x00a3: 'Phx1600_LTCG_C', 0x00a4: 'Phx1600_LTCG_CPP',
    0x00a5: 'Phx1600_LTCG_MSIL', 0x00a6: 'Phx1600_POGO_I_C', 0x00a7: 'Phx1600_POGO_I_CPP',
    0x00a8: 'Phx1600_POGO_O_C', 0x00a9: 'Phx1600_POGO_O_CPP', 0x00aa: 'Utc1600_C',
    0x00ab: 'Utc1600_CPP', 0x00ac: 'Utc1600_CVTCIL_C', 0x00ad: 'Utc1600_CVTCIL_CPP',
    0x00ae: 'Utc1600_LTCG_C', 0x00af: 'Utc1600_LTCG_CPP', 0x00b0: 'Utc1600_LTCG_MSIL',
    0x00b1: 'Utc1600_POGO_I_C', 0x00b2: 'Utc1600_POGO_I_CPP', 0x00b3: 'Utc1600_POGO_O_C',
    0x00b4: 'Utc1600_POGO_O_CPP', 0x00b5: 'AliasObj1010', 0x00b6: 'Cvtpgd1610',
    0x00b7: 'Cvtres1010', 0x00b8: 'Export1010', 0x00b9: 'Implib1010', 0x00ba: 'Linker1010',
    0x00bb: 'Masm1010', 0x00bc: 'Utc1610_C', 0x00bd: 'Utc1610_CPP', 0x00be: 'Utc1610_CVTCIL_C',
    0x00bf: 'Utc1610_CVTCIL_CPP', 0x00c0: 'Utc1610_LTCG_C', 0x00c1: 'Utc1610_LTCG_CPP',
    0x00c2: 'Utc1610_LTCG_MSIL', 0x00c3: 'Utc1610_POGO_I_C', 0x00c4: 'Utc1610_POGO_I_CPP',
    0x00c5: 'Utc1610_POGO_O_C', 0x00c6: 'Utc1610_POGO_O_CPP', 0x00c7: 'AliasObj1100',
    0x00c8: 'Cvtpgd1700', 0x00c9: 'Cvtres1100', 0x00ca: 'Export1100', 0x00cb: 'Implib1100',
    0x00cc: 'Linker1100', 0x00cd: 'Masm1100', 0x00ce: 'Utc1700_C', 0x00cf: 'Utc1700_CPP',
    0x00d0: 'Utc1700_CVTCIL_C', 0x00d1: 'Utc1700_CVTCIL_CPP', 0x00d2: 'Utc1700_LTCG_C',
    0x00d3: 'Utc1700_LTCG_CPP', 0x00d4: 'Utc1700_LTCG_MSIL', 0x00d5: 'Utc1700_POGO_I_C',
    0x00d6: 'Utc1700_POGO_I_CPP', 0x00d7: 'Utc1700_POGO_O_C', 0x00d8: 'Utc1700_POGO_O_CPP',
    0x00d9: 'AliasObj1200', 0x00da: 'Cvtpgd1800', 0x00db: 'Cvtres1200', 0x00dc: 'Export1200',
    0x00dd: 'Implib1200', 0x00de: 'Linker1200', 0x00df: 'Masm1200', 0x00e0: 'Utc1800_C',
    0x00e1: 'Utc1800_CPP', 0x00e2: 'Utc1800_CVTCIL_C', 0x00e3: 'Utc1800_CVTCIL_CPP',
    0x00e4: 'Utc1800_LTCG_C', 0x00e5: 'Utc1800_LTCG_CPP', 0x00e6: 'Utc1800_LTCG_MSIL',
    0x00e7: 'Utc1800_POGO_I_C', 0x00e8: 'Utc1800_POGO_I_CPP', 0x00e9: 'Utc1800_POGO_O_C',
    0x00ea: 'Utc1800_POGO_O_CPP', 0x00eb: 'AliasObj1210', 0x00ec: 'Cvtpgd1810',
    0x00ed: 'Cvtres1210', 0x00ee: 'Export1210', 0x00ef: 'Implib1210', 0x00f0: 'Linker1210',
    0x00f1: 'Masm1210', 0x00f2: 'Utc1810_C', 0x00f3: 'Utc1810_CPP', 0x00f4: 'Utc1810_CVTCIL_C',
    0x00f5: 'Utc1810_CVTCIL_CPP', 0x00f6: 'Utc1810_LTCG_C', 0x00f7: 'Utc1810_LTCG_CPP',
    0x00f8: 'Utc1810_LTCG_MSIL', 0x00f9: 'Utc1810_POGO_I_C', 0x00fa: 'Utc1810_POGO_I_CPP',
    0x00fb: 'Utc1810_POGO_O_C', 0x00fc: 'Utc1810_POGO_O_CPP', 0x00fd: 'AliasObj1400',
    0x00fe: 'Cvtpgd1900', 0x00ff: 'Cvtres1400', 0x0100: 'Export1400', 0x0101: 'Implib1400',
    0x0102: 'Linker1400', 0x0103: 'Masm1400', 0x0104: 'Utc1900_C', 0x0105: 'Utc1900_CPP',
    0x0106: 'Utc1900_CVTCIL_C', 0x0107: 'Utc1900_CVTCIL_CPP', 0x0108: 'Utc1900_LTCG_C',
    0x0109: 'Utc1900_LTCG_CPP', 0x010a: 'Utc1900_LTCG_MSIL', 0x010b: 'Utc1900_POGO_I_C',
    0x010c: 'Utc1900_POGO_I_CPP', 0x010d: 'Utc1900_POGO_O_C', 0x010e: 'Utc1900_POGO_O_CPP',
}

# Build numbers -> release, for the families this project meets. A build shared
# by several releases says so; do not resolve it here.
BUILD = {
    7299: 'VC6 tools (MASM 6.13)',
    8168: 'VC6 RTM',
    8447: 'VC6 SP3 (c2.dll back end)',
    9044: 'VC6 SP5/SP6 era',
    9466: 'VS2002 (7.0) RTM',
    3077: 'VS2003 (7.1) RTM',
    4035: 'VC 7.1 as shipped in the Windows Server 2003 SP1 SDK/DDK',
    6030: 'VS2003 (7.1) SP1',
    50727: 'VS2005 (8.0): RTM .42 and SP1 .762 both stamp 50727',
    21022: 'VS2008 (9.0) RTM',
    30729: 'VS2008 (9.0) SP1',
    30319: 'VS2010 (10.0) RTM',
    40219: 'VS2010 (10.0) SP1',
}


def rich_entries(data):
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    stub = data[0x40:pe]
    ri = stub.find(b'Rich')
    if ri < 0:
        return None, []
    key = struct.unpack_from('<I', stub, ri + 4)[0]
    di = stub.find(struct.pack('<I', 0x536E6144 ^ key))  # 'DanS'
    if di < 0:
        return key, []
    out = []
    for i in range(di + 16, ri, 8):
        cid = struct.unpack_from('<I', stub, i)[0] ^ key
        cnt = struct.unpack_from('<I', stub, i + 4)[0] ^ key
        out.append((cid >> 16, cid & 0xffff, cnt))
    return key, out


def main(path):
    data = open(path, 'rb').read()
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    if data[pe:pe + 4] != b'PE\0\0':
        sys.exit('not a PE image: %s' % path)
    stamp = struct.unpack_from('<I', data, pe + 8)[0]
    opt = pe + 24
    print('%s' % path)
    print('  TimeDateStamp  0x%08x  %s UTC' % (
        stamp, datetime.datetime.fromtimestamp(stamp, datetime.timezone.utc).strftime('%Y-%m-%d %H:%M:%S')))
    print('  LinkerVersion  %d.%d' % (data[opt + 2], data[opt + 3]))
    key, entries = rich_entries(data)
    if not entries:
        print('  no Rich header')
        return
    print('  Rich header    %d records, XOR key 0x%08x' % (len(entries), key))
    print('  %6s  %-22s %6s %6s  %s' % ('prodid', 'tool', 'build', 'count', 'release'))
    for pid, build, count in entries:
        print('  0x%04x  %-22s %6d %6d  %s' % (pid, PRODID.get(pid, '?'), build, count, BUILD.get(build, '')))


if __name__ == '__main__':
    if len(sys.argv) != 2:
        sys.exit(__doc__)
    main(sys.argv[1])
