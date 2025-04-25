#include <winuser.h>
#include <stdlib.h>
#include "display.h"

#include <DC.h>

//XCreateGC(display, window, 0, 0) - tworzy kontekst
//XFreeGC(display, gc) - niszczy kontekst


//TODO: Docelowo trzeba obsługiwać błędy



//The BeginPaint function prepares the specified window for painting and fills a PAINTSTRUCT structure with information about the painting.
HDC WINAPI BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint) {
  //TODO: Wypełnić strukturę lpPaint, na razie nieistotne

  Display* display = defaultDisplay();

  DC* dc = (DC*)malloc(sizeof(DC));

  dc->window = (Window)hWnd;
  dc->gc = XCreateGC(display, (Window)hWnd, 0, 0);

  lpPaint->hdc = (HDC)dc;
  return (HDC)dc;
}

//Animates the caption of a window to indicate the opening of an icon or the minimizing or maximizing of a window.
BOOL WINAPI DrawAnimatedRects(HWND hwnd, int idAni, const RECT* lprcFrom, const RECT* lprcTo) {
  //TODO
  return 0;
}

//The DrawCaption function draws a window caption.
BOOL WINAPI DrawCaption(HWND hwnd, HDC hdc, const RECT* lprect, UINT flags) {
  //TODO
  return 0;
}

//The DrawEdge function draws one or more edges of rectangle.
BOOL WINAPI DrawEdge(HDC hdc, LPRECT qrc, UINT edge, UINT grfFlags) {
  //TODO
  return 0;
}

//The DrawFocusRect function draws a rectangle in the style used to indicate that the rectangle has the focus.
BOOL WINAPI DrawFocusRect(HDC hDC, const RECT* lprc) {
  //TODO
  return 0;
}

//The DrawFrameControl function draws a frame control of the specified type and style.
BOOL WINAPI DrawFrameControl(HDC hdc, LPRECT lprc, UINT uType, UINT uState) {
  //TODO
  return 0;
}

//The DrawState function displays an image and applies a visual effect to indicate a state, such as a disabled or default state.
BOOL WINAPI DrawStateA(HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

//The DrawState function displays an image and applies a visual effect to indicate a state, such as a disabled or default state.
BOOL WINAPI DrawStateW(HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

//The EndPaint function marks the end of painting in the specified window. This function is required for each call to the BeginPaint function, but only after painting is complete.
BOOL WINAPI EndPaint(HWND hWnd, const PAINTSTRUCT* lpPaint) {
  Display* display = defaultDisplay();

  DC* dc = (DC*)lpPaint->hdc;

  XFreeGC(display, dc->gc);
  free(dc);

  return 1;
}

//The ExcludeUpdateRgn function prevents drawing within invalid areas of a window by excluding an updated region in the window from a clipping region.
int WINAPI ExcludeUpdateRgn(HDC hDC, HWND hWnd) {
  //TODO
  return 0;
}

//The GetUpdateRect function retrieves the coordinates of the smallest rectangle that completely encloses the update region of the specified window. GetUpdateRect retrieves the rectangle in logical coordinates. If there is no update region, GetUpdateRect retrieves an empty rectangle (sets all coordinates to zero).
BOOL WINAPI GetUpdateRect(HWND hWnd, LPRECT lpRect, BOOL bErase) {
  //TODO
  return 0;
}

//The GetUpdateRgn function retrieves the update region of a window by copying it into the specified region. The coordinates of the update region are relative to the upper-left corner of the window (that is, they are client coordinates).
int WINAPI GetUpdateRgn(HWND hWnd, HRGN hRgn, BOOL bErase) {
  //TODO
  return 0;
}

//The GetWindowDC function retrieves the device context (DC) for the entire window, including title bar, menus, and scroll bars. A window device context permits painting anywhere in a window, because the origin of the device context is the upper-left corner of the window instead of the client area.
//GetWindowDC assigns default attributes to the window device context each time it retrieves the device context. Previous attributes are lost.
HDC WINAPI GetWindowDC(HWND hWnd) {
  //TODO
  return 0;
}

//The GetWindowRgn function obtains a copy of the window region of a window. The window region of a window is set by calling the SetWindowRgn function. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region
int WINAPI GetWindowRgn(HWND hWnd, HRGN hRgn) {
  //TODO
  return 0;
}

//The GetWindowRgnBox function retrieves the dimensions of the tightest bounding rectangle for the window region of a window.
int WINAPI GetWindowRgnBox(HWND hWnd, LPRECT lprc) {
  //TODO
  return 0;
}

//The GrayString function draws gray text at the specified location. The function draws the text by copying it into a memory bitmap, graying the bitmap, and then copying the bitmap to the screen. The function grays the text regardless of the selected brush and background. GrayString uses the font currently selected for the specified device context.
//If thelpOutputFuncparameter is NULL, GDI uses the TextOut function, and thelpDataparameter is assumed to be a pointer to the character string to be output. If the characters to be output cannot be handled by TextOut (for example, the string is stored as a bitmap), the application must supply its own output function.
BOOL WINAPI GrayStringA(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight) {
  //TODO
  return 0;
}

//The GrayString function draws gray text at the specified location. The function draws the text by copying it into a memory bitmap, graying the bitmap, and then copying the bitmap to the screen. The function grays the text regardless of the selected brush and background. GrayString uses the font currently selected for the specified device context.
//If thelpOutputFuncparameter is NULL, GDI uses the TextOut function, and thelpDataparameter is assumed to be a pointer to the character string to be output. If the characters to be output cannot be handled by TextOut (for example, the string is stored as a bitmap), the application must supply its own output function.
BOOL WINAPI GrayStringW(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight) {
  //TODO
  return 0;
}

//The InvalidateRect function adds a rectangle to the specified window's update region. The update region represents the portion of the window's client area that must be redrawn.
BOOL WINAPI InvalidateRect(HWND hWnd, const RECT* lpRect, BOOL bErase) {
  //TODO
  return 0;
}

//The InvalidateRgn function invalidates the client area within the specified region by adding it to the current update region of a window. The invalidated region, along with all other areas in the update region, is marked for painting when the next WM_PAINT message occurs.
BOOL WINAPI InvalidateRgn(HWND hWnd, HRGN hRgn, BOOL bErase) {
  //TODO
  return 0;
}

//The LockWindowUpdate function disables or enables drawing in the specified window. Only one window can be locked at a time.
BOOL WINAPI LockWindowUpdate(HWND hWndLock) {
  //TODO
  return 0;
}

//The PaintDesktop function fills the clipping region in the specified device context with the desktop pattern or wallpaper. The function is provided primarily for shell desktops.
BOOL WINAPI PaintDesktop(HDC hdc) {
  //TODO
  return 0;
}

//The RedrawWindow function updates the specified rectangle or region in a window's client area.
BOOL WINAPI RedrawWindow(HWND hWnd, const RECT* lprcUpdate, HRGN hrgnUpdate, UINT flags) {
  //TODO
  return 0;
}

//The SetWindowRgn function sets the window region of a window. The window region determines the area within the window where the system permits drawing. The system does not display any portion of a window that lies outside of the window region
int WINAPI SetWindowRgn(HWND hWnd, HRGN hRgn, BOOL bRedraw) {
  //TODO
  return 0;
}

//The UpdateWindow function updates the client area of the specified window by sending a WM_PAINT message to the window if the window's update region is not empty. The function sends a WM_PAINT message directly to the window procedure of the specified window, bypassing the application queue. If the update region is empty, no message is sent.
BOOL WINAPI UpdateWindow(HWND hWnd) {
  //TODO
  return 0;
}

//The ValidateRect function validates the client area within a rectangle by removing the rectangle from the update region of the specified window.
BOOL WINAPI ValidateRect(HWND hWnd, const RECT* lpRect) {
  //TODO
  return 0;
}

//The ValidateRgn function validates the client area within a region by removing the region from the current update region of the specified window.
BOOL WINAPI ValidateRgn(HWND hWnd, HRGN hRgn) {
  //TODO
  return 0;
}

//The WindowFromDC function returns a handle to the window associated with the specified display device context (DC). Output functions that use the specified device context draw into this window.
HWND WINAPI WindowFromDC(HDC hDC) {
  //TODO
  return 0;
}
