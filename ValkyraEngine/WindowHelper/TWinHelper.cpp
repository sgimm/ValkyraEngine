#include "TWinHelper.h"
HWND Create3DWindow(HINSTANCE hInstance, LPCSTR lpszClassName, int iCmdShow, bool Windowed, LPCSTR lpszMenuName)
{
	HWND hwnd;
    WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));
    wcex.cbSize = sizeof( WNDCLASSEX );
    wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.hCursor = LoadCursor( NULL, IDC_ARROW );
    wcex.lpszClassName = lpszClassName;
	wcex.lpszMenuName = MAKEINTRESOURCE(lpszMenuName);

	RegisterClassEx(&wcex);

	RECT rc = { 0, 0, 1920, 1080 };
    AdjustWindowRect( &rc, WS_OVERLAPPEDWINDOW, FALSE );
	
	if(Windowed)
	{
		hwnd = CreateWindowEx(0, lpszClassName, "My Very First Directx Programm", WS_OVERLAPPEDWINDOW,
							   CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, hInstance,
							   NULL );
	}
	else
	{
		hwnd = CreateWindowEx(0,
							  lpszClassName,
							  "My Very First Directx Programm",
							  WS_EX_TOPMOST | WS_POPUP,   
							  0, 0,    
							  1920, 1080,
							  NULL,
							  NULL,
							  hInstance,
							  NULL);
	}	
	ShowWindow(hwnd, iCmdShow);
	return hwnd;
}

