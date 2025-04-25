#include <wingdi.h>

#include <DC.h>

//TODO: Trzeba będzie chyba trzymać tam także pointer do displaya


//The Chord function draws a chord (a region bounded by the intersection of an ellipse and a line segment, called a secant). The chord is outlined by using the current pen and filled by using the current brush.
BOOL WINAPI Chord(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  //TODO
  return 0;
}

//The Ellipse function draws an ellipse. The center of the ellipse is the center of the specified bounding rectangle. The ellipse is outlined by using the current pen and is filled by using the current brush.
BOOL WINAPI Ellipse(HDC hdc, int left, int top, int right, int bottom) {
  //TODO
  return 0;
}

//The FillRect function fills a rectangle by using the specified brush. This function includes the left and top borders, but excludes the right and bottom borders of the rectangle.
int WINAPI FillRect(HDC hDC, const RECT* lprc, HBRUSH hbr) {
  //TODO: Wybrać kolor na podstawie (hbr)
  //Na razie przetestujmy, czy to w ogóle działa

  /*Display* display = defaultDisplay();

  DC* dc = (DC*)hDC;

  //Funkcje X11 wymagają podania okna, sam kontekst nie wystarczy
  //Trzeba będzie przechowywać okno oraz GC w jakiejś strukturze

  //XFillRectangle(display, )
  XFillRectangle(display, dc->window, dc->gc, lprc->left, lprc->top, lprc->right - lprc->left, lprc->bottom - lprc->top);*/

  return 1;
}

//The FrameRect function draws a border around the specified rectangle by using the specified brush. The width and height of the border are always one logical unit.
int WINAPI FrameRect(HDC hDC, const RECT* lprc, HBRUSH hbr) {
  //TODO
  return 0;
}

//The InvertRect function inverts a rectangle in a window by performing a logical NOT operation on the color values for each pixel in the rectangle's interior.
BOOL WINAPI InvertRect(HDC hDC, const RECT* lprc) {
  //TODO
  return 0;
}

//The Pie function draws a pie-shaped wedge bounded by the intersection of an ellipse and two radials. The pie is outlined by using the current pen and filled by using the current brush.
BOOL WINAPI Pie(HDC hdc, int left, int top, int right, int bottom, int xr1, int yr1, int xr2, int yr2) {
  //TODO
  return 0;
}

//The Polygon function draws a polygon consisting of two or more vertices connected by straight lines. The polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode.
BOOL WINAPI Polygon(HDC hdc, const POINT* apt, int cpt) {
  //TODO
  return 0;
}

//The PolyPolygon function draws a series of closed polygons. Each polygon is outlined by using the current pen and filled by using the current brush and polygon fill mode. The polygons drawn by this function can overlap.
BOOL WINAPI PolyPolygon(HDC hdc, const POINT* apt, const INT* asz, int csz) {
  //TODO
  return 0;
}

//The Rectangle function draws a rectangle. The rectangle is outlined by using the current pen and filled by using the current brush.
BOOL WINAPI Rectangle(HDC hdc, int left, int top, int right, int bottom) {
  //TODO
  return 0;
}

//The RoundRect function draws a rectangle with rounded corners. The rectangle is outlined by using the current pen and filled by using the current brush.
BOOL WINAPI RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height) {
  //TODO
  return 0;
}
