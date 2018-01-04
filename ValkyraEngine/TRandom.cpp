#include "TRandom.h"
TRandom::TRandom()
{
}


TRandom::~TRandom()
{
}

int TRandom::Next(int from, int to)
{
	int __x = 0;
	if (from == 0)
		__x = rand() % to;
	else
		__x = rand() % from + to;
	return __x;
}

float TRandom::NextFloat()
{
	return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}
