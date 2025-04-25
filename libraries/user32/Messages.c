#include "winuser.h"
#include <X11/Xlib.h>
#include <stdio.h>

#include "display.h"

//Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.
//To receive additional information if the request is defined, use the BroadcastSystemMessageEx function.
long WINAPI BroadcastSystemMessage(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.
//To receive additional information if the request is defined, use the BroadcastSystemMessageEx function.
long WINAPI BroadcastSystemMessageA(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.
//To receive additional information if the request is defined, use the BroadcastSystemMessageEx function.
long WINAPI BroadcastSystemMessageW(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.
//This function is similar to BroadcastSystemMessage except that this function can return more information from the recipients.
long WINAPI BroadcastSystemMessageExA(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo) {
  //TODO
  return 0;
}

//Sends a message to the specified recipients. The recipients can be applications, installable drivers, network drivers, system-level device drivers, or any combination of these system components.
//This function is similar to BroadcastSystemMessage except that this function can return more information from the recipients.
long WINAPI BroadcastSystemMessageExW(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo) {
  //TODO
  return 0;
}

//Dispatches a message to a window procedure. It is typically used to dispatch a message retrieved by the GetMessage function.
LRESULT WINAPI DispatchMessage(const MSG* lpMsg) {
  //TODO: Ta funkcja ma za zadanie wywołać procedurę obsługi zdarzeń przypisaną do okna
  //Na razie de facto można pominąć

  return 0;
}

//Dispatches a message to a window procedure. It is typically used to dispatch a message retrieved by the GetMessage function.
LRESULT WINAPI DispatchMessageA(const MSG* lpMsg) {
  //TODO
  return 0;
}

//Dispatches a message to a window procedure. It is typically used to dispatch a message retrieved by the GetMessage function.
LRESULT WINAPI DispatchMessageW(const MSG* lpMsg) {
  //TODO
  return 0;
}

//Determines whether there are mouse-button or keyboard messages in the calling thread's message queue.
BOOL WINAPI GetInputState() {
  //TODO
  return 0;
}

//Retrieves a message from the calling thread's message queue. The function dispatches incoming sent messages until a posted message is available for retrieval.
//GetMessage functions like PeekMessage, however, GetMessage blocks until a message is posted before returning.
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

//Retrieves the extra message information for the current thread. Extra message information is an application- or driver-defined value associated with the current thread's message queue.
LPARAM WINAPI GetMessageExtraInfo() {
  //TODO
  return 0;
}

//Retrieves the cursor position for the last message retrieved by the GetMessage function.
//To determine the current position of the cursor, use the GetCursorPos function.
DWORD WINAPI GetMessagePos() {
  //TODO
  return 0;
}

//Retrieves the message time for the last message retrieved by the GetMessage function. The time is a long integer that specifies the elapsed time, in milliseconds, from the time the system was started to the time the message was created (that is, placed in the thread's message queue).
LONG WINAPI GetMessageTime() {
  //TODO
  return 0;
}

//Retrieves the type of messages found in the calling thread's message queue.
DWORD WINAPI GetQueueStatus(UINT flags) {
  //TODO
  return 0;
}

//Determines whether the current window procedure is processing a message that was sent from another thread (in the same process or a different process) by a call to the SendMessage function.
//To obtain additional information about how the message was sent, use the InSendMessageEx function.
BOOL WINAPI InSendMessage() {
  //TODO
  return 0;
}

//Determines whether the current window procedure is processing a message that was sent from another thread (in the same process or a different process).
DWORD WINAPI InSendMessageEx(LPVOID lpReserved) {
  //TODO
  return 0;
}

//Dispatches incoming nonqueued messages, checks the thread message queue for a posted message, and retrieves the message (if any exist).
BOOL WINAPI PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) {
  //TODO
  return 0;
}

//Dispatches incoming nonqueued messages, checks the thread message queue for a posted message, and retrieves the message (if any exist).
BOOL WINAPI PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg) {
  //TODO
  return 0;
}

//Places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message.
//To post a message in the message queue associated with a thread, use the PostThreadMessage function.
BOOL WINAPI PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Places (posts) a message in the message queue associated with the thread that created the specified window and returns without waiting for the thread to process the message.
//To post a message in the message queue associated with a thread, use the PostThreadMessage function.
BOOL WINAPI PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Indicates to the system that a thread has made a request to terminate (quit). It is typically used in response to a WM_DESTROY message.
void WINAPI PostQuitMessage(int nExitCode) {
  //TODO
}

//Posts a message to the message queue of the specified thread. It returns without waiting for the thread to process the message.
BOOL WINAPI PostThreadMessageA(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Posts a message to the message queue of the specified thread. It returns without waiting for the thread to process the message.
BOOL WINAPI PostThreadMessageW(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Defines a new window message that is guaranteed to be unique throughout the system. The message value can be used when sending or posting messages.
UINT WINAPI RegisterWindowMessageA(LPCSTR lpString) {
  //TODO
  return 0;
}

//Defines a new window message that is guaranteed to be unique throughout the system. The message value can be used when sending or posting messages.
UINT WINAPI RegisterWindowMessageW(LPCWSTR lpString) {
  //TODO
  return 0;
}

//Replies to a message sent from another thread by the SendMessage function.
BOOL WINAPI ReplyMessage(LRESULT lResult) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. The SendMessage function calls the window procedure for the specified window and does not return until the window procedure has processed the message.
//To send a message and return immediately, use the SendMessageCallback or SendNotifyMessage function. To post a message to a thread's message queue and return immediately, use the PostMessage or PostThreadMessage function.
LRESULT WINAPI SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. The SendMessage function calls the window procedure for the specified window and does not return until the window procedure has processed the message.
//To send a message and return immediately, use the SendMessageCallback or SendNotifyMessage function. To post a message to a thread's message queue and return immediately, use the PostMessage or PostThreadMessage function.
LRESULT WINAPI SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. The SendMessage function calls the window procedure for the specified window and does not return until the window procedure has processed the message.
//To send a message and return immediately, use the SendMessageCallback or SendNotifyMessage function. To post a message to a thread's message queue and return immediately, use the PostMessage or PostThreadMessage function.
LRESULT WINAPI SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. It calls the window procedure for the specified window and returns immediately if the window belongs to another thread. After the window procedure processes the message, the system calls the specified callback function, passing the result of the message processing and an application-defined value to the callback function.
BOOL WINAPI SendMessageCallbackA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpResultCallBack, ULONG_PTR dwData) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. It calls the window procedure for the specified window and returns immediately if the window belongs to another thread. After the window procedure processes the message, the system calls the specified callback function, passing the result of the message processing and an application-defined value to the callback function.
BOOL WINAPI SendMessageCallbackW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpResultCallBack, ULONG_PTR dwData) {
  //TODO
  return 0;
}

//Sends the specified message to one or more windows.
LRESULT WINAPI SendMessageTimeoutA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult) {
  //TODO
  return 0;
}

//Sends the specified message to one or more windows.
LRESULT WINAPI SendMessageTimeoutW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. If the window was created by the calling thread, SendNotifyMessage calls the window procedure for the window and does not return until the window procedure has processed the message. If the window was created by a different thread, SendNotifyMessage passes the message to the window procedure and returns immediately; it does not wait for the window procedure to finish processing the message.
BOOL WINAPI SendNotifyMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sends the specified message to a window or windows. If the window was created by the calling thread, SendNotifyMessage calls the window procedure for the window and does not return until the window procedure has processed the message. If the window was created by a different thread, SendNotifyMessage passes the message to the window procedure and returns immediately; it does not wait for the window procedure to finish processing the message.
BOOL WINAPI SendNotifyMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return 0;
}

//Sets the extra message information for the current thread. Extra message information is an application- or driver-defined value associated with the current thread's message queue. An application can use the GetMessageExtraInfo function to retrieve a thread's extra message information.
LPARAM WINAPI SetMessageExtraInfo(LPARAM lParam) {
  //TODO
  return 0;
}

//Translates virtual-key messages into character messages. The character messages are posted to the calling thread's message queue, to be read the next time the thread calls the GetMessage or PeekMessage function.
BOOL WINAPI TranslateMessage(const MSG* lpMsg) {
  //TODO: Ta funkcja przetwarza komunikaty związane z naciskaniem klawiszy
  //Na razie pomińmy

  return 0;
}

//Yields control to other threads when a thread has no other messages in its message queue. The WaitMessage function suspends the thread and does not return until a new message is placed in the thread's message queue.
BOOL WINAPI WaitMessage() {
  //TODO
  return 0;
}
