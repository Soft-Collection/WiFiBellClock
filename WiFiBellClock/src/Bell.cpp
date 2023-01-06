#include "Bell.h"

Bell::Bell()
{
    mPeriod = new Period(this, 0, false);
   	mHour = (-1);
  	mMinute = (-1);
  	mSecond = (-1);
}
Bell::~Bell()
{
}
void Bell::Init()
{
    //-------------------------------
    pinMode(BUSY_PIN, INPUT_PULLUP);
    pinMode(SOUND_PIN_00, OUTPUT);
    pinMode(SOUND_PIN_01, OUTPUT);
    pinMode(SOUND_PIN_02, OUTPUT);
    pinMode(SOUND_PIN_03, OUTPUT);
    //-------------------------------
    digitalWrite(SOUND_PIN_00, HIGH); 
    digitalWrite(SOUND_PIN_01, HIGH); 
    digitalWrite(SOUND_PIN_02, HIGH); 
    digitalWrite(SOUND_PIN_03, HIGH); 
    //-------------------------------
    //attachInterrupt(digitalPinToInterrupt(BUSY_PIN), Bell::StopBell, RISING);
    //-------------------------------
    mPeriod->AddOnPeriodExpiredHandler(Bell::OnPeriodExpiredStatic);
    //-------------------------------
}
void Bell::Check(int8_t hour, int8_t minute, int8_t second)
{
    mPeriod->Check(millis());
    //-------------------------------
   	if (mHour == (-1)) mHour = hour;
  	if (mMinute == (-1)) mMinute = minute;
  	if (mSecond == (-1)) mSecond = second;
    if (mSecond != second)
    {
      if (mMinute != minute)
      {
        if (minute == 0)
        {
          OnNewHour(hour);
        }
        else if  (minute == 30)
        {
          On30Minutes();
        }
        mMinute = minute;
      }
      mSecond = second;
    }
    //-------------------------------
}
void Bell::BellNTimes(uint8_t n)
{
    digitalWrite(SOUND_PIN_00, (((n >> 0) & 1) ? LOW : HIGH)); 
    digitalWrite(SOUND_PIN_01, (((n >> 1) & 1) ? LOW : HIGH)); 
    digitalWrite(SOUND_PIN_02, (((n >> 2) & 1) ? LOW : HIGH)); 
    digitalWrite(SOUND_PIN_03, (((n >> 3) & 1) ? LOW : HIGH)); 
    mPeriod->SetPeriodInTicks(mBellPeriods[n - 1]);
    mPeriod->Reset();
}
IRAM_ATTR void Bell::StopBell() 
{
    digitalWrite(SOUND_PIN_00, HIGH); 
    digitalWrite(SOUND_PIN_01, HIGH); 
    digitalWrite(SOUND_PIN_02, HIGH); 
    digitalWrite(SOUND_PIN_03, HIGH); 
}
void Bell::OnPeriodExpiredStatic(void* instance)
{
 	  Bell* bell = (Bell*)instance;
	  if (bell != NULL) bell->OnPeriodExpired();
}
void Bell::OnPeriodExpired()
{
    StopBell();
}
void Bell::OnNewHour(int8_t hour)
{
    int8_t bellHour = hour % 12;
    if (bellHour == 0) bellHour = 12;
    BellNTimes(bellHour);
}
void Bell::On30Minutes()
{
  BellNTimes(1);
}
