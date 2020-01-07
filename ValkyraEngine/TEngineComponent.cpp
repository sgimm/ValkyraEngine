#include "TEngineComponent.h"



TEngineComponent::TEngineComponent(TComponent * owner, void * parent, TMiracle* mirc) :TComponent(owner, parent, mirc)
{
}

void TEngineComponent::InitializeComponents()
{		
	TConfigReader r;
	r.ReadGraphicConfig();
	m_mirc->GraphicDevice->SetPresentationParams(r.m_GraphicDeviceConfig);
	m_mirc->InitDevice();
	TComponent::InitializeComponents();
}

void TEngineComponent::Render()
{	
	m_mirc->GraphicDevice->BeginRender();
	m_mirc->GraphicDevice->EndRender();
	TComponent::Render();
}

void TEngineComponent::Update()
{
	TComponent::Update();
}

void TEngineComponent::OnMessage(TMessage * message)
{
	TComponent::OnMessage(message);
}

TEngineComponent::~TEngineComponent()
{
}
