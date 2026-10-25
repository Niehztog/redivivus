// vc8_after_windows.h - included by the oracle's copy of d2_platform.h directly
// after the Windows headers (vc8_translate.py inserts the #include). It undoes
// the few Platform SDK definitions that collide with names the tree declares.
#pragma once

// rpcndr.h: `#define small char`. d2_enums.h has an enumerator named small.
#undef small

// vc8_compat.h renamed excpt.h's enum tag so that the tree's own
// `typedef int _EXCEPTION_DISPOSITION` (d2_enums.h) is the one that exists.
#undef _EXCEPTION_DISPOSITION

// d2_platform.h targets mingw and spells the MSVC CRT's case-insensitive
// compares by their POSIX names; VC8 has only the MSVC ones. vc8_translate
// drops d2_platform.h's `#define _stricmp strcasecmp` (it would loop with these).
#define strcasecmp _stricmp
#define strncasecmp _strnicmp

// The C99 names VC8's CRT lacks, as the functions they stand for. (vc8_translate
// drops d2_platform.h's reverse `#define _snprintf snprintf`, which would loop.
// A wrapper function would not do: a variadic one cannot be inlined, and every
// call site would call it instead of the CRT.)
#define snprintf _snprintf
#define vsnprintf _vsnprintf

// A typedef the Windows Server 2003 SDK predates (winreg.h gained it later).
typedef LONG LSTATUS;
