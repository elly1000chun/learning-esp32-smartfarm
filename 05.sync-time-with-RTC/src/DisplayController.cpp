#include "DisplayController.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

DisplayController::DisplayController()
  : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1)
{}

DisplayController::~DisplayController()
{}

bool DisplayController::Initialize()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    return false;
  }

  display.clearDisplay();
  
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.display();  
  return true;
}


void DisplayController::SetTextSize(int size)
{
  display.setTextSize(size);
}

void DisplayController::PrintLine(String string, bool bUpdate)
{
  display.println(string);
  if(bUpdate)
  {
    display.display();
  }
}

void DisplayController::ClearDisplay(bool bUpdate)
{
  display.clearDisplay();
  display.setCursor(0,0);

  if(bUpdate)
  {
    display.display();
  }
}
