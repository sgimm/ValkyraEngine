#pragma once
#include "TGraphicDeviceBase.h"
#include "D3D11.h"
class TDirectX11Device :
	public TGraphicDeviceBase
{
private:
	DXGI_SWAP_CHAIN_DESC sd;
public:
	TDirectX11Device();
	~TDirectX11Device();
};

