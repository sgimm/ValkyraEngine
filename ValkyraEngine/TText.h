#pragma once
#include "TGraphicObject.h"
class TText :
	public TGraphicObject
{
private:
	int iSize;
public:
	void Render();
	TText();
	~TText();
};

