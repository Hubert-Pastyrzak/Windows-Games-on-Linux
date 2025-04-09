#pragma once

#include <winuser.h>
#include <X11/Xlib.h>

//TODO: Uchwyty do okien (HWND) mogą występować w różnych bibliotekach
//Więc docelowo ten plik będę musiał przenieść gdzieś indziej

typedef struct {
  Window window;

  WNDCLASSEXA* lpwcx;

  int cbWndExtra;

  //TODO: Kwestia, czy należy takie style przechowywać w strukturze okna, czy sprawdzać systemowo przez X11, jeśli takie coś jest obsługiwane?
  //Może trzeba będzie też nasłuchiwać na takie zmiany z innych aplikacji
  DWORD dwExStyle;

  HINSTANCE hInstance;
  WNDPROC lpfnWndProc;

  //TODO: Rodzic też jest ustawiany przez X11, jak inna aplikacja nam podmieni rodzica to pasowałoby się dowiedzieć, które okno nim jest
  HWND hWndParent;

  //TODO: Identyfikator okna

  //TODO: Tak samo czysto teoretycznie jakaś Linuxowa aplikacja może nam podmienić style
  DWORD dwStyle;

  //TODO: User data
} UserWindow; //UserWindowA
//TODO: Jakaś inna nazwa
