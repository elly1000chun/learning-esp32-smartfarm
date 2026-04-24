#include <RtcDS1302.h>
#include <WiFi.h>
#include "RTCController.h"

#define GPIO_RTC_CLK 14
#define GPIO_RTC_DAT 12
#define GPIO_RTC_RST 13

RTCController Rtc(GPIO_RTC_DAT, GPIO_RTC_CLK, GPIO_RTC_RST);

void setup() {
  Serial.begin(115200);
  Rtc.InitializeRTC();
  
}

void loop() {
  Serial.println(Rtc.GetCurrentTimeString());
  delay(200);
}