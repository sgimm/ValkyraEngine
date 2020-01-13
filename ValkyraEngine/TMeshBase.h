#pragma once
#include "d3d9.h"
#include "./DataStructure/TArray.h"
#include "TGraphicObject.h"
#define tri_fvf (D3DFVF_XYZ|D3DFVF_DIFFUSE|D3DFVF_NORMAL)
typedef struct SimpleVertex
{
#ifdef __cplusplus
public:
	FLOAT x, y, z, rhw;
	//D3DXVECTOR3 NORMAL;
	DWORD COLOR;
	D3DXVECTOR3 NORMAL;
	//FLOAT TU, TV;

#endif //__cplusplus
}SimpleVertex, *LPSimpleVertex;
class TMeshBase :
	public TGraphicObject
{
protected:
	TArray* m_oVertices;
	LPDIRECT3DVERTEXBUFFER9 m_Vertexbuffer;
public:

	//DWORD tri_fvf;
	HRESULT Render() { return NULL; }
	TMeshBase();
	~TMeshBase();
};
