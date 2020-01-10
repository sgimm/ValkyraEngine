#pragma once
#include "TText.h"
#include <d3d9.h>
#include <d3dx9core.h>
class TD3DText :
	public TText
{
private:
	LPD3DXFONT m_lpd3dfont; 
	LPDIRECT3DDEVICE9 m_lpd3ddevice;
public:
	void Initialize();
	TD3DText(LPDIRECT3DDEVICE9 lpd3ddevice);
	HRESULT Render();
	void Reset(LPDIRECT3DDEVICE9 lpD3dDevice);
	~TD3DText();
};

