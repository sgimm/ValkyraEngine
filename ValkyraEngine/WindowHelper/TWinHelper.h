#pragma once
#include <Windows.h>

class TWinHelper
{
private:
	static LRESULT CALLBACK StaticWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	UINT_PTR winTimer;
public:
	TWinHelper(void);
	~TWinHelper(void);
	HWND Create3DWindow(HINSTANCE hInstance, LPCSTR lpszClassName, int iCmdShow, bool Windowed, LPCSTR lpszMenuName);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};

