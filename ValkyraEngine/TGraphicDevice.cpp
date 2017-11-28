#include "TGraphicDevice.h"


TGraphicDevice::TGraphicDevice()
{
}


TGraphicDevice::~TGraphicDevice()
{
}

void TGraphicDevice::InitDevice(HWND hwnd)
{
	m_hwnd = hwnd;
	if(NULL ==(	m_lpD3d9 = Direct3DCreate9(D3D_SDK_VERSION)))		
	{
	}
	if (FAILED(m_lpD3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &D3D9pp, &m_lpd3ddevice)))
	{
		int x;
	}
}

void TGraphicDevice::BeginRender()
{
	m_lpd3ddevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
	m_lpd3ddevice->BeginScene();
}

void TGraphicDevice::EndRender()
{
	m_lpd3ddevice->EndScene();
	m_lpd3ddevice->Present(NULL, NULL, NULL, NULL);
}

void TGraphicDevice::SetPresentationParameters(PresentationParams pp)
{
	ZeroMemory(&D3D9pp, sizeof(D3DPRESENT_PARAMETERS));
	D3D9pp.Windowed = pp.Windowed;
	D3D9pp.SwapEffect = pp.SwapEffekt;
	D3D9pp.hDeviceWindow = pp.hDeviceWindow;
	D3D9pp.BackBufferHeight = pp.uiBackBufferHeight;
	D3D9pp.BackBufferWidth = pp.uiBackBufferWidth;
	D3D9pp.AutoDepthStencilFormat = pp.AutoDepthStencilFormat;
	D3D9pp.BackBufferCount = pp.uiBackBufferCount;
	D3D9pp.EnableAutoDepthStencil = pp.EnableAutoDepthStencil;
	D3D9pp.Flags = pp.dwFlags;
	D3D9pp.FullScreen_RefreshRateInHz = pp.uiFullScreen_RefreshRateInHz;
	D3D9pp.MultiSampleType = pp.MultiSampleType;
	D3D9pp.PresentationInterval = pp.uiPresentationInterval;
	D3D9pp.BackBufferFormat = pp.BackBufferFormat;
}
