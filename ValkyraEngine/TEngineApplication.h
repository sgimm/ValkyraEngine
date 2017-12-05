#pragma once
#include "TBaseClass.h"
#include "TEngineComponent.h"
class TEngineApplication :
	public TBaseClass
{
private:
	TEngineComponent* cEngineComponent;
	TMiracle* mirc;
public:
	TEngineApplication(HWND hwnd);
	~TEngineApplication();
	void UpdateRender();
	void InitializeComponents();	
};

