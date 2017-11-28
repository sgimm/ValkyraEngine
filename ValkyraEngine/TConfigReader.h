#pragma once
#include "TBaseClass.h"
class TConfigReader :
	public TBaseClass
{
public:
	void ReadConfig();
	TConfigReader();
	~TConfigReader();
};

