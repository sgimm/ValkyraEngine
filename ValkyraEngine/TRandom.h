#pragma once
#include "TBaseClass.h"
#include <cstdlib>
#include <ctime> 
class TRandom :
	public TBaseClass
{
public:
	TRandom();
	~TRandom();
	int Next(int from, int to);
	float NextFloat();
};

