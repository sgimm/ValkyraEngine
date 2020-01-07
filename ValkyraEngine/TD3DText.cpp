#include "TD3DText.h"


void TD3DText::Initialize()
{
	ZeroMemory(&m_oRect, sizeof(m_oRect));
	m_oRect = { 0,0,100,30 };
	D3DXCreateFont(m_lpd3ddevice, 30, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &m_lpd3dfont);
	TText::Initialize();
}

TD3DText::TD3DText(LPDIRECT3DDEVICE9 lpd3ddevice)
{	
	m_szClassName = "TD3DText";
	m_lpd3ddevice = lpd3ddevice;
}

void TD3DText::Render()
{
	m_lpd3dfont->DrawText(NULL, "Hallo, wie geht es Dir?", -1, &m_oRect, DT_LEFT | DT_NOCLIP, 0xFFFFFFFF);
}

TD3DText::~TD3DText()
{
}

void TD3DText::Reset(LPDIRECT3DDEVICE9 lpD3dDevice)
{
	m_lpd3ddevice = lpD3dDevice;
}
