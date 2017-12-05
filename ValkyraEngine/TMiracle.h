#pragma once
#include "TBaseClass.h"
#include "TGraphicDeviceBase.h"
#include "TSoundDeviceBase.h"
#include "TConfigReader.h"
#include <Windows.h>
class TMiracle :
	public TBaseClass
{
protected:
	TConfigReader* m_configReader;
	GraphicDeviceConfig* m_GraphicConfig;
public:
	HWND m_Hwnd;
	TGraphicDeviceBase* GraphicDevice;
	TSoundDeviceBase* SoundDevice;
	void InitDevice();
	TMiracle();
	~TMiracle();
};

