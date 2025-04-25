#include <wingdi.h>

//The GdiFlush function flushes the calling thread's current batch.
BOOL WINAPI GdiFlush() {
  //TODO
  return 0;
}

//The GdiGetBatchLimit function returns the maximum number of function calls that can be accumulated in the calling thread's current batch. The system flushes the current batch whenever this limit is exceeded.
DWORD WINAPI GdiGetBatchLimit() {
  //TODO
  return 0;
}

//The GdiSetBatchLimit function sets the maximum number of function calls that can be accumulated in the calling thread's current batch. The system flushes the current batch whenever this limit is exceeded.
DWORD WINAPI GdiSetBatchLimit(DWORD dw) {
  //TODO
  return 0;
}

//The GetBkColor function returns the current background color for the specified device context.
COLORREF WINAPI GetBkColor(HDC hdc) {
  //TODO
  return 0;
}

//The GetBkMode function returns the current background mix mode for a specified device context. The background mix mode of a device context affects text, hatched brushes, and pen styles that are not solid lines.
int WINAPI GetBkMode(HDC hdc) {
  //TODO
  return 0;
}

//The GetBoundsRect function obtains the current accumulated bounding rectangle for a specified device context.
//The system maintains an accumulated bounding rectangle for each application. An application can retrieve and set this rectangle.
UINT WINAPI GetBoundsRect(HDC hdc, LPRECT lprect, UINT flags) {
  //TODO
  return 0;
}

//The GetROP2 function retrieves the foreground mix mode of the specified device context. The mix mode specifies how the pen or interior color and the color already on the screen are combined to yield a new color.
int WINAPI GetROP2(HDC hdc) {
  //TODO
  return 0;
}

//The SetBkColor function sets the current background color to the specified color value, or to the nearest physical color if the device cannot represent the specified color value.
COLORREF WINAPI SetBkColor(HDC hdc, COLORREF color) {
  //TODO
  return 0;
}

//The SetBkMode function sets the background mix mode of the specified device context. The background mix mode is used with text, hatched brushes, and pen styles that are not solid lines.
int WINAPI SetBkMode(HDC hdc, int mode) {
  //TODO
  return 0;
}

//The SetBoundsRect function controls the accumulation of bounding rectangle information for the specified device context. The system can maintain a bounding rectangle for all drawing operations. An application can examine and set this rectangle. The drawing boundaries are useful for invalidating bitmap caches.
UINT WINAPI SetBoundsRect(HDC hdc, const RECT* lprect, UINT flags) {
  //TODO
  return 0;
}

//The SetROP2 function sets the current foreground mix mode. GDI uses the foreground mix mode to combine pens and interiors of filled objects with the colors already on the screen. The foreground mix mode defines how colors from the brush or pen and the colors in the existing image are to be combined.
int WINAPI SetROP2(HDC hdc, int rop2) {
  //TODO
  return 0;
}
