#include "RTC.h"

RTC::RTC()
{
 	mSSID = STASSID; 
	mPass = STAPSK;  
}
RTC::~RTC()
{
}
void RTC::Init()
{
  configTime(MYTZ, "pool.ntp.org");
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(STASSID, STAPSK);
}
void RTC::GetTime(int8_t &hour, int8_t &minute, int8_t &second)
{
  timeval tv;
  time_t now;  
  gettimeofday(&tv, nullptr);
  now = time(nullptr);
  hour = localtime(&now)->tm_hour;
  minute = localtime(&now)->tm_min;
  second = localtime(&now)->tm_sec;
}
bool RTC::GetIsUpdated()
{
  timeval tv;
  time_t now;  
  gettimeofday(&tv, nullptr);
  now = time(nullptr);
  int year = localtime(&now)->tm_year;
  return(year != 70);
}