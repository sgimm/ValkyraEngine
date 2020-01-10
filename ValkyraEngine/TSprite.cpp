#include "TSprite.h"



TSprite::TSprite(LPDIRECT3DDEVICE9 lpd3ddevice)
{
	//position + w + h
	m_lpd3ddevice = lpd3ddevice;
	m_oVertices = new TArray(10);
	m_oVertices->SetResizeable(0);

}

void TSprite::Initialize()
{
	/*
	SimpleVertex vul[] =
	{
		{D3DXVECTOR3(150.0f,  50.0f, 0.5f), D3DXVECTOR3(1.0f,1.0f,1.0f), D3DCOLOR_XRGB(0,255,255), 0,0},
		{D3DXVECTOR3(250.0f, 250.0f, 0.5f), D3DXVECTOR3(1.0f,1.0f,1.0f), D3DCOLOR_XRGB(0,0,255), 0,0},
		{D3DXVECTOR3(50.0f, 250.0f, 0.5f), D3DXVECTOR3(1.0f,1.0f,1.0f), D3DCOLOR_XRGB(0,0,255), 0,0}
		//{D3DXVECTOR3(0.0f,0.0f,-10.0f), D3DXVECTOR3(1.0f,1.0f,1.0f), D3DCOLOR_XRGB(0,0,255), 0,0},
		//{D3DXVECTOR3(10.0f,10.0f,-10.0f), D3DXVECTOR3(1.0f,1.0f,1.0f), D3DCOLOR_XRGB(0,0,255), 0,0},
		//{D3DXVECTOR3(10.0f,0.0f,-10.0f), D3DXVECTOR3(1.0f,1.0f,1.0f), D3DCOLOR_XRGB(0,0,255), 0,0}
	};
	*/
	float w, h;
	float x, y, z;

	x = 3.0f;
	y = 3.0f;
	z = 0.5f;
	w = 3.0f;
	h = 3.0f;
	SimpleVertex vul[] =
	{
		{x,  y, z,			0xffffffff},
		{x + w, y, z,		0xffffffff},
		{x+w, y+h, z,		0xffffffff},
		{x, y, z,			0xffffffff},
		{x + w, y + h, z,	0xffffffff},
		{x, y+h, z,			0xff00ffff}
	};

	HRESULT result = m_lpd3ddevice->CreateVertexBuffer(6 * sizeof(SimpleVertex),
													   0, tri_fvf, 
													   D3DPOOL_DEFAULT, &m_Vertexbuffer, NULL);
	VOID* pVertices;
	result = m_Vertexbuffer->Lock(0, sizeof(vul), (void**)&pVertices, 0);
	memcpy(pVertices, vul, sizeof(vul));
	m_Vertexbuffer->Unlock();
}

TSprite::~TSprite()
{
}

HRESULT TSprite::Render()
{

	OutputDebugString("Sprite Rendering\n");
	m_lpd3ddevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	m_lpd3ddevice->SetStreamSource(0, m_Vertexbuffer, 0, sizeof(SimpleVertex));
	m_lpd3ddevice->SetFVF(tri_fvf);
	return m_lpd3ddevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 2);
}
