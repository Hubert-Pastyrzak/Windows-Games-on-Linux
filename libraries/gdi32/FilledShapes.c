#include <wingdi.h>

#include <DC.h>

//TODO: Trzeba będzie chyba trzymać tam także pointer do displaya


BOOL WINAPI Chord(HDC hdc, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  //TODO
  return 0;
}

BOOL WINAPI Ellipse(HDC hdc, int left, int top, int right, int bottom) {
  //TODO
  return 0;
}

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

int WINAPI FrameRect(HDC hDC, const RECT* lprc, HBRUSH hbr) {
  //TODO
  return 0;
}

BOOL WINAPI InvertRect(HDC hDC, const RECT* lprc) {
  //TODO
  return 0;
}

BOOL WINAPI Pie(HDC hdc, int left, int top, int right, int bottom, int xr1, int yr1, int xr2, int yr2) {
  //TODO
  return 0;
}

BOOL WINAPI Polygon(HDC hdc, const POINT* apt, int cpt) {
  //TODO
  return 0;
}

BOOL WINAPI PolyPolygon(HDC hdc, const POINT* apt, const INT* asz, int csz) {
  //TODO
  return 0;
}

BOOL WINAPI Rectangle(HDC hdc, int left, int top, int right, int bottom) {
  //TODO
  return 0;
}

BOOL WINAPI RoundRect(HDC hdc, int left, int top, int right, int bottom, int width, int height) {
  //TODO
  return 0;
}
