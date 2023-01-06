[![WiFi Bell Clock](http://img.youtube.com/vi/wLbWGUTRMRM/0.jpg)](http://www.youtube.com/watch?v=wLbWGUTRMRM "WiFi Bell Clock")

# WiFi Bell Clock
Bell clock that updates via WiFi

## Parts
| Qty | Product                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   | Description               |
| --- |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|
|1 | [DEVKIT v3](https://www.aliexpress.com/item/4000502101618.html?spm=a2g0o.productlist.main.5.3198f68fA7sb7l&algo_pvid=c776aa69-0f96-465c-8a3a-5ed33ba152b4&algo_exp_id=c776aa69-0f96-465c-8a3a-5ed33ba152b4-2&pdp_ext_f=%7B%22sku_id%22%3A%2210000002402566500%22%7D&pdp_npi=2%40dis%21ILS%2113.54%2113.54%21%21%21%21%21%40214527c616727687280498709d0741%2110000002402566500%21sea&curPageLogUid=hq0vy3dw9STm)                                                                                                                                                           | Main board                |
|1 | [TM-1637](https://www.aliexpress.com/item/1005003947103358.html?spm=a2g0o.productlist.main.5.2c1f54efabdjQw&algo_pvid=3a7beeb0-bfc2-45bb-9f4b-5e0a09c89a8d&aem_p4p_detail=202301030955189596255770804560001502397&algo_exp_id=3a7beeb0-bfc2-45bb-9f4b-5e0a09c89a8d-2&pdp_ext_f=%7B%22sku_id%22%3A%2212000027537145198%22%7D&pdp_npi=2%40dis%21ILS%212.51%212.51%21%21%21%21%21%402100b69816727685187147254d0787%2112000027537145198%21sea&curPageLogUid=76aEuJp2I9M5&ad_pvid=202301030955189596255770804560001502397_3&ad_pvid=202301030955189596255770804560001502397_3) | Digital LED Display Module |
|1 | [DY-SV8F](https://www.aliexpress.com/item/4000158216197.html?spm=a2g0o.productlist.main.3.43d39053hV2HAa&algo_pvid=34eaf8de-aa17-41dc-a00b-5ab655bd2f69&algo_exp_id=34eaf8de-aa17-41dc-a00b-5ab655bd2f69-1&pdp_ext_f=%7B%22sku_id%22%3A%2210000000499261457%22%7D&pdp_npi=2%40dis%21ILS%2111.16%2110.62%21%21%21%21%21%402100bbf516730229230858157d06fd%2110000000499261457%21sea&curPageLogUid=IDiaDdlFM516) | Voice Playback Module |

## Notes
[TM1637 ](https://github.com/Seeed-Studio/Grove_4Digital_Display) must be installed.

In the file Config.h you must set:
```
//Your WiFi SSID and Password
#define STASSID "YourSSID"
#define STAPSK  "YourPassword"
```
```
//Your Time Zone
#define MYTZ YourTimeZone
```
[See all time zones here](https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h)

Set desired **upload_port** in the file **platformio.ini** file.

## Connection Diagram
![Connection Diagram](Images/Connection%20Diagram.png)
