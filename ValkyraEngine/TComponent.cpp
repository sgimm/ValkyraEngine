#include "TComponent.h"


TComponent::TComponent(TComponent* owner, void * parent, TMiracle* mirc)
{
	m_mirc = mirc;
	m_szClassName = "TComponent";
	Children = new TArray(10);	
	if (owner)
	{
		m_Root = owner->m_Root;
		m_Owner = owner;
		m_Owner->Children->Add(this);
		m_Owner->iComponentSize++;
	}
	else
	{
		m_Root = this;
		iComponentSize++;
	}
}

void TComponent::Update()
{
	for (int i = 0; i < Children->Count(); i++)
	{
		((TComponent*)Children->GetItemAtIndex(i))->Update();
	}
}

void TComponent::Render()
{
	for (int i = 0; i < Children->Count(); i++)
	{
		((TComponent*)Children->GetItemAtIndex(i))->Render();
	}
}

void TComponent::OnMessage(TMessage* message)
{
	for (int i = 0; i < Children->Count(); i++)
	{
		((TComponent*)Children->GetItemAtIndex(i))->OnMessage(message);
	}
}

TComponent * TComponent::GetRootComponent()
{
	return m_Root;
}

TComponent::~TComponent()
{
}
