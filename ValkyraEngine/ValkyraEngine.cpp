// "ValkyraEngine.cpp": Definiert den Einstiegspunkt der Anwendung.
//

#include "ValkyraEngine.h"
#include "WindowHelper\TWinHelper.h"
#include "TString.h"
#include "TTimerHelper.h"
#include "TGraphicDevice.h"
#include "TConfigReader.h"
#define MAX_LOADSTRING 100

// Globale Variablen:
TGraphicDevice* _device;
HINSTANCE hInst;                                // Aktuelle Instanz
TWinHelper* Window;
HWND hWindow;
double dClockCycles;
double dRenderingClycles;
double dActualRenderingCycle;
TTimerHelper th;
TConfigReader* tconf;
bool bInitialized = false;
bool bRetainedModeRendering = false;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    //UNREFERENCED_PARAMETER(hPrevInstance);
    //UNREFERENCED_PARAMETER(lpCmdLine);
	/*	TString s;
	s = "hallo";
	s += " Welt!";
	*/
	tconf = new TConfigReader();
	tconf->ReadConfig();
	dClockCycles = 0.0f;
	dRenderingClycles = 0.0f;
	MSG msg;
	hWindow = Window->Create3DWindow(hInstance, "sf", nCmdShow, 0, "Blah");
	bRetainedModeRendering = false;
	//////////
	// Test //
	_device = new TGraphicDevice();
	TGraphicDevice::PresentationParams pp;
	ZeroMemory(&pp, sizeof(pp));
	pp.uiBackBufferHeight = 1080;
	pp.uiBackBufferWidth = 1920;
	pp.SwapEffekt = D3DSWAPEFFECT_DISCARD;
	pp.hDeviceWindow = hWindow;
	pp.Windowed = FALSE;
	pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	
	_device->SetPresentationParameters(pp);
	_device->InitDevice(hWindow);


    // Hauptnachrichtenschleife:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
		if (!bInitialized)
		{
			SetThreadPriority(hWindow, THREAD_PRIORITY_HIGHEST);
			th.PerformanceCounterStart();
			Sleep(1000);
			th.PerformanceCounterEnd();
			dClockCycles = th.GetDifference();
			bInitialized = true;
			SetThreadPriority(hWindow, THREAD_PRIORITY_NORMAL);
			dRenderingClycles = dClockCycles / 60;
		}


        TranslateMessage(&msg);
        DispatchMessage(&msg);   
		if (bRetainedModeRendering)
		{
			if (dActualRenderingCycle >= dRenderingClycles)
			{
				_device->BeginRender();
				_device->EndRender();
				dActualRenderingCycle = 0.0f;
			}
			dActualRenderingCycle++;
		}
		else
		{
			_device->BeginRender();
			_device->EndRender();
		}
    }
    return (int) msg.wParam;
}