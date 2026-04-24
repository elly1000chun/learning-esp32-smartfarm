#include <RtcDS1302.h>

#include "RTCController.h"
#include "WifiController.hpp"

#define GPIO_RTC_CLK 14
#define GPIO_RTC_DAT 12
#define GPIO_RTC_RST 13

RTCController Rtc(GPIO_RTC_DAT, GPIO_RTC_CLK, GPIO_RTC_RST);

void setup() {
  Serial.begin(115200);

  bool isRTCAvailable = Rtc.InitializeRTC();
  bool isWifiConnected = ConnectWifi();
  if(isRTCAvailable && isWifiConnected)
  {
    Rtc.SyncRTCToNTP();
  }
}

void loop() {
  Serial.println(Rtc.GetCurrentTimeString());
  delay(1000);
}