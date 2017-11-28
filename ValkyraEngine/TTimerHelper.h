#pragma once
#include "TBaseClass.h"
#include <Windows.h>
class TTimerHelper : public TBaseClass
{
private:
	LONGLONG m_Frequency;
	LONGLONG m_CurrentCount;
	LONGLONG m_LastCount;
public:
	TTimerHelper();
	~TTimerHelper();
	void PerformanceCounterStart();
	void PerformanceCounterEnd();
	double GetDifference();
};

