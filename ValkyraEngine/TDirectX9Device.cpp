#include "TDirectX9Device.h"


TDirectX9Device::TDirectX9Device()
{
	m_szClassName = "TDirectX9Device";
}


TDirectX9Device::~TDirectX9Device()
{
}

void TDirectX9Device::InitDevice()
{
	if(NULL ==(	m_lpD3d9 = Direct3DCreate9(D3D_SDK_VERSION)))		
	{
	}
	if (FAILED(m_lpD3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &D3D9pp, &m_lpd3ddevice)))
	{
		int x;
	}
}

void TDirectX9Device::BeginRender()
{
	m_lpd3ddevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
	m_lpd3ddevice->BeginScene();
}

void TDirectX9Device::EndRender()
{
	m_lpd3ddevice->EndScene();
	m_lpd3ddevice->Present(NULL, NULL, NULL, NULL);
}

void TDirectX9Device::AddRenderList()
{
}

void TDirectX9Device::SetPresentationParameters(PresentationParams pp)
{
	ZeroMemory(&D3D9pp, sizeof(D3DPRESENT_PARAMETERS));
	D3D9pp.Windowed = pp.Windowed;
	D3D9pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
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

void TDirectX9Device::SetPresentationParams(GraphicDeviceConfig * graphicConfig)
{
	m_hwnd = graphicConfig->hWnd;
	ZeroMemory(&D3D9pp, sizeof(D3DPRESENT_PARAMETERS));
	D3D9pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	D3D9pp.BackBufferFormat = D3DFMT_X8R8G8B8;
	D3D9pp.BackBufferHeight = graphicConfig->m_iHeight;
	D3D9pp.BackBufferWidth = graphicConfig->m_iWidth;
	D3D9pp.Windowed = graphicConfig->m_bWindowed;
	D3D9pp.hDeviceWindow = graphicConfig->hWnd;
	D3D9pp.AutoDepthStencilFormat = D3DFMT_D16;
	D3D9pp.EnableAutoDepthStencil = true;
}
