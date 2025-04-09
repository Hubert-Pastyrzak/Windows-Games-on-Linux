#include "winuser.h"
#include <X11/Xlib.h>
#include <stdio.h>

#include "display.h"

long WINAPI BroadcastSystemMessage(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

long WINAPI BroadcastSystemMessageA(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

long WINAPI BroadcastSystemMessageW(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

long WINAPI BroadcastSystemMessageExA(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo) {
  //TODO
  return 0;
}

long WINAPI BroadcastSystemMessageExW(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo) {
  //TODO
  return 0;
}

LRESULT WINAPI DispatchMessage(const MSG* lpMsg) {
  //TODO: Ta funkcja ma za zadanie wywołać procedurę obsługi zdarzeń przypisaną do okna
  //Na razie de facto można pominąć

  return 0;
}

LRESULT WINAPI DispatchMessageA(const MSG* lpMsg) {
  //TODO
  return 0;
}

LRESULT WINAPI DispatchMessageW(const MSG* lpMsg) {
  //TODO
  return 0;
}

BOOL WINAPI GetInputState() {
  //TODO
  return 0;
}

BOOL WINAPI GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) {
  //GetMessage czeka na event
  
  Display* display = defaultDisplay();

  printf("Before XNextEvent\n");

  XEvent event = {};
  XNextEvent(display, &event);

  printf("After XNextEvent\n");

  //TODO: Trzeba jakoś przechwycić event WM_QUIT
  //Tylko wtedy zwracamy 0

  return 1;
}

LPARAM WINAPI GetMessageExtraInfo() {
  //TODO
  return 0;
}

DWORD WINAPI GetMessagePos() {
  //TODO
  return 0;
}

LONG WINAPI GetMessageTime() {
  //TODO
  return 0;
}

DWORD WINAPI GetQueueStatus(UINT flags) {
  //TODO
  return 0;
}

BOOL WINAPI InSendMessage() {
  //TODO
  return 0;
}

DWORD WINAPI InSendMessageEx(LPVOID lpReserved) {
  //TODO
  return 0;
}

BOOL WINAPI PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) {
  //TODO
  return 0;
}

BOOL WINAPI PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) {
  //TODO
  return 0;
}

BOOL WINAPI PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

BOOL WINAPI PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

void WINAPI PostQuitMessage(int nExitCode) {
  //TODO
}

BOOL WINAPI PostThreadMessageA(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

BOOL WINAPI PostThreadMessageW(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

UINT WINAPI RegisterWindowMessageA(LPCSTR lpString) {
  //TODO
  return 0;
}

UINT WINAPI RegisterWindowMessageW(LPCWSTR lpString) {
  //TODO
  return 0;
}

BOOL WINAPI ReplyMessage(LRESULT lResult) {
  //TODO
  return 0;
}

LRESULT WINAPI SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

LRESULT WINAPI SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

LRESULT WINAPI SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

BOOL WINAPI SendMessageCallbackA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpResultCallBack, ULONG_PTR dwData) {
  //TODO
  return 0;
}

BOOL WINAPI SendMessageCallbackW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpResultCallBack, ULONG_PTR dwData) {
  //TODO
  return 0;
}

LRESULT WINAPI SendMessageTimeoutA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult) {
  //TODO
  return 0;
}

LRESULT WINAPI SendMessageTimeoutW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult) {
  //TODO
  return 0;
}

BOOL WINAPI SendNotifyMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

BOOL WINAPI SendNotifyMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

LPARAM WINAPI SetMessageExtraInfo(LPARAM lParam) {
  //TODO
  return 0;
}

BOOL WINAPI TranslateMessage(const MSG* lpMsg) {
  //TODO: Ta funkcja przetwarza komunikaty związane z naciskaniem klawiszy
  //Na razie pomińmy

  return 0;
}

BOOL WINAPI WaitMessage() {
  //TODO
  return 0;
}
