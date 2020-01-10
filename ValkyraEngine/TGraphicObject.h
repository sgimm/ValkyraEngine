#pragma once
#include "TBaseClass.h"
#include "d3dx9math.h"
class TGraphicObject :
	public TBaseClass
{
private:
	D3DXVECTOR3 Position;
public:
	virtual HRESULT Render() { return NULL; }
	virtual void Update() {}	
	virtual void Initialize(){}
	virtual void Reset(LPDIRECT3DDEVICE9 lpD3dDevice) {}
	TGraphicObject();
	~TGraphicObject();
	D3DXVECTOR3 GetPosition();
	void SetPosition(D3DXVECTOR3 position);
};

