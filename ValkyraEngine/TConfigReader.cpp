#include "TConfigReader.h"
#include <Windows.h>

void TConfigReader::ReadGraphicConfig()
{
	m_GraphicDeviceConfig = new GraphicDeviceConfig();
	m_GraphicDeviceConfig->m_iWidth = GetPrivateProfileInt("Graphics", "width", 0, ".\\Game.ini");
	m_GraphicDeviceConfig->m_iHeight = GetPrivateProfileInt("Graphics", "height", 0, ".\\Game.ini");
	m_GraphicDeviceConfig->m_bWindowed = GetPrivateProfileInt("Graphics", "windowed", 0, ".\\Game.ini");
}

TConfigReader::TConfigReader()
{
	m_szClassName = "TConfigReader";
}


TConfigReader::~TConfigReader()
{
}
