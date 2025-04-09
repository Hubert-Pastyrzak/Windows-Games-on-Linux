#pragma once

#include <stdint.h>

#define POINTER_32
#define POINTER_64
#define POINTER_SIGNED
#define POINTER_UNSIGNED

typedef unsigned int   DWORD32;
typedef uint64_t       DWORD64;
typedef signed char    INT8;
typedef signed short   INT16;
typedef signed int     INT32;
typedef signed int     LONG32;
typedef int64_t        INT64;
typedef signed int     LONG32;
typedef int64_t        LONG64;
typedef unsigned char  UINT8;
typedef unsigned short UINT16;
typedef unsigned int   UINT32;
typedef uint64_t       UINT64;
typedef unsigned int   ULONG32;
typedef uint64_t       ULONG64;

#if defined(__x86_64__)
  typedef int            HALF_PTR;
  typedef int64_t        INT_PTR;
  typedef int64_t        LONG_PTR;
  typedef unsigned int   UHALF_PTR;
  typedef uint64_t       UINT_PTR;
  typedef uint64_t       ULONG_PTR;
#else
  typedef short          HALF_PTR;
  typedef int            INT_PTR;
  typedef long           LONG_PTR;
  typedef unsigned short UHALF_PTR;
  typedef unsigned int   UINT_PTR;
  typedef unsigned long  ULONG_PTR;
#endif



typedef ULONG_PTR DWORD_PTR;
typedef DWORD32*  PDWORD32;
typedef DWORD64*  PDWORD64;
typedef HALF_PTR* PHALF_PTR;
typedef INT_PTR*  PINT_PTR;
typedef INT8*     PINT8;
typedef INT16*    PINT16;
typedef INT32*    PINT32;
typedef INT64*    PINT64;
typedef LONG_PTR* PLONG_PTR;
typedef LONG32*   PLONG32;
typedef LONG64*   PLONG64;

typedef DWORD_PTR* PDWORD_PTR;

//TODO: Tutaj brakuje wielu typów
