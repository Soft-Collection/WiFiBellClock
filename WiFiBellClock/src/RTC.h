#ifndef RTC_h
#define RTC_h

#include <Arduino.h>
#include "Config.h"
#include <TZ.h>
#include <ESP8266WiFi.h>
#include <coredecls.h>                  // settimeofday_cb()
#include <Schedule.h>
#include <PolledTimeout.h>
#include <time.h>                       // time() ctime()
#include <sys/time.h>                   // struct timeval
#include <sntp.h>                       // sntp_servermode_dhcp()

class RTC
{
public:
	RTC();
	virtual ~RTC();
	void Init();
	void GetTime(int8_t &hour, int8_t &minute, int8_t &second);
	bool GetIsUpdated();
private:
	const char* mSSID;                       // your network SSID (name)
	const char* mPass;                       // your network password
};

#endif //RTC_h