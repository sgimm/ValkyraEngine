#pragma once
#include "TGraphicObject.h"
class TLight :
	public TGraphicObject
{
private:
	D3DMATERIAL9 mtrl;
	D3DXVECTOR3 vecDir;
	D3DLIGHT9 light;
public:
	TLight(LPDIRECT3DDEVICE9 lpd3ddevice);
	~TLight();
	void Initialize();
	HRESULT Render();
};

