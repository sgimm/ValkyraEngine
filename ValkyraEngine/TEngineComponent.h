#pragma once
#include "TComponent.h"
class TEngineComponent :
	public TComponent
{
public:
	TEngineComponent(TComponent* owner, void* parent);
	~TEngineComponent();
};

