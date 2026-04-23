
#include <Arduino.h>

int note[] = {440, 554, 659, 880};

void SoundSuccess(int gpio)
{
  for(int i=0; i < 4; i++)
  {
    tone(gpio, note[i], 250);
    delay(250);
  }
}

void SoundFailure(int gpio)
{
  tone(gpio, 880, 500);
}