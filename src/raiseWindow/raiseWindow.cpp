#include "raiseWindow.h"
#include <windows.h>

HWND getWindow(const wchar_t *name, const wchar_t *cls)
{
  return FindWindowW(cls, name);
}

bool isAbove(HWND hwndA, HWND hwndB)
{
  HWND h = hwndA;
  for (; h != 0 && h != hwndB; h = GetWindow(h, GW_HWNDPREV))
    ;
  return h == 0;
}

bool raiseWindow(const HWND toRise, const HWND toLower)
{
  return SetWindowPos(toRise, toLower, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}