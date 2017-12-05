#include "TTimerHelper.h"


TTimerHelper::TTimerHelper()
{
	m_szClassName = "TTimerHelper";
}


TTimerHelper::~TTimerHelper()
{
}

void TTimerHelper::PerformanceCounterStart()
{
	if (!QueryPerformanceFrequency((LARGE_INTEGER*)&m_Frequency))
		QueryPerformanceCounter((LARGE_INTEGER*)&m_CurrentCount);
}

void TTimerHelper::PerformanceCounterEnd()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&m_LastCount);
}

double TTimerHelper::GetDifference()
{
	double dTimeDiff = (((double)(m_LastCount - m_CurrentCount))); // ((double)m_Frequency));
	return dTimeDiff;
}
