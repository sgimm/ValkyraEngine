#include "TConfigReader.h"
#include <Windows.h>

void TConfigReader::ReadConfig()
{
	int x = GetPrivateProfileInt("Graphics", "width", 0, ".\\Game.ini");
}

TConfigReader::TConfigReader()
{
}


TConfigReader::~TConfigReader()
{
}
