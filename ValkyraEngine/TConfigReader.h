#pragma once
#include "TBaseClass.h"
#include "TGraphicDeviceBase.h"
class TConfigReader :
	public TBaseClass
{
public:
	GraphicDeviceConfig* m_GraphicDeviceConfig;
	void ReadGraphicConfig();
	TConfigReader();
	~TConfigReader();
};


