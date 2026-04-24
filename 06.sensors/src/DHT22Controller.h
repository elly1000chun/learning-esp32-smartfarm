#ifndef _DHT22_CONTROLLER_H_
#define _DHT22_CONTROLLER_H_

#include <DHT.h>
#include <DHT_U.h>

class DHT22Controller
{
public:
  DHT22Controller(uint8_t pin, uint8_t type);
  ~DHT22Controller();
  void Initialize();
  void PrintTemperatureSensorInfo();
  void PrintHumiditySensorInfo();

  float GetTemperature();
  float GetHumitidy();

  uint32_t GetDelayMS() { return delayMS; }
private:
  void SetDelayMS();

  DHT_Unified dht;
  uint32_t delayMS;
};

#endif
