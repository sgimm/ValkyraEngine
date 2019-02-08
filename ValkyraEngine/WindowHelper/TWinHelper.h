#pragma once
#include <Windows.h>
#include "..\TBaseClass.h"
//void WINAPI  SetCallBackOnPaint(OnPaintEvent OnPaintCallBack);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
HWND Create3DWindow(HINSTANCE hInstance, LPCSTR lpszClassName, int iCmdShow, bool Windowed, LPCSTR lpszMenuName);

 