# `support/` - the hand-owned half of the tree

Files here are **option 3** in [`docs/regen-workflow.md`](../../../docs/regen-workflow.md): new
files the generator never emits. `rsync --delete` cannot reach them and a merge cannot conflict in
them, so they carry no debt and no `Retire-When` trailer. They exist because the generator *cannot
know* them, not because it gets them wrong.

|File|What it supplies|
|-|-|
|`d2_hand.h`|Declarations for entities the extraction cannot supply - the DirectDraw import thunks, and the `compiler::` functions dropped by `excludePatterns`.|
|`d2_crt_support.cpp`|Definitions for the CRT and intrinsic symbols the link needs. Documented below.|
|`d2_crash.cpp`|The crash report: on a fatal exception, a symbolised stack written next to the exe. See below.|

## If it crashes

The game writes `d2crash-YYYYMMDD-HHMMSS.txt` next to `d2.exe` (or in `%TEMP%` when that folder
is not writable). **Send that file.** It names the build, the exception, the registers, the stack
as function and `file:line`, and every loaded module (wrappers such as cnc-ddraw, glide or an
overlay show up there). The names come from the DWARF in your own `d2.exe`, read with the vendored
libbacktrace (`thirdparty/libbacktrace`), so the report is readable without your exe - keep the
build unstripped. One report is written per crash; the game's own error handling runs after it.
A Fog halt (`ERROR_UnrecoverableInternalError_Halt`, the engine's assert) writes the same report,
headed `HALT line=<n> at <addr>`, with the halting thread's stack; it is called from the halt's
body in `Fog/Src/ErrorManager.cpp`, the one generated-file line this feature needs.

`d2_crt_support.cpp` is compiled by the ad-hoc measure build (which globs `*.cpp`) and is listed
explicitly in the hand-owned `CMakeLists.txt`.

## The measurement

Reproduced on `source/modified` `49f0e04fb`, all 503 TUs compiled with

```sh
i686-w64-mingw32-g++ -std=c++17 -c -w -fms-extensions \
  -include d2_platform.h -include support/d2_hand.h @incdirs.rsp -o <obj> <src>
i686-w64-mingw32-ar rcs libd2.a *.o
i686-w64-mingw32-g++ -o test.exe main.cpp -Wl,--whole-archive libd2.a -Wl,--no-whole-archive \
  -lgdi32 -luser32 -lkernel32 -ladvapi32 -lwinmm -lws2_32 -lole32 -loleaut32 -luuid -lcomctl32
```

against a `main(){return 0;}`.

|Unique undefined symbols|Count|
|-|-|
|before `d2_crt_support.o`|**153**|
|after|**138**|

15 resolved, 0 newly introduced. The CRT/intrinsic lane owns 26 of the original 153; 15 are shimmed,
11 are deliberately left undefined and prescribed as Ghidra work below.

## Standing rule this file is written under

> A tree that fails to link beats a binary that runs wrong.

Every symbol below is either backed by disassembly / decompilation of a named address in
`Diablo2Lod /windows/lod/1.14d/Game.exe` (Ghidra v791), or left undefined with the reason written
down. Nothing is stubbed to make a count fall.

---

# Shimmed

## The five MSVC x87 `__CI*` intrinsics

`_CIcos`, `_CIsin`, `_CIlog`, `_CIlog10`, `_CIpow` take their operands **in the x87 stack
registers** and return in `ST(0)`. They are not ABI-compatible with `cos`/`sin`/`log`/`pow`, and
aliasing the symbols to those would link and read garbage.

That trap does not apply here, and the reason is the load-bearing part: **Ghidra v791 already models
the operands as parameters with `ST0`/`ST1` custom storage**, with the evidence recorded in each
function's plate comment. The decompiler therefore threads the values through, and the emitted call
sites are ordinary C calls carrying the operand as a `long double` argument -
`D2Common/Drlg/Environment.cpp:83` is `fFloatResult = CRT_CICos(fVar1);`, not an argument-less call.
The definitions in `d2_crt_support.cpp` match the prototypes in `d2_platform.h` that those call
sites were compiled against, so GCC generates the calls and the x87 stack never enters it. mingw's
`long double` is the same 80-bit x87 type as Ghidra's `float10`.

|Symbol|Address|Ghidra signature|Body evidence|Shim|
|-|-|-|-|-|
|`CRT_CICos`|`006886c0`|`float10 CRT_CICos(float10 fValue @ST0)`|`FCOS` at `0068872d`, with `FLD 2pi`/`FXCH`/`FPREM1` range reduction at `00688752..00688766`|`cosl`|
|`CRT_CISin`|`00688590`|`float10 CRT_CISin(float10 @ST0)`|sibling of the above at the same SSE2-dispatch prologue|`sinl`|
|`CRT_CILog`|`00687ac0`|`float10 CRT_CILog(float10 @ST0)`|`FLDLN2`/`FXCH`/`FYL2X` at `00687b3f` = `ln(2)*log2(x)` = **natural** log|`logl`|
|`CRT_CILog10`|`00687ea0`|`float10 CRT_CILog10(float10 @ST0)`|the `FLDLG2` form of the same sequence|`log10l`|
|`CRT_CIPow`|`00687c10`|`float10 CRT_CIPow(float10 fBase @ST1, float10 fExponent @ST0)`|`FXCH`/`FSTP qword[ESP]`/`FST qword[ESP+8]` at `00687c4e..00687c53` spills two live operands; `FYL2X`+`F2XM1` body at `00687c6d`|`powl(base, exponent)`|

The `FXCH` is what fixes `CRT_CIPow`'s operand order - base is `ST(1)`, exponent is `ST(0)`. The
shim's argument order follows Ghidra's parameter ordinals, which encode exactly that.

Call-site ABI confirmed directly at `0061bc26` (`DRLGENV_UpdateLightIntensity`): the operand is
computed into `ST(0)` by `FMUL double[006e7d30]` / `FST double[EBP-0xc]`, `CALL 006886c0` follows
with **no `PUSH`**, and `FCHS`/`FSTP float[ESI+0x1c]` consumes the result from `ST(0)`.

## Ordinary CRT with a genuine equivalent

Three of these are declared in the generated `d2_platform.h` with the emitter's unknown-signature
fallback `T NAME(...)`. A variadic declaration with no named parameter cannot be defined portably,
and re-declaring the name concretely in the same TU collides with the forced include. Both problems
are avoided by giving the real definition a private C++ name plus an **asm label** carrying the exact
object-file symbol (`__asm__("_CRT_Floor")` - i386 PE user-label prefix). On i386 `cdecl` a
fixed-arity definition is call-compatible with a variadic declaration: every argument goes on the
stack and the caller cleans up.

### `CRT_Floor` -> `floor` @ `00683080`

Ghidra: `float10 CRT_Floor(double fParam)` `__cdecl`, argument at `Stack[0x4]`. The x87 fallback
jumps to `0068ea71`, which Ghidra's FID matches as `__floor_default` (Visual Studio 2005 Release,
single match); the SSE2 path at `006830c0` loads `qword[ESP+4]` and does exponent-field extraction
(`PSRLQ` by `0x34`, `PSUBD` against a bias constant) - the standard branch-free floor. It is the one
member of this family that is *not* an `__CI*` intrinsic: normal stack argument. Both call sites,
`Fog/Source/SFile.cpp:614-615` inside the Julian-day-number computation, discard the result.

### `CRT_Strchr` -> `strchr` @ `00687740`

Ghidra: `char *CRT_Strchr(char *pszStr, char cChar)` `__cdecl`. The decompiled body is the
word-at-a-time `strchr` verbatim - the 4-byte alignment prologue, the `0x7efefeff` / `0x81010100`
zero-byte test, the broadcast of `cChar` into all four lanes, the four per-byte compares returning
`pszStr+0..3`. `char` promotes to `int` through the variadic declaration, which is exactly `strchr`'s
own second parameter type, so the shim is `char* (char*, int)`.

### `CRT_ClearFP` - **not `_clearfp`** @ `006987d8`

`_clearfp` takes no arguments. This takes two, and is 22 bytes:

```
006987d8  MOV EAX, dword ptr [ESP + 0x8]
006987dc  AND EAX, 0x7ff00000
006987e1  CMP EAX, 0x7ff00000
006987e6  JZ  006987e9
006987e8  RET                                <- ZF clear
006987e9  MOV EAX, dword ptr [ESP + 0x8]
006987ed  RET                                <- ZF set
```

The two arguments are the low and high halves of one `double` at `[ESP+4]`, and **EAX is the same
value on both paths**. The branch exists only to leave `ZF` set when the exponent field is all ones,
i.e. Inf/NaN. Its x87-CRT callers consume the flag, not EAX: `CRT_CICos` does `FST double[ESP]` /
`CALL 006987d8` at `006886fe`, and `__cos_common` at `0068871d` then branches on the `ZF` it left.

C has no spelling for a flag return. Every emitted call site discards the result -
`D2Sound/Src/D2SoundSmp.cpp:1046`, `D2CMP/Draw.cpp:1164`, `D2CMP/SRC/FastCmp.cpp:1591`,
`D2Client/Utils.cpp:43`, `:54`, `:101` - so returning the high dword is exactly faithful to
everything this tree can observe. The name is wrong and should be retired by a naming lane; it is
kept because it is what the call sites spell.

### `compiler::_fprintf` @ `00684c94` - no shim

The body locks the `FILE`, calls `__stbuf`, runs the printf output core, then `__ftbuf` and the
unlock: MSVC's `fprintf`. Ghidra types it `int (FILE*, char*, ...)` (v1049), so every call site
carries its format arguments and the generated `#define _fprintf fprintf` binds `<cstdio>`
directly. It used to be named `CRT_Fgetc`, typed fixed-arity, and shimmed here; that shim is gone.

### `CRT_Vsprintf_L` -> `vfprintf` @ `00685637`

`__cdecl`, one statement:
`compiler::CRT_Output_L(compiler::CRT_Output_Printf, pFile, nParam, 0, dwParam)` - the
locale-explicit `printf` core, with a **null locale**, a format pointer and an argument list. So the
`_l` variant degenerates to plain `vfprintf(FILE*, const char*, va_list)`. Parameter 2 is typed
`int` by Ghidra but is the format pointer; `Fog/File.cpp:300` passes `(int)Format` and a `va_list`
built from `(uint8_t*)&Format + 4`, which agrees.

### `CRT_LocalTime_S` -> `_localtime64_s` @ `006856e9`

`errno_t CRT_LocalTime_S(tm *pTm, uint *pnParam)` `__cdecl`. The body is `_localtime64_s`:
`memset(pTm, 0xff, 0x24)`, the `__time64_t` range check against `0x93406fff`, `___tzset`,
`__get_dstbias`, `__isindst`, and `__gmtime64_s(pTm, (__time64_t *)pnParam)`. The second parameter is
therefore a pointer to a **64-bit** time, not a 32-bit one - which the call site confirms:
`Fog/File.cpp:85-86` declares `__time64_t tTime = __time64(nullptr)` and casts its address to
`uint32_t*`. The shim copies 8 bytes out and calls mingw's `_localtime64_s`.

### `CRT_Encode_Secure_Pointer` - **it is `_set_se_translator`** @ `00684af3`

Not `_encode_pointer`. The body is:

```
ptd = __getptd();  old = ptd->_translator;
ptd = __getptd();  ptd->_translator = pParam;  return old;
```

`_ptiddata::_translator` is the per-thread slot `_set_se_translator` writes, and the one emitted
call site is `Fog/Debug.cpp:2731`,
`CRT_Encode_Secure_Pointer((void*)HandleExceptionWithStackDump)`, inside Fog's crash-handler
installer, immediately after `InitializeCriticalSection`.

mingw-GCC has no MSVC structured-exception translator, so the shim reproduces the get / set /
return-previous semantics and the per-thread storage (`thread_local`) exactly, and **nothing else**.
The recorded function is never invoked, because there is no MSVC SEH layer to invoke it.

### `CRT_ReturnValue` - **it is ATL's `AtlThrow`** @ `006b1a30`

Not a return-value helper. `__stdcall`, does not return, one statement:
`std::exception::__CxxThrowException_8(&dwParam, &DAT_007020b4)`.

Chasing the `ThrowInfo` at `007020b4`:

```
007020b4  00000000 00000000 00000000 007020c4   attributes, pmfnUnwind, pForwardCompat, pCatchableTypeArray
007020c4  00000001 007020cc                     nCatchableTypes = 1
007020cc  00000000 0074c0a8 ... 00000004        pType, sizeOrOffset = 4
0074c0a8  ".?AVCAtlException@ATL@@"             TypeDescriptor
```

So it throws a 4-byte `ATL::CAtlException` carrying the HRESULT. The only call site,
`D2Direct3D/Renderer/Direct3D.cpp:596` - `CRT_ReturnValue(0x80004005)` (`E_FAIL`) guarded by a null
test - is the `ATLENSURE` shape.

mingw has no ATL. The shim declares the type to the shape the type descriptor gives (a 4-byte object
holding the HRESULT, named `ATL::CAtlException`) and throws it. Nothing in this tree catches it,
because the MSVC EH frames are not emitted, so in practice it terminates - which matches the
binary's own "does not return".

## SEH and /GS

### `__purecall` @ `006877fe` - abort, and that is faithful

FID single match `__purecall`, Visual Studio 2005 Release. The body fetches the unexpected handler,
calls it if non-null, then `__set_abort_behavior(0,1)` and `_abort()`. `abort()` is the faithful
tail, not a placeholder. Referenced only as data - twelve vftable slots at
`globals.D2Client.cpp:36280-36291` and seven at `globals.cpp:45235` - so it runs only when a pure
virtual is actually called, which is when the binary aborts too.

### `__except_handler4` @ `00684f50` - **a stub that dies, stated plainly**

FID single match `__except_handler4`, Visual Studio 2005 Release, 406 bytes, `__cdecl(int*, PVOID,
undefined4)`. This is the MSVC SEH frame handler. mingw-GCC does not provide it and there is no
honest reimplementation: it walks an MSVC scope table this tree does not build.

**It is a stub. Any code path that reaches its body dies at `abort()`. It does not dispatch, unwind,
or filter, and no plausible-looking handler has been written in its place.**

What makes the stub acceptable rather than a lie is that it is referenced **only by address, never
called**: `Fog/Debug.cpp:191`, `Fog/Engine/Application.cpp:1516`, `:1642` and
`Fog/Src/LogManager.cpp:1880` all only store it into a local SEH registration record, and the
emitted code never links that record onto `fs:[0]`. The link needs the address; nothing reaches the
body.

---

# Left undefined, with the reason

Eleven symbols in this lane are **not** shimmed. Each is a Ghidra defect with a bounded fix, and
shimming would be either a fabrication or a papering-over of real game code.

## A. The operand is in `ST(0)` and the call sites pass nothing

### `__ftol2` @ `00683006`, and `__CIsqrt` @ `006879c0`

The ABI *is* established. `__ftol2` is MSVC's `_ftol2`:

```
0068300f  FLD   ST0                     <- duplicates the incoming operand
00683011  FST   float ptr [ESP + 0x18]
00683015  FISTP qword ptr [ESP + 0x10]
00683019  FILD  qword ptr [ESP + 0x10]
...       FSUBP / sign test / ADD 0x7fffffff / ADC-SBB   <- round-to-nearest corrected to truncation
```

operand in `ST(0)`, 64-bit result in `EDX:EAX`, no stack arguments, no control-word change.

It is left undefined anyway, because **Ghidra's prototype is `ulonglong __ftol2(void)` with no `ST0`
parameter**, so the emitted call sites carry no operand at all:
`Storm/Source/SSTR.cpp:1669` and `:1684` are bare `nFtolResult = __ftol2();`. A shim reading `ST(0)`
would read whatever GCC last left there, which is not the value the binary would have had. A shim
returning anything else is a fabrication. Same defect at `__CIsqrt`, called argument-less at
`D2CMP/SRC/FastCmp.cpp:1596`.

**Prescription** (writer lane, `Diablo2Lod/windows/lod/1.14d/Game.exe`) - do for these two exactly
what was already done for the five `__CI*` siblings:

```
set_custom_signature(functionAddress="0x00683006", returnType="longlong",
                     parameters=[{name:"fValue", dataType:"float10", storage:"ST0"}])
set_custom_signature(functionAddress="0x006879c0", returnType="float10",
                     parameters=[{name:"fValue", dataType:"float10", storage:"ST0"}])
```

Once the operand reaches the call sites, both become one-line shims here
(`(long long)x` and `sqrtl(x)`). `__sqrt_common` @ the same family has the same defect; it is
outside this lane's list but has the same fix.

## B. Real game code, excluded only by its namespace

`ghidra-reconstruct/run.ts` excludes `/^compiler$/` and `/^_Wrappers$/`. Everything below is game
code or third-party code that is *in* the binary and would be emitted if the symbol simply lived
somewhere else. Stubbing any of it would be a metric gain by non-algorithmic means. The fix is
`move_symbol_to_namespace`, not a shim.

### `_Wrappers::CRT_SecurityCookieStub2` @ `006cb430` - **not a cookie stub**

One statement: `Storm::Source::SSComp::COMPRESS_ResetDecoder(gnBnetLogFileHandle)`. It is **called**,
not merely address-taken - `atexit(_Wrappers::CRT_SecurityCookieStub2)` at `Bnclient/Bnet.cpp:28`,
`:35`, `:64` and `Bnclient/Bnclient.cpp:278`. An `abort()` stub would abort at process exit.

```
move_symbol_to_namespace(address="0x006cb430", type="function", namespace="Storm::Source::SSComp")
```

Its siblings `CRT_SecurityCookieStub1` @ `006cb420` and `CRT_SecurityCookieStub3` @ `006cb440` are
not currently undefined but are the same kind of symbol and should be looked at in the same pass.

### `_Wrappers::CRT_ExceptionFilter1/2/3` @ `006c9c3b`, `006ca0b8`, `006ca118`

Real wrappers around the C++ EH frame handler, not CRT:

```
CRT_ExceptionFilter1: Fog::Debug::GuardStack(pRegistrationNode + 0xc); Fog::Debug::GuardStack(ret);
                      compiler::FID_conflict____CxxFrameHandler3(record, node, context, dispatcher);
CRT_ExceptionFilter2: compiler::FID_conflict____CxxFrameHandler3(record, node, context, dispatcher);
```

Address-taken only (`Fog/Src/ErrorManager.cpp:642`, `D2Client/ButtonWrapper.cpp:20`,
`D2Client/EditBoxImplementation.cpp:43`), but a body exists and is short, so a stub is not
warranted. Move them to the module that owns them - `Fog::Debug` for filter 1 by its callee, and by
its call sites `D2Client` for 2 and 3.

Note the knock-on: emitting them makes `FID_conflict____CxxFrameHandler3` a called symbol rather
than a merely-declared one. That symbol is already undefined today and belongs to another lane.

### `compiler::PKWARE_explode` @ `006b01b0` / `compiler::PKWARE_implode` @ `006b0870`

Storm's PKWARE DCL compression - real game code sitting in `compiler::`, excluded because of the
namespace and not because it is CRT.

**Re-pricing the earlier "5 compile errors to clear 3".** That number was for moving the two entry
points. It is the wrong unit: the DCL is a **closure of eight functions and eight data tables**, and
the helpers are misnamed with a `CRT_` prefix that hides them:

|Address|Symbol|Called by|
|-|-|-|
|`006b01b0`|`PKWARE_explode`|Storm|
|`006b0330`|`CRT_GetItemDataField`|`PKWARE_explode` only|
|`006b06f0`|`CRT_CompareItemValues`|`PKWARE_explode` only|
|`006b0730`|`CRT_IterateItemData`|`PKWARE_explode` only|
|`006b0830`|`CRT_SetMemoryValue`|`PKWARE_explode` only|
|`006b0870`|`PKWARE_implode`|Storm|
|`006b0a10`|`CRT_ProcessMemoryBlock`|`PKWARE_implode` only - 884 bytes, the compressor core|
|`006b1160`|`CRT_CopyMemoryValue`|`PKWARE_implode`, `CRT_ProcessMemoryBlock`|

plus `gaCRT_PKWareLitLenBitsTableA/B/C`, `gaCRT_PKWareDistBitsTable`, `gaCRT_PKWareDistBaseTable`,
`gaCRT_PKWareDistDecodeTable`, `gaCRT_PKWareLitDecodeTable`, `gaCRT_PKWareLenBaseTable`,
`gaCRT_PKWareLenBitsTable`, `gaPKWARE_DistCodeTable`, `gaPKWARE_ExtraLenBitsTable`,
`gbCRT_BitwiseOpState`. Every helper is DCL-private (call counts above), so the move is clean - but
it is eight functions, not two, and `PKWARE_implode` already shows one decompiler artifact that will
not compile as written: its table loop bound is the *string symbol*
`s_PKWARE_Data_Compression_Library_f_0074be60` used as a pointer limit.

So the honest answer to "re-price it": the trade is no longer 5-for-3, it is **an unmeasured
eight-function Storm-lane move with at least one known artifact, against two undefined symbols**.
Recommended, but as scoped Storm work with its own before/after measurement - not as a side effect
of CRT link work. Prescription, all eight:

```
move_symbol_to_namespace(address="0x006b01b0", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b0330", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b06f0", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b0730", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b0830", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b0870", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b0a10", type="function", namespace="Storm::Source::SSComp")
move_symbol_to_namespace(address="0x006b1160", type="function", namespace="Storm::Source::SSComp")
```

Until that lands, `d2_hand.h` keeps the *declarations* (which is why the tree compiles) and the two
entry points stay undefined at link.

### `compiler::CRT_GetItemDataAndFlags` @ `006b1b60` - the D3D enum-pixel-format callback

Confirmed, not CRT. Its plate comment records it and the decompilation agrees: its only xref is the
`PUSH` at `006b4aff` feeding `IDirect3DDevice3::EnumTextureFormats` in `Direct3DCallBack`;
parameter 1 is an `LPDDPIXELFORMAT`, parameter 2 the device-caps flag word, and the `0x200` bit it
sets is the one `Direct3DCallBack` tests for "supports 1555 textures". `__stdcall`, returns 1.

```
move_symbol_to_namespace(address="0x006b1b60", type="function", namespace="D2Direct3D::Renderer")
```

A rename to `D3D_EnumTextureFormatsCallback` belongs to a naming lane; the tree spells the current
name, so renaming and moving must land in the same regen.

## C. String data typed as a FUNCTION

Two of the "CRT" undefined symbols are **not code at all**. Both are `_Wrappers::` FUNCTION symbols
sitting on top of `.rdata` string bytes, and both are address-taken by the emitted command-line
option table.

`006d5b20` `_Wrappers::gCmdLineHelpText`, hexdump:

```
006d5b20  41 76 61 69 6c 61 62 6c  65 20 63 6f 6d 6d 61 6e  |Available comman|
006d5b30  64 20 6c 69 6e 65 20 6f  70 74 69 6f 6e 73 3a 0a  |d line options:.|
006d5b40  20 20 2d 73 65 74 5b 64  65 66 61 75 6c 74 20 63  |  -set[default c|
...
006d5b90  65 73 6f 75 72 63 65 73  0a 00 00 00 70 00 00 00  |esources....p...|
006d5bc0  63 00 00 00 6d 6f 64 65  00 00 00 00 73 65 74 00  |c...mode....set.|
006d5bd0  68 65 6c 70 00 00 00 00  68 00 00 00 3f 00 00 00  |help....h...?...|
```

so `gCmdLineHelpText` is a 154-byte NUL-terminated string, and `_Wrappers::CRT_StrLen` at `006d5bd0`
- prototyped `uint32_t CRT_StrLen(char*)`, which reads like `strlen` - is **the five bytes
`"help"`**. It disassembles to `PUSH 0x706c65` (`68 65 6c 70 00`), which is the string bytes decoded
as an instruction, and its decompilation ends in `halt_baddata()`.

The neighbours confirm the reading: the emitted table at `D2Client/ClientModeInGame.cpp:230-246`
already holds `DAT_006d5bdc` (`"?"`) and `DAT_006d5bd8` (`"h"`) in the same slot that holds
`&_Wrappers::CRT_StrLen`, and `_Wrappers::gCmdLineHelpText` is passed to `MessageBoxA` as `LPCSTR
lpText` at `:152` and `:215`. Ghidra's `COMPUTED_CALL` xref at `0044b6ce` is an artifact of the
table-walking loop, not a real call.

No shim is possible: defining functions with these names would put *machine code* where the tree
expects a help string, which is the "builds and then runs wrong" outcome the rules forbid.
Prescription:

```
delete_function(address="0x006d5b20")
set_data_type(address="0x006d5b20", dataType="char", length=154)
delete_function(address="0x006d5bd0")
set_data_type(address="0x006d5bd0", dataType="char", length=5)
```

They then reach the tree as `globals` string data and the two symbols disappear from the link.
