#include <Arduino.h>
#include "RTCController.h"

RTCController::RTCController(uint8_t ioPin, uint8_t clkPin, uint8_t cePin)
  : mywire(ioPin, clkPin, cePin)
  , Rtc(mywire)
{

}

RTCController::~RTCController()
{
  // do nothing
}

bool RTCController::InitializeRTC()
{
  Rtc.Begin();

  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  String timestamp = GetDateTimeString(compiled);
  Serial.println(timestamp);

  if (!Rtc.IsDateTimeValid()) 
  {
    Serial.println("RTC lost confidence in the DateTime!");
    Rtc.SetDateTime(compiled);
  }

  if (!Rtc.GetIsRunning())
  {
    Serial.println("RTC was not actively running, starting now");
    Rtc.SetIsRunning(true);
  }

  RtcDateTime now = Rtc.GetDateTime();
  if (now < compiled) 
  {
    Serial.println("RTC is older than compile time!  (Updating DateTime)");
    Rtc.SetDateTime(compiled);
  }
  else if (now > compiled) 
  {
    Serial.println("RTC is newer than compile time. (this is expected)");
  }
  else if (now == compiled) 
  {
    Serial.println("RTC is the same as compile time! (not expected but all is fine)");
  }

  if(!Rtc.GetIsRunning() || !Rtc.IsDateTimeValid())
  {
    return false;
  }

  return true;
}

String RTCController::GetCurrentTimeString()
{
  if (!Rtc.IsDateTimeValid()) 
  {
    // Common Causes:
    //    1) the battery on the device is low or even missing and the power line was disconnected
    Serial.println("RTC lost confidence in the DateTime!");
    return String("");
  }

  return GetDateTimeString(Rtc.GetDateTime());
}

String RTCController::GetDateTimeString(const RtcDateTime& dt)
{
    char datestring[20];
    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%04u/%02u/%02u %02u:%02u:%02u"),
            dt.Year(),
            dt.Month(),
            dt.Day(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );

    return String(datestring);
}