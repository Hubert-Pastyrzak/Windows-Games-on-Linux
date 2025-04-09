#include <winuser.h>
#include <X11/Xlib.h>
#include <stdlib.h>

#include "display.h"
#include "window.h"



//TODO: Pojawia się pierwszy problem: Czy uchwyt do okna może być zwykłą konwersją z Linuxowego Window na HWND?

//Na razie w sumie jakieś tam tworzenie okien działa
//Teraz trzeba dokończyć implementację pozostałych funkcji od klas okien



BOOL WINAPI AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu) {
  //TODO: Trzeba uwzględnić menu, itd
  //Tak to raczej pozostaje niezmienne, bo pod Linuxem wymiary dotyczą obszaru klienta

  return 1;
}

BOOL WINAPI AdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle) {
  //TODO: To samo co wyżej
  return 1;
}

BOOL WINAPI AllowSetForegroundWindow(DWORD dwProcessId) {
  //TODO
  return 0;
}

BOOL WINAPI AnimateWindow(HWND hWnd, DWORD dwTime, DWORD dwFlags) {
  //TODO
  return 0;
}

BOOL WINAPI AnyPopup() {
  //TODO
  return 0;
}

UINT WINAPI ArrangeIconicWindows(HWND hWnd) {
  //TODO
  return 0;
}

HDWP WINAPI BeginDeferWindowPos(int nNumWindows) {
  //TODO
  return 0;
}

BOOL WINAPI BringWindowToTop(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI CalculatePopupWindowPosition(const POINT* anchorPoint, const SIZE* windowSize, UINT flags, RECT* excludeRect, RECT* popupWindowPosition) {
  //TODO
  return 0;
}

WORD WINAPI CascadeWindows(HWND hwndParent, UINT wHow, const RECT* lpRect, UINT cKids, const HWND* lpKids) {
  //TODO
  return 0;
}

BOOL WINAPI ChangeWindowMessageFilter(UINT message, DWORD dwFlag) {
  //TODO
  return 0;
}

BOOL WINAPI ChangeWindowMessageFilterEx(HWND hwnd, UINT message, DWORD action, PCHANGEFILTERSTRUCT pChangeFilterStruct) {
  //TODO
  return 0;
}

HWND WINAPI ChildWindowFromPoint(HWND hWndParent, POINT Point) {
  //TODO: Podobnie jak WindowFromPoint, ale względem rodzica

  return 0;
}

HWND WINAPI ChildWindowFromPointEx(HWND hwnd, POINT pt, UINT flags) {
  //TODO: Podobnie jak ChildWindowFromPoint

  return 0;
}

BOOL WINAPI CloseWindow(HWND hWnd) {
  //TODO
  return 0;
}

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

HWND WINAPI CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) {
  //TODO
  return 0;
}

HDWP WINAPI DeferWindowPos(HDWP hWinPosInfo, HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

BOOL WINAPI DeregisterShellHookWindow(HWND hwnd) {
  //TODO
  return 0;
}

BOOL WINAPI DestroyWindow(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI EndDeferWindowPos(HDWP hWinPosInfo) {
  //TODO
  return 0;
}

BOOL WINAPI EndTask(HWND hWnd, BOOL fShutDown, BOOL fForce) {
  //TODO
  return 0;
}

BOOL WINAPI EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam) {
  //TODO
  return 0;
}

BOOL WINAPI EnumThreadWindows(DWORD dwThreadId, WNDENUMPROC lpfn, LPARAM lParam) {
  //TODO: Wyenumerować okna należące do danego wątku

  return 0;
}

BOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam) {
  //TODO: Wyenumerować okna
  return 0;
}

HWND WINAPI FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName) {
  //TODO: Znaleźć okno po nazwie klasy lub tytule
  return 0;
}

HWND WINAPI FindWindowW(LPCWSTR lpClassName, LPCWSTR lpWindowName) {
  //TODO
  return 0;
}

HWND WINAPI FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow) {
  //TODO: Podobnie jak FindWindow
  return 0;
}

HWND WINAPI FindWindowExW(HWND hWndParent, HWND hWndChildAfter, LPCWSTR lpszClass, LPCWSTR lpszWindow) {
  //TODO
  return 0;
}

BOOL WINAPI GetAltTabInfoA(HWND hwnd, int iItem, PALTTABINFO pati, LPSTR pszItemText, UINT cchItemText) {
  //TODO
  return 0;
}

BOOL WINAPI GetAltTabInfoW(HWND hwnd, int iItem, PALTTABINFO pati, LPWSTR pszItemText, UINT cchItemText) {
  //TODO
  return 0;
}

HWND WINAPI GetAncestor(HWND hwnd, UINT gaFlags) {
  //TODO
  return 0;
}

BOOL WINAPI GetClientRect(HWND hWnd, LPRECT lpRect) {
  //TODO
  return 0;
}

HWND WINAPI GetDesktopWindow() {
  Display* display = defaultDisplay();
  return (HWND)XDefaultRootWindow(display);
}

HWND WINAPI GetForegroundWindow() {
  //TODO
  return 0;
}

BOOL WINAPI GetGUIThreadInfo(DWORD idThread, PGUITHREADINFO pgui) {
  //TODO
  return 0;
}

HWND WINAPI GetLastActivePopup(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI GetLayeredWindowAttributes(HWND hwnd, COLORREF* pcrKey, BYTE* pbAlpha, DWORD* pdwFlags) {
  //TODO
  return 0;
}

HWND WINAPI GetParent(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI GetProcessDefaultLayout(DWORD* pdwDefaultLayout) {
  //TODO
  return 0;
}

HWND WINAPI GetShellWindow() {
  //TODO
  return 0;
}

DWORD WINAPI GetSysColor(int nIndex) {
  //TODO
  return 0;
}

BOOL WINAPI GetTitleBarInfo(HWND hwnd, PTITLEBARINFO pti) {
  //TODO
  return 0;
}

HWND WINAPI GetTopWindow(HWND hWnd) {
  //TODO
  return 0;
}

HWND WINAPI GetWindow(HWND hWnd, UINT uCmd) {
  //TODO
  return 0;
}

BOOL WINAPI GetWindowDisplayAffinity(HWND hWnd, DWORD* pdwAffinity) {
  //TODO
  return 0;
}

BOOL WINAPI GetWindowInfo(HWND hwnd, PWINDOWINFO pwi) {
  //TODO
  return 0;
}

UINT WINAPI GetWindowModuleFileNameA(HWND hwnd, LPSTR pszFileName, UINT cchFileNameMax) {
  //TODO
  return 0;
}

UINT WINAPI GetWindowModuleFileNameW(HWND hwnd, LPWSTR pszFileName, UINT cchFileNameMax) {
  //TODO
  return 0;
}

BOOL WINAPI GetWindowPlacement(HWND hWnd, WINDOWPLACEMENT* lpwndpl) {
  //TODO
  return 0;
}

BOOL WINAPI GetWindowRect(HWND hWnd, LPRECT lpRect) {
  //TODO
  return 0;
}

int WINAPI GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount) {
  //TODO: Wysłać komunikat WM_GETTEXT

  return 0;
}

int WINAPI GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount) {
  //TODO
  return 0;
}

int WINAPI GetWindowTextLengthA(HWND hWnd) {
  //TODO: Wysłać komunikat WM_GETTEXTLENGTH do okna

  return 0;
}

int WINAPI GetWindowTextLengthW(HWND hWnd) {
  //TODO
  return 0;
}

DWORD WINAPI GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId) {
  //TODO: Pobrać identyfikator procesu oraz wątku, do których dane okno należy
  return 0;
}

int WINAPI InternalGetWindowText(HWND hWnd, LPWSTR pString, int cchMaxCount) {
  //TODO
  return 0;
}

BOOL WINAPI IsChild(HWND hWndParent, HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI IsGUIThread(BOOL bConvert) {
  //TODO
  return 0;
}

BOOL WINAPI IsHungAppWindow(HWND hwnd) {
  //TODO
  return 0;
}

BOOL WINAPI IsIconic(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI IsProcessDPIAware() {
  //TODO
  return 0;
}

BOOL WINAPI IsWindow(HWND hWnd) {
  //TODO: Trzeba sprawdzić, czy dany uchwyt jest uchwytem do okna
  //Najlepiej by było zrobić faktycznie tę strukturę i trzymać takie dane wewnątrz

  return 0;
}

BOOL WINAPI IsWindowUnicode(HWND hWnd) {
  //TODO: Trzeba sprawdzić, czy dane okno zostało zarejestrowane przy użyciu klasy Unicode

  return 0;
}

BOOL WINAPI IsWindowVisible(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI IsZoomed(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI LockSetForegroundWindow(UINT uLockCode) {
  //TODO
  return 0;
}

BOOL WINAPI LogicalToPhysicalPoint(HWND hWnd, LPPOINT lpPoint) {
  //TODO
  return 0;
}

BOOL WINAPI MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint) {
  //TODO
  return 0;
}

BOOL WINAPI OpenIcon(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI PhysicalToLogicalPoint(HWND hWnd, LPPOINT lpPoint) {
  //TODO
  return 0;
}

HWND WINAPI RealChildWindowFromPoint(HWND hwndParent, POINT ptParentClientCoords) {
  //TODO
  return 0;
}

UINT WINAPI RealGetWindowClassA(HWND hwnd, LPSTR ptszClassName, UINT cchClassNameMax) {
  //TODO
  return 0;
}

UINT WINAPI RealGetWindowClassW(HWND hwnd, LPWSTR ptszClassName, UINT cchClassNameMax) {
  //TODO
  return 0;
}

BOOL WINAPI RegisterShellHookWindow(HWND hwnd) {
  //TODO
  return 0;
}

BOOL WINAPI SetForegroundWindow(HWND hWnd) {
  //TODO
  return 0;
}

BOOL WINAPI SetLayeredWindowAttributes(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags) {
  //TODO
  return 0;
}

HWND WINAPI SetParent(HWND hWndChild, HWND hWndNewParent) {
  //TODO
  return 0;
}

BOOL WINAPI SetProcessDefaultLayout(DWORD dwDefaultLayout) {
  //TODO
  return 0;
}

BOOL WINAPI SetProcessDPIAware() {
  //TODO
  return 0;
}

BOOL WINAPI SetSysColors(int cElements, const INT* lpaElements, const COLORREF* lpaRgbValues) {
  //TODO
  return 0;
}

BOOL WINAPI SetWindowDisplayAffinity(HWND hWnd, DWORD dwAffinity) {
  //TODO
  return 0;
}

BOOL WINAPI SetWindowFeedbackSettings(HWND hwnd, FEEDBACK_TYPE feedback, DWORD flags, UINT32 size, const VOID* configuration) {
  //TODO
  return 0;
}

BOOL WINAPI SetWindowPlacement(HWND hWnd, const WINDOWPLACEMENT* lpwndpl) {
  //TODO
  return 0;
}

BOOL WINAPI SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags) {
  //TODO
  return 0;
}

BOOL WINAPI SetWindowTextA(HWND hWnd, LPCSTR lpString) {
  //TODO: Rzekomo ta funkcja działa tylko na okna, których właścicielem jest aktualny proces
  //Czy wtedy zostanie zwrócone FALSE?
  
  //Display* display = defaultDisplay();
  //XStoreName(display, (Window)hWnd, lpString);

  //TODO: Trzeba wysłać komunikat WM_SETTEXT do okna
  //Trzeba uwzględnić także to, że rzekomo tabulatory są wyświetlane jako "|"

  return 1;
}

BOOL WINAPI SetWindowTextW(HWND hWnd, LPCWSTR lpString) {
  //TODO
  return 0;
}

BOOL WINAPI ShowOwnedPopups(HWND hWnd, BOOL fShow) {
  //TODO
  return 0;
}

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

BOOL WINAPI ShowWindowAsync(HWND hWnd, int nCmdShow) {
  //TODO: Wyświetlić/ukryć okno asynchronicznie

  return 0;
}

BOOL WINAPI SoundSentry() {
  //TODO
  return 0;
}

void WINAPI SwitchToThisWindow(HWND hwnd, BOOL fUnknown) {
  //TODO
}

WORD WINAPI TileWindows(HWND hwndParent, UINT wHow, const RECT* lpRect, UINT cKids, const HWND* lpKids) {
  //TODO
  return 0;
}

BOOL WINAPI UpdateLayeredWindow(HWND hWnd, HDC hdcDst, POINT* pptDst, SIZE* psize, HDC hdcSrc, POINT* pptSrc, COLORREF crKey, BLENDFUNCTION* pblend, DWORD dwFlags) {
  //TODO
  return 0;
}

BOOL WINAPI UpdateLayeredWindowIndirect(HWND hwnd, const UPDATELAYEREDWINDOWINFO* pULWInfo) {
  //TODO
  return 0;
}

HWND WINAPI WindowFromPhysicalPoint(POINT Point) {
  //TODO
  return 0;
}

HWND WINAPI WindowFromPoint(POINT Point) {
  //TODO: Trzeba będzie wyenumerować okna i znaleźć takie, w którym znajduje się dany punkt
  //Z uwzględnieniem Z-order

  //Jeśli znajdujemy się nad oknem typu Static, to zwracany jest uchwyt do okna pod tym staticiem

  //TODO: WindowFromPoint ignoruje ukryte i wyłączone okna

  return 0;
}
