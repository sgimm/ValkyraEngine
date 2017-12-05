#pragma once
#define STRING_MAX 2048
#include <string.h>
#include "TBaseClass.h"
class TString:public TBaseClass
{
private:
	const char* s;
public:
	TString();
	~TString();	
	const char* getChar();
	const char* operator=(const char* string)
	{
		s = string;
		return s;
	};
	const char* operator+=(const char* string)
	{
		char t[STRING_MAX];
		strcpy(t, s);
		strcat(t, string);
		s = t;
		return s;
	}
};

