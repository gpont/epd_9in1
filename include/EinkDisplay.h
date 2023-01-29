#ifndef EinkDisplay_h
#define EinkDisplay_h
#include "EPD_1in9.h"

#define IMAGE_SIZE 15

#define CELSIUS 0x05
#define FAHRENHEIT 0x06

class EinkDisplay
{
  bool needUpdate = false;
  uint16_t degreesType = CELSIUS;
  unsigned char image[IMAGE_SIZE];

  void setData(unsigned char new_image[]);

public:
  /**
   * @param degreesType CELSIUS || FAHRENHEIT
   */
  EinkDisplay(uint16_t degreesType = CELSIUS);
  ~EinkDisplay();
  virtual void loop();

  void setNumbers(float first, float second);
  void setLowPowerIndicator(bool isLowPower);
};

#endif