#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true) {}
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(2);
  display.println(F("Wi-Fi Connecting"));
  display.display();

  for(int i = 0; i < 10; i++)
  {
    display.print(F("."));
    delay(200);
    display.display();
  }

  display.clearDisplay();
  display.setCursor(0,0);
  display.print(F("Wi-Fi Connected."));
  display.display();

  delay(1000);
  
}

int rand5()
{
  double R = (double)rand() / (double)RAND_MAX;
  int val = (int)((R*10)-5 + 0.5);
  return val;
}

void loop() {
  int temperature = 23+ rand5();
  String tem = "Tem: " + String(temperature) + (char)247 + "C";
  int humidity = 40+ rand5();
  String hum = "Hum: " + String(humidity) + "%";
  int dryness = 60+ rand5();
  String dry = "Dry: " + String(dryness) + "%";

  display.clearDisplay();
  display.setCursor(0,0);
  display.println(tem);
  display.println(hum);
  display.println(dry);
  display.display();

  delay(1000);
}