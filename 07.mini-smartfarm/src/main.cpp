#include <Arduino.h>
#include <WiFi.h>
#include "network/thingspeak.hpp"
#include "network/wifiController.hpp"
#include "display/OledController.h"

OledController oled;

bool isDisplayAvailable = false;
bool isWifiConnected = false;

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
}

int count = 0;

int rand5()
{
  double R = (double)rand() / (double)RAND_MAX;
  int val = (int)((R*10)-5 + 0.5);
  return val;
}

void loop() {

  if(count > 2) 
  {
    delay(1000);
    return;
  }
  
  // send dummy value for now
  network::SendDataThingspeak(23 + rand5(), 40+ rand5(), 60+ rand5());
  delay(10000);
  count++;
}
