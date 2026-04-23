#include <Arduino.h>
#include <WiFi.h>
#include "piezo_sound.hpp"
#include "thingspeak.hpp"

#define LED 2
#define GPIO_PIEZO 14

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  Serial.println("Simple Wi-Fi Example");
 
  // start connection
  Serial.println(String("Connect try : ") + WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int counter = 0;
  bool isConnected = true;

  // waiting connection...
  while(WiFi.status() != WL_CONNECTED )
  {
    if(counter > 20) 
    {
      isConnected = false;
      break;
    }

    delay(500);
    Serial.println(".");
    counter++;
  }

  // handle result
  if(isConnected == true)
  {
    Serial.print(String("WIFI conneted\n IP : "));
    Serial.println(WiFi.localIP());  
    SoundSuccess(GPIO_PIEZO);
  }
  else
  {
    SoundFailure(GPIO_PIEZO);
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
  SendDataThingspeak(23 + rand5(), 40+ rand5(), 60+ rand5());
  delay(10000);
  count++;
}
