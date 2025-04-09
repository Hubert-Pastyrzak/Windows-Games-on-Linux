#pragma once

#include <stdint.h>
#include <wchar.h>
#include "intsafe.h"

#define VOID void

typedef char     CCHAR;
typedef char     CHAR;
typedef long     LONG;
typedef int64_t  LONGLONG;
typedef void*    PVOID;
typedef short    SHORT;
typedef uint64_t ULONGLONG;
typedef wchar_t  WCHAR;

typedef BYTE       BOOLEAN;
typedef WORD       LANGID;
typedef DWORD      LCID;
typedef DWORDLONG* PDWORDLONG;
typedef PDWORD     PLCID;

typedef struct _LUID {
  DWORD LowPart;
  LONG HighPart;
} LUID, *PLUID;



typedef BOOLEAN*     PBOOLEAN;
typedef PVOID        HANDLE;
typedef LONG         HRESULT;
typedef CONST CHAR*  LPCSTR;
typedef CONST WCHAR* LPCWSTR;
typedef CHAR*        LPSTR;
typedef WCHAR*       LPWSTR;
typedef CHAR*        PCHAR;
typedef CONST CHAR*  PCSTR;
typedef CONST WCHAR* PCWSTR;
typedef LONG*        PLONG;
typedef LONGLONG*    PLONGLONG;
typedef SHORT*       PSHORT;
typedef CHAR*        PSTR;
typedef WCHAR*       PWCHAR;
typedef WCHAR*       PWSTR;
typedef LONGLONG     USN;



typedef HANDLE* PHANDLE;

#if defined(UNICODE)
  typedef LPCWSTR LPCTSTR;
  typedef LPWSTR  LPTSTR;
  typedef LPCWSTR PCTSTR;
  typedef LPWSTR  PTSTR;
  typedef WCHAR   TBYTE;
  typedef WCHAR   TCHAR;
#else
  typedef LPCSTR        LPCTSTR;
  typedef LPSTR         LPTSTR;
  typedef LPCSTR        PCTSTR;
  typedef LPSTR         PTSTR;
  typedef unsigned char TBYTE;
  typedef char          TCHAR;
#endif



typedef TBYTE* PTBYTE;
typedef TCHAR* PTCHAR;
