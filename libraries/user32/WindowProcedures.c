#include <winuser.h>

//Passes message information to the specified window procedure.
LRESULT WINAPI CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Passes message information to the specified window procedure.
LRESULT WINAPI CallWindowProcW(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. DefWindowProc is called with the same parameters received by the window procedure.
LRESULT WINAPI DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO

  //Tutaj trzeba będzie domyślnie obsłużyć komunikaty przychodzące do okien
  //Na razie nie mamy żadnych, jakie tutaj trzeba obsłużyć

  //Tutaj obsłużymy np. komunikaty takie jak WM_SETTEXT, WM_GETTEXTLENGTH, WM_GETTEXT, itd

  return 0;
}

//Calls the default window procedure to provide default processing for any window messages that an application does not process. This function ensures that every message is processed. DefWindowProc is called with the same parameters received by the window procedure.
LRESULT WINAPI DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}
