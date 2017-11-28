#pragma once
#include "TComponent.h"
#include "TZip.h"
#include "TConfigReader.h"
class TEngineComponent :
	public TComponent
{
public:
	TEngineComponent(TComponent* owner, void* parent);
	~TEngineComponent();
};

