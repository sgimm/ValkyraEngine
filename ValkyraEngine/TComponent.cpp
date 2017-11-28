#include "TComponent.h"


TComponent::TComponent(TComponent* owner, void * parent)
{
	szClassName = "TComponent";
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
		m_Owner->iComponentSize++;
	}
}

void TComponent::Udpdate()
{
	for (int i = 0; i < Children->Count(); i++)
	{
		((TComponent*)Children->GetItemAtIndex(i))->Udpdate();
	}
}

void TComponent::Render()
{
	for (int i = 0; i < Children->Count(); i++)
	{
		((TComponent*)Children->GetItemAtIndex(i))->Render();
	}
}

void TComponent::OnMessage(TMessage message)
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
