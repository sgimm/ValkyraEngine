#pragma once
#include "TBaseClass.h"
#include "TEngineComponent.h"
class TValkyraEngine
{
private:
	TEngineComponent* cEngineComponent;
public:
	void Initialize();
	void Update();
	void Render();
	void Destroy();
	TValkyraEngine();
	~TValkyraEngine();
};

