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

	m_lpd3ddevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}



void TDirectX9Device::BeginRender()
{
	if (D3D_OK == m_lpd3ddevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0))
		m_iAcutalSate = 0;
	if (D3D_OK == m_lpd3ddevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0))
		m_iAcutalSate = 0;
	if (D3D_OK == m_lpd3ddevice->BeginScene())
		m_iAcutalSate = 0;
}

void TDirectX9Device::EndRender()
{
	m_lpd3ddevice->EndScene();
	m_hRenderResult = m_lpd3ddevice->Present(NULL, NULL, NULL, NULL);	
}

HRESULT TDirectX9Device::Render()
{
	if (m_oRenderListSave && m_oRenderListSave->Count() > 0)
		RestoreRenderList();
	BeginRender();
	if (m_iAcutalSate == 0)
	{		
		if(m_oRenderList->Count() > 0)
			for (int i = 0; i < m_oRenderList->Count(); i++)
			{				
				OutputDebugString("Rendering\n");	




				D3DXMATRIX matView;    // the view transform matrix
				D3DXMatrixLookAtLH(&matView,
					&D3DXVECTOR3(0.0f, 0.0f, 15.0f),   // the camera position
					&D3DXVECTOR3(0.0f, 0.0f, 0.0f),    // the look-at position
					&D3DXVECTOR3(0.0f, 1.0f, 0.0f));    // the up direction
				m_lpd3ddevice->SetTransform(D3DTS_VIEW, &matView);    // set the view transform to matView

				// set the projection transform
				D3DXMATRIX matProjection;    // the projection transform matrix
				D3DXMatrixPerspectiveFovLH(&matProjection,
					D3DXToRadian(45),    // the horizontal field of view
					(FLOAT)1920 / (FLOAT)1080, // aspect ratio
					1.0f,    // the near view-plane
					100.0f);    // the far view-plane
				m_lpd3ddevice->SetTransform(D3DTS_PROJECTION, &matProjection);     // set the projection





				switch (((TGraphicObject*)m_oRenderList->GetItemAtIndex(i))->Render())
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
					}
				}
			}		
	}
	EndRender();
	return NULL;
}

TText * TDirectX9Device::CreateText()
{
	TD3DText* t = new TD3DText(m_lpd3ddevice);
	t->Initialize();
	return t;
}

TSprite * TDirectX9Device::CreateSprite()
{
	TSprite* t = new TSprite(m_lpd3ddevice);
	t->Initialize();
	return t;
}

TLight * TDirectX9Device::CreateLight()
{
	TLight* l = new TLight(m_lpd3ddevice);
	l->Initialize();
	return l;
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
	D3D9pp.EnableAutoDepthStencil = TRUE;
}

void TDirectX9Device::RestoreDevice(int* state)
{
	
	HRESULT hr = m_lpd3ddevice->TestCooperativeLevel();
	switch (hr)
	{		
		case D3D_OK:	
			*state = 0;
			OutputDebugString("D3D_OK");
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