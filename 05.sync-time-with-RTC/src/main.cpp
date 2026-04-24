#include <RtcDS1302.h>

#include "RTCController.h"
#include "WifiController.hpp"
#include "DisplayController.h"

#define GPIO_RTC_CLK 14
#define GPIO_RTC_DAT 12
#define GPIO_RTC_RST 13

RTCController Rtc(GPIO_RTC_DAT, GPIO_RTC_CLK, GPIO_RTC_RST);
DisplayController display;

void setup() {
  Serial.begin(115200);

  bool isRTCAvailable = Rtc.InitializeRTC();
  bool isWifiConnected = ConnectWifi();
  if(isRTCAvailable && isWifiConnected)
  {
    Rtc.SyncRTCToNTP();
  }

  bool isDisplayAvailable = display.Initialize();
}

int rand5()
{
  double R = (double)rand() / (double)RAND_MAX;
  int val = (int)((R*10)-5 + 0.5);
  return val;
}

void loop() {
  String currentTime = Rtc.GetCurrentTimeString();
  Serial.println(currentTime);
  display.ClearDisplay(false);
  display.SetTextSize(1);
  display.PrintLine(currentTime, false);
  display.PrintLine("");

  display.SetTextSize(2);

  int temperature = 23+ rand5();
  String tem = "Tem: " + String(temperature) + (char)247 + "C";
  int humidity = 40+ rand5();
  String hum = "Hum: " + String(humidity) + "%";
  int dryness = 60+ rand5();
  String dry = "Dry: " + String(dryness) + "%";

  display.PrintLine(tem, false);
  display.PrintLine(hum, false);
  display.PrintLine(dry);

  delay(1000);
}