#pragma once
#include "d3d9.h"
#include <d3dx9math.h>
#include "TBaseClass.h"

class TCamera:public TBaseClass
{	D3DXMATRIXA16 m_matView;
	D3DXMATRIX m_matProj;
	D3DXMATRIX m_ViewProj;
public:
	TCamera();
	~TCamera();
};

