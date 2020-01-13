#include "TEngineApplication.h"
#include "TDirectX9Device.h"
#include "TText.h"
#include "TSprite.h"


TEngineApplication::TEngineApplication(HWND hwnd)
{
	m_szClassName = "TEngineApplication";
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
	mirc->GraphicDevice->Render();
}

void TEngineApplication::InitializeComponents()
{
	if(cEngineComponent)
		cEngineComponent->InitializeComponents();	


	TLight* light = mirc->GraphicDevice->CreateLight();
	mirc->GraphicDevice->AddRenderList(light);

	TText* text = mirc->GraphicDevice->CreateText();
	text->Settext("Hallo Welt!");
	mirc->GraphicDevice->AddRenderList(text);

	TSprite* sprite = mirc->GraphicDevice->CreateSprite();	
	mirc->GraphicDevice->AddRenderList(sprite);

}

void TEngineApplication::OnMessage(TMessage * msg)
{
	cEngineComponent->OnMessage(msg);
}
