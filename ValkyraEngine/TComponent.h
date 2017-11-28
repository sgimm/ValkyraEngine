#pragma once
#include "TBaseClass.h"
#include "TArray.h"
#include "TMessage.h"
class TComponent;
class TComponent:public TBaseClass
{
protected:
	int iComponentSize;
	TComponent* m_Root;
	TComponent* m_Owner;
	TArray* Children;
public:
	TComponent(TComponent* owner, void* parent);
	virtual void InitializeComponents() {};
	virtual void Udpdate();
	virtual void Render();
	virtual void OnMessage(TMessage message);
	virtual TComponent* GetRootComponent();
	~TComponent();
};

