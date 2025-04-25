#include <winuser.h>
#include <X11/Xlib.h>
#include <stdlib.h>

#include "display.h"
#include "window.h"



//TODO: Pojawia się pierwszy problem: Czy uchwyt do okna może być zwykłą konwersją z Linuxowego Window na HWND?

//Na razie w sumie jakieś tam tworzenie okien działa
//Teraz trzeba dokończyć implementację pozostałych funkcji od klas okien



//Calculates the required size of the window rectangle, based on the desired client-rectangle size. The window rectangle can then be passed to the CreateWindow function to create a window whose client area is the desired size.
//To specify an extended window style, use the AdjustWindowRectEx function.
BOOL WINAPI AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu) {
  //TODO: Trzeba uwzględnić menu, itd
  //Tak to raczej pozostaje niezmienne, bo pod Linuxem wymiary dotyczą obszaru klienta

  return 1;
}

//Calculates the required size of the window rectangle, based on the desired size of the client rectangle. The window rectangle can then be passed to the CreateWindowEx function to create a window whose client area is the desired size.
BOOL WINAPI AdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle) {
  //TODO: To samo co wyżej
  return 1;
}

//Enables the specified process to set the foreground window using the SetForegroundWindow function. The calling process must already be able to set the foreground window. For more information, see Remarks later in this topic.
BOOL WINAPI AllowSetForegroundWindow(DWORD dwProcessId) {
  //TODO
  return 0;
}

//Enables you to produce special effects when showing or hiding windows. There are four types of animation: roll, slide, collapse or expand, and alpha-blended fade.
BOOL WINAPI AnimateWindow(HWND hWnd, DWORD dwTime, DWORD dwFlags) {
  //TODO
  return 0;
}

//Indicates whether an owned, visible, top-level pop-up, or overlapped window exists on the screen. The function searches the entire screen, not just the calling application's client area.
//This function is provided only for compatibility with 16-bit versions of Windows. It is generally not useful.
BOOL WINAPI AnyPopup() {
  //TODO
  return 0;
}

//Arranges all the minimized (iconic) child windows of the specified parent window.
UINT WINAPI ArrangeIconicWindows(HWND hWnd) {
  //TODO
  return 0;
}

//Allocates memory for a multiple-window- position structure and returns the handle to the structure.
HDWP WINAPI BeginDeferWindowPos(int nNumWindows) {
  //TODO
  return 0;
}

//Brings the specified window to the top of the Z order. If the window is a top-level window, it is activated. If the window is a child window, the top-level parent window associated with the child window is activated.
BOOL WINAPI BringWindowToTop(HWND hWnd) {
  //TODO
  return 0;
}

//Calculates an appropriate pop-up window position using the specified anchor point, pop-up window size, flags, and the optional exclude rectangle. When the specified pop-up window size is smaller than the desktop window size, use the CalculatePopupWindowPosition function to ensure that the pop-up window is fully visible on the desktop window, regardless of the specified anchor point.
BOOL WINAPI CalculatePopupWindowPosition(const POINT* anchorPoint, const SIZE* windowSize, UINT flags, RECT* excludeRect, RECT* popupWindowPosition) {
  //TODO
  return 0;
}

//Cascades the specified child windows of the specified parent window.
WORD WINAPI CascadeWindows(HWND hwndParent, UINT wHow, const RECT* lpRect, UINT cKids, const HWND* lpKids) {
  //TODO
  return 0;
}

//[Using the ChangeWindowMessageFilter function is not recommended, as it has process-wide scope. Instead, use the ChangeWindowMessageFilterEx function to control access to specific windows as needed. ChangeWindowMessageFilter may not be supported in future versions of Windows.]
//Adds or removes a message from the User Interface Privilege Isolation (UIPI) message filter.
BOOL WINAPI ChangeWindowMessageFilter(UINT message, DWORD dwFlag) {
  //TODO
  return 0;
}

//Modifies the User Interface Privilege Isolation (UIPI) message filter for a specified window.
BOOL WINAPI ChangeWindowMessageFilterEx(HWND hwnd, UINT message, DWORD action, PCHANGEFILTERSTRUCT pChangeFilterStruct) {
  //TODO
  return 0;
}

//Determines which, if any, of the child windows belonging to a parent window contains the specified point. The search is restricted to immediate child windows. Grandchildren, and deeper descendant windows are not searched.
//To skip certain child windows, use the ChildWindowFromPointEx function.
HWND WINAPI ChildWindowFromPoint(HWND hWndParent, POINT Point) {
  //TODO: Podobnie jak WindowFromPoint, ale względem rodzica

  return 0;
}

//Determines which, if any, of the child windows belonging to the specified parent window contains the specified point. The function can ignore invisible, disabled, and transparent child windows. The search is restricted to immediate child windows. Grandchildren and deeper descendants are not searched.
HWND WINAPI ChildWindowFromPointEx(HWND hwnd, POINT pt, UINT flags) {
  //TODO: Podobnie jak ChildWindowFromPoint

  return 0;
}

//Minimizes (but does not destroy) the specified window.
BOOL WINAPI CloseWindow(HWND hWnd) {
  //TODO
  return 0;
}

//Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the CreateWindow function. For more information about creating a window and for full descriptions of the other parameters of CreateWindowEx, see CreateWindow.
HWND WINAPI CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) {
  //TODO: dwExStyle może zawierać dodatkowe klasy, które będziemy chcieli obsłużyć też
  //Na razie to zignorujmy
  
  //Tutaj pobieramy informacje o klasie
  WNDCLASSEXA wcx = {};
  if (!GetClassInfoExA(hInstance, lpClassName, &wcx)) {
    return 0;
  }

  //TODO: Trzeba przypisać adres procedury obsługi zdarzeń do okna


  Display* display = defaultDisplay();

  //Domyślnie na razie przyjmijmy biały jako kolor tła

  //TODO: Trzeba jakoś ustalić domyślne wartości, na razie wrzucimy tam byle co
  int x = (X == CW_USEDEFAULT) ? 0 : X;
  int y = (Y == CW_USEDEFAULT) ? 0 : Y;
  int width = (nWidth == CW_USEDEFAULT) ? 800 : ((nWidth == 0) ? 800 : nWidth);
  int height = (nHeight == CW_USEDEFAULT) ? 600 : ((nHeight == 0) ? 600 : nHeight);

  //Co w przypadku, gdy np. nWidth lub nHeight jest równe zero? Czy funkcja Windowsowa wtedy się wykrzaczy?

  //hWndParent
  HWND parentWindow = (hWndParent) ? hWndParent : GetDesktopWindow();

  UserWindow* userWindow = (UserWindow*)malloc(sizeof(UserWindow) + wcx.cbWndExtra);

  userWindow->window = XCreateSimpleWindow(display, (Window)parentWindow, x, y, width, height, 0, 0, 0xFFFFFFFF);
  
  //TODO: userWindow->lpwcx
  //Hmm, trzeba będzie się jakoś dostać bezpośrednio do tego rejestru klas, inaczej nie ma opcji, żeby tutaj wpakować ten oryginalny pointer
  
  userWindow->cbWndExtra = wcx.cbWndExtra;
  userWindow->dwExStyle = dwExStyle;
  userWindow->hInstance = wcx.hInstance;
  userWindow->hWndParent = hWndParent;
  //TODO: ID
  userWindow->dwStyle = dwStyle;
  //TODO: User data
  userWindow->lpfnWndProc = wcx.lpfnWndProc;

  //TODO: Menu aplikacji - hMenu

  //hInstance pewnie będzie używane tylko przy wyszukiwaniu klasy

  //Na razie ostatni parametr jest NULLem, on wskazuje na dane użytkownika
  //Trzeba będzie ustalić, czy w X11 da się jakoś do okna przekazać taką wartość
  //Jak nie, to stworzymy strukturę

  //lpWindowName jest tytułem okna
  XStoreName(display, userWindow->window, lpWindowName);
  XFlush(display);

  if (dwStyle & WS_VISIBLE) {
    //TODO: Czy dla WS_VISIBLE używane jest SW_SHOW?
    ShowWindow((HWND)userWindow, SW_SHOW);
  }

  //dwStyle to styl okna
  //Przeważnie używany jest WS_OVERLAPPEDWINDOW, ale trzeba będzie też obsłużyć inne
  //Jeśli ustawiony jest styl WS_OVERLAPPEDWINDOW, to właściwie nic więcej z oknem nie musimy robić

  //TODO: Obsłużyć różne style okien

  //TODO: Docelowo może być konieczne zaalokowanie bufora w pamięci na informacje o oknie
  //Na razie wystarczy zwykła konwersja identyfikatora na uchwyt
  //XFlush(display);
  return (HWND)userWindow;
}

//Creates an overlapped, pop-up, or child window with an extended window style; otherwise, this function is identical to the CreateWindow function. For more information about creating a window and for full descriptions of the other parameters of CreateWindowEx, see CreateWindow.
HWND WINAPI CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) {
  //TODO
  return 0;
}

//Updates the specified multiple-window – position structure for the specified window. The function then returns a handle to the updated structure. The EndDeferWindowPos function uses the information in this structure to change the position and size of a number of windows simultaneously. The BeginDeferWindowPos function creates the structure.
HDWP WINAPI DeferWindowPos(HDWP hWinPosInfo, HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

//[This function is not intended for general use. It may be altered or unavailable in subsequent versions of Windows.]
//Unregisters a specified Shell window that is registered to receive Shell hook messages.
BOOL WINAPI DeregisterShellHookWindow(HWND hwnd) {
  //TODO
  return 0;
}

//Destroys the specified window. The function sends WM_DESTROY and WM_NCDESTROY messages to the window to deactivate it and remove the keyboard focus from it. The function also destroys the window's menu, destroys timers, removes clipboard ownership, and breaks the clipboard viewer chain (if the window is at the top of the viewer chain).
//If the specified window is a parent or owner window, DestroyWindow automatically destroys the associated child or owned windows when it destroys the parent or owner window. The function first destroys child or owned windows, and then it destroys the parent or owner window.
//DestroyWindow also destroys modeless dialog boxes created by the CreateDialog function.
BOOL WINAPI DestroyWindow(HWND hWnd) {
  //TODO
  return 0;
}

//Simultaneously updates the position and size of one or more windows in a single screen-refreshing cycle.
BOOL WINAPI EndDeferWindowPos(HDWP hWinPosInfo) {
  //TODO
  return 0;
}

//[This function is not intended for general use. It may be altered or unavailable in subsequent versions of Windows.]
//Forcibly closes the specified window.
BOOL WINAPI EndTask(HWND hWnd, BOOL fShutDown, BOOL fForce) {
  //TODO
  return 0;
}

//Enumerates the child windows that belong to the specified parent window by passing the handle to each child window, in turn, to an application-defined callback function. EnumChildWindows continues until the last child window is enumerated or the callback function returns FALSE.
BOOL WINAPI EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam) {
  //TODO
  return 0;
}

//Enumerates all nonchild windows associated with a thread by passing the handle to each window, in turn, to an application-defined callback function. EnumThreadWindows continues until the last window is enumerated or the callback function returns FALSE. To enumerate child windows of a particular window, use the EnumChildWindows function.
BOOL WINAPI EnumThreadWindows(DWORD dwThreadId, WNDENUMPROC lpfn, LPARAM lParam) {
  //TODO: Wyenumerować okna należące do danego wątku

  return 0;
}

//Enumerates all top-level windows on the screen by passing the handle to each window, in turn, to an application-defined callback function. EnumWindows continues until the last top-level window is enumerated or the callback function returns FALSE.
BOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam) {
  //TODO: Wyenumerować okna
  return 0;
}

//Retrieves a handle to the top-level window whose class name and window name match the specified strings. This function does not search child windows. This function does not perform a case-sensitive search.
//To search child windows, beginning with a specified child window, use the FindWindowEx function.
HWND WINAPI FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName) {
  //TODO: Znaleźć okno po nazwie klasy lub tytule
  return 0;
}

//Retrieves a handle to the top-level window whose class name and window name match the specified strings. This function does not search child windows. This function does not perform a case-sensitive search.
//To search child windows, beginning with a specified child window, use the FindWindowEx function.
HWND WINAPI FindWindowW(LPCWSTR lpClassName, LPCWSTR lpWindowName) {
  //TODO
  return 0;
}

//Retrieves a handle to a window whose class name and window name match the specified strings. The function searches child windows, beginning with the one following the specified child window. This function does not perform a case-sensitive search.
HWND WINAPI FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow) {
  //TODO: Podobnie jak FindWindow
  return 0;
}

//Retrieves a handle to a window whose class name and window name match the specified strings. The function searches child windows, beginning with the one following the specified child window. This function does not perform a case-sensitive search.
HWND WINAPI FindWindowExW(HWND hWndParent, HWND hWndChildAfter, LPCWSTR lpszClass, LPCWSTR lpszWindow) {
  //TODO
  return 0;
}

//Retrieves status information for the specified window if it is the application-switching (ALT+TAB) window.
BOOL WINAPI GetAltTabInfoA(HWND hwnd, int iItem, PALTTABINFO pati, LPSTR pszItemText, UINT cchItemText) {
  //TODO
  return 0;
}

//Retrieves status information for the specified window if it is the application-switching (ALT+TAB) window.
BOOL WINAPI GetAltTabInfoW(HWND hwnd, int iItem, PALTTABINFO pati, LPWSTR pszItemText, UINT cchItemText) {
  //TODO
  return 0;
}

//Retrieves the handle to the ancestor of the specified window.
HWND WINAPI GetAncestor(HWND hwnd, UINT gaFlags) {
  //TODO
  return 0;
}

//Retrieves the coordinates of a window's client area. The client coordinates specify the upper-left and lower-right corners of the client area. Because client coordinates are relative to the upper-left corner of a window's client area, the coordinates of the upper-left corner are (0,0).
BOOL WINAPI GetClientRect(HWND hWnd, LPRECT lpRect) {
  //TODO
  return 0;
}

//Retrieves a handle to the desktop window. The desktop window covers the entire screen. The desktop window is the area on top of which other windows are painted.
HWND WINAPI GetDesktopWindow() {
  Display* display = defaultDisplay();
  return (HWND)XDefaultRootWindow(display);
}

//Retrieves a handle to the foreground window (the window with which the user is currently working). The system assigns a slightly higher priority to the thread that creates the foreground window than it does to other threads.
HWND WINAPI GetForegroundWindow() {
  //TODO
  return 0;
}

//Retrieves information about the active window or a specified GUI thread.
BOOL WINAPI GetGUIThreadInfo(DWORD idThread, PGUITHREADINFO pgui) {
  //TODO
  return 0;
}

//Determines which pop-up window owned by the specified window was most recently active.
HWND WINAPI GetLastActivePopup(HWND hWnd) {
  //TODO
  return 0;
}

//Retrieves the opacity and transparency color key of a layered window.
BOOL WINAPI GetLayeredWindowAttributes(HWND hwnd, COLORREF* pcrKey, BYTE* pbAlpha, DWORD* pdwFlags) {
  //TODO
  return 0;
}

//Retrieves a handle to the specified window's parent or owner.
//To retrieve a handle to a specified ancestor, use the GetAncestor function.
HWND WINAPI GetParent(HWND hWnd) {
  //TODO
  return 0;
}

//Retrieves the default layout that is used when windows are created with no parent or owner.
BOOL WINAPI GetProcessDefaultLayout(DWORD* pdwDefaultLayout) {
  //TODO
  return 0;
}

//Retrieves a handle to the Shell's desktop window.
HWND WINAPI GetShellWindow() {
  //TODO
  return 0;
}

//Retrieves the current color of the specified display element. Display elements are the parts of a window and the display that appear on the system display screen.
DWORD WINAPI GetSysColor(int nIndex) {
  //TODO
  return 0;
}

//Retrieves information about the specified title bar.
BOOL WINAPI GetTitleBarInfo(HWND hwnd, PTITLEBARINFO pti) {
  //TODO
  return 0;
}

//Examines the Z order of the child windows associated with the specified parent window and retrieves a handle to the child window at the top of the Z order.
HWND WINAPI GetTopWindow(HWND hWnd) {
  //TODO
  return 0;
}

//Retrieves a handle to a window that has the specified relationship (Z-Order or owner) to the specified window.
HWND WINAPI GetWindow(HWND hWnd, UINT uCmd) {
  //TODO
  return 0;
}

//Retrieves the current display affinity setting, from any process, for a given window.
BOOL WINAPI GetWindowDisplayAffinity(HWND hWnd, DWORD* pdwAffinity) {
  //TODO
  return 0;
}

//Retrieves information about the specified window.
BOOL WINAPI GetWindowInfo(HWND hwnd, PWINDOWINFO pwi) {
  //TODO
  return 0;
}

//Retrieves the full path and file name of the module associated with the specified window handle.
UINT WINAPI GetWindowModuleFileNameA(HWND hwnd, LPSTR pszFileName, UINT cchFileNameMax) {
  //TODO
  return 0;
}

//Retrieves the full path and file name of the module associated with the specified window handle.
UINT WINAPI GetWindowModuleFileNameW(HWND hwnd, LPWSTR pszFileName, UINT cchFileNameMax) {
  //TODO
  return 0;
}

//Retrieves the show state and the restored, minimized, and maximized positions of the specified window.
BOOL WINAPI GetWindowPlacement(HWND hWnd, WINDOWPLACEMENT* lpwndpl) {
  //TODO
  return 0;
}

//Retrieves the dimensions of the bounding rectangle of the specified window. The dimensions are given in screen coordinates that are relative to the upper-left corner of the screen.
BOOL WINAPI GetWindowRect(HWND hWnd, LPRECT lpRect) {
  //TODO
  return 0;
}

//Copies the text of the specified window's title bar (if it has one) into a buffer. If the specified window is a control, the text of the control is copied. However, GetWindowText cannot retrieve the text of a control in another application.
int WINAPI GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount) {
  //TODO: Wysłać komunikat WM_GETTEXT

  return 0;
}

//Copies the text of the specified window's title bar (if it has one) into a buffer. If the specified window is a control, the text of the control is copied. However, GetWindowText cannot retrieve the text of a control in another application.
int WINAPI GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount) {
  //TODO
  return 0;
}

//Retrieves the length, in characters, of the specified window's title bar text (if the window has a title bar). If the specified window is a control, the function retrieves the length of the text within the control. However, GetWindowTextLength cannot retrieve the length of the text of an edit control in another application.
int WINAPI GetWindowTextLengthA(HWND hWnd) {
  //TODO: Wysłać komunikat WM_GETTEXTLENGTH do okna

  return 0;
}

//Retrieves the length, in characters, of the specified window's title bar text (if the window has a title bar). If the specified window is a control, the function retrieves the length of the text within the control. However, GetWindowTextLength cannot retrieve the length of the text of an edit control in another application.
int WINAPI GetWindowTextLengthW(HWND hWnd) {
  //TODO
  return 0;
}

//Retrieves the identifier of the thread that created the specified window and, optionally, the identifier of the process that created the window.
DWORD WINAPI GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId) {
  //TODO: Pobrać identyfikator procesu oraz wątku, do których dane okno należy
  return 0;
}

//[This function is not intended for general use. It may be altered or unavailable in subsequent versions of Windows.]
//Copies the text of the specified window's title bar (if it has one) into a buffer.
//This function is similar to the GetWindowText function. However, it obtains the window text directly from the window structure associated with the specified window's handle and then always provides the text as a Unicode string. This is unlike GetWindowText which obtains the text by sending the window a WM_GETTEXT message. If the specified window is a control, the text of the control is obtained.
int WINAPI InternalGetWindowText(HWND hWnd, LPWSTR pString, int cchMaxCount) {
  //TODO
  return 0;
}

//Determines whether a window is a child window or descendant window of a specified parent window. A child window is the direct descendant of a specified parent window if that parent window is in the chain of parent windows; the chain of parent windows leads from the original overlapped or pop-up window to the child window.
BOOL WINAPI IsChild(HWND hWndParent, HWND hWnd) {
  //TODO
  return 0;
}

//Determines whether the calling thread is already a GUI thread. It can also optionally convert the thread to a GUI thread.
BOOL WINAPI IsGUIThread(BOOL bConvert) {
  //TODO
  return 0;
}

//[This function is not intended for general use. It may be altered or unavailable in subsequent versions of Windows.]
//Determines whether the system considers that a specified application is not responding. An application is considered to be not responding if it is not waiting for input, is not in startup processing, and has not called PeekMessage within the internal timeout period of 5 seconds.
BOOL WINAPI IsHungAppWindow(HWND hwnd) {
  //TODO
  return 0;
}

//Determines whether the specified window is minimized (iconic).
BOOL WINAPI IsIconic(HWND hWnd) {
  //TODO
  return 0;
}

//[IsProcessDPIAware is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use GetProcessDPIAwareness.]
//Determines whether the current process is dots per inch (dpi) aware such that it adjusts the sizes of UI elements to compensate for the dpi setting.
BOOL WINAPI IsProcessDPIAware() {
  //TODO
  return 0;
}

//Determines whether the specified window handle identifies an existing window.
BOOL WINAPI IsWindow(HWND hWnd) {
  //TODO: Trzeba sprawdzić, czy dany uchwyt jest uchwytem do okna
  //Najlepiej by było zrobić faktycznie tę strukturę i trzymać takie dane wewnątrz

  return 0;
}

//Determines whether the specified window is a native Unicode window.
BOOL WINAPI IsWindowUnicode(HWND hWnd) {
  //TODO: Trzeba sprawdzić, czy dane okno zostało zarejestrowane przy użyciu klasy Unicode

  return 0;
}

//Determines the visibility state of the specified window.
BOOL WINAPI IsWindowVisible(HWND hWnd) {
  //TODO
  return 0;
}

//Determines whether a window is maximized.
BOOL WINAPI IsZoomed(HWND hWnd) {
  //TODO
  return 0;
}

//The foreground process can call the LockSetForegroundWindow function to disable calls to the SetForegroundWindow function.
BOOL WINAPI LockSetForegroundWindow(UINT uLockCode) {
  //TODO
  return 0;
}

//Converts the logical coordinates of a point in a window to physical coordinates.
BOOL WINAPI LogicalToPhysicalPoint(HWND hWnd, LPPOINT lpPoint) {
  //TODO
  return 0;
}

//Changes the position and dimensions of the specified window. For a top-level window, the position and dimensions are relative to the upper-left corner of the screen. For a child window, they are relative to the upper-left corner of the parent window's client area.
BOOL WINAPI MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint) {
  //TODO
  return 0;
}

//Restores a minimized (iconic) window to its previous size and position; it then activates the window.
BOOL WINAPI OpenIcon(HWND hWnd) {
  //TODO
  return 0;
}

//Converts the physical coordinates of a point in a window to logical coordinates.
BOOL WINAPI PhysicalToLogicalPoint(HWND hWnd, LPPOINT lpPoint) {
  //TODO
  return 0;
}

//Retrieves a handle to the child window at the specified point. The search is restricted to immediate child windows; grandchildren and deeper descendant windows are not searched.
HWND WINAPI RealChildWindowFromPoint(HWND hwndParent, POINT ptParentClientCoords) {
  //TODO
  return 0;
}

//Retrieves a string that specifies the window type.
UINT WINAPI RealGetWindowClassA(HWND hwnd, LPSTR ptszClassName, UINT cchClassNameMax) {
  //TODO
  return 0;
}

//Retrieves a string that specifies the window type.
UINT WINAPI RealGetWindowClassW(HWND hwnd, LPWSTR ptszClassName, UINT cchClassNameMax) {
  //TODO
  return 0;
}

//[This function is not intended for general use. It may be altered or unavailable in subsequent versions of Windows.]
//Registers a specified Shell window to receive certain messages for events or notifications that are useful to Shell applications.
//The event messages received are only those sent to the Shell window associated with the specified window's desktop. Many of the messages are the same as those that can be received after calling the SetWindowsHookEx function and specifying WH_SHELL for the hook type. The difference with RegisterShellHookWindow is that the messages are received through the specified window's WindowProc and not through a call back procedure.
BOOL WINAPI RegisterShellHookWindow(HWND hwnd) {
  //TODO
  return 0;
}

//Brings the thread that created the specified window into the foreground and activates the window. Keyboard input is directed to the window, and various visual cues are changed for the user. The system assigns a slightly higher priority to the thread that created the foreground window than it does to other threads.
BOOL WINAPI SetForegroundWindow(HWND hWnd) {
  //TODO
  return 0;
}

//Sets the opacity and transparency color key of a layered window.
BOOL WINAPI SetLayeredWindowAttributes(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags) {
  //TODO
  return 0;
}

//Changes the parent window of the specified child window.
HWND WINAPI SetParent(HWND hWndChild, HWND hWndNewParent) {
  //TODO
  return 0;
}

//Changes the default layout when windows are created with no parent or owner only for the currently running process.
BOOL WINAPI SetProcessDefaultLayout(DWORD dwDefaultLayout) {
  //TODO
  return 0;
}

//Sets the process-default DPI awareness to system-DPI awareness. This is equivalent to calling SetProcessDpiAwarenessContext with a DPI_AWARENESS_CONTEXT value of DPI_AWARENESS_CONTEXT_SYSTEM_AWARE.
BOOL WINAPI SetProcessDPIAware() {
  //TODO
  return 0;
}

//Sets the colors for the specified display elements. Display elements are the various parts of a window and the display that appear on the system display screen.
BOOL WINAPI SetSysColors(int cElements, const INT* lpaElements, const COLORREF* lpaRgbValues) {
  //TODO
  return 0;
}

//Specifies where the content of the window can be displayed.
BOOL WINAPI SetWindowDisplayAffinity(HWND hWnd, DWORD dwAffinity) {
  //TODO
  return 0;
}

BOOL WINAPI SetWindowFeedbackSettings(HWND hwnd, FEEDBACK_TYPE feedback, DWORD flags, UINT32 size, const VOID* configuration) {
  //TODO
  return 0;
}

//Sets the show state and the restored, minimized, and maximized positions of the specified window.
BOOL WINAPI SetWindowPlacement(HWND hWnd, const WINDOWPLACEMENT* lpwndpl) {
  //TODO
  return 0;
}

//Changes the size, position, and Z order of a child, pop-up, or top-level window. These windows are ordered according to their appearance on the screen. The topmost window receives the highest rank and is the first window in the Z order.
BOOL WINAPI SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

//Changes the text of the specified window's title bar (if it has one). If the specified window is a control, the text of the control is changed. However, SetWindowText cannot change the text of a control in another application.
BOOL WINAPI SetWindowTextA(HWND hWnd, LPCSTR lpString) {
  //TODO: Rzekomo ta funkcja działa tylko na okna, których właścicielem jest aktualny proces
  //Czy wtedy zostanie zwrócone FALSE?
  
  //Display* display = defaultDisplay();
  //XStoreName(display, (Window)hWnd, lpString);

  //TODO: Trzeba wysłać komunikat WM_SETTEXT do okna
  //Trzeba uwzględnić także to, że rzekomo tabulatory są wyświetlane jako "|"

  return 1;
}

//Changes the text of the specified window's title bar (if it has one). If the specified window is a control, the text of the control is changed. However, SetWindowText cannot change the text of a control in another application.
BOOL WINAPI SetWindowTextW(HWND hWnd, LPCWSTR lpString) {
  //TODO
  return 0;
}

//Shows or hides all pop-up windows owned by the specified window.
BOOL WINAPI ShowOwnedPopups(HWND hWnd, BOOL fShow) {
  //TODO
  return 0;
}

//Sets the specified window's show state.
BOOL WINAPI ShowWindow(HWND hWnd, int nCmdShow) {
  //TODO: Rzekomo przy pierwszym wywołaniu do ShowWindow, jeśli dostępna jest jakaś struktura STARTUPINFO, to parametr nCmdShow jest ignorowany
  //Trzeba to zbadać

  //TODO: Trzeba jakoś zwrócić informację, czy okno było wcześniej widoczne
  //Na razie nie jest to istotne, i przyjmijmy, że nie było

  Display* display = defaultDisplay();
  UserWindow* userWindow = (UserWindow*)hWnd;

  if (nCmdShow == SW_HIDE) {
    XUnmapWindow(display, userWindow->window);
    XFlush(display);

    return 0;
  }

  if (nCmdShow == SW_SHOWNORMAL) {
    XMapWindow(display, userWindow->window);
    XFlush(display);

    return 0;
  }

  if (nCmdShow == SW_SHOWNORMAL) {
    //TODO: Jeśli okno jest zminimalizowane, zmaksymalizowane, lub "arranged", to trzeba je przywrócić do pierwotnych wymiarów

    XMapWindow(display, userWindow->window);
    XFlush(display);
    
    return 0;
  }

  if (nCmdShow == SW_SHOWMINIMIZED) {
    XMapWindow(display, userWindow->window);

    //TODO: Zminimalizować okno

    XFlush(display);

    return 0;
  }

  if (nCmdShow == SW_SHOWMAXIMIZED) {
    XMapWindow(display, userWindow->window);

    //TODO: Zmaksymalizować okno

    XFlush(display);

    return 0;
  }

  if (nCmdShow == SW_SHOWNOACTIVATE) {
    XMapWindow(display, userWindow->window);

    //TODO: Czy da się wyświetlić okno nie aktywując go?
    //Jak nie, to może po prostu aktywowanie poprzednio aktywnego okna?

    XFlush(display);

    return 0;
  }

  //TODO: Do przetestowania, czy to pozostawia okno np. w zminimalizowanym stanie
  if (nCmdShow == SW_SHOW) {
    XMapWindow(display, userWindow->window);
    XFlush(display);

    return 0;
  }

  if (nCmdShow == SW_MINIMIZE) {
    //TODO: Minimalizacja okna

    return 0;
  }

  if (nCmdShow == SW_SHOWMINNOACTIVE) {
    XMapWindow(display, userWindow->window);
    XFlush(display);

    //TODO: Minimalizacja, ale bez aktywacji okna? Co??

    return 0;
  }

  if (nCmdShow == SW_SHOWNA) {
    XMapWindow(display, userWindow->window);
    XFlush(display);

    //TODO: Bez aktywacji okna

    return 0;
  }

  if (nCmdShow == SW_RESTORE) {
    //TODO: Co to robi?!
  }

  if (nCmdShow == SW_SHOWDEFAULT) {
    //TODO: Pobrać informacje ze struktury STARTUPINFO
    //Na razie tej struktury nie mamy

    return 0;
  }

  if (nCmdShow == SW_FORCEMINIMIZE) {
    //TODO: Zminimalizować okno na siłę, nawet jeśli wątek posiadający to okno nie odpowiada
    //Ciekawe, czy pod Linuxem się to będzie z czymś wiązało

    return 0;
  }

  return 0;
}

//Sets the show state of a window without waiting for the operation to complete.
BOOL WINAPI ShowWindowAsync(HWND hWnd, int nCmdShow) {
  //TODO: Wyświetlić/ukryć okno asynchronicznie

  return 0;
}

//Triggers a visual signal to indicate that a sound is playing.
BOOL WINAPI SoundSentry() {
  //TODO
  return 0;
}

//[This function is not intended for general use. It may be altered or unavailable in subsequent versions of Windows.]
//Switches focus to the specified window and brings it to the foreground.
void WINAPI SwitchToThisWindow(HWND hwnd, BOOL fUnknown) {
  //TODO
}

//Tiles the specified child windows of the specified parent window.
WORD WINAPI TileWindows(HWND hwndParent, UINT wHow, const RECT* lpRect, UINT cKids, const HWND* lpKids) {
  //TODO
  return 0;
}

//Updates the position, size, shape, content, and translucency of a layered window.
BOOL WINAPI UpdateLayeredWindow(HWND hWnd, HDC hdcDst, POINT* pptDst, SIZE* psize, HDC hdcSrc, POINT* pptSrc, COLORREF crKey, BLENDFUNCTION* pblend, DWORD dwFlags) {
  //TODO
  return 0;
}

//Updates the position, size, shape, content, and translucency of a layered window.
BOOL WINAPI UpdateLayeredWindowIndirect(HWND hwnd, const UPDATELAYEREDWINDOWINFO* pULWInfo) {
  //TODO
  return 0;
}

//Retrieves a handle to the window that contains the specified physical point.
HWND WINAPI WindowFromPhysicalPoint(POINT Point) {
  //TODO
  return 0;
}

//Retrieves a handle to the window that contains the specified point.
HWND WINAPI WindowFromPoint(POINT Point) {
  //TODO: Trzeba będzie wyenumerować okna i znaleźć takie, w którym znajduje się dany punkt
  //Z uwzględnieniem Z-order

  //Jeśli znajdujemy się nad oknem typu Static, to zwracany jest uchwyt do okna pod tym staticiem

  //TODO: WindowFromPoint ignoruje ukryte i wyłączone okna

  return 0;
}
