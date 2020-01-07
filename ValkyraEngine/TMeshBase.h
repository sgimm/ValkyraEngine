#pragma once
#include "d3d9.h"
#include "TGraphicObject.h"
typedef struct SimpleVertex
{
#ifdef __cplusplus
public:
	D3DXVECTOR3 Normal;
	D3DCOLOR Color;
	FLOAT  tu, tv;
#endif //__cplusplus
}SimpleVertex, *LPSimpleVertex;
class TMeshBase :
	public TGraphicObject
{
public:
	DWORD tri_fvf;
	TMeshBase();
	~TMeshBase();
};
