#pragma once
#include "TComponent.h"
class TScene:public TComponent
{
public:
	void Render();
	void OnMessage(TMessage message);
	TScene(TComponent* owner, void* parent);
	~TScene();
};

