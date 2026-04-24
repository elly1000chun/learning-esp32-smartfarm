#include <WiFi.h>

bool ConnectWifi()
{
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
  }
  else
  {
    Serial.print(String("Failed to connect"));
  }

  return isConnected;
}