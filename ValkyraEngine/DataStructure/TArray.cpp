#include "TArray.h"
#include <malloc.h>

TArray::TArray(int Length)
{
	m_iCount = 0;
	m_iLenght = 0;
	m_iResizeVector = 0;	
	m_bResizable = false;
	m_lpVoid = (void**)malloc(Length*sizeof(void*)+1);
	m_iLenght = Length;
}

TArray::~TArray(void)
{
	for(int i = 0; i < m_iLenght; i++)
	{
		if(i < m_iCount)
			free(m_lpVoid[m_iLenght]);
	}
	m_iCount = 0;
	m_iLenght = 0;
	m_iResizeVector = 0;
}

void TArray::Add(void* Element)
{	
	if(m_iCount < m_iLenght)
	{
		m_lpVoid[m_iCount] = Element;
		m_iCount++;
	}
	if(m_bResizable && m_iCount >= m_iLenght && m_iResizeVector > 0)
	{
		m_iCount--;
		m_iLenght *= m_iResizeVector;
		m_lpVoid = (void**)realloc(m_lpVoid, m_iLenght*sizeof(void*));
		Add(Element);
	}
}

void TArray::AddItemAt(void* item, int index)
{
	m_lpVoid[index] = item;
}


//void TArray::Add(const void*& Element)
//{
//	if(m_iCount < m_iLenght)
//	{
//		m_lpVoid[m_iCount] = &Element;
//		m_iCount++;
//	}
//	if(m_bResizable && m_iCount >= m_iLenght && m_iResizeVector > 0)
//	{
//		m_iCount--;
//		m_iLenght *= m_iResizeVector;
//		m_lpVoid = (void**)realloc(m_lpVoid, m_iLenght*sizeof(void*));
//		Add(Element);
//	}
//}

void TArray::Remove(void* Element)
{
	if(m_iCount > 0)
	{
		for(int index = 0; index < m_iCount; index ++)
		{			
			if(m_lpVoid[index] == Element)
			{
				m_lpVoid[index] = 0;
				ReArrange(index);
				m_iCount--;
				Remove(Element);
			}
		}
		return;
	}
	return;
}

void TArray::RemoveAt(int index)
{
	if(index < m_iCount && m_lpVoid[index] != 0)
	{
		m_lpVoid[index] = 0;
		free (m_lpVoid[index]);
		m_iCount--;
	}
}

void* TArray::GetItemAtIndex(int index)
{
	if(index < m_iCount)
		if(m_lpVoid)
			if(m_lpVoid[index])
				return m_lpVoid[index];
	
		return 0;
}

void TArray::ReArrange(int pos)
{
	for(int arrange = pos; arrange < m_iCount-1; arrange++)
	{
		m_lpVoid[arrange] = m_lpVoid[arrange+1];
	}
}

void TArray::SetResizeable(bool resizeable)
{
	m_bResizable = resizeable;

}
bool TArray::GetResizeable()
{
	return m_bResizable;
}
void TArray::SetResizeVector(int resizevector)
{
	m_iResizeVector = resizevector;
}
int TArray::GetResizeVector()
{
	return m_iResizeVector;
}

int TArray::Count()
{
	return m_iCount;
}

int TArray::Lenght()
{
	return m_iLenght;
}

void TArray::Destroy()
{
	free(m_lpVoid);
	m_lpVoid = 0;
}

void TArray::Clear()
{
	free(m_lpVoid);
	m_lpVoid = 0;
	m_iCount = 0;
	m_lpVoid = (void**)malloc(m_iLenght * sizeof(void*) + 1);
}
