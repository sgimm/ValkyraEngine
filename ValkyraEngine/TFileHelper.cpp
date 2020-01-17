#include "TFileHelper.h"
#include <stdio.h>
#include<malloc.h>

#define  MAX_LINE_SIZE	256

const char * TFileHelper::LoadStringFromFile(const char * file)
{
	char** szFileContent;
	FILE* hFile = fopen(file, "rb");
	int iFileSize = 0;
	while (!feof(hFile))
	{
		if (fgetc(hFile) == '\n')
		{
			++iFileSize;
		}
	}
	++iFileSize;
	fclose(hFile);

	hFile = fopen(file, "r");
	szFileContent = (char**)malloc(iFileSize * sizeof(char*));
	for (int iCurrentLineIndex = 0; iCurrentLineIndex < iFileSize; iCurrentLineIndex++)
	{
		szFileContent[iCurrentLineIndex] = (char*)malloc(MAX_LINE_SIZE + 1);
		fgets(szFileContent[iCurrentLineIndex], MAX_LINE_SIZE, hFile);
	}
	fclose(hFile);
	return NULL;
}

TFileHelper::TFileHelper()
{
}


TFileHelper::~TFileHelper()
{
}
