#include <Arduino.h>
#include "DHT22Controller.h"
#include "DrynessSensorController.hpp"

#define DHTPIN 27    // Digital pin connected to the DHT sensor 
#define DHTTYPE DHT22     // DHT 22 (AM2302)

#define SOILPIN 26

DHT22Controller dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.Initialize();
}

void loop() {

  Serial.print(F("Temperature: "));
  Serial.print(dht.GetTemperature());
  Serial.println(F("°C"));

  Serial.print(F("Humidity: "));
  Serial.print(dht.GetHumitidy());
  Serial.println(F("%"));


  Serial.print(F("Soil Dryness: "));
  Serial.print(GetSoilDryness(SOILPIN));
  Serial.println("%");

  // Delay between measurements.
  delay(dht.GetDelayMS());
}
