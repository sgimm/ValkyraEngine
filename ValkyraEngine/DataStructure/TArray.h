#ifndef _TARRAY_H
#define _TARRAY_H
#pragma once
class TArray
{
private:
	void** m_lpVoid;
	int m_iCount;
	int m_iLenght;
	int m_iResizeVector;
	bool m_bResizable;
	void ReArrange(int);
public:
	TArray(int);
	~TArray(void);
	void Add(void*);
	void AddItemAt(void*, int);
	//void Add(const void*&);
	void Remove(void*);
	void RemoveAt(int);
	void* GetItemAtIndex(int);
	void SetResizeable(bool);
	bool GetResizeable();
	void SetResizeVector(int);
	int GetResizeVector();
	int Count();
	int Lenght();
	void Destroy();
	void Clear();
};
#endif // _TARRAY_H

