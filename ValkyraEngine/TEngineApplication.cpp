#include "TEngineApplication.h"
#include "TDirectX9Device.h"


TEngineApplication::TEngineApplication(HWND hwnd)
{
	mirc = new TMiracle();
	mirc->m_Hwnd = hwnd;
	mirc->GraphicDevice = new TDirectX9Device();
	cEngineComponent = new TEngineComponent(NULL, NULL, mirc);
}


TEngineApplication::~TEngineApplication()
{
}

void TEngineApplication::UpdateRender()
{
	cEngineComponent->Render();
}

void TEngineApplication::InitializeComponents()
{
	if(cEngineComponent)
		cEngineComponent->InitializeComponents();
}
