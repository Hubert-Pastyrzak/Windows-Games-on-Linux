#include <winuser.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

#include "window.h"



//Wygląda na to, że implementacja API ASCII do obsługi klas okien jest gotowa (przynajmniej w większości)
//Trzeba będzie jeszcze przetestować, czy wszystko działa identycznie jak na prawdziwym Windowsie



//Trzeba będzie dokończyć implementację klas okien



//Istnieją jeszcze standardowe kontrolki systemowe,
//rejestrując klasę jej nazwa nie może kolidować z tymi systemowymi (Update: A być może według dokumentacji da się jednak nadpisać lokalnie w danym procesie te systemowe klasy?)
//TODO: Trzeba będzie skądś wziąć te systemowe
//TODO: Systemowe klasy już mamy, tylko trzeba przenieść ich procedury do osobnego pliku



//TODO: Rzekomo na 16-bitowym Windowsie działa to inaczej, ale raczej nie będziemy implementować wsparcia dla 16-bitowych aplikacji (przynajmniej na razie)


//Poniższe klasy są tylko dla systemu: (ciekawe, jak będziemy je rejestrować, jeśli w ogóle :P) (raczej nie)
// - ComboLBox
// - DDEMLEvent
// - Message
// - #32768
// - #32769
// - #32770
// - #32771
// - #32772




//TODO: W rejestrze istnieje ścieżka, która pozwala podpiąć swoją DLLkę do każdego ładowanego procesu:
//HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\NT\CurrentVersion\Windows
//Trzeba to będzie też zaimplementować razem z rejestrem



//TODO: Obsługa Unicode :P



//Atomy do nazw klas są chyba przechowywane już w jakiejś systemowej tabelce, więc
//trzeba będzie zaimplementować to oddzielnie.

//TODO: Kursory
//Jeśli hCursor == NULL, wtedy system nie robi nic z kursorami

//TODO: Ikony
//Jeśli hIcon == NULL, używana jest po prostu domyślna ikona

//TODO: Tło
//Jeśli hbrBackground == NULL, to aplikacja musi sama rysować swoje tło po otrzymaniu komunikatu WM_ERASEBKGND

//TODO: Menu
//Jeśli hMenuName (czy jakoś tak) == NULL, to po prostu nie ma menu

//TODO: Style klas

//TODO: Jakiś styl CS_OWNDC związany z device contextami, ale nie wiem o co chodzi
//To chyba jest tak, że domyślnie system przechowuje w pamięci DC dla wszystkich okien, z których korzystamy np. przez GetDC i ReleaseDC
//Według dokumentacji, jeśli zostanie podany styl CS_OWNDC, to każde okno utworzone z danej klasy będzie miało swój własny prywatny DC niezarządzany przez system?
//Wtedy rzekomo można pobrać taki DC raz i nie trzeba go zwalniać

//TODO: Czy RegisterClass wywala błąd, jeśli cbClsExtra < 0 lub cbWndExtra < 0?



typedef struct {
  size_t count;
  WNDCLASSEXA** classes;
} ClassListA;

ClassListA localClassesA = { 0, NULL };
ClassListA globalClassesA = { 0, NULL };
ClassListA systemClassesA = { 0, NULL };



typedef struct {
  size_t count;
  WNDCLASSEXW** classes;
} ClassListW;

ClassListW localClassesW = { 0, NULL };
ClassListW globalClassesW = { 0, NULL };
ClassListW systemClassesW = { 0, NULL };



//TODO: To docelowo trzeba przenieść do jakiegoś folderu z utilsami
const char* copyStringA(const char* str) {
  size_t length = strlen(str);

  const char* strDup = (const char*)malloc(length + 1);
  strcpy((char*)strDup, str);

  return strDup;
}



int isSystemClassNameA(const char* className) {
  const char* systemClassNames[] = {
    "Button",
    "ComboBox",
    "Edit",
    "ListBox",
    "MDIClient",
    "ScrollBar",
    "Static",
  };

  size_t systemClassNameCount = sizeof(systemClassNames) / sizeof(const char*);

  for (size_t i = 0; i < systemClassNameCount; i++) {
    if (strcasecmp(className, systemClassNames[i]) == 0) {
      return 1;
    }
  }

  return 0;
}

int isClassNameUsedA(const char* className) {
  //TODO: Swoją drogą, czy systemowe klasy faktycznie mogą być nadpisywane? (TODO: Do sprawdzenia)
  
  for (size_t i = 0; i < localClassesA.count; i++) {
    WNDCLASSEXA* lpwcx = localClassesA.classes[i];
    if (strcasecmp(className, lpwcx->lpszClassName) == 0) {
      return 1;
    }
  }

  for (size_t i = 0; i < globalClassesA.count; i++) {
    WNDCLASSEXA* lpwcx = globalClassesA.classes[i];
    if (strcasecmp(className, lpwcx->lpszClassName) == 0) {
      return 1;
    }
  }

  for (size_t i = 0; i < systemClassesA.count; i++) {
    WNDCLASSEXA* lpwcx = systemClassesA.classes[i];
    if (strcasecmp(className, lpwcx->lpszClassName) == 0) {
      return 1;
    }
  }

  //TODO: Przeszukiwanie także klas Unicode

  return 0;
}

void setClassCountA(ClassListA* classList, size_t newCount) {
  classList->count = newCount;
  classList->classes = (WNDCLASSEXA**)realloc(classList->classes, classList->count * sizeof(WNDCLASSEXA*));
}

//TODO: Jakaś inna nazwa może, bo za bardzo koliduje
//TODO: Obsługa błędów (co się dzieje, gdy nawali realloc albo malloc?)
int registerClassA(ClassListA* classList, const WNDCLASSEXA* lpwcx) {
  setClassCountA(classList, classList->count + 1);

  WNDCLASSEXA* lpDstWcx = (WNDCLASSEXA*)malloc(sizeof(WNDCLASSEXA) + lpwcx->cbClsExtra);
  classList->classes[classList->count - 1] = lpDstWcx;

  lpDstWcx->cbSize = lpwcx->cbSize;
  lpDstWcx->style = lpwcx->style;
  lpDstWcx->lpfnWndProc = lpwcx->lpfnWndProc;
  lpDstWcx->cbClsExtra = lpwcx->cbClsExtra;
  lpDstWcx->cbWndExtra = lpwcx->cbWndExtra;
  lpDstWcx->hInstance = lpwcx->hInstance;
  lpDstWcx->hIcon = lpwcx->hIcon;
  lpDstWcx->hCursor = lpwcx->hCursor;
  lpDstWcx->hbrBackground = lpwcx->hbrBackground;
  
  if (lpwcx->lpszMenuName) {
    lpDstWcx->lpszMenuName = copyStringA(lpwcx->lpszMenuName);
  } else {
    lpDstWcx->lpszMenuName = NULL;
  }

  lpDstWcx->lpszClassName = copyStringA(lpwcx->lpszClassName);
  lpDstWcx->hIconSm = lpwcx->hIconSm;

  if (lpwcx->cbClsExtra > 0) {
    memset(&((char*)lpDstWcx)[sizeof(WNDCLASSEXA)], lpwcx->cbClsExtra, 0);
  }

  return 1;
}

int tryGetClassInfoExA(ClassListA* classList, HINSTANCE hInstance, const char* className, LPWNDCLASSEXA lpDstWcx) {
  for (size_t i = 0; i < classList->count; i++) {
    WNDCLASSEXA* lpwcx = classList->classes[i];
    if (lpwcx->hInstance == hInstance && strcasecmp(lpwcx->lpszClassName, className) == 0) {
      lpDstWcx->cbSize = lpwcx->cbSize;
      lpDstWcx->style = lpwcx->style;
      lpDstWcx->lpfnWndProc = lpwcx->lpfnWndProc;
      lpDstWcx->cbClsExtra = lpwcx->cbClsExtra;
      lpDstWcx->cbWndExtra = lpwcx->cbWndExtra;
      lpDstWcx->hInstance = lpwcx->hInstance;
      lpDstWcx->hIcon = lpwcx->hIcon;
      lpDstWcx->hCursor = lpwcx->hCursor;
      lpDstWcx->hbrBackground = lpwcx->hbrBackground;

      //TODO: Istotna kwestia - Czy system podaje nam adresy do oryginalnych stringów w pamięci systemowej czy tworzy kopie?
      lpDstWcx->lpszMenuName = lpwcx->lpszMenuName;
      lpDstWcx->lpszClassName = lpwcx->lpszClassName;

      lpDstWcx->hIconSm = lpwcx->hIconSm;

      return 1;
    }
  }

  return 0;
}

int tryUnregisterClassA(ClassListA* classList, const char* className, HINSTANCE hInstance) {
  for (size_t i = 0; i < classList->count; i++) {
    WNDCLASSEXA* lpwcx = classList->classes[i];
    if (strcasecmp(lpwcx->lpszClassName, className) == 0 && lpwcx->hInstance == hInstance) {
      if (lpwcx->lpszMenuName) {
        free((void*)lpwcx->lpszMenuName);
      }

      free((void*)lpwcx->lpszClassName);
      free((void*)lpwcx);

      for (size_t j = i + 1; j < classList->count; j++) {
        classList->classes[j - 1] = classList->classes[j];
      }

      setClassCountA(classList, classList->count - 1);
      return 1;
    }
  }

  return 0;
}



int systemClassesMutexInitialized = 0;
pthread_mutex_t systemClassesMutex;

void lockSystemClassesMutex() {
  if (!systemClassesMutexInitialized) {
    pthread_mutex_init(&systemClassesMutex, NULL);
    systemClassesMutexInitialized = 1;
  }

  pthread_mutex_lock(&systemClassesMutex);
}

void unlockSystemClassesMutex() {
  if (!systemClassesMutexInitialized) {
    return;
  }

  pthread_mutex_unlock(&systemClassesMutex);
}



//TODO: To trzeba przenieść do osobnego pliku, bo te klasy są rejestrowane przy każdym wywołaniu do user32.dll lub gdi32.dll
int systemClassesRegistered = 0;

LRESULT CALLBACK ButtonWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK ComboBoxWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK EditWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK ListBoxWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK MDIClientWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK ScrollBarWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT CALLBACK StaticWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
  //TODO
  return DefWindowProc(hWnd, uMsg, wParam, lParam);
}



//TODO: Jakaś inna nazwa
void systemClasses() {
  //TODO: Jaka to ma być właściwie instancja? Jak chcemy np. pobrać informacje o klasie przez GetClassInfo(Ex), to podajemy hInstance = NULL
  HINSTANCE hInstance = (HINSTANCE)1;
  
  if (systemClassesRegistered) {
    return;
  }

  systemClassesRegistered = 1;

  {
    WNDCLASSA buttonWc = {};
    buttonWc.style = CS_GLOBALCLASS;
    buttonWc.lpfnWndProc = ButtonWndProc;
    buttonWc.hInstance = hInstance;
    buttonWc.lpszClassName = "Button";

    RegisterClassA(&buttonWc);
  }

  {
    WNDCLASSA comboBoxWc = {};
    comboBoxWc.style = CS_GLOBALCLASS;
    comboBoxWc.lpfnWndProc = ComboBoxWndProc;
    comboBoxWc.hInstance = hInstance;
    comboBoxWc.lpszClassName = "ComboBox";

    RegisterClassA(&comboBoxWc);
  }

  {
    WNDCLASSA editWc = {};
    editWc.style = CS_GLOBALCLASS;
    editWc.lpfnWndProc = EditWndProc;
    editWc.hInstance = hInstance;
    editWc.lpszClassName = "Edit";

    RegisterClassA(&editWc);
  }

  {
    WNDCLASSA listBoxWc = {};
    listBoxWc.style = CS_GLOBALCLASS;
    listBoxWc.lpfnWndProc = ListBoxWndProc;
    listBoxWc.hInstance = hInstance;
    listBoxWc.lpszClassName = "ListBox";

    RegisterClassA(&listBoxWc);
  }

  {
    WNDCLASSA mdiClientWc = {};
    mdiClientWc.style = CS_GLOBALCLASS;
    mdiClientWc.lpfnWndProc = MDIClientWndProc;
    mdiClientWc.hInstance = hInstance;
    mdiClientWc.lpszClassName = "MDIClient";

    RegisterClassA(&mdiClientWc);
  }

  {
    WNDCLASSA scrollBarWc = {};
    scrollBarWc.style = CS_GLOBALCLASS;
    scrollBarWc.lpfnWndProc = ScrollBarWndProc;
    scrollBarWc.hInstance = hInstance;
    scrollBarWc.lpszClassName = "ScrollBar";

    RegisterClassA(&scrollBarWc);
  }

  {
    WNDCLASSA staticWc = {};
    staticWc.style = CS_GLOBALCLASS;
    staticWc.lpfnWndProc = StaticWndProc;
    staticWc.hInstance = hInstance;
    staticWc.lpszClassName = "Static";

    RegisterClassA(&staticWc);
  }
}



int windowClassesMutexInitialized = 0;
pthread_mutex_t windowClassesMutex;

void lockWindowClassesMutex() {
  if (!windowClassesMutexInitialized) {
    pthread_mutex_init(&windowClassesMutex, NULL);
    windowClassesMutexInitialized = 1;
  }

  pthread_mutex_lock(&windowClassesMutex);
}

void unlockWindowClassesMutex() {
  if (!windowClassesMutexInitialized) {
    return;
  }

  pthread_mutex_unlock(&windowClassesMutex);
}



//Retrieves information about a window class.
BOOL WINAPI GetClassInfoA(HINSTANCE hInstance, LPCSTR lpClassName, LPWNDCLASSA lpWndClass) {
  systemClasses();

  WNDCLASSEXA wcx = {};
  if (!GetClassInfoExA(hInstance, lpClassName, &wcx)) {
    return 0;
  }

  lpWndClass->style = wcx.style;
  lpWndClass->lpfnWndProc = wcx.lpfnWndProc;
  lpWndClass->cbClsExtra = wcx.cbClsExtra;
  lpWndClass->cbWndExtra = wcx.cbWndExtra;
  lpWndClass->hInstance = wcx.hInstance;
  lpWndClass->hIcon = wcx.hIcon;
  lpWndClass->hCursor = wcx.hCursor;
  lpWndClass->hbrBackground = wcx.hbrBackground;
  lpWndClass->lpszMenuName = wcx.lpszMenuName;
  lpWndClass->lpszClassName = wcx.lpszClassName;

  return 1;
}

//Retrieves information about a window class.
BOOL WINAPI GetClassInfoW(HINSTANCE hInstance, LPCWSTR lpClassName, LPWNDCLASSW lpWndClass) {
  systemClasses();

  //TODO

  return 0;
}

//Retrieves information about a window class, including a handle to the small icon associated with the window class. The GetClassInfo function does not retrieve a handle to the small icon.
BOOL WINAPI GetClassInfoExA(HINSTANCE hInstance, LPCSTR lpszClass, LPWNDCLASSEXA lpwcx) {
  systemClasses();

  lockWindowClassesMutex();

  //TODO: lpszClass może być atomem

  if (tryGetClassInfoExA(&localClassesA, hInstance, lpszClass, lpwcx)) {
    unlockWindowClassesMutex();
    return 1;
  }

  if (tryGetClassInfoExA(&globalClassesA, hInstance, lpszClass, lpwcx)) {
    unlockWindowClassesMutex();
    return 1;
  }

  if (tryGetClassInfoExA(&systemClassesA, hInstance, lpszClass, lpwcx)) {
    unlockWindowClassesMutex();
    return 1;
  }

  unlockWindowClassesMutex();
  return 0;
}

//Retrieves information about a window class, including a handle to the small icon associated with the window class. The GetClassInfo function does not retrieve a handle to the small icon.
BOOL WINAPI GetClassInfoExW(HINSTANCE hInstance, LPCWSTR lpszClass, LPWNDCLASSEXW lpwcx) {
  systemClasses();

  //TODO
  return 0;
}

//Retrieves the specified 32-bit (DWORD) value from the WNDCLASSEX structure associated with the specified window.
DWORD WINAPI GetClassLongA(HWND hWnd, int nIndex) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  if (nIndex >= 0 && nIndex < (lpwcx->cbClsExtra / sizeof(LONG))) {
    return *((LONG*)&((char*)lpwcx)[sizeof(WNDCLASSEXA) + nIndex]);
  }

  return (DWORD)GetClassLongPtrA(hWnd, nIndex);
}

//Retrieves the specified 32-bit (DWORD) value from the WNDCLASSEX structure associated with the specified window.
DWORD WINAPI GetClassLongW(HWND hWnd, int nIndex) {
  systemClasses();

  //TODO
  return 0;
}

//Retrieves the specified value from the WNDCLASSEX structure associated with the specified window.
ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd, int nIndex) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  if (nIndex >= 0 && nIndex < (lpwcx->cbClsExtra / sizeof(ULONG_PTR))) {
    return *((ULONG_PTR*)&((char*)lpwcx)[sizeof(WNDCLASSEXA) + nIndex]);
  }

  if (nIndex == GCW_ATOM) {
    //TODO: Atom klasy (na razie przyjmijmy 1)
    return 1;
  }

  if (nIndex == GCL_CBCLSEXTRA) {
    return lpwcx->cbClsExtra;
  }

  if (nIndex == GCL_CBWNDEXTRA) {
    return lpwcx->cbWndExtra;
  }

  if (nIndex == GCL_HBRBACKGROUND) {
    return (ULONG_PTR)lpwcx->hbrBackground;
  }

  if (nIndex == GCL_HCURSOR) {
    return (ULONG_PTR)lpwcx->hCursor;
  }

  if (nIndex == GCL_HICON) {
    return (ULONG_PTR)lpwcx->hIcon;
  }

  if (nIndex == GCL_HICONSM) {
    return (ULONG_PTR)lpwcx->hIconSm;
  }

  if (nIndex == GCL_HMODULE) {
    return (ULONG_PTR)lpwcx->hInstance;
  }

  if (nIndex == GCL_MENUNAME) {
    //TODO: Czy zwracany jest oryginalny string?
    return (ULONG_PTR)lpwcx->lpszMenuName;
  }

  if (nIndex == GCL_STYLE) {
    return lpwcx->style;
  }

  if (nIndex == GCL_WNDPROC) {
    return (ULONG_PTR)lpwcx->lpfnWndProc;
  }

  return 0;
}

//Retrieves the specified value from the WNDCLASSEX structure associated with the specified window.
ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd, int nIndex) {
  systemClasses();

  //TODO
  return 0;
}

//Retrieves the name of the class to which the specified window belongs.
int WINAPI GetClassNameA(HWND hWnd, LPSTR lpClassName, int nMaxCount) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  int outLength = 0;

  size_t srcLength = strlen(lpwcx->lpszClassName) + 1;
  size_t finalLength = (nMaxCount > srcLength) ? nMaxCount : srcLength;
  for (size_t i = 0; i < finalLength; i++) {
    if (i < finalLength - 1) {
      lpClassName[i] = lpwcx->lpszClassName[i];
      outLength++;
    } else {
      lpClassName[i] = '\0';
    }
  }

  return outLength;
}

//Retrieves the name of the class to which the specified window belongs.
int WINAPI GetClassNameW(HWND hWnd, LPWSTR lpClassName, int nMaxCount) {
  systemClasses();

  //TODO
  return 0;
}

//Retrieves the 16-bit (WORD) value at the specified offset into the extra class memory for the window class to which the specified window belongs.
WORD WINAPI GetClassWord(HWND hWnd, int nIndex) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  if (nIndex >= 0 && nIndex < (lpwcx->cbClsExtra / sizeof(WORD))) {
    return *((WORD*)&((char*)lpwcx)[sizeof(WNDCLASSEXA) + nIndex]);
  }

  if (nIndex == GCW_ATOM) {
    //TODO: Atom
    return 1;
  }

  return 0;
}

//Retrieves information about the specified window. The function also retrieves the 32-bit (DWORD) value at the specified offset into the extra window memory.
LONG WINAPI GetWindowLongA(HWND hWnd, int nIndex) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  if (nIndex >= 0 && nIndex < (userWindow->cbWndExtra / sizeof(LONG))) {
    return *((LONG*)&((char*)userWindow)[sizeof(UserWindow) + nIndex]);
  }

  return GetWindowLongPtrA(hWnd, nIndex);
}

//Retrieves information about the specified window. The function also retrieves the 32-bit (DWORD) value at the specified offset into the extra window memory.
LONG WINAPI GetWindowLongW(HWND hWnd, int nIndex) {
  systemClasses();

  //TODO
  return 0;
}

//Retrieves information about the specified window. The function also retrieves the value at a specified offset into the extra window memory.
LONG_PTR WINAPI GetWindowLongPtrA(HWND hWnd, int nIndex) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  if (nIndex >= 0 && nIndex < (userWindow->cbWndExtra / sizeof(LONG_PTR))) {
    return *((LONG_PTR*)&((char*)userWindow)[sizeof(UserWindow) + nIndex]);
  }

  if (nIndex == GWL_EXSTYLE) {
    return userWindow->dwExStyle;
  }

  if (nIndex == GWL_HINSTANCE) {
    return (LONG_PTR)userWindow->hInstance;
  }

  if (nIndex == GWL_HWNDPARENT) {
    return (LONG_PTR)userWindow->hWndParent;
  }

  if (nIndex == GWL_ID) {
    //TODO: Pobrać identyfikator okna
    return 0;
  }

  if (nIndex == GWL_STYLE) {
    return userWindow->dwStyle;
  }

  if (nIndex == GWL_USERDATA) {
    //TODO: Pobrać wskaźnik do user data
    return 0;
  }

  if (nIndex == GWL_WNDPROC) {
    //TODO: Istnieje taka możliwość, że tutaj zostanie zwrócony uchwyt
    //Czy to się dzieje w przypadku, gdy ściągamy WndProc z okna w innym procesie?

    return (LONG_PTR)userWindow->lpfnWndProc;
  }

  return 0;
}

//Retrieves information about the specified window. The function also retrieves the value at a specified offset into the extra window memory.
LONG_PTR WINAPI GetWindowLongPtrW(HWND hWnd, int nIndex) {
  systemClasses();

  //TODO
  return 0;
}

//Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
ATOM WINAPI RegisterClassA(const WNDCLASSA* lpWndClass) {
  systemClasses();

  WNDCLASSEXA wcx = {};
  wcx.cbSize = sizeof(WNDCLASSEXA);
  wcx.style = lpWndClass->style;
  wcx.lpfnWndProc = lpWndClass->lpfnWndProc;
  wcx.cbClsExtra = lpWndClass->cbClsExtra;
  wcx.cbWndExtra = lpWndClass->cbWndExtra;
  wcx.hInstance = lpWndClass->hInstance;
  wcx.hIcon = lpWndClass->hIcon;
  wcx.hCursor = lpWndClass->hCursor;
  wcx.hbrBackground = lpWndClass->hbrBackground;
  wcx.lpszMenuName = lpWndClass->lpszMenuName;
  wcx.lpszClassName = lpWndClass->lpszClassName;

  //TODO: Na podstawie hIcon trzeba stworzyć mniejszą wersję ikonki
  //Na razie i tak nie da się załadować żadnej ikony
  wcx.hIconSm = wcx.hIcon;

  return RegisterClassExA(&wcx);
}

//Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
ATOM WINAPI RegisterClassW(const WNDCLASSW* lpWndClass) {
  systemClasses();

  //TODO
  return 0;
}

//Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
ATOM WINAPI RegisterClassExA(const WNDCLASSEXA* lpwcx) {
  systemClasses();

  //TODO: Czy nie ma jeszcze jakichś przypadków, które trzeba zweryfikować?
  if (lpwcx->cbSize != sizeof(WNDCLASSEXA) || !lpwcx->lpfnWndProc || !lpwcx->hInstance || !lpwcx->lpszClassName || lpwcx->cbClsExtra < 0 || lpwcx->cbClsExtra > 40 || lpwcx->cbWndExtra < 0 || lpwcx->cbWndExtra > 40) {
    return 0;
  }

  if (strlen(lpwcx->lpszClassName) > 255) {
    return 0;
  }

  lockWindowClassesMutex();

  if (isClassNameUsedA(lpwcx->lpszClassName)) {
    unlockWindowClassesMutex();
    return 0;
  }

  //TODO: Czy ta wspomniana gdzieś wyżej podmiana klas systemowych jest możliwa?
  if (isSystemClassNameA(lpwcx->lpszClassName)) {
    registerClassA(&systemClassesA, lpwcx);
  } else {
    if (lpwcx->style & CS_GLOBALCLASS) {
      registerClassA(&globalClassesA, lpwcx);
    } else {
      registerClassA(&localClassesA, lpwcx);
    }
  }

  unlockWindowClassesMutex();

  //TODO: Trzeba jeszcze wpisać atom i go zwrócić
  //Na razie przyjmijmy, że każda nazwa ma atom 1, bo nie mam jeszcze zaimplementowanej listy atomów
  //Lista atomów jest prawdopodobnie współdzielona między procesami, więc będzie trochę zabawy

  return 1;

  //TODO: Swoją drogą, bo istnieje możliwości podmiany wartości pól klas po zarejestrowaniu, w tym stylów
  //Co w sytuacji, gdy zdejmiemy styl CS_GLOBALCLASS już po zarejestrowaniu?
  //Taka klasa zostanie na liście globalnych klas, czy zostanie przeniesiona do lokalnych?
  //To też trzeba uwzględnić


  //TODO: Trzeba zobaczyć, co robią pozostałe style klas i je obsłużyć
}

//Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.
ATOM WINAPI RegisterClassExW(const WNDCLASSEXW* lpwcx) {
  systemClasses();

  //TODO
  return 0;
}

//Replaces the specified 32-bit (long) value at the specified offset into the extra class memory or the WNDCLASSEX structure for the class to which the specified window belongs.
DWORD WINAPI SetClassLongA(HWND hWnd, int nIndex, LONG dwNewLong) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  if (nIndex >= 0 && nIndex < (lpwcx->cbClsExtra / sizeof(LONG))) {
    DWORD dwOldLong = GetClassLongA(hWnd, nIndex);
    *((LONG*)&((char*)lpwcx)[sizeof(WNDCLASSEXA) + nIndex]) = dwNewLong;
    
    return dwOldLong;
  }

  return SetClassLongPtrA(hWnd, nIndex, (ULONG)dwNewLong);
}

//Replaces the specified 32-bit (long) value at the specified offset into the extra class memory or the WNDCLASSEX structure for the class to which the specified window belongs.
DWORD WINAPI SetClassLongW(HWND hWnd, int nIndex, LONG dwNewLong) {
  systemClasses();

  //TODO
  return 0;
}

//Replaces the specified value at the specified offset in the extra class memory or the WNDCLASSEX structure for the class to which the specified window belongs.
ULONG_PTR WINAPI SetClassLongPtrA(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
  systemClasses();

  ULONG_PTR dwOldLong = GetClassLongPtrA(hWnd, nIndex);

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  if (nIndex >= 0 && nIndex < (lpwcx->cbClsExtra / sizeof(ULONG_PTR))) {
    *((LONG_PTR*)&((char*)lpwcx)[sizeof(WNDCLASSEXA) + nIndex]) = dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCL_CBCLSEXTRA) {
    //TODO: Tutaj trzeba uważać
    //cbClsExtra jest już wykorzystywane do sprawdzania, czy nIndex mieści się w buforze, ale nie zmienia rozmiaru tego bufora
    //Docelowo może do struktury trzeba by było dokleić także rozmiar tych danych?
    //I tak trzeba w CreateWindowEx jakoś przekażać do lpwcx oryginalną strukturę, więc na razie pomińmy

    return dwOldLong;
  }

  if (nIndex == GCL_CBWNDEXTRA) {
    lpwcx->cbWndExtra = dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCLP_HBRBACKGROUND) {
    lpwcx->hbrBackground = (HBRUSH)dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCLP_HCURSOR) {
    lpwcx->hCursor = (HCURSOR)dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCLP_HICON) {
    lpwcx->hIcon = (HICON)dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCLP_HICONSM) {
    lpwcx->hIconSm = (HICON)dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCLP_HMODULE) {
    //TODO: Czy to zmienia hInstance?
    lpwcx->hInstance = (HINSTANCE)dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GCLP_MENUNAME) {
    if (lpwcx->lpszMenuName) {
      free((void*)lpwcx->lpszMenuName);
    }

    if (dwNewLong) {
      lpwcx->lpszMenuName = copyStringA((const char*)dwNewLong);
    } else {
      lpwcx->lpszMenuName = NULL;
    }

    return dwOldLong;
  }

  return 0;
}

//Replaces the specified value at the specified offset in the extra class memory or the WNDCLASSEX structure for the class to which the specified window belongs.
ULONG_PTR WINAPI SetClassLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
  systemClasses();

  //TODO
  return 0;
}

//Replaces the 16-bit (WORD) value at the specified offset into the extra class memory for the window class to which the specified window belongs.
WORD WINAPI SetClassWord(HWND hWnd, int nIndex, WORD wNewWord) {
  systemClasses();

  UserWindow* userWindow = (UserWindow*)hWnd;

  WNDCLASSEXA* lpwcx = userWindow->lpwcx;

  if (nIndex >= 0 && nIndex < (lpwcx->cbClsExtra / sizeof(WORD))) {
    WORD wOldWord = GetClassWord(hWnd, nIndex);
    *((WORD*)&((char*)lpwcx)[sizeof(WNDCLASSEXA) + nIndex]) = wNewWord;
    
    return wOldWord;
  }

  return 0;
}

//Changes an attribute of the specified window. The function also sets the 32-bit (long) value at the specified offset into the extra window memory.
LONG WINAPI SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong) {
  systemClasses();

  //TODO: Rzekomo wywołanie tego na progress barze resetuje jego pozycję

  UserWindow* userWindow = (UserWindow*)hWnd;

  //TODO: Co w przypadku, gdy cbWndExtra < 4? Chyba, że to jest niedopuszczalne i musi to być wielokrotność 4
  if (nIndex >= 0 && nIndex < (userWindow->cbWndExtra / sizeof(LONG))) {
    LONG dwOldLong = GetWindowLongA(hWnd, nIndex);
    *((LONG*)&((char*)userWindow)[sizeof(UserWindow) + nIndex]) = dwNewLong;
    
    return dwOldLong;
  }

  return SetWindowLongPtrA(hWnd, nIndex, (ULONG)dwNewLong);
}

//Changes an attribute of the specified window. The function also sets the 32-bit (long) value at the specified offset into the extra window memory.
LONG WINAPI SetWindowLongW(HWND hWnd, int nIndex, LONG dwNewLong) {
  systemClasses();

  //TODO
  return 0;
}

//Changes an attribute of the specified window. The function also sets a value at the specified offset in the extra window memory. 
LONG_PTR WINAPI SetWindowLongPtrA(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
  systemClasses();

  //TODO: Jeśli okno należy do procesu o wyższym process privilege, to ta funkcja zwraca FALSE
  //TODO: Jakaś hierarchia UIPI - na razie nie musimy się tym przejmować

  //TODO: Rzekomo wywołanie tego na progress barze resetuje jego pozycję

  LONG_PTR dwOldLong = GetWindowLongPtrA(hWnd, nIndex);

  UserWindow* userWindow = (UserWindow*)hWnd;

  //TODO: Co w przypadku, gdy cbWndExtra < 4? Chyba, że to jest niedopuszczalne i musi to być wielokrotność 4
  if (nIndex >= 0 && nIndex < (userWindow->cbWndExtra / sizeof(LONG_PTR))) {
    *((LONG_PTR*)&((char*)userWindow)[sizeof(UserWindow) + nIndex]) = dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GWL_EXSTYLE) {
    //TODO: W dokumentacji jest napisane, że jeśli stylem klasy jest CS_CLASSDC lub CS_OWNDC, to nie należy tutaj wrzucać WS_EX_COMPOSITED ani WS_EX_LAYERED
    userWindow->dwExStyle = dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GWL_HINSTANCE) {
    //TODO: Czy z tym się wiążą jakieś dodatkowe operacje?
    userWindow->hInstance = (HINSTANCE)dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GWL_ID) {
    //TODO: Ustawić identyfikator
    return dwOldLong;
  }

  if (nIndex == GWL_STYLE) {
    userWindow->dwStyle = dwNewLong;
    return dwOldLong;
  }

  if (nIndex == GWL_USERDATA) {
    //TODO: Ustawić user data
    return dwOldLong;
  }

  if (nIndex == GWL_WNDPROC) {
    //TODO: Tę wartość można zmienić tylko, jeśli okno należy do tego samego procesu
    //TODO: Taka zmiana tworzy subklasę. Pytanie, czy wtedy tworzony jest łańcuch subklas, czy po prostu jest podmieniana klasa, a CallWindowProc wywołuje oryginalne WndProc z klasy?

    userWindow->lpfnWndProc = (WNDPROC)dwNewLong;
    return dwOldLong;
  }

  //TODO: DWL_DLGPROC
  //TODO: DWL_MSGRESULT
  //TODO: DWL_USER

  return 0;
}

//Changes an attribute of the specified window. The function also sets a value at the specified offset in the extra window memory. 
LONG_PTR WINAPI SetWindowLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong) {
  systemClasses();

  //TODO
  return 0;
}

//Unregisters a window class, freeing the memory required for the class.
BOOL WINAPI UnregisterClassA(LPCSTR lpClassName, HINSTANCE hInstance) {
  systemClasses();

  //TODO: lpClassName może być atomem

  lockWindowClassesMutex();

  if (tryUnregisterClassA(&localClassesA, lpClassName, hInstance)) {
    unlockWindowClassesMutex();
    return 1;
  }

  if (tryUnregisterClassA(&globalClassesA, lpClassName, hInstance)) {
    unlockWindowClassesMutex();
    return 1;
  }

  //TODO: Czy możliwe jest usunięcie klasy, jeśli istnieją jakiekolwiek okna stworzone na jej podstawie?

  //TODO: Unicode

  unlockWindowClassesMutex();
  return 0;
}

//Unregisters a window class, freeing the memory required for the class.
BOOL WINAPI UnregisterClassW(LPCWSTR lpClassName, HINSTANCE hInstance) {
  systemClasses();

  //TODO
  return 0;
}
