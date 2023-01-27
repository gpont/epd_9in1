#include <Arduino.h>

#include "EinkDisplay.h"

EinkDisplay *display;

void setup()
{
  display = new EinkDisplay();
}

void loop()
{
  display->setNumbers(
      123.4,
      12.3);

  display->loop();
  delay(500);
}
