#if !defined(__PERIOD_H__)
#define __PERIOD_H__

#include <Arduino.h>

class Period
{
public:
	typedef void(*dlgOnPeriodExpired)(void* instance);
public:
	Period(void* instance, uint32_t periodInTicks, boolean autoReset);
	virtual ~Period();
	void Check(uint32_t ticks);
	void Reset();
	boolean PeriodExpired(uint32_t ticks);
	boolean GetAutoReset();
	void SetPeriodInTicks(uint32_t periodInTicks);
	void AddOnPeriodExpiredHandler(dlgOnPeriodExpired onPeriodExpired);
private:
	uint32_t           mPeriodInTicks;
	boolean            mAutoReset;
	//-----------------------------------
	void*              mInstance;
	dlgOnPeriodExpired mOnPeriodExpired;
	//-----------------------------------
	uint32_t           mLastTicks;
	boolean            mOnPeriodExpiredMayRun;
	boolean            mMustPerformReset;
};

#endif // !defined(__PERIOD_H__)