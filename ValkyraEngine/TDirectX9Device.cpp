#include "TDirectX9Device.h"
#include "TGraphicObject.h"
#include "TD3DText.h"
#include <atlstr.h>

void TDirectX9Device::SaveRenderList()
{

	OutputDebugString("SaveRenderList\n");
	if (!m_oRenderListSave)
	{
		m_oRenderListSave = new TArray(m_oRenderList->Count());
		m_oRenderListSave->SetResizeable(true);
		m_oRenderListSave->SetResizeVector(100);
		for (int i = 0; i < m_oRenderList->Count(); i++)
		{
			m_oRenderListSave->Add(m_oRenderList->GetItemAtIndex(i));
		}
		m_oRenderList->Clear();
	}
}

void TDirectX9Device::RestoreRenderList()
{
	OutputDebugString("RestoreRenderList\n");
	if (m_oRenderListSave)
	{
		for (int i = 0; i < m_oRenderListSave->Count(); i++)
		{
			TGraphicObject* temp = (TGraphicObject*)m_oRenderListSave->GetItemAtIndex(i);
			temp->Reset(m_lpd3ddevice);
			temp->Initialize();
			m_oRenderList->Add(temp);
		}
		m_oRenderListSave->Clear();
		ZeroMemory(&m_oRenderListSave, sizeof(m_oRenderList));
		delete m_oRenderListSave;
		m_oRenderListSave = NULL;
	}
}

TDirectX9Device::TDirectX9Device()
{
	m_szClassName = "TDirectX9Device";
	m_iAcutalSate = 0;
	m_iLastState = -1;
}


TDirectX9Device::~TDirectX9Device()
{
}

void TDirectX9Device::InitDevice()
{
	OutputDebugString("InitDevice\n");
	m_oRenderList = new TArray(50);
	m_oRenderList->SetResizeable(true);
	m_oRenderList->SetResizeVector(100);
	if(NULL ==(	m_lpD3d9 = Direct3DCreate9(D3D_SDK_VERSION)))		
	{
	}
	if (FAILED(m_lpD3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hwnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &D3D9pp, &m_lpd3ddevice)))
	{
		
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
	m_hRenderResult = m_lpd3ddevice->Present(NULL, NULL, NULL, NULL);
	if (m_hRenderResult = D3DERR_DEVICELOST)
	{
		//MessageBox(0, "Lost Device", "LostDevice", MB_OKCANCEL);
	}
	switch (m_hRenderResult)
	{
	case D3DERR_DEVICELOST:
		m_iAcutalSate = 2;
		if (m_iAcutalSate != m_iLastState)
		{
			OutputDebugString("Device Lost \n");
			if (!m_oRenderListSave)
			{
				SaveRenderList();
			}
			//m_lpd3ddevice->Reset(&D3D9pp);			
		}
	}
	if (m_iAcutalSate == 3)
	{
		//CString t;
		//t.Format("%d", m_iAcutalSate);

		OutputDebugString("m_actualState = 3");
		m_iAcutalSate = 0;
	}
	if (m_iAcutalSate == 2)
	{
	}
}

void TDirectX9Device::Render()
{
	if (m_oRenderListSave && m_oRenderListSave->Count() > 0)
		RestoreRenderList();
	BeginRender();
	if (m_iAcutalSate == 0)
	{		
		if(m_oRenderList->Count() > 0)
			for (int i = 0; i < m_oRenderList->Count(); i++)
				((TGraphicObject*)m_oRenderList->GetItemAtIndex(i))->Render();
	}
	EndRender();
	
}

TText * TDirectX9Device::CreateText()
{
	TD3DText* t = new TD3DText(m_lpd3ddevice);
	t->Initialize();
	return t;
}

void TDirectX9Device::AddRenderList(TGraphicObject * gObject)
{	
	m_oRenderList->Add(gObject);
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

void TDirectX9Device::SetPresentationParams(GraphicDeviceConfig* graphicConfig)
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

void TDirectX9Device::RestoreDevice(int* state)
{
	
	HRESULT hr = m_lpd3ddevice->TestCooperativeLevel();
	switch (hr)
	{		
		case D3D_OK:	
			*state = 0;
			RestoreRenderList();
			break;
		case D3DERR_DEVICENOTRESET:
			hr =  m_lpd3ddevice->Reset(&D3D9pp);
			RestoreDevice(&m_iAcutalSate);
			OutputDebugString("D3DERR_DEVICENOTRESET\n");
			*state = 3;
			break;
	}
	m_iLastState = m_iAcutalSate;
}