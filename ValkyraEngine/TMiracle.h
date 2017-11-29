#pragma once
#include "TBaseClass.h"
#include "TGraphicDeviceBase.h"
#include "TSoundDeviceBase.h"
class TMiracle :
	public TBaseClass
{
public:
	TGraphicDeviceBase* GraphicDevice;
	TSoundDeviceBase* SoundDevice;
	TMiracle();
	~TMiracle();
};

