#pragma once
#include "TBaseClass.h"
#include <Windows.h>
#include "../ValkyraEngine/DataStructure/TArray.h"
#include "TText.h"
#include "TSprite.h"
#include "TLight.h"
class GraphicDeviceConfig;
class TGraphicDeviceBase :
	public TBaseClass
{
protected:
	TArray * m_oRenderList;
	TArray * m_oRenderListSave;
public:
	HWND hWnd;
	TGraphicDeviceBase();
	~TGraphicDeviceBase();
	virtual void InitDevice() {}
	virtual void BeginRender() {}
	virtual void EndRender() {}
	virtual HRESULT Render() { return NULL; }
	virtual void AddRenderList(TGraphicObject* gObject) {}
	virtual void RemoveRenderList(void*) {};	
	virtual void SetPresentationParams(GraphicDeviceConfig* graphicConfig) {};
	virtual TText* CreateText() { return nullptr; }
	virtual TSprite* CreateSprite() { return nullptr; }
	virtual TLight* CreateLight() { return nullptr; }
	virtual void Reset(LPDIRECT3DDEVICE9 m_lpd3ddevice) {}
};

class GraphicDeviceConfig
{
public:
	int m_iWidth;
	int m_iHeight;
	bool m_bWindowed;
	HWND hWnd;
};

