#include "Period.h"
#include "CommonFunctions.h"

Period::Period(void* instance, uint32_t periodInTicks, boolean autoReset)
{
	mPeriodInTicks = periodInTicks;
	mAutoReset = autoReset;
	//--------------------------------------------
	mInstance = instance;
	mOnPeriodExpired = NULL;
	//--------------------------------------------
	mLastTicks = TIME_NOT_SET;
	mOnPeriodExpiredMayRun = true;
	mMustPerformReset = false;
}
Period::~Period()
{
}
void Period::Reset()
{
	mMustPerformReset = true;
}
boolean Period::PeriodExpired(uint32_t ticks)
{
	return((minus_time(ticks, mLastTicks) > mPeriodInTicks) && (mLastTicks > 0));
}
void Period::Check(uint32_t ticks)
{
	if (mMustPerformReset)
	{
		mLastTicks = ticks;
		mOnPeriodExpiredMayRun = true;
		mMustPerformReset = false;
	}
	if (PeriodExpired(ticks))
	{
		if (mOnPeriodExpiredMayRun)
		{
			mOnPeriodExpiredMayRun = false;
			if (mOnPeriodExpired != 0) mOnPeriodExpired(mInstance);
		}
		//---------------------------------
		if (mAutoReset)
		{
			mLastTicks = ticks;
			mOnPeriodExpiredMayRun = true;
		}
	}
}
boolean Period::GetAutoReset()
{
	return(mAutoReset);
}
void Period::SetPeriodInTicks(uint32_t periodInTicks)
{
	mPeriodInTicks = periodInTicks;
}
void Period::AddOnPeriodExpiredHandler(dlgOnPeriodExpired onPeriodExpired)
{
	mOnPeriodExpired = onPeriodExpired;
}