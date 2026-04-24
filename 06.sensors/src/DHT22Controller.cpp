#include "DHT22Controller.h"

DHT22Controller::DHT22Controller(uint8_t pin, uint8_t type)
  : dht(pin, type)
{}

DHT22Controller::~DHT22Controller()
{}

void DHT22Controller::Initialize()
{
  // Initialize device.
  dht.begin();

  PrintTemperatureSensorInfo();
  PrintHumiditySensorInfo();
  SetDelayMS();
}


void DHT22Controller::SetDelayMS()
{
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);

  // Set delay between sensor readings based on sensor details.
  int delayMSTemp = sensor.min_delay / 1000;
  Serial.print("Delay ms Tem: ");
  Serial.println(delayMSTemp);

  dht.humidity().getSensor(&sensor);
  // Set delay between sensor readings based on sensor details.
  int delayMSHum = sensor.min_delay / 1000;
  Serial.print("Delay ms Hum: ");
  Serial.println(delayMSHum);

  delayMS = delayMSHum > delayMSTemp ? delayMSHum : delayMSTemp;
}

void DHT22Controller::PrintTemperatureSensorInfo()
{
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
}

void DHT22Controller::PrintHumiditySensorInfo()
{
  // Print humidity sensor details.
  sensor_t sensor;
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
}

float DHT22Controller::GetTemperature()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  float tm = 0;
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    tm = event.temperature;
  }

  return tm;
}

float DHT22Controller::GetHumitidy()
{
  sensors_event_t event;
  dht.humidity().getEvent(&event);

  float hm = 0;
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    hm = event.relative_humidity;
  }

  return hm;
}