#pragma once

#include <stdint.h>

#ifdef GAMECUBE
#define BIG_ENDIAN
#else
#define LITTLE_ENDIAN
#endif

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float float32;
typedef double float64;

typedef long long32;
typedef unsigned long ulong32;

typedef int32 bool32;

#ifdef NULL
#undef NULL
#endif
#define NULL 0

#ifdef TRUE
#undef TRUE
#endif
#define TRUE 1

#ifdef FALSE
#undef FALSE
#endif
#define FALSE 0

#ifdef OK
#undef OK
#endif
#define OK 0

#ifdef FAILED
#undef FAILED
#endif
#define FAILED 1

#define WIP

#define STUB { return {}; }
#define STUB_VOID { return; }
#define STUB_REF(T) { static T _; return _; }

#define FORCEENUMSIZEINT ((int32)((~((uint32)0))>>1))