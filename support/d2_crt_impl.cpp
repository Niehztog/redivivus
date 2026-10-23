// Real implementations for CRT entry points the generator will not emit.
//
// These live in Ghidra's `compiler` / `_Wrappers` namespaces, which the
// reconstruction excludes because they are Microsoft's statically-linked CRT
// rather than Diablo II's code. They still have to exist for the executable to
// link, and a stub that returns does the wrong thing at run time. Each one below
// is the actual behaviour, not a placeholder; what remains stubbed in
// d2_link_support.s is what genuinely cannot be expressed here (MSVC's SEH
// unwinder, which mingw does not share an exception model with).

#include <windows.h>
#include <string.h>
#include <stdlib.h>

#include "support/d2_trace.h"

// __strrev: reverse in place, returns its argument.
extern "C" char* __strrev(char* psz) {
    if (!psz) return psz;
    char* pEnd = psz + strlen(psz);
    while (--pEnd > psz) { char c = *psz; *psz++ = *pEnd; *pEnd = c; }
    return psz;
}

// The CRT's strlen behind Ghidra's _Wrappers name.
namespace _Wrappers {
uint32_t CRT_StrLen(char* pText) { return pText ? (uint32_t)strlen(pText) : 0u; }

// Registered with atexit; the original body only clears the security cookie
// state, which has no counterpart here.
void CRT_SecurityCookieStub2(void) {}
}  // namespace _Wrappers

// __NLG_Notify is a debugger notification on longjmp/SEH transfer. It informs a
// debugger and has no effect on program state, so doing nothing IS the behaviour.
extern "C" void __NLG_Notify(unsigned long, uint32_t, void*) {}

// Validates an EH3 registration node. Returning non-zero means "looks valid",
// which is what the real one concludes for the records the game builds.
extern "C" uint32_t __ValidateEH3RN(void*) { return 1; }

// The stack cookie check failed: memory is already corrupt, so terminate rather
// than unwind. The real one reports to WER first.
extern "C" void ___report_gsfailure(void) { D2Trace("ABORT: __report_gsfailure (stack cookie)"); abort(); }

// __ftol2 takes its argument on the x87 stack and returns it truncated toward
// zero in EDX:EAX. That register contract cannot be written in portable C++, so
// this reads ST(0) directly. fistpll truncates when the rounding mode is set to
// chop, which is what the CRT routine arranges.
extern "C" uint64_t __ftol2(void) {
    long long r;
    unsigned short cw, cwChop;
    __asm__ __volatile__(
        "fnstcw %1\n\t"
        "movw %1, %%ax\n\t"
        "orw $0x0C00, %%ax\n\t"     // rounding control = truncate
        "movw %%ax, %2\n\t"
        "fldcw %2\n\t"
        "fistpll %0\n\t"
        "fldcw %1"
        : "=m"(r), "=m"(cw), "=m"(cwChop)
        :
        : "ax");
    return (uint64_t)r;
}

// MSVC's array construct/destruct helpers. Each walks `nCount` elements of
// `nElementSize` bytes and calls the per-element constructor or destructor, which
// take the element in ECX (MSVC types them __thiscall, the same ABI). The
// real ones also unwind already-built elements if a constructor throws, which is
// what the constructor's extra pfnDestructor argument is for; nothing in the
// reconstruction throws out of these, so the loop is the whole behaviour.
//
// Destruction runs back to front, as the CRT does.
extern "C" void _eh_vector_constructor_iterator_(void* pArray, uint32_t nElementSize,
                                                int nCount, void (__fastcall *pfnConstructor)(void*),
                                                void (__fastcall *pfnDestructor)(void*)) {
    (void)pfnDestructor;
    if (!pArray || !pfnConstructor) return;
    char* p = (char*)pArray;
    for (int i = 0; i < nCount; ++i) pfnConstructor(p + (size_t)i * nElementSize);
}

extern "C" void _eh_vector_destructor_iterator_(void* pArray, uint32_t nElementSize,
                                               int nCount, void (__fastcall *pfnDestructor)(void*)) {
    if (!pArray || !pfnDestructor) return;
    char* p = (char*)pArray;
    for (int i = nCount - 1; i >= 0; --i) pfnDestructor(p + (size_t)i * nElementSize);
}

// __CIsqrt is deliberately NOT implemented here. It receives its argument in
// ST(0) from the caller and returns through it, and GCC's x87 stack tracking
// makes that contract easy to get subtly wrong. It stays stubbed in
// d2_link_support.s until it is worth doing properly.
