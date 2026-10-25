/* stdint.h - C99 exact-width integers for Visual C++ 2005, which has none.
   intptr_t/uintptr_t/size_t come from the CRT's own <crtdefs.h>. */
#ifndef VC8_STDINT_H
#define VC8_STDINT_H
#include <crtdefs.h>
#include <limits.h>

typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef __int64            int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned __int64   uint64_t;

typedef int8_t   int_least8_t;   typedef uint8_t  uint_least8_t;
typedef int16_t  int_least16_t;  typedef uint16_t uint_least16_t;
typedef int32_t  int_least32_t;  typedef uint32_t uint_least32_t;
typedef int64_t  int_least64_t;  typedef uint64_t uint_least64_t;
typedef int8_t   int_fast8_t;    typedef uint8_t  uint_fast8_t;
typedef int32_t  int_fast16_t;   typedef uint32_t uint_fast16_t;
typedef int32_t  int_fast32_t;   typedef uint32_t uint_fast32_t;
typedef int64_t  int_fast64_t;   typedef uint64_t uint_fast64_t;
typedef int64_t  intmax_t;       typedef uint64_t uintmax_t;

#define INT8_MIN    (-127 - 1)
#define INT16_MIN   (-32767 - 1)
#define INT32_MIN   (-2147483647 - 1)
#define INT64_MIN   (-9223372036854775807i64 - 1)
#define INT8_MAX    127
#define INT16_MAX   32767
#define INT32_MAX   2147483647
#define INT64_MAX   9223372036854775807i64
#define UINT8_MAX   0xff
#define UINT16_MAX  0xffff
#define UINT32_MAX  0xffffffffu
#define UINT64_MAX  0xffffffffffffffffui64
#define INTPTR_MIN  INT32_MIN
#define INTPTR_MAX  INT32_MAX
#define UINTPTR_MAX UINT32_MAX

#define INT8_C(v)   (v)
#define INT16_C(v)  (v)
#define INT32_C(v)  (v)
#define INT64_C(v)  (v##i64)
#define UINT8_C(v)  (v)
#define UINT16_C(v) (v)
#define UINT32_C(v) (v##u)
#define UINT64_C(v) (v##ui64)
#endif
