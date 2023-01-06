#include "ClockLEDDisplay.h"

ClockLEDDisplay::ClockLEDDisplay()
{
    mTM1637 = new TM1637(CLK_PIN, DIO_PIN);
}
ClockLEDDisplay::~ClockLEDDisplay()
{
    if (mTM1637 != NULL)
    {
        delete mTM1637;
    }
}
void ClockLEDDisplay::Init()
{
    mTM1637->set();
    mTM1637->init();
}
void ClockLEDDisplay::DisplayTime(int8_t hour, int8_t minute, bool showPoints)
{
  	int8_t TimeDisp[] = {hour / 10, hour % 10, minute / 10, minute % 10};
    mTM1637->point((showPoints) ? POINT_ON : POINT_OFF);
    mTM1637->display(TimeDisp);
}
void ClockLEDDisplay::DisplayPointsOnly(bool showPoints)
{
    mTM1637->point((showPoints) ? POINT_ON : POINT_OFF);
    mTM1637->clearDisplay();
}