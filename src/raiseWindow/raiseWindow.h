#pragma once

#include <windows.h>

HWND getWindow(const wchar_t *name, const wchar_t *cls);
bool isAbove(HWND hwndA, HWND hwndB);
bool raiseWindow(const HWND toRise, const HWND toLower);