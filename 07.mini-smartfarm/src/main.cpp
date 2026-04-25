#include <Arduino.h>
#include <WiFi.h>
#include "network/thingspeak.hpp"
#include "network/wifiController.hpp"
#include "display/OledController.h"
#include "sensors/AHT20Controller.h"
#include "sensors/DrynessSensorController.hpp"

#define SOILPIN 33

OledController oled;
AHT20Controller aht;

bool isDisplayAvailable = false;
bool isWifiConnected = false;
bool isAHTAvailable = false;

void setup() {
  Serial.begin(115200);

  // Init display
  isDisplayAvailable = oled.Initialize();
  if(isDisplayAvailable == false)
  {
    // don't do anything
    while(1);
  }

  oled.SetTextSize(1);
  oled.PrintLine("Welcome.");
  delay(1000);
  oled.PrintLine("Wi-Fi Connecting...");
 
  int counter = 0;
  isWifiConnected = network::ConnectWifi();

  if(isWifiConnected == true)
  {
    oled.PrintLine("Wi-Fi Connected.");
  }
  else
  {
    oled.PrintLine("Wi-Fi Error.");
    // don't do anything
    while(1);
  }

  isAHTAvailable = aht.Initialize();
  if(isAHTAvailable)
  {
    oled.PrintLine("Temp&Hum sensor initialized.");
  }
  else
  {
    oled.PrintLine("Temp&Hum sensor error.");
    // don't do anything
    while(1);
  }
}

int count = 0;

void loop()
{
  if(isAHTAvailable == false)
  {
    return;
  }

  if(count > 3) 
  {
    delay(1000);
    return;
  }

  int temperature = aht.GetTemperature();
  String tem = "Tem: " + String(temperature) + (char)247 + "C";
  int humidity = aht.GetHumitidy();
  String hum = "Hum: " + String(humidity) + "%";
  int dryness = DrynessSensor::GetSoilDryness(SOILPIN);
  String dry = "Dry: " + String(dryness) + "%";

  oled.ClearDisplay(false);
  oled.SetTextSize(2);
  oled.PrintLine(tem, false);
  oled.PrintLine(hum, false);
  oled.PrintLine(dry);
  
    // send dummy value for now
  //network::SendDataThingspeak(temperature, humidity, dryness);
  delay(10000);
  count++;
}
