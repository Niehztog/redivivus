// vc8_compat.h - forced first include of every oracle compile (cl /FI).
//
// The tree is written for a C++17 compiler; the original was built with Visual
// C++ 2005. This header supplies, for VC8, the handful of C++11/17 spellings the
// generator emits that have an exact C++03 equivalent. Nothing here may change
// generated code: each definition expands to what VC8 compiles the original
// construct to. What cannot be expressed as a macro is rewritten per file by
// vc8_translate.py instead (nested namespaces, packed structs, = default).
#pragma once

// A null pointer constant. VC8's `0` is the same constant; only overload
// resolution could tell them apart, and the tree overloads nothing on it.
#define nullptr 0

// d2_enums.h's only use: namespace-scope constants, which `const` gives the
// same internal linkage and constant-expression status.
#define constexpr const

// C++11 static_assert as a C++03 negative-array typedef. Same check, no code.
#define VC8_CAT2(a, b) a##b
#define VC8_CAT(a, b) VC8_CAT2(a, b)
#define static_assert(c, m) typedef char VC8_CAT(vc8_static_assert_, __COUNTER__)[(c) ? 1 : -1]

#define thread_local __declspec(thread)

// The Windows version the headers declare for. Unset, the 2003 SDK hides
// IsDebuggerPresent, TrackMouseEvent and other NT4+ APIs the tree calls. XP is
// the era's floor; a struct whose size depends on it would show in the audit
// as a differing cbSize constant.
#define _WIN32_WINNT 0x0501
#define WINVER 0x0501

// The time-stamp-counter intrinsic (<intrin.h> in VC8).
extern "C" unsigned __int64 __rdtsc(void);
#pragma intrinsic(__rdtsc)

// GCC's frame/return-address builtins, level 0 only (the only level the tree
// uses). The return address is MSVC's own intrinsic; the frame address is EBP.
#define __builtin_frame_address(level) vc8_frame_address()
static __forceinline void* vc8_frame_address(void) { void* p; __asm { mov p, ebp } return p; }
extern "C" void* _ReturnAddress(void);
#pragma intrinsic(_ReturnAddress)
#define __builtin_return_address(level) _ReturnAddress()

// d2_platform.h's _MSC_VER path of D2_Cpuid; VC8 declares it only in <intrin.h>,
// which would bring hundreds of declarations the tree redeclares its own way.
extern "C" void __cpuid(int cpuInfo[4], int infoType);
#pragma intrinsic(__cpuid)

// d2_platform.h re-declares mingw's socket types (psdk_inc/_ip_types.h) so that
// sockaddr_in.sin_addr is the 32-bit word Ghidra models. Under the Platform SDK
// winsock2.h declares them itself; claiming the guard skips the mingw copy.
#define _MINGW_IP_TYPES_H

// The tree declares `typedef int _EXCEPTION_DISPOSITION` (d2_enums.h); VC8's
// excpt.h declares an enum of that tag. Rename the CRT's while the Windows
// headers are read; vc8_after_windows.h drops the rename again.
#define _EXCEPTION_DISPOSITION vc8_EXCEPTION_DISPOSITION

// C4481: `override` is a VC8 extension keyword. C4480: so is an enum's
// underlying type. Both are what the tree means; neither changes code.
#pragma warning(disable: 4480 4481)

// C++11 <cmath> additions the tree uses. Ghidra lowers an x87 FISTP/FRNDINT
// (round in the current rounding mode) to std::nearbyint; this is that.
namespace std {
inline double nearbyint(double x) { double r; __asm { fld x } __asm { frndint } __asm { fstp r } return r; }
inline bool isnan(double x) { return x != x; }
}

// GCC's spelling of MSVC's _alloca intrinsic. malloc.h is included last, so
// that every rename above is in force before any CRT header is read.
#include <malloc.h>
#define __builtin_alloca _alloca
