#include <Arduino.h>

#define LED 2
#define GPIO 13

void setup() {
  Serial.begin(115200);
  pinMode(GPIO, GPIO_MODE_OUTPUT);
}

void loop() {
  digitalWrite(GPIO, HIGH);
  Serial.println("LED is on");
  delay(1000);
  digitalWrite(GPIO, LOW);
  Serial.println("LED is off");
  delay(1000);
}
