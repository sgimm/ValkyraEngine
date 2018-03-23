// "ValkyraEngine.cpp": Definiert den Einstiegspunkt der Anwendung.
//
#include "TEngineApplication.h"
#include "WindowHelper\TWinHelper.h"
#include "TString.h"
#include <iostream>
#include "TRandom.h"
#include "TGeneticAlgorithm.h"
#define MAX_LOADSTRING 100


void Paint();

// Globale Variablen:
//TDirectX9Device* _device;
TEngineApplication * _engineApp;
HINSTANCE hInst;                                // Aktuelle Instanz
TWinHelper* Window;
HWND hWindow;
typedef void(*test)();
TRandom* rnd;
#pragma region MyRegion
TGeneticAlgorithm* _gena;
int iPopilationSize = 500;
float fMutationRate = 0.008f;
void GeneticTest();
const char* szPhrase = "Sein, oder nicht sein, das ist hier die Frage!";
const char* szValidChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,.|!$%&/()=? ";

#pragma endregion
//double dClockCycles;
//double dRenderingClycles;
//double dActualRenderingCycle;
//TTimerHelper th;
//TConfigReader* tconf;
//bool bInitialized = false;
//bool bRetainedModeRendering = false;

void* getRandomChar()
{
	int charPos = rnd->Next(0, strlen(szValidChars));
	return (void*)szValidChars[charPos];
}

float charGeneFitnessFunction(int index)
{
	float score = 0;
	TDNA* dna = (TDNA*)_gena->m_oPopulation->GetItemAtIndex(index);
	for (int i = 0; i < dna->_genes->Count(); i++)
	{
		if ((char)dna->_genes->GetItemAtIndex(i) == szPhrase[i])
		{
			score += 1;
		}
	}

	score /= strlen(szPhrase);

	score = ((float)pow(2, score) - 1) / (2 - 1);

	return score;
}

void* fptest()
{
	std::cout << "blahahaha";
	return 0;
}

float xFitnessFunction(int index)
{
	return 0;
}

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
	/*
	tconf = new TConfigReader();
	tconf->ReadConfig();
	dClockCycles = 0.0f;
	dRenderingClycles = 0.0f;
	*/
	MSG msg;
	rnd = new TRandom();
	
	_gena = new TGeneticAlgorithm(iPopilationSize, (int)strlen(szPhrase), rnd, &getRandomChar, &charGeneFitnessFunction, fMutationRate);
	Window = new TWinHelper();
	hWindow = Window->Create3DWindow(hInstance, "sf", nCmdShow, 0, "Blah");
	
	_engineApp = new TEngineApplication(hWindow);
	_engineApp->InitializeComponents();
	Window->OnPaint = &Paint;
	int adsadsad = 0;
	//////////
	// Test //
	/*
	_device = new TDirectX9Device();
	TDirectX9Device::PresentationParams pp;
	ZeroMemory(&pp, sizeof(pp));
	pp.uiBackBufferHeight = 1080;
	pp.uiBackBufferWidth = 1920;
	pp.SwapEffekt = D3DSWAPEFFECT_DISCARD;
	pp.hDeviceWindow = hWindow;
	pp.Windowed = FALSE;
	pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	
	_device->SetPresentationParameters(pp);
	_device->InitDevice(hWindow);

	*/

    // Hauptnachrichtenschleife:
	/*
	AllocConsole();
	rnd = new TRandom();
	getRadomGeneFunction g = &fptest;
	freopen("CONOUT$", "w", stdout);

	char cc[50];
	
	while(_gena->GetFitness() < 1)
	{
		float x = _gena->GetFitness();
		_gena->NewGeneration();
		ZeroMemory(&cc, sizeof(cc));
		for (int c = 0; c < _gena->m_oBestGenes->Count(); c++)
		{
			cc[c] = (char)_gena->m_oBestGenes->GetItemAtIndex(c);
		}
		std::cout << cc << "\n";
	}
	*/
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
			//_engineApp->UpdateRender();
		}
    }
    return S_OK;
}
void Paint()
{ 
	_engineApp->UpdateRender();
}
void GeneticTest()
{

}
