#include <Arduino.h>

#include "EinkDisplay.h"

EinkDisplay *display;

void setup()
{
  display = new EinkDisplay(CELSIUS);
}

void loop()
{
  display->setNumbers(
      123.4,
      12.3);

  display->setLowPowerIndicator(true);

  display->loop();
  delay(300); // For stable updating
}
