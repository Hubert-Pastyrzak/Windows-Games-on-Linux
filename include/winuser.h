#pragma once

#include "basetsd.h"
#include "windef.h"
#include "wingdi.h"

#define CS_BYTEALIGNCLIENT 0x00001000
#define CS_BYTEALIGNWINDOW 0x00002000
#define CS_CLASSDC         0x00000040
#define CS_DBLCLKS         0x00000008
#define CS_DROPSHADOW      0x00020000
#define CS_GLOBALCLASS     0x00004000
#define CS_HREDRAW         0x00000002
#define CS_NOCLOSE         0x00000200
#define CS_OWNDC           0x00000020
#define CS_PARENTDC        0x00000080
#define CS_SAVEBITS        0x00000800
#define CS_VREDRAW         0x00000001

#define GCW_ATOM          -32
#define GCL_CBCLSEXTRA    -20
#define GCL_CBWNDEXTRA    -18
#define GCL_HBRBACKGROUND -10
#define GCL_HCURSOR       -12
#define GCL_HICON         -14
#define GCL_HICONSM       -34
#define GCL_HMODULE       -16
#define GCL_MENUNAME       -8
#define GCL_STYLE         -26
#define GCL_WNDPROC       -24

#define GCLP_HBRBACKGROUND -10
#define GCLP_HCURSOR       -12
#define GCLP_HICON         -14
#define GCLP_HICONSM       -34
#define GCLP_HMODULE       -16
#define GCLP_MENUNAME       -8
#define GCLP_WNDPROC       -24

#define GWL_EXSTYLE    -20
#define GWL_HINSTANCE   -6
#define GWL_HWNDPARENT  -8
#define GWL_ID         -12
#define GWL_STYLE      -16
#define GWL_USERDATA   -21
#define GWL_WNDPROC     -4

#define GWLP_HINSTANCE  -6
#define GWLP_ID        -12
#define GWLP_USERDATA  -21
#define GWLP_WNDPROC    -4

#define WS_EX_ACCEPTFILES         0x00000010L
#define WS_EX_APPWINDOW           0x00040000L
#define WS_EX_CLIENTEDGE          0x00000200L
#define WS_EX_COMPOSITED          0x02000000L
#define WS_EX_CONTEXTHELP         0x00000400L
#define WS_EX_CONTROLPARENT       0x00010000L
#define WS_EX_DLGMODALFRAME       0x00000001L
#define WS_EX_LAYERED             0x00080000L
#define WS_EX_LAYOUTRTL           0x00400000L
#define WS_EX_LEFT                0x00000000L
#define WS_EX_LEFTSCROLLBAR       0x00004000L
#define WS_EX_LTRREADING          0x00000000L
#define WS_EX_MDICHILD            0x00000040L
#define WS_EX_NOACTIVATE          0x08000000L
#define WS_EX_NOINHERITLAYOUT     0x00100000L
#define WS_EX_NOPARENTNOTIFY      0x00000004L
#define WS_EX_NOREDIRECTIONBITMAP 0x00200000L
#define WS_EX_RIGHT               0x00001000L
#define WS_EX_RIGHTSCROLLBAR      0x00000000L
#define WS_EX_RTLREADING          0x00002000L
#define WS_EX_STATICEDGE          0x00020000L
#define WS_EX_TOOLWINDOW          0x00000080L
#define WS_EX_TOPMOST             0x00000008L
#define WS_EX_TRANSPARENT         0x00000020L
#define WS_EX_WINDOWEDGE          0x00000100L

#define WS_BORDER       0x00800000L
#define WS_CAPTION      0x00C00000L
#define WS_CHILD        0x40000000L
#define WS_CHILDWINDOW  0x40000000L
#define WS_CLIPCHILDREN 0x02000000L
#define WS_CLIPSIBLINGS 0x04000000L
#define WS_DISABLED     0x08000000L
#define WS_DLGFRAME     0x00400000L
#define WS_GROUP        0x00020000L
#define WS_HSCROLL      0x00100000L
#define WS_ICONIC       0x20000000L
#define WS_MAXIMIZE     0x01000000L
#define WS_MAXIMIZEBOX  0x00010000L
#define WS_MINIMIZE     0x20000000L
#define WS_MINIMIZEBOX  0x00020000L
#define WS_OVERLAPPED   0x00000000L
#define WS_POPUP        0x08000000L
#define WS_SIZEBOX      0x00040000L
#define WS_SYSMENU      0x00080000L
#define WS_TABSTOP      0x00010000L
#define WS_THICKFRAME   0x00040000L
#define WS_TILED        0x00000000L
#define WS_VISIBLE      0x10000000L
#define WS_VSCROLL      0x00200000L

#define MSGFLTINFO_NONE                     0
#define MSGFLTINFO_ALLOWED_HIGHER           3
#define MSGFLTINFO_ALREADYALLOWED_FORWND    1
#define MSGFLTINFO_ALREADYDISALLOWED_FORWND 2

#define GUI_CARETBLINKING  0x00000001
#define GUI_INMENUMODE     0x00000004
#define GUI_INMOVESIZE     0x00000002
#define GUI_POPUPMENUMODE  0x00000010
#define GUI_SYSTEMMENUMODE 0x00000008

#define STATE_SYSTEM_FOCUSABLE   0x00100000
#define STATE_SYSTEM_INVISIBLE   0x00008000
#define STATE_SYSTEM_OFFSCREEN   0x00010000
#define STATE_SYSTEM_UNAVAILABLE 0x00000001
#define STATE_SYSTEM_PRESSED     0x00000008

#define ULW_ALPHA       0x00000002
#define ULW_COLORKEY    0x00000001
#define ULW_OPAQUE      0x00000004
#define ULW_EX_NORESIZE 0x00000008

#define WPF_ASYNCWINDOWPLACEMENT 0x0004
#define WPF_RESTORETOMAXIMIZED   0x0002
#define WPF_SETMINPOSITION       0x0001

#define SWP_ASYNCWINDOWPOS 0x4000
#define SWP_DEFERERASE     0x2000
#define SWP_DRAWFRAME      0x0020
#define SWP_FRAMECHANGED   0x0020
#define SWP_HIDEWINDOW     0x0080
#define SWP_NOACTIVATE     0x0010
#define SWP_NOCOPYBITS     0x0100
#define SWP_NOMOVE         0x0002
#define SWP_NOOWNERZORDER  0x0200
#define SWP_NOREDRAW       0x0008
#define SWP_NOREPOSITION   0x0200
#define SWP_NOSENDCHANGING 0x0400
#define SWP_NOSIZE         0x0001
#define SWP_NOZORDER       0x0004
#define SWP_SHOWWINDOW     0x0040

#define AW_ACTIVATE     0x00020000
#define AW_BLEND        0x00080000
#define AW_CENTER       0x00000010
#define AW_HIDE         0x00010000
#define AW_HOR_POSITIVE 0x00000001
#define AW_HOR_NEGATIVE 0x00000002
#define AW_SLIDE        0x00040000
#define AW_VER_POSITIVE 0x00000004
#define AW_VER_NEGATIVE 0x00000008

#define TPM_CENTERALIGN   0x0004L
#define TPM_LEFTALIGN     0x0000L
#define TPM_RIGHTALIGN    0x0008L
#define TPM_BOTTOMALIGN   0x0020L
#define TPM_TOPALIGN      0x0000L
#define TPM_VCENTERALIGN  0x0010L
#define TPM_HORIZONTAL    0x0000L
#define TPM_VERTICAL      0x0040L
#define TPM_WORKAREA     0x10000L

#define MDITILE_SKIPDISABLED 0x0002
#define MDITILE_ZORDER       0x0004
#define MDITILE_HORIZONTAL   0x0001
#define MDITILE_VERTICAL     0x0000

#define MSGFLT_ADD    1
#define MSGFLT_REMOVE 2

#define MSGFLT_ALLOW    1
#define MSGFLT_DISALLOW 2
#define MSGFLT_RESET    0

#define CWP_ALL             0x0000
#define CWP_SKIPDISABLED    0x0002
#define CWP_SKIPINVISIBLE   0x0001
#define CWP_SKIPTRANSPARENT 0x0004

#define HWND_BOTTOM    ((HWND)1)
#define HWND_NOTOPMOST ((HWND)-2)
#define HWND_TOP       ((HWND)0)
#define HWND_TOPMOST   ((HWND)-1)

#define GA_PARENT    1
#define GA_ROOT      2
#define GA_ROOTOWNER 3

#define LWA_ALPHA    0x00000002
#define LWA_COLORKEY 0x00000001

#define GW_CHILD        5
#define GW_ENABLEDPOPUP 6
#define GW_HWNDFIRST    0
#define GW_HWNDLAST     1
#define GW_HWNDNEXT     2
#define GW_HWNDPREV     3
#define GW_OWNER        4

#define COLOR_3DDKSHADOW              21
#define COLOR_3DFACE                  15
#define COLOR_3DHIGHLIGHT             20
#define COLOR_3DHILIGHT               20
#define COLOR_3DLIGHT                 22
#define COLOR_3DSHADOW                16
#define COLOR_ACTIVEBORDER            10
#define COLOR_ACTIVECAPTION            2
#define COLOR_APPWORKSPACE            12
#define COLOR_BACKGROUND               1
#define COLOR_BTNFACE                 15
#define COLOR_BTNHIGHLIGHT            20
#define COLOR_BTNHILIGHT              20
#define COLOR_BTNSHADOW               16
#define COLOR_BTNTEXT                 18
#define COLOR_CAPTIONTEXT              9
#define COLOR_DESKTOP                  1
#define COLOR_GRADIENTACTIVECAPTION   27
#define COLOR_GRADIENTINACTIVECAPTION 28
#define COLOR_GRAYTEXT                17
#define COLOR_HIGHLIGHT               13
#define COLOR_HIGHLIGHTTEXT           14
#define COLOR_HOTLIGHT                26
#define COLOR_INACTIVEBORDER          11
#define COLOR_INACTIVECAPTION          3
#define COLOR_INACTIVECAPTIONTEXT     19
#define COLOR_INFOBK                  24
#define COLOR_INFOTEXT                23
#define COLOR_MENU                     4
#define COLOR_MENUHILIGHT             29
#define COLOR_MENUBAR                 30
#define COLOR_MENUTEXT                 7
#define COLOR_SCROLLBAR                0
#define COLOR_WINDOW                   5
#define COLOR_WINDOWFRAME              6
#define COLOR_WINDOWTEXT               8

#define LSFW_LOCK   1
#define LSFW_UNLOCK 2

#define LAYOUT_RTL 0x00000001

#define WDA_NONE               0x00000000
#define WDA_MONITOR            0x00000001
#define WDA_EXCLUDEFROMCAPTURE 0x00000011

#define SW_HIDE             0
#define SW_SHOWNORMAL       1
#define SW_NORMAL           1
#define SW_SHOWMINIMIZED    2
#define SW_SHOWMAXIMIZED    3
#define SW_MAXIMIZE         3
#define SW_SHOWNOACTIVATE   4
#define SW_SHOW             5
#define SW_MINIMIZE         6
#define SW_SHOWMINNOACTIVE  7
#define SW_SHOWNA           8
#define SW_RESTORE          9
#define SW_SHOWDEFAULT     10
#define SW_FORCEMINIMIZE   11

#define CCHILDREN_TITLEBAR 5

#define CW_USEDEFAULT 0x80000000

#define BSF_ALLOWSFW           0x00000080
#define BSF_FLUSHDISK          0x00000004
#define BSF_FORCEIFHUNG        0x00000020
#define BSF_IGNORECURRENTTASK  0x00000002
#define BSF_NOHANG             0x00000008
#define BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#define BSF_POSTMESSAGE        0x00000010
#define BSF_QUERY              0x00000001
#define BSF_SENDNOTIFYMESSAGE  0x00000100

#define BSM_ALLCOMPONENTS 0x00000000
#define BSM_ALLDESKTOPS   0x00000010
#define BSM_APPLICATIONS  0x00000008

#define QS_KEY            0x0001
#define QS_MOUSEMOVE      0x0002
#define QS_MOUSEBUTTON    0x0004
#define QS_POSTMESSAGE    0x0008
#define QS_TIMER          0x0010
#define QS_PAINT          0x0020
#define QS_SENDMESSAGE    0x0040
#define QS_HOTKEY         0x0080
#define QS_ALLPOSTMESSAGE 0x0100
#define QS_RAWINPUT       0x0400
#define QS_TOUCH          0x0800
#define QS_POINTER        0x1000

#define QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)

#define QS_INPUT (QS_MOUSE | QS_KEY | QS_RAWINPUT | QS_TOUCH | QS_POINTER)

#define QS_ALLEVENTS (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#define QS_ALLINPUT  (QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#define ISMEX_CALLBACK 0x00000004
#define ISMEX_NOTIFY   0x00000002
#define ISMEX_REPLIED  0x00000008
#define ISMEX_SEND     0x00000001

//#define HWND_??? ((HWND)0xFFFF)

#define WM_APP  0x8000
#define WM_USER 0x0400

//TODO: Zaimplementować te komunikaty
#define WM_DISPLAYCHANGE 0x007E //TODO: Ten komunikat jest wysyłany do wszystkich okien gdy zmienia się rozdzielczość ekranu
#define WM_ERASEBKGND    0x0014 //TODO: Wysyłane w jakimś tam momencie związanym z tłem okna (np. przy zmianie rozmiaru)
#define WM_NCPAINT       0x0085 //TODO: Wysyłane do okna, gdy potrzebne jest narysowanie jego ramki (ciężko stwierdzić, jak będzie wyglądała implementacja tego komunikatu pod Linuksem)
#define WM_PAINT         0x000F
#define WM_PRINT         0x0317
#define WM_PRINTCLIENT   0x0318
#define WM_SETREDRAW     0x000B
#define WM_SYNCPAINT     0x0088

//Pozostałe komunikaty (trzeba zebrać wszystkie)
#define WM_DESTROY 0x0002



#define WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#define WS_EX_PALETTEWINDOW    (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)

#define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#define WS_POPUPWINDOW      (WS_POPUP | WS_BORDER | WS_SYSMENU)
#define WS_TILEDWINDOW      (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)



typedef HANDLE HDWP;

typedef BOOL (WINAPI *WNDENUMPROC)(HWND hwnd, LPARAM lParam);
typedef LRESULT (WINAPI *WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef void (WINAPI *SENDASYNCPROC)(HWND, UINT, ULONG_PTR, LRESULT);
typedef BOOL (WINAPI *DRAWSTATEPROC)(HDC hdc, LPARAM lData, WPARAM wData, int cx, int cy);
typedef BOOL (WINAPI *GRAYSTRINGPROC)(HDC, LPARAM, int);

typedef enum tagFEEDBACK_TYPE {
  FEEDBACK_TOUCH_CONTACTVISUALIZATION = 1,
  FEEDBACK_PEN_BARRELVISUALIZATION = 2,
  FEEDBACK_PEN_TAP = 3,
  FEEDBACK_PEN_DOUBLETAP = 4,
  FEEDBACK_PEN_PRESSANDHOLD = 5,
  FEEDBACK_PEN_RIGHTTAP = 6,
  FEEDBACK_TOUCH_TAP = 7,
  FEEDBACK_TOUCH_DOUBLETAP = 8,
  FEEDBACK_TOUCH_PRESSANDHOLD = 9,
  FEEDBACK_TOUCH_RIGHTTAP = 10,
  FEEDBACK_GESTURE_PRESSANDTAP = 11,
  FEEDBACK_MAX = 0xFFFFFFFF,
} FEEDBACK_TYPE;

typedef struct tagWNDCLASSA {
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCSTR    lpszMenuName;
  LPCSTR    lpszClassName;
} WNDCLASSA, *PWNDCLASSA, *NPWNDCLASSA, *LPWNDCLASSA;

typedef struct tagWNDCLASSW {
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCWSTR   lpszMenuName;
  LPCWSTR   lpszClassName;
} WNDCLASSW, *PWNDCLASSW, *NPWNDCLASSW, *LPWNDCLASSW;

typedef struct tagWNDCLASSEXA {
  UINT      cbSize;
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCSTR    lpszMenuName;
  LPCSTR    lpszClassName;
  HICON     hIconSm;
} WNDCLASSEXA, *PWNDCLASSEXA, *NPWNDCLASSEXA, *LPWNDCLASSEXA;

typedef struct tagWNDCLASSEXW {
  UINT      cbSize;
  UINT      style;
  WNDPROC   lpfnWndProc;
  int       cbClsExtra;
  int       cbWndExtra;
  HINSTANCE hInstance;
  HICON     hIcon;
  HCURSOR   hCursor;
  HBRUSH    hbrBackground;
  LPCWSTR   lpszMenuName;
  LPCWSTR   lpszClassName;
  HICON     hIconSm;
} WNDCLASSEXW, *PWNDCLASSEXW, *NPWNDCLASSEXW, *LPWNDCLASSEXW;

typedef struct tagALTTABINFO {
  DWORD cbSize;
  int   cItems;
  int   cColumns;
  int   cRows;
  int   iColFocus;
  int   iRowFocus;
  int   cxItem;
  int   cyItem;
  POINT ptStart;
} ALTTABINFO, *PALTTABINFO, *LPALTTABINFO;

typedef struct tagCHANGEFILTERSTRUCT {
  DWORD cbSize;
  DWORD ExtStatus;
} CHANGEFILTERSTRUCT, *PCHANGEFILTERSTRUCT;

typedef struct tagCLIENTCREATESTRUCT {
  HANDLE hWindowMenu;
  UINT   idFirstChild;
} CLIENTCREATESTRUCT, *LPCLIENTCREATESTRUCT;

typedef struct tagCREATESTRUCTA {
  LPVOID    lpCreateParams;
  HINSTANCE hInstance;
  HMENU     hMenu;
  HWND      hwndParent;
  int       cy;
  int       cx;
  int       y;
  int       x;
  LONG      style;
  LPCSTR    lpszName;
  LPCSTR    lpszClass;
  DWORD     dwExStyle;
} CREATESTRUCTA, *LPCREATESTRUCTA;

typedef struct tagCREATESTRUCTW {
  LPVOID    lpCreateParams;
  HINSTANCE hInstance;
  HMENU     hMenu;
  HWND      hwndParent;
  int       cy;
  int       cx;
  int       y;
  int       x;
  LONG      style;
  LPCWSTR   lpszName;
  LPCWSTR   lpszClass;
  DWORD     dwExStyle;
} CREATESTRUCTW, *LPCREATESTRUCTW;

typedef struct tagGUITHREADINFO {
  DWORD cbSize;
  DWORD flags;
  HWND  hwndActive;
  HWND  hwndFocus;
  HWND  hwndCapture;
  HWND  hwndMenuOwner;
  HWND  hwndMoveSize;
  HWND  hwndCaret;
  RECT  rcCaret;
} GUITHREADINFO, *PGUITHREADINFO, *LPGUITHREADINFO;

typedef struct tagMINMAXINFO {
  POINT ptReserved;
  POINT ptMaxSize;
  POINT ptMaxPosition;
  POINT ptMinTrackSize;
  POINT ptMaxTrackSize;
} MINMAXINFO, *PMINMAXINFO, *LPMINMAXINFO;

typedef struct tagWINDOWPOS {
  HWND hwnd;
  HWND hwndInsertAfter;
  int  x;
  int  y;
  int  cx;
  int  cy;
  UINT flags;
} WINDOWPOS, *LPWINDOWPOS, *PWINDOWPOS;

typedef struct tagSTYLESTRUCT {
  DWORD styleOld;
  DWORD styleNew;
} STYLESTRUCT, *LPSTYLESTRUCT;

typedef struct tagTITLEBARINFO {
  DWORD cbSize;
  RECT  rcTitleBar;
  DWORD rgstate[CCHILDREN_TITLEBAR + 1];
} TITLEBARINFO, *PTITLEBARINFO, *LPTITLEBARINFO;

typedef struct tagTITLEBARINFOEX {
  DWORD cbSize;
  RECT  rcTitleBar;
  DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  RECT  rgrect[CCHILDREN_TITLEBAR + 1];
} TITLEBARINFOEX, *PTITLEBARINFOEX, *LPTITLEBARINFOEX;

typedef struct tagUPDATELAYEREDWINDOWINFO {
  DWORD                cbSize;
  HDC                  hdcDst;
  const POINT*         pptDst;
  const SIZE*          psize;
  HDC                  hdcSrc;
  const POINT*         pptSrc;
  COLORREF             crKey;
  const BLENDFUNCTION* pblend;
  DWORD                dwFlags;
  const RECT*          prcDirty;
} UPDATELAYEREDWINDOWINFO, *PUPDATELAYEREDWINDOWINFO;

typedef struct tagWINDOWINFO {
  DWORD cbSize;
  RECT  rcWindow;
  RECT  rcClient;
  DWORD dwStyle;
  DWORD dwExStyle;
  DWORD dwWindowStatus;
  UINT  cxWindowBorders;
  UINT  cyWindowBorders;
  ATOM  atomWindowType;
  WORD  wCreatorVersion;
} WINDOWINFO, *PWINDOWINFO, *LPWINDOWINFO;

typedef struct tagWINDOWPLACEMENT {
  UINT  length;
  UINT  flags;
  UINT  showCmd;
  POINT ptMinPosition;
  POINT ptMaxPosition;
  RECT  rcNormalPosition;
  RECT  rcDevice;
} WINDOWPLACEMENT;

typedef struct {
  UINT cbSize;
  HDESK hdesk;
  HWND hwnd;
  LUID luid;
} BSMINFO, *PBSMINFO;

typedef struct tagMSG {
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
  DWORD lPrivate;
} MSG, *PMSG, *NPMSG, *LPMSG;

typedef struct tagPAINTSTRUCT {
  HDC hdc;
  BOOL fErase;
  RECT rcPaint;
  BOOL fRestore;
  BOOL fIncUpdate;
  BYTE rgbReserved[32];
} PAINTSTRUCT, *PPAINTSTRUCT, *NPPAINTSTRUCT, *LPPAINTSTRUCT;



typedef struct tagNCCALCSIZE_PARAMS {
  RECT       rgrc[3];
  PWINDOWPOS lppos;
} NCCALCSIZE_PARAMS, *LPNCCALCSIZE_PARAMS;



#if defined(UNICODE)
  #define WNDCLASS   WNDCLASSW
  #define WNDCLASSEX WNDCLASSEXW
#else
  #define WNDCLASS   WNDCLASSA
  #define WNDCLASSEX WNDCLASSEXA
#endif



BOOL WINAPI GetClassInfoA(HINSTANCE hInstance, LPCSTR lpClassName, LPWNDCLASSA lpWndClass);
BOOL WINAPI GetClassInfoW(HINSTANCE hInstance, LPCWSTR lpClassName, LPWNDCLASSW lpWndClass);
BOOL WINAPI GetClassInfoExA(HINSTANCE hInstance, LPCSTR lpszClass, LPWNDCLASSEXA lpwcx);
BOOL WINAPI GetClassInfoExW(HINSTANCE hInstance, LPCWSTR lpszClass, LPWNDCLASSEXW lpwcx);
DWORD WINAPI GetClassLongA(HWND hWnd, int nIndex);
DWORD WINAPI GetClassLongW(HWND hWnd, int nIndex);
ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd, int nIndex);
ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd, int nIndex);
//TODO: GetClassName??? Funkcja czy macro? Wtf? Raczej makro
int WINAPI GetClassNameA(HWND hWnd, LPSTR lpClassName, int nMaxCount);
int WINAPI GetClassNameW(HWND hWnd, LPWSTR lpClassName, int nMaxCount);
WORD WINAPI GetClassWord(HWND hWnd, int nIndex);
LONG WINAPI GetWindowLongA(HWND hWnd, int nIndex);
LONG WINAPI GetWindowLongW(HWND hWnd, int nIndex);
LONG_PTR WINAPI GetWindowLongPtrA(HWND hWnd, int nIndex);
LONG_PTR WINAPI GetWindowLongPtrW(HWND hWnd, int nIndex);
ATOM WINAPI RegisterClassA(const WNDCLASSA* lpWndClass);
ATOM WINAPI RegisterClassW(const WNDCLASSW* lpWndClass);
ATOM WINAPI RegisterClassExA(const WNDCLASSEXA* lpwcx);
ATOM WINAPI RegisterClassExW(const WNDCLASSEXW* lpwcx);
DWORD WINAPI SetClassLongA(HWND hWnd, int nIndex, LONG dwNewLong);
DWORD WINAPI SetClassLongW(HWND hWnd, int nIndex, LONG dwNewLong);
ULONG_PTR WINAPI SetClassLongPtrA(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
ULONG_PTR WINAPI SetClassLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
WORD WINAPI SetClassWord(HWND hWnd, int nIndex, WORD wNewWord);
LONG WINAPI SetWindowLongA(HWND hWnd, int nIndex, LONG dwNewLong);
LONG WINAPI SetWindowLongW(HWND hWnd, int nIndex, LONG dwNewLong);
LONG_PTR WINAPI SetWindowLongPtrA(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
LONG_PTR WINAPI SetWindowLongPtrW(HWND hWnd, int nIndex, LONG_PTR dwNewLong);
BOOL WINAPI UnregisterClassA(LPCSTR lpClassName, HINSTANCE hInstance);
BOOL WINAPI UnregisterClassW(LPCWSTR lpClassName, HINSTANCE hInstance);

BOOL WINAPI AdjustWindowRect(LPRECT lpRect, DWORD dwStyle, BOOL bMenu);
BOOL WINAPI AdjustWindowRectEx(LPRECT lpRect, DWORD dwStyle, BOOL bMenu, DWORD dwExStyle);
BOOL WINAPI AllowSetForegroundWindow(DWORD dwProcessId);
BOOL WINAPI AnimateWindow(HWND hWnd, DWORD dwTime, DWORD dwFlags);
BOOL WINAPI AnyPopup();
UINT WINAPI ArrangeIconicWindows(HWND hWnd);
HDWP WINAPI BeginDeferWindowPos(int nNumWindows);
BOOL WINAPI BringWindowToTop(HWND hWnd);
BOOL WINAPI CalculatePopupWindowPosition(const POINT* anchorPoint, const SIZE* windowSize, UINT flags, RECT* excludeRect, RECT* popupWindowPosition);
WORD WINAPI CascadeWindows(HWND hwndParent, UINT wHow, const RECT* lpRect, UINT cKids, const HWND* lpKids);
BOOL WINAPI ChangeWindowMessageFilter(UINT message, DWORD dwFlag);
BOOL WINAPI ChangeWindowMessageFilterEx(HWND hwnd, UINT message, DWORD action, PCHANGEFILTERSTRUCT pChangeFilterStruct);
HWND WINAPI ChildWindowFromPoint(HWND hWndParent, POINT Point);
HWND WINAPI ChildWindowFromPointEx(HWND hwnd, POINT pt, UINT flags);
BOOL WINAPI CloseWindow(HWND hWnd);
HWND WINAPI CreateWindowExA(DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
HWND WINAPI CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam);
HDWP WINAPI DeferWindowPos(HDWP hWinPosInfo, HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags);
BOOL WINAPI DeregisterShellHookWindow(HWND hwnd);
BOOL WINAPI DestroyWindow(HWND hWnd);
BOOL WINAPI EndDeferWindowPos(HDWP hWinPosInfo);
BOOL WINAPI EndTask(HWND hWnd, BOOL fShutDown, BOOL fForce);
BOOL WINAPI EnumChildWindows(HWND hWndParent, WNDENUMPROC lpEnumFunc, LPARAM lParam);
BOOL WINAPI EnumThreadWindows(DWORD dwThreadId, WNDENUMPROC lpfn, LPARAM lParam);
BOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam);
HWND WINAPI FindWindowA(LPCSTR lpClassName, LPCSTR lpWindowName);
HWND WINAPI FindWindowW(LPCWSTR lpClassName, LPCWSTR lpWindowName);
HWND WINAPI FindWindowExA(HWND hWndParent, HWND hWndChildAfter, LPCSTR lpszClass, LPCSTR lpszWindow);
HWND WINAPI FindWindowExW(HWND hWndParent, HWND hWndChildAfter, LPCWSTR lpszClass, LPCWSTR lpszWindow);
BOOL WINAPI GetAltTabInfoA(HWND hwnd, int iItem, PALTTABINFO pati, LPSTR pszItemText, UINT cchItemText);
BOOL WINAPI GetAltTabInfoW(HWND hwnd, int iItem, PALTTABINFO pati, LPWSTR pszItemText, UINT cchItemText);
HWND WINAPI GetAncestor(HWND hwnd, UINT gaFlags);
BOOL WINAPI GetClientRect(HWND hWnd, LPRECT lpRect);
HWND WINAPI GetDesktopWindow();
HWND WINAPI GetForegroundWindow();
BOOL WINAPI GetGUIThreadInfo(DWORD idThread, PGUITHREADINFO pgui);
HWND WINAPI GetLastActivePopup(HWND hWnd);
BOOL WINAPI GetLayeredWindowAttributes(HWND hwnd, COLORREF* pcrKey, BYTE* pbAlpha, DWORD* pdwFlags);
HWND WINAPI GetParent(HWND hWnd);
BOOL WINAPI GetProcessDefaultLayout(DWORD* pdwDefaultLayout);
HWND WINAPI GetShellWindow();
DWORD WINAPI GetSysColor(int nIndex);
BOOL WINAPI GetTitleBarInfo(HWND hwnd, PTITLEBARINFO pti);
HWND WINAPI GetTopWindow(HWND hWnd);
HWND WINAPI GetWindow(HWND hWnd, UINT uCmd);
BOOL WINAPI GetWindowDisplayAffinity(HWND hWnd, DWORD* pdwAffinity);
BOOL WINAPI GetWindowInfo(HWND hwnd, PWINDOWINFO pwi);
UINT WINAPI GetWindowModuleFileNameA(HWND hwnd, LPSTR pszFileName, UINT cchFileNameMax);
UINT WINAPI GetWindowModuleFileNameW(HWND hwnd, LPWSTR pszFileName, UINT cchFileNameMax);
BOOL WINAPI GetWindowPlacement(HWND hWnd, WINDOWPLACEMENT* lpwndpl);
BOOL WINAPI GetWindowRect(HWND hWnd, LPRECT lpRect);
int WINAPI GetWindowTextA(HWND hWnd, LPSTR lpString, int nMaxCount);
int WINAPI GetWindowTextW(HWND hWnd, LPWSTR lpString, int nMaxCount);
int WINAPI GetWindowTextLengthA(HWND hWnd);
int WINAPI GetWindowTextLengthW(HWND hWnd);
DWORD WINAPI GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId);
int WINAPI InternalGetWindowText(HWND hWnd, LPWSTR pString, int cchMaxCount);
BOOL WINAPI IsChild(HWND hWndParent, HWND hWnd);
BOOL WINAPI IsGUIThread(BOOL bConvert);
BOOL WINAPI IsHungAppWindow(HWND hwnd);
BOOL WINAPI IsIconic(HWND hWnd);
BOOL WINAPI IsProcessDPIAware();
BOOL WINAPI IsWindow(HWND hWnd);
BOOL WINAPI IsWindowUnicode(HWND hWnd);
BOOL WINAPI IsWindowVisible(HWND hWnd);
BOOL WINAPI IsZoomed(HWND hWnd);
BOOL WINAPI LockSetForegroundWindow(UINT uLockCode);
BOOL WINAPI LogicalToPhysicalPoint(HWND hWnd, LPPOINT lpPoint);
BOOL WINAPI MoveWindow(HWND hWnd, int X, int Y, int nWidth, int nHeight, BOOL bRepaint);
BOOL WINAPI OpenIcon(HWND hWnd);
BOOL WINAPI PhysicalToLogicalPoint(HWND hWnd, LPPOINT lpPoint);
HWND WINAPI RealChildWindowFromPoint(HWND hwndParent, POINT ptParentClientCoords);
UINT WINAPI RealGetWindowClassA(HWND hwnd, LPSTR ptszClassName, UINT cchClassNameMax);
UINT WINAPI RealGetWindowClassW(HWND hwnd, LPWSTR ptszClassName, UINT cchClassNameMax);
BOOL WINAPI RegisterShellHookWindow(HWND hwnd);
BOOL WINAPI SetForegroundWindow(HWND hWnd);
BOOL WINAPI SetLayeredWindowAttributes(HWND hwnd, COLORREF crKey, BYTE bAlpha, DWORD dwFlags);
HWND WINAPI SetParent(HWND hWndChild, HWND hWndNewParent);
BOOL WINAPI SetProcessDefaultLayout(DWORD dwDefaultLayout);
BOOL WINAPI SetProcessDPIAware();
BOOL WINAPI SetSysColors(int cElements, const INT* lpaElements, const COLORREF* lpaRgbValues);
BOOL WINAPI SetWindowDisplayAffinity(HWND hWnd, DWORD dwAffinity);
BOOL WINAPI SetWindowFeedbackSettings(HWND hwnd, FEEDBACK_TYPE feedback, DWORD flags, UINT32 size, const VOID* configuration);
BOOL WINAPI SetWindowPlacement(HWND hWnd, const WINDOWPLACEMENT* lpwndpl);
BOOL WINAPI SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int X, int Y, int cx, int cy, UINT uFlags);
BOOL WINAPI SetWindowTextA(HWND hWnd, LPCSTR lpString);
BOOL WINAPI SetWindowTextW(HWND hWnd, LPCWSTR lpString);
BOOL WINAPI ShowOwnedPopups(HWND hWnd, BOOL fShow);
BOOL WINAPI ShowWindow(HWND hWnd, int nCmdShow);
BOOL WINAPI ShowWindowAsync(HWND hWnd, int nCmdShow);
BOOL WINAPI SoundSentry();
void WINAPI SwitchToThisWindow(HWND hwnd, BOOL fUnknown);
WORD WINAPI TileWindows(HWND hwndParent, UINT wHow, const RECT* lpRect, UINT cKids, const HWND* lpKids);
BOOL WINAPI UpdateLayeredWindow(HWND hWnd, HDC hdcDst, POINT* pptDst, SIZE* psize, HDC hdcSrc, POINT* pptSrc, COLORREF crKey, BLENDFUNCTION* pblend, DWORD dwFlags);
BOOL WINAPI UpdateLayeredWindowIndirect(HWND hwnd, const UPDATELAYEREDWINDOWINFO* pULWInfo);
HWND WINAPI WindowFromPhysicalPoint(POINT Point);
HWND WINAPI WindowFromPoint(POINT Point);

long WINAPI BroadcastSystemMessage(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam);
long WINAPI BroadcastSystemMessageA(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam);
long WINAPI BroadcastSystemMessageW(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam);
long WINAPI BroadcastSystemMessageExA(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo);
long WINAPI BroadcastSystemMessageExW(DWORD flags, LPDWORD lpInfo, UINT Msg, WPARAM wParam, LPARAM lParam, PBSMINFO pbsmInfo);
LRESULT WINAPI DispatchMessage(const MSG* lpMsg);
LRESULT WINAPI DispatchMessageA(const MSG* lpMsg);
LRESULT WINAPI DispatchMessageW(const MSG* lpMsg);
BOOL WINAPI GetInputState();
BOOL WINAPI GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL WINAPI GetMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
BOOL WINAPI GetMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
LPARAM WINAPI GetMessageExtraInfo();
DWORD WINAPI GetMessagePos();
LONG WINAPI GetMessageTime();
DWORD WINAPI GetQueueStatus(UINT flags);
BOOL WINAPI InSendMessage();
DWORD WINAPI InSendMessageEx(LPVOID lpReserved);
BOOL WINAPI PeekMessageA(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL WINAPI PeekMessageW(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg);
BOOL WINAPI PostMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void WINAPI PostQuitMessage(int nExitCode);
BOOL WINAPI PostThreadMessageA(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI PostThreadMessageW(DWORD idThread, UINT Msg, WPARAM wParam, LPARAM lParam);
UINT WINAPI RegisterWindowMessageA(LPCSTR lpString);
UINT WINAPI RegisterWindowMessageW(LPCWSTR lpString);
BOOL WINAPI ReplyMessage(LRESULT lResult);
LRESULT WINAPI SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI SendMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI SendMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI SendMessageCallbackA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpResultCallBack, ULONG_PTR dwData);
BOOL WINAPI SendMessageCallbackW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, SENDASYNCPROC lpResultCallBack, ULONG_PTR dwData);
LRESULT WINAPI SendMessageTimeoutA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult);
LRESULT WINAPI SendMessageTimeoutW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam, UINT fuFlags, UINT uTimeout, PDWORD_PTR lpdwResult);
BOOL WINAPI SendNotifyMessageA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
BOOL WINAPI SendNotifyMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LPARAM WINAPI SetMessageExtraInfo(LPARAM lParam);
BOOL WINAPI TranslateMessage(const MSG* lpMsg);
BOOL WINAPI WaitMessage();

LRESULT WINAPI CallWindowProcA(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI CallWindowProcW(WNDPROC lpPrevWndFunc, HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI DefWindowProcA(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

HDC WINAPI BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint);
BOOL WINAPI DrawAnimatedRects(HWND hwnd, int idAni, const RECT* lprcFrom, const RECT* lprcTo);
BOOL WINAPI DrawCaption(HWND hwnd, HDC hdc, const RECT* lprect, UINT flags);
BOOL WINAPI DrawEdge(HDC hdc, LPRECT qrc, UINT edge, UINT grfFlags);
BOOL WINAPI DrawFocusRect(HDC hDC, const RECT* lprc);
BOOL WINAPI DrawFrameControl(HDC hdc, LPRECT lprc, UINT uType, UINT uState);
BOOL WINAPI DrawStateA(HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags);
BOOL WINAPI DrawStateW(HDC hdc, HBRUSH hbrFore, DRAWSTATEPROC qfnCallBack, LPARAM lData, WPARAM wData, int x, int y, int cx, int cy, UINT uFlags);
BOOL WINAPI EndPaint(HWND hWnd, const PAINTSTRUCT* lpPaint);
int WINAPI ExcludeUpdateRgn(HDC hDC, HWND hWnd);
BOOL WINAPI GetUpdateRect(HWND hWnd, LPRECT lpRect, BOOL bErase);
int WINAPI GetUpdateRgn(HWND hWnd, HRGN hRgn, BOOL bErase);
HDC WINAPI GetWindowDC(HWND hWnd);
int WINAPI GetWindowRgn(HWND hWnd, HRGN hRgn);
int WINAPI GetWindowRgnBox(HWND hWnd, LPRECT lprc);
BOOL WINAPI GrayStringA(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight);
BOOL WINAPI GrayStringW(HDC hDC, HBRUSH hBrush, GRAYSTRINGPROC lpOutputFunc, LPARAM lpData, int nCount, int X, int Y, int nWidth, int nHeight);
BOOL WINAPI InvalidateRect(HWND hWnd, const RECT* lpRect, BOOL bErase);
BOOL WINAPI InvalidateRgn(HWND hWnd, HRGN hRgn, BOOL bErase);
BOOL WINAPI LockWindowUpdate(HWND hWndLock);
BOOL WINAPI PaintDesktop(HDC hdc);
BOOL WINAPI RedrawWindow(HWND hWnd, const RECT* lprcUpdate, HRGN hrgnUpdate, UINT flags);
int WINAPI SetWindowRgn(HWND hWnd, HRGN hRgn, BOOL bRedraw);
BOOL WINAPI UpdateWindow(HWND hWnd);
BOOL WINAPI ValidateRect(HWND hWnd, const RECT* lpRect);
BOOL WINAPI ValidateRgn(HWND hWnd, HRGN hRgn);
HWND WINAPI WindowFromDC(HDC hDC);



#define CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam) CreateWindowExA(0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam) CreateWindowExW(0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam)
#define GetNextWindow(hWnd, wCmd) GetWindow(hWnd, wCmd)



#if defined(UNICODE)
  #define GetClassInfo     GetClassInfoW
  #define GetClassInfoEx   GetClassInfoExW
  #define GetClassLong     GetClassLongW
  #define GetClassLongPtr  GetClassLongPtrW
  #define GetClassName     GetClassNameW
  #define GetWindowLong    GetWindowLongW
  #define GetWindowLongPtr GetWindowLongPtrW
  #define RegisterClass    RegisterClassW
  #define RegisterClassEx  RegisterClassExW
  #define SetClassLong     SetClassLongW
  #define SetClassLongPtr  SetClassLongPtrW
  #define SetWindowLong    SetWindowLongW
  #define SetWindowLongPtr SetWindowLongPtrW
  #define UnregisterClass  UnregisterClassW

  #define CreateWindow            CreateWindowW
  #define CreateWindowEx          CreateWindowExW
  #define FindWindow              FindWindowW
  #define FindWindowEx            FindWindowExW
  #define GetAltTabInfo           GetAltTabInfoW
  #define GetWindowModuleFileName GetWindowModuleFileNameW
  #define GetWindowText           GetWindowTextW
  #define GetWindowTextLength     GetWindowTextLengthW
  #define RealGetWindowClass      RealGetWindowClassW
  #define SetWindowText           SetWindowTextW

  #define BroadcastSystemMessageEx BroadcastSystemMessageExW
  #define PeekMessage              PeekMessageW
  #define PostMessage              PostMessageW
  #define PostThreadMessage        PostThreadMessageW
  #define RegisterWindowMessage    RegisterWindowMessageW
  #define SendMessageCallback      SendMessageCallbackW
  #define SendMessageTimeout       SendMessageTimeoutW
  #define SendNotifyMessage        SendNotifyMessageW

  #define CallWindowProc CallWindowProcW
  #define DefWindowProc  DefWindowProcW

  #define DrawState  DrawStateW
  #define GrayString GrayStringW
#else
  #define GetClassInfo     GetClassInfoA
  #define GetClassInfoEx   GetClassInfoExA
  #define GetClassLong     GetClassLongA
  #define GetClassLongPtr  GetClassLongPtrA
  #define GetClassName     GetClassNameA
  #define GetWindowLong    GetWindowLongA
  #define GetWindowLongPtr GetWindowLongPtrA
  #define RegisterClass    RegisterClassA
  #define RegisterClassEx  RegisterClassExA
  #define SetClassLong     SetClassLongA
  #define SetClassLongPtr  SetClassLongPtrA
  #define SetWindowLong    SetWindowLongA
  #define SetWindowLongPtr SetWindowLongPtrA
  #define UnregisterClass  UnregisterClassA

  #define CreateWindow            CreateWindowA
  #define CreateWindowEx          CreateWindowExA
  #define FindWindow              FindWindowA
  #define FindWindowEx            FindWindowExA
  #define GetAltTabInfo           GetAltTabInfoA
  #define GetWindowModuleFileName GetWindowModuleFileNameA
  #define GetWindowText           GetWindowTextA
  #define GetWindowTextLength     GetWindowTextLengthA
  #define RealGetWindowClass      RealGetWindowClassA
  #define SetWindowText           SetWindowTextA

  #define BroadcastSystemMessageEx BroadcastSystemMessageExA
  #define PeekMessage              PeekMessageA
  #define PostMessage              PostMessageA
  #define PostThreadMessage        PostThreadMessageA
  #define RegisterWindowMessage    RegisterWindowMessageA
  #define SendMessageCallback      SendMessageCallbackA
  #define SendMessageTimeout       SendMessageTimeoutA
  #define SendNotifyMessage        SendNotifyMessageA

  #define CallWindowProc CallWindowProcA
  #define DefWindowProc  DefWindowProcA

  #define DrawState  DrawStateA
  #define GrayString GrayStringA
#endif
