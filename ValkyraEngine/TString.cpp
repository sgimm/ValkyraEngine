#include "TString.h"


TString::TString()
{
	m_szClassName = "TString";
}


TString::~TString()
{
}

const char * TString::getChar()
{
	return s;
}

