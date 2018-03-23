#pragma once
#include <Windows.h>
#include "..\TBaseClass.h"

typedef void(*OnKeyDownEvent)(WPARAM wParam);
typedef void(*OnKeyUpEvent)(WPARAM wParam);
typedef void(*OnMouseMoveEvent)();
typedef void(*OnMouseKeyDownEvent)();
typedef void(*OnPaintEvent)();

class TWinHelper:public TBaseClass
{
private:
	static LRESULT CALLBACK StaticWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	UINT_PTR winTimer;
public:
	TWinHelper(void);
	~TWinHelper(void);
	OnKeyDownEvent OnKeyDown;
	OnKeyUpEvent OnKeyUp;
	OnPaintEvent OnPaint;
	HWND Create3DWindow(HINSTANCE hInstance, LPCSTR lpszClassName, int iCmdShow, bool Windowed, LPCSTR lpszMenuName);
	LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
};

