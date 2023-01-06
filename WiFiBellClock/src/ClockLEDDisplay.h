#ifndef ClockLEDDisplay_h
#define ClockLEDDisplay_h

#include <Arduino.h>
#include <TM1637.h>
#include "Config.h"

class ClockLEDDisplay
{
public:
	ClockLEDDisplay();
	virtual ~ClockLEDDisplay();
	void Init();
	void DisplayTime(int8_t hour, int8_t minute, bool showPoints);
	void DisplayPointsOnly(bool showPoints);
private:
	TM1637* mTM1637;
};

#endif //ClockLEDDisplay_h