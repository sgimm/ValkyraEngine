#pragma once
#include "TBaseClass.h"
#include <Windows.h>
class GraphicDeviceConfig;
class TGraphicDeviceBase :
	public TBaseClass
{
public:
	HWND hWnd;
	TGraphicDeviceBase();
	~TGraphicDeviceBase();
	virtual void InitDevice() {};
	virtual void BeginRender() {};
	virtual void EndRender() {};
	virtual void SetPresentationParams(GraphicDeviceConfig* graphicConfig) {};
};

class GraphicDeviceConfig
{
public:
	int m_iWidth;
	int m_iHeight;
	bool m_bWindowed;
	HWND hWnd;
};

