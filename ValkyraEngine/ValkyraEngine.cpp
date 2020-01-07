// "ValkyraEngine.cpp": Definiert den Einstiegspunkt der Anwendung.
//

#include "TEngineApplication.h"
#include "WindowHelper\TWinHelper.h"
#include "TString.h"
#include <iostream>
#include "TRandom.h"
#include "TGeneticAlgorithm.h"
#define MAX_LOADSTRING 100

typedef void(*OnPaintEvent)();
typedef void(*OnExitEvent)();
OnPaintEvent fOnPaint;
OnExitEvent fOnExit;
void Paint();
void Exit();
TEngineApplication * _engineApp;
HINSTANCE hInst;   

HWND hWindow;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:		
		fOnPaint();
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			fOnExit();
			PostQuitMessage(0);
			return 0;
		}
	case WM_KEYUP:
		break;
	case WM_MOUSEMOVE:
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	MSG msg;
	
	hWindow = Create3DWindow(hInstance, "sf", nCmdShow, 0, "Blah");
	
	_engineApp = new TEngineApplication(hWindow);
	_engineApp->InitializeComponents();
	
	int adsadsad = 0;
	fOnPaint = &Paint;
	fOnExit = &Exit;	
	OutputDebugString("Engine Inialized \n");
	
	bool bGotMsg;
	msg.message = WM_NULL;
	PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE);
    while (WM_QUIT != msg.message)
    {
		bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);
		if (bGotMsg)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
		}
    }
    return S_OK;
}
void Paint()
{ 
	OutputDebugString("WM_OnPaint \n");
	//_engineApp->UpdateRender();
	_engineApp->UpdateRender();
}

void Exit()
{
	OutputDebugString("WM_Exit \n");
}
void GeneticTest()
{

}