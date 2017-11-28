#include "TMeshBase.h"

TMeshBase::TMeshBase()
{
	tri_fvf = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX0;
}


TMeshBase::~TMeshBase()
{
}
