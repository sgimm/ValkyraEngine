#include "TEngineApplication.h"


TEngineApplication::TEngineApplication()
{
	mirc = new TMiracle();
	cEngineComponent = new TEngineComponent(NULL, NULL, mirc);
}


TEngineApplication::~TEngineApplication()
{
}

void TEngineApplication::UpdateRender()
{
}

void TEngineApplication::InitializeComponents()
{
	if(cEngineComponent)
		cEngineComponent->InitializeComponents();
}
