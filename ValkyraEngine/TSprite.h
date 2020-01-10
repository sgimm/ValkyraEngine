#pragma once
#include "TMeshBase.h"
class TSprite :
	public TMeshBase
{
public:
	TSprite(LPDIRECT3DDEVICE9 lpd3ddevice);
	void Initialize();
	~TSprite();
	HRESULT Render();
};