#pragma once

#include "intsafe.h"
#include "basetsd.h"

//#define CALLBACK __attribute__((stdcall))
#define CONST    const
//#define WINAPI __attribute__((stdcall))

//TODO:
#if defined (__x86_64__)
  #define WINAPI //TODO: Definicja dla 64-bitowych systemów
  #define CALLBACK //TODO
#else
  #define WINAPI __attribute__((stdcall))
  #define CALLBACK __attribute__((stdcall))
#endif

typedef int            BOOL;
typedef unsigned char  BYTE;
typedef float          FLOAT;
typedef int            HFILE;
typedef int            INT;
typedef CONST void*    LPCVOID;
typedef int*           LPINT;
typedef long*          LPLONG;
typedef void*          LPVOID;
typedef int*           PINT;
typedef unsigned char  UCHAR;
typedef unsigned int   UINT;
typedef unsigned long  ULONG;
typedef unsigned short USHORT;
typedef unsigned short WORD;

typedef DWORD    COLORREF;
typedef LONG_PTR LPARAM;
typedef DWORD*   LPCOLORREF;
typedef DWORD*   LPDWORD;
typedef LONG_PTR LRESULT;
typedef DWORD*   PDWORD;
typedef UINT_PTR WPARAM;



#define APIENTRY WINAPI

typedef WORD    ATOM;
typedef BYTE    BOOLEAN;
typedef BOOL*   LPBOOL;
typedef BYTE*   LPBYTE;
typedef WORD*   LPWORD;
typedef BOOL*   PBOOL;
typedef BYTE*   PBYTE;
typedef FLOAT*  PFLOAT;
typedef UCHAR*  PUCHAR;
typedef UINT*   PUINT;
typedef ULONG*  PULONG;
typedef USHORT* PUSHORT;
typedef WORD*   PWORD;



#include "winnt.h"

typedef HANDLE     HACCEL;
typedef HANDLE     HBITMAP;
typedef HANDLE     HBRUSH;
typedef HANDLE     HCOLORSPACE;
typedef HANDLE     HDC;
typedef HANDLE     HDESK;
typedef HANDLE     HENHMETAFILE;
typedef HANDLE     HFONT;
typedef HANDLE     HGDIOBJ;
typedef HANDLE     HGLOBAL;
typedef HANDLE     HHOOK;
typedef HANDLE     HICON;
typedef HANDLE     HINSTANCE;
typedef HANDLE     HKEY;
typedef HANDLE     HKL;
typedef HANDLE     HLOCAL;
typedef HANDLE     HMENU;
typedef HANDLE     HMETAFILE;
typedef HANDLE     HMONITOR;
typedef HANDLE     HPALETTE;
typedef HANDLE     HPEN;
typedef HANDLE     HRGN;
typedef HANDLE     HRSRC;
typedef HANDLE     HWINSTA;
typedef HANDLE     HWND;
typedef HANDLE*    LPHANDLE;
typedef ULONGLONG* PULONGLONG;

typedef struct tagRECT {
  LONG left;
  LONG top;
  LONG right;
  LONG bottom;
} RECT, *PRECT, *NPRECT, *LPRECT;

typedef struct tagPOINT {
  LONG x;
  LONG y;
} POINT, *PPOINT, *NPPOINT, *LPPOINT;

typedef struct tagSIZE {
  LONG cx;
  LONG cy;
} SIZE, *PSIZE, *LPSIZE;



typedef HICON     HCURSOR;
typedef HINSTANCE HMODULE;
typedef HKEY*     PHKEY;
