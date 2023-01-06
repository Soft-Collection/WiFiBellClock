#ifndef Config_h
#define Config_h

#ifndef STASSID
#define STASSID "YourSSID"
#define STAPSK  "YourPassword"
#endif

#define MYTZ TZ_America_New_York

//pins definitions for TM1637 and can be changed to other ports
#define  CLK_PIN  5 
#define  DIO_PIN  0

#define  BUSY_PIN      10 
#define  SOUND_PIN_00  16
#define  SOUND_PIN_01  13 
#define  SOUND_PIN_02  12
#define  SOUND_PIN_03  14 

#endif //Config_h