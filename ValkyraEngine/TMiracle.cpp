#include "TMiracle.h"


void TMiracle::InitDevice()
{
	m_szClassName = "TMiracle";
	m_configReader->ReadGraphicConfig();
	m_configReader->m_GraphicDeviceConfig->hWnd = m_Hwnd;
	GraphicDevice->SetPresentationParams(m_configReader->m_GraphicDeviceConfig);
	GraphicDevice->InitDevice();
}

TMiracle::TMiracle()
{
	m_configReader = new TConfigReader();
}


TMiracle::~TMiracle()
{
}
