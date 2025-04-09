#include <winuser.h>

LRESULT WINAPI CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

LRESULT WINAPI CallWindowProcW(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

LRESULT WINAPI DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO

  //Tutaj trzeba będzie domyślnie obsłużyć komunikaty przychodzące do okien
  //Na razie nie mamy żadnych, jakie tutaj trzeba obsłużyć

  //Tutaj obsłużymy np. komunikaty takie jak WM_SETTEXT, WM_GETTEXTLENGTH, WM_GETTEXT, itd

  return 0;
}

LRESULT WINAPI DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}
