#pragma once
#include "TComponent.h"
class TSenceNode :
	public TComponent
{
public:	
	TSenceNode(TComponent* owner, void* parent);
	~TSenceNode();
};

