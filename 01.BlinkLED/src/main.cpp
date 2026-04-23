#include <Arduino.h>

#define LED 2
#define GPIO_LED 13

void setup() {
  Serial.begin(115200);
  pinMode(GPIO_LED, GPIO_MODE_OUTPUT);
}

void loop() {
  digitalWrite(GPIO_LED, HIGH);
  Serial.println("LED is on");
  delay(1000);
  digitalWrite(GPIO_LED, LOW);
  Serial.println("LED is off");
  delay(1000);
}
