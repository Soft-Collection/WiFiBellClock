#ifndef Bell_h
#define Bell_h

#include <Arduino.h>
#include "Config.h"
#include "Period.h"

class Bell
{
public:
	Bell();
	virtual ~Bell();
	void Init();
	void Check(int8_t hour, int8_t minute, int8_t second);
	void BellNTimes(uint8_t n);
private:
	static IRAM_ATTR void StopBell();
	static void OnPeriodExpiredStatic(void* instance);
	void OnPeriodExpired();	
	void OnNewHour(int8_t hour);	
	void On30Minutes();	
private:
    Period* mPeriod;
	uint32_t mBellPeriods[12] = {18080, 22076, 26082, 30099, 34085, 38081, 42097, 46098, 50120, 54111, 58117, 62123};
	int8_t mHour;
	int8_t mMinute;
	int8_t mSecond;
};

#endif //Bell_h