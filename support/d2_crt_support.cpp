#include "support/d2_trace.h"
// Hand-written CRT / intrinsic support layer.
//
// Every definition here stands in for a function that IS in Game.exe but is
// dropped before emission by `excludePatterns` (`/^compiler$/`, `/^_Wrappers$/`
// in ghidra-reconstruct/run.ts). The generator never writes this file, so it
// carries no merge risk and no debt (regen-workflow.md, option 3).
//
// Rules obeyed here, from docs/regen-workflow.md:
//   - No fabricated ABI. Every body below is backed by the disassembly or the
//     decompilation of the named address in
//     Diablo2Lod /windows/lod/1.14d/Game.exe, quoted in support/README.md.
//   - Where the ABI could not be honestly reproduced at the emitted call site,
//     the symbol is LEFT UNDEFINED rather than stubbed. See README.md.
//   - No shim exists only to make a count fall.
//
// Symbols deliberately NOT defined here (see README.md for each):
//   __ftol2, __CIsqrt                          - operand lives in ST(0) and the
//                                                emitted call sites pass nothing
//   _Wrappers::CRT_StrLen, _Wrappers::gCmdLineHelpText
//                                              - string DATA typed as FUNCTION
//   _Wrappers::CRT_ExceptionFilter1/2/3, _Wrappers::CRT_SecurityCookieStub2
//   compiler::PKWARE_explode/implode, compiler::CRT_GetItemDataAndFlags
//                                              - real game code, excluded only
//                                                by namespace

#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// ---------------------------------------------------------------------------
// The five MSVC x87 __CI* intrinsics.
//
// Their operands travel in the x87 stack registers, NOT on the C stack:
//   006886c0 CRT_CICos    __CIcos    ST(0) -> ST(0)   FCOS at 0068872d
//   00688590 CRT_CISin    __CIsin    ST(0) -> ST(0)
//   00687ac0 CRT_CILog    __CIlog    ST(0) -> ST(0)   FLDLN2/FXCH/FYL2X @00687b3f
//   00687ea0 CRT_CILog10  __CIlog10  ST(0) -> ST(0)   FLDLG2 form
//   00687c10 CRT_CIPow    __CIpow    ST(1),ST(0) -> ST(0)  FYL2X+F2XM1 @00687c6d
//
// Aliasing these to cos/sin/log/log10/pow AT THE BINARY'S ABI would read
// garbage. That is not what happens here: Ghidra (v791) models the operands as
// parameters with ST0/ST1 custom storage, so the decompiler threads the values
// through and the emitted call sites are ordinary C calls carrying the operand
// as a `long double` argument - e.g. D2Common/Drlg/Environment.cpp:83
// `fFloatResult = CRT_CICos(fVar1);`. The definitions below therefore match the
// prototypes the call sites were compiled against, and the x87 stack never
// enters the picture. mingw's `long double` is the same 80-bit x87 type as
// Ghidra's `float10`.
//
// CRT_CIPow's parameter order is load-bearing: Ghidra records fBase in ST(1)
// and fExponent in ST(0), fixed from the FXCH at 00687c4e. powl(base, exp).
// ---------------------------------------------------------------------------
extern "C" long double CRT_CICos(long double x) { return cosl(x); }
extern "C" long double CRT_CISin(long double x) { return sinl(x); }
extern "C" long double CRT_CILog(long double x) { return logl(x); }
extern "C" long double CRT_CILog10(long double x) { return log10l(x); }
extern "C" long double CRT_CIPow(long double base, long double exponent) {
  return powl(base, exponent);
}

// ---------------------------------------------------------------------------
// Three CRT functions whose generated prototype in d2_platform.h is the
// emitter's unknown-signature fallback `T NAME(...)`. A variadic declaration
// with no named parameter cannot be defined portably, and re-declaring the name
// with a concrete signature in this TU would collide with the forced include.
// Both are avoided by giving the real definition a private C++ name and an asm
// label carrying the exact object-file symbol (i386 PE user-label prefix `_`).
// On i386 cdecl a fixed-arity definition is call-compatible with the variadic
// declaration: all arguments go on the stack and the caller cleans up.
// ---------------------------------------------------------------------------

// 00683080 `float10 CRT_Floor(double fParam)` __cdecl. Its x87 fallback jumps to
// 0068ea71, which Ghidra's FID matches as __floor_default (VS2005 Release,
// single match); the SSE2 path at 006830c0 is the branch-free exponent-field
// floor. Its only caller, Fog/Source/SFile.cpp:614-615 (SFILE_JulianDayNumber),
// is a floor consumer. Both call sites discard the result.
extern "C" double d2_CRT_Floor(double x) __asm__("_CRT_Floor");
extern "C" double d2_CRT_Floor(double x) { return floor(x); }

// 00687740 `char *CRT_Strchr(char *pszStr, char cChar)` __cdecl. The body is
// the word-at-a-time strchr verbatim: the 0x7efefeff / 0x81010100 zero-byte
// test, the 4-byte alignment prologue, the four per-byte compares. It is
// strchr. `char` promotes to `int` through the variadic declaration, which is
// exactly strchr's own second parameter type.
extern "C" char* d2_CRT_Strchr(char* s, int c) __asm__("_CRT_Strchr");
extern "C" char* d2_CRT_Strchr(char* s, int c) { return strchr(s, c); }

// 006987d8 - NOT `_clearfp`, which takes no arguments. 22 bytes, __cdecl:
//   MOV EAX,[ESP+8] / AND EAX,0x7ff00000 / CMP EAX,0x7ff00000 / JZ +1
//   RET                       <- ZF clear
//   MOV EAX,[ESP+8] / RET     <- ZF set
// The two arguments are the low and high halves of one double at [ESP+4], and
// EAX is the same value on both paths - the branch exists only to leave ZF set
// when the exponent field is all ones (Inf/NaN). Its x87-CRT callers consume
// that flag (00688701 calls it, then __cos_common at 0068871d branches on the
// ZF it left). C has no spelling for a flag return, and every emitted call site
// - D2Sound/Src/D2SoundSmp.cpp:1046, D2CMP/Draw.cpp:1164,
// D2CMP/SRC/FastCmp.cpp:1591, D2Client/Utils.cpp:43/54/101 - discards the
// result, so reproducing EAX is exactly faithful to what the tree observes.
extern "C" unsigned int d2_CRT_ClearFP(unsigned int nLow,
                                       unsigned int nHigh) __asm__("_CRT_ClearFP");
extern "C" unsigned int d2_CRT_ClearFP(unsigned int nLow, unsigned int nHigh) {
  (void)nLow;
  return nHigh;
}

// ---------------------------------------------------------------------------
// CRT functions whose generated prototype is already concrete.
// ---------------------------------------------------------------------------

// 00685637 __cdecl, one statement:
//   CRT_Output_L(CRT_Output_Printf, pFile, nParam, 0, dwParam)
// i.e. the locale-explicit printf core with a null locale, a format string and
// an argument list: `vfprintf(FILE*, const char*, va_list)`. Parameter 2 is
// typed `int` by Ghidra but is the format pointer - the call site,
// Fog/File.cpp:300, passes `(int)Format` and a va_list built from `&Format + 4`.
extern "C" int CRT_Vsprintf_L(FILE* pFile, int nFormat, void* pArgList) {
  return vfprintf(pFile, reinterpret_cast<const char*>(nFormat),
                  static_cast<va_list>(pArgList));
}

// 006856e9 `errno_t CRT_LocalTime_S(tm *pTm, uint *pnParam)` __cdecl. The body
// is _localtime64_s: memset(pTm, 0xff, 0x24), the __time64_t range check
// against 0x93406fff, ___tzset, __get_dstbias, __isindst, and __gmtime64_s
// against `(__time64_t *)pnParam` - so the second parameter is a pointer to a
// 64-bit time, not a 32-bit one. Fog/File.cpp:85-86 agrees: it declares
// `__time64_t tTime = __time64(nullptr)` and casts its address to uint32_t*.
extern "C" int CRT_LocalTime_S(struct tm* pTm, unsigned int* pnTime) {
  __time64_t tTime;
  memcpy(&tTime, pnTime, sizeof(tTime));
  return _localtime64_s(pTm, &tTime);
}

// 00684af3 - NOT `_encode_pointer`. The body is
//   ptd = __getptd(); old = ptd->_translator;
//   ptd = __getptd(); ptd->_translator = pParam; return old;
// `_ptiddata::_translator` is the slot `_set_se_translator` writes, and the one
// emitted call site is Fog/Debug.cpp:2731,
// `CRT_Encode_Secure_Pointer((void*)HandleExceptionWithStackDump)`, inside Fog's
// crash-handler installer. So this is `_set_se_translator`.
//
// mingw-GCC has no MSVC structured-exception translator, so the recorded
// function is never invoked. The get/set/return-previous semantics and the
// per-thread storage are reproduced exactly; the dispatch is not, and cannot be
// without the MSVC SEH layer.
static thread_local void* g_pSeTranslator = nullptr;
extern "C" void* CRT_Encode_Secure_Pointer(void* pTranslator) {
  void* pPrevious = g_pSeTranslator;
  g_pSeTranslator = pTranslator;
  return pPrevious;
}

// 006b1a30 - NOT a return-value helper. __stdcall, does not return, one
// statement: `__CxxThrowException_8(&dwParam, &DAT_007020b4)`. The ThrowInfo at
// 007020b4 names one catchable type at 007020cc with sizeOrOffset 4 and a
// TypeDescriptor at 0074c0a8 whose decorated name is
// `.?AVCAtlException@ATL@@`. So the function throws a 4-byte ATL::CAtlException
// carrying the HRESULT: it is ATL's AtlThrow. The only call site,
// D2Direct3D/Renderer/Direct3D.cpp:596 `CRT_ReturnValue(0x80004005)` guarded by
// a null test, is the ATLENSURE shape.
//
// mingw has no ATL, so the exception type is declared here to the shape the
// type descriptor gives - a 4-byte object holding the HRESULT - and thrown.
// Nothing in the tree catches it (the MSVC EH frames are not emitted), so in
// practice this terminates. That matches the binary's own "does not return".
namespace ATL {
struct CAtlException {
  long m_hr;
};
}  // namespace ATL

extern "C" unsigned int CRT_ReturnValue(unsigned int dwHResult) {
  throw ATL::CAtlException{static_cast<long>(dwHResult)};
}

// ---------------------------------------------------------------------------
// SEH and /GS.
// ---------------------------------------------------------------------------

// 006877fe, FID single match "__purecall", VS2005 Release. The body fetches the
// unexpected handler, calls it if non-null, then __set_abort_behavior(0,1) and
// _abort(). abort() is the faithful tail, not a placeholder. Referenced only as
// data - twelve vftable slots in globals.D2Client.cpp:36280-36291 and seven in
// globals.cpp:45235 - so it runs only if a pure virtual is actually called,
// which is when the binary aborts too.
extern "C" void __purecall(void) { D2Trace("ABORT: __purecall"); abort(); }

// 00684f50, FID single match "__except_handler4", VS2005 Release. This is the
// MSVC SEH frame handler; mingw-GCC does not provide it and there is no honest
// reimplementation - it walks an MSVC scope table this tree does not build.
//
// It is referenced ONLY by address, never called: Fog/Debug.cpp:191,
// Fog/Engine/Application.cpp:1516 and :1642, Fog/Src/LogManager.cpp:1880 all
// only store it into a local SEH registration record, and the emitted code
// never links that record onto fs:[0]. The link needs the address; nothing
// reaches the body.
//
// STATED PLAINLY: this is a stub, not a handler. Any path that ever calls it
// dies at the abort() below. It does not dispatch, unwind, or filter.
extern "C" int __except_handler4(struct _EXCEPTION_RECORD* pRecord, EH4_EXCEPTION_REGISTRATION* pRegistration,
                                 CONTEXT* pContext, void* pDispatcherContext) {
  (void)pRecord;
  (void)pRegistration;
  (void)pContext;
  (void)pDispatcherContext;
  D2Trace("ABORT called");
    abort();
}
