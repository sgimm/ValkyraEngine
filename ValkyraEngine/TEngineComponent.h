#pragma once
#include "TComponent.h"
#include "TZip.h"
#include "TConfigReader.h"
class TEngineComponent :
	public TComponent
{
public:
	TEngineComponent(TComponent* owner, void* parent, TMiracle* mirc);
	void InitializeComponents();
	void Render();
	void Update();
	void OnMessage(TMessage* message);
	~TEngineComponent();
};

