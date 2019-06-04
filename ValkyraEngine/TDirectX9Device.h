#pragma once
#include <d3d9.h>
#include "TGraphicDeviceBase.h"
#include "TGraphicObject.h"
#include  "../ValkyraEngine/DataStructure/TArray.h"
class TDirectX9Device:public TGraphicDeviceBase
{
private:	
	//**********************TEST**********************
	
	//************************************************
	LPDIRECT3DDEVICE9 m_lpd3ddevice;
	LPDIRECT3D9 m_lpD3d9;
	D3DPRESENT_PARAMETERS D3D9pp;
	D3DCOLOR m_DeviceClearColor;
	HWND m_hwnd;
	HRESULT m_hRenderResult;
	int m_iAcutalSate;
	int m_iLastState;
public:
	struct PresentationParams
	{
		bool Windowed;
		bool EnableAutoDepthStencil;
		D3DSWAPEFFECT SwapEffekt;
		HWND hDeviceWindow;
		UINT uiBackBufferCount;
		UINT uiBackBufferHeight;
		UINT uiBackBufferWidth;
		UINT uiFullScreen_RefreshRateInHz;
		UINT uiPresentationInterval;
		DWORD dwFlags;
		D3DFORMAT AutoDepthStencilFormat;
		D3DFORMAT BackBufferFormat;
		D3DMULTISAMPLE_TYPE MultiSampleType;
	};
	PresentationParams pp;
	TDirectX9Device();
	~TDirectX9Device();
	
	void InitDevice();
	void BeginRender();
	void EndRender();
	void Render();
	TText* CreateText();
	void AddRenderList();
	void SetPresentationParameters(PresentationParams pp);
	void SetPresentationParams(GraphicDeviceConfig* graphicConfig);
	void RestoreDevice(int* state);
};

