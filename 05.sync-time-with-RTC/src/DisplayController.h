#ifndef _DISPLAY_CONTROLLER_H
#define _DISPLAY_CONTROLLER_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayController
{
public:
  DisplayController();
  ~DisplayController();
  bool Initialize();

  void SetTextSize(int size);
  void PrintLine(String string, bool bUpdate = true);
  void ClearDisplay(bool bUpdate);

private: 
  Adafruit_SSD1306 display;
};

#endif