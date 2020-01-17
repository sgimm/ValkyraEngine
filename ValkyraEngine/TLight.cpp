#include "TLight.h"



TLight::TLight(LPDIRECT3DDEVICE9 lpd3ddevice)
{
	m_lpd3ddevice = lpd3ddevice;
}


TLight::~TLight()
{
}

void TLight::Initialize()
{
	/*
	vecDir.x = 0;
	vecDir.y = 0;
	vecDir.z = 1.0f;
	ZeroMemory(&mtrl, sizeof(mtrl));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
	mtrl.Diffuse.b = mtrl.Ambient.b = 0.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;
	m_lpd3ddevice->SetMaterial(&mtrl);

	ZeroMemory(&light, sizeof(light));
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Direction = vecDir;
	light.Range = 1000.0f;
	m_lpd3ddevice->SetLight(0, &light);
	m_lpd3ddevice->LightEnable(0, TRUE);
	m_lpd3ddevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	m_lpd3ddevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	*/
}

HRESULT TLight::Render()
{
	vecDir.x = 3.0f;
	vecDir.y = 10.0f;
	vecDir.z = 80.0f;
	ZeroMemory(&mtrl, sizeof(D3DMATERIAL9));
	mtrl.Diffuse.r = mtrl.Ambient.r = 1.0f;
	mtrl.Diffuse.g = mtrl.Ambient.g = 1.0f;
	mtrl.Diffuse.b = mtrl.Ambient.b = 1.0f;
	mtrl.Diffuse.a = mtrl.Ambient.a = 1.0f;
	m_lpd3ddevice->SetMaterial(&mtrl);

	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Diffuse.r = 1.0f;
	light.Diffuse.g = 1.0f;
	light.Diffuse.b = 1.0f;
	D3DXVec3Normalize((D3DXVECTOR3*)&light.Direction, &vecDir);
	light.Range = 1000.0f;
	m_lpd3ddevice->SetLight(0, &light);
	m_lpd3ddevice->LightEnable(0, TRUE);
	m_lpd3ddevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	m_lpd3ddevice->SetRenderState(D3DRS_AMBIENT, 0x00202020);
	return NULL;
}
