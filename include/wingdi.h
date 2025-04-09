#pragma once

#include "windef.h"

#define DCB_DISABLE
#define DCB_ENABLE
#define DCB_RESET //TODO
#define DCB_SET

typedef struct _BLENDFUNCTION {
  BYTE BlendOp;
  BYTE BlendFlags;
  BYTE SourceConstantAlpha;
  BYTE AlphaFormat;
} BLENDFUNCTION, *PBLENDFUNCTION;



BOOL WINAPI GdiFlush();
DWORD WINAPI GdiGetBatchLimit();
DWORD WINAPI GdiSetBatchLimit(DWORD dw);
COLORREF WINAPI GetBkColor(HDC hdc);
int WINAPI GetBkMode(HDC hdc);
UINT WINAPI GetBoundsRect(HDC hdc, LPRECT lprect, UINT flags);
int WINAPI GetROP2(HDC hdc);
COLORREF WINAPI SetBkColor(HDC hdc, COLORREF color);
int WINAPI SetBkMode(HDC hdc, int mode);
UINT WINAPI SetBoundsRect(HDC hdc, const RECT* lprect, UINT flags);
int WINAPI SetROP2(HDC hdc, int rop2);

BOOL WINAPI Chord(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
BOOL WINAPI Ellipse(HDC hdc, int left, int top, int right, int bottom);
int WINAPI FillRect(HDC hDC, const RECT* lprc, HBRUSH hbr);
int WINAPI FrameRect(HDC hDC, const RECT* lprc, HBRUSH hbr);
BOOL WINAPI InvertRect(HDC hDC, const RECT* lprc);
BOOL WINAPI Pie(HDC hdc, int left, int top, int right, int bottom, int xr1, int yr1, int xr2, int yr2);
BOOL WINAPI Polygon(HDC hdc, const POINT* apt, int cpt);
BOOL WINAPI PolyPolygon(HDC hdc, const POINT* apt, const INT* asz, int csz);
BOOL WINAPI Rectangle(HDC hdc, int left, int top, int right, int bottom);
BOOL WINAPI RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height);
