#ifndef EinkDisplay_h
#define EinkDisplay_h
#include "EPD_1in9.h"

#define IMAGE_SIZE 15

#define CELSIUS 0x05
#define FAHRENHEIT 0x06
#define DOT 0b0000000000100000
#define PERCENT 0b0000000000100000
#define LOW_POWER_ON 0b0000000000010000
#define LOW_POWER_OFF 0b1111111111101111

class EinkDisplay
{
  bool needUpdate = false;
  unsigned char degreesType = CELSIUS;
  unsigned char image[IMAGE_SIZE];

  void setData(unsigned char new_image[IMAGE_SIZE]);

public:
  /**
   * @param degreesType CELSIUS || FAHRENHEIT
   */
  EinkDisplay(unsigned char degreesTypeInit = CELSIUS);
  ~EinkDisplay();
  virtual void loop();

  void setNumbers(float first, float second);
  void setLowPowerIndicator(bool isLowPower);
};

#endif