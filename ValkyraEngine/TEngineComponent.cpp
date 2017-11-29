#include "TEngineComponent.h"



TEngineComponent::TEngineComponent(TComponent * owner, void * parent, TMiracle* mirc) :TComponent(owner, parent, mirc)
{
}

void TEngineComponent::InitializeComponents()
{
	TComponent::InitializeComponents();
}

void TEngineComponent::Render()
{
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
