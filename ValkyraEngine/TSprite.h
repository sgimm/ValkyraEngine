#pragma once
#include "TMeshBase.h"
class TSprite :
	public TMeshBase
{
public:
	TSprite(LPDIRECT3DDEVICE9 lpd3ddevice);
	void SetPosition(D3DXVECTOR3* position);
	void Initialize();
	~TSprite();
	HRESULT Render();
};