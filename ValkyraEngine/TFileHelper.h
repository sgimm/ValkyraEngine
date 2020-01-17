#pragma once
#include "TBaseClass.h"
class TFileHelper :
	public TBaseClass
{
public:
	const char* LoadStringFromFile(const char* file);
	TFileHelper();
	~TFileHelper();
};

