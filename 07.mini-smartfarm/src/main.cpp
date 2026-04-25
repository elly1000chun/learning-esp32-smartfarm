#include <Arduino.h>
#include <WiFi.h>
#include "network/thingspeak.hpp"
#include "network/wifiController.hpp"

void setup() {
  Serial.begin(115200);
 
  int counter = 0;
  bool isConnected = network::ConnectWifi();

  if(isConnected == false)
  {
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
