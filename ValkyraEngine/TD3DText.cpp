#include "TD3DText.h"


void TD3DText::Initialize()
{
}

TD3DText::TD3DText(LPDIRECT3DDEVICE9 lpd3ddevice)
{
	m_szClassName = "TD3DText";
	ZeroMemory(&m_oRect, sizeof(m_oRect));
	m_oRect = { 0,0,100,30 };
	//D3DXCreateFont(lpd3ddevice, 0, 0, 0, 0, false, 0, 0, 0, 0, TEXT("ss"), &m_lpd3dfont);
	D3DXCreateFont(lpd3ddevice, 30, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &m_lpd3dfont);
}

void TD3DText::Render()
{
		m_lpd3dfont->DrawText(NULL, "Hallo", -1, &m_oRect, DT_LEFT | DT_NOCLIP, 0xFFFFFFFF);
}


TD3DText::~TD3DText()
{
}

void TD3DText::Reset(LPDIRECT3DDEVICE9 lpD3dDevice)
{
}
