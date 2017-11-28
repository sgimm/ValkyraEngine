#pragma once
#include "TBaseClass.h"
#include "zlib\zlib.h"

class TZip :
	public TBaseClass
{
public:
	void GetContenFromPackage();
	TZip();
	~TZip();
};

