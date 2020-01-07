#pragma once
#include "TBaseClass.h"
#include "../ValkyraEngine/DataStructure/TArray.h"
#include "TMessage.h"
#include "TMiracle.h"
class TComponent;
class TComponent:public TBaseClass
{
protected:
	int iComponentSize;
	TComponent* m_Root;
	TComponent* m_Owner;
	TArray* Children;
	TMiracle* m_mirc;
public:
	TComponent(TComponent* owner, void* parent, TMiracle* mirc);
	virtual void InitializeComponents();
	virtual void Update();
	virtual void Render();
	virtual void OnMessage(TMessage* message);
	virtual TComponent* GetRootComponent();
	~TComponent();
};

