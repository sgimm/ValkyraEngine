#pragma once
#include "TGraphicObject.h"
class TText : public TGraphicObject
{
protected:
	int iSize;
	RECT m_oRect;
public:
	void Render();
	TText();
	virtual void Settext(const char* text) {}
	~TText();
};

