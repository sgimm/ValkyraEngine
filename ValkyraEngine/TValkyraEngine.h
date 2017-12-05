#pragma once
#include "TBaseClass.h"
#include "TEngineComponent.h"
#include "TBaseClass.h"
class TValkyraEngine:public TBaseClass
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

