#include <winuser.h>
#include <stdlib.h>
#include "display.h"

#include <DC.h>

//XCreateGC(display, window, 0, 0) - tworzy kontekst
//XFreeGC(display, gc) - niszczy kontekst


//TODO: Docelowo trzeba obsługiwać błędy



HDC WINAPI BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint) {
  //TODO: Wypełnić strukturę lpPaint, na razie nieistotne

  Display* display = defaultDisplay();

  DC* dc = (DC*)malloc(sizeof(DC));

  dc->window = (Window)hWnd;
  dc->gc = XCreateGC(display, (Window)hWnd, 0, 0);

  lpPaint->hdc = (HDC)dc;
  return (HDC)dc;
}

BOOL WINAPI DrawAnimatedRects(HWND hwnd, int idAni, const RECT* lprcFrom, const RECT* lprcTo) {
  //TODO
  return 0;
}

BOOL WINAPI DrawCaption(HWND hwnd, HDC hdc, const RECT* lprect, UINT flags) {
  //TODO
  return 0;
}

BOOL WINAPI DrawEdge(HDC hdc, LPRECT qrc, UINT edge, UINT grfFlags) {
  //TODO
  return 0;
}

BOOL WINAPI DrawFocusRect(HDC hDC, const RECT* lprc) {
  //TODO
  return 0;
}

BOOL WINAPI DrawFrameControl(HDC hdc, LPRECT lprc, UINT uType, UINT uState) {
  //TODO
  return 0;
}

BOOL WINAPI DrawStateA(HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

BOOL WINAPI DrawStateW(HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

BOOL WINAPI EndPaint(HWND hWnd, const PAINTSTRUCT* lpPaint) {
  Display* display = defaultDisplay();

  DC* dc = (DC*)lpPaint->hdc;

  XFreeGC(display, dc->gc);
  free(dc);

  return 1;
}

int WINAPI ExcludeUpdateRgn(HDC hDC, HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI GetUpdateRect(HWND hWnd, LPRECT lpRect, BOOL bErase) {
  //TODO
  return 0;
}

int WINAPI GetUpdateRgn(HWND hWnd, HRGN hRgn, BOOL bErase) {
  //TODO
  return 0;
}

HDC WINAPI GetWindowDC(HWND hWnd) {
  //TODO
  return 0;
}

int WINAPI GetWindowRgn(HWND hWnd, HRGN hRgn) {
  //TODO
  return 0;
}

int WINAPI GetWindowRgnBox(HWND hWnd, LPRECT lprc) {
  //TODO
  return 0;
}

BOOL WINAPI GrayStringA(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight) {
  //TODO
  return 0;
}

BOOL WINAPI GrayStringW(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight) {
  //TODO
  return 0;
}

BOOL WINAPI InvalidateRect(HWND hWnd, const RECT* lpRect, BOOL bErase) {
  //TODO
  return 0;
}

BOOL WINAPI InvalidateRgn(HWND hWnd, HRGN hRgn, BOOL bErase) {
  //TODO
  return 0;
}

BOOL WINAPI LockWindowUpdate(HWND hWndLock) {
  //TODO
  return 0;
}

BOOL WINAPI PaintDesktop(HDC hdc) {
  //TODO
  return 0;
}

BOOL WINAPI RedrawWindow(HWND hWnd, const RECT* lprcUpdate, HRGN hrgnUpdate, UINT flags) {
  //TODO
  return 0;
}

int WINAPI SetWindowRgn(HWND hWnd, HRGN hRgn, BOOL bRedraw) {
  //TODO
  return 0;
}

BOOL WINAPI UpdateWindow(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI ValidateRect(HWND hWnd, const RECT* lpRect) {
  //TODO
  return 0;
}

BOOL WINAPI ValidateRgn(HWND hWnd, HRGN hRgn) {
  //TODO
  return 0;
}

HWND WINAPI WindowFromDC(HDC hDC) {
  //TODO
  return 0;
}
