#include <Wire.h>
#include "EinkDisplay.h"

#include "utils.cpp"

EinkDisplay::EinkDisplay(uint16_t degreesType = CELSIUS)
    : image{
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x00,
          0x05, // С°/F°
          0x00}
{
  Serial.begin(115200);
  Wire.begin();

  image[13] = degreesType;

  GPIOInit();
  EPD_1in9_init();

  // Clear screen
  EPD_1in9_lut_DU_WB();
  EPD_1in9_Write_Screen(DSPNUM_1in9_off);
  delay(500);
}

void EinkDisplay::loop()
{
  if (needUpdate)
  {
    delay(300);
    EPD_1in9_Write_Screen(image);

    needUpdate = false;
  }
}

void EinkDisplay::setData(unsigned char new_image[IMAGE_SIZE])
{
  for (int i = 0; i < IMAGE_SIZE; i++)
  {
    if (new_image[i] != image[i])
    {
      image[i] = new_image[i];
      needUpdate = true;
    }
  }
}

void EinkDisplay::setNumbers(float first, float second)
{
  int *digitsParsedFirst = parseNumber(first, 4);
  int *digitsParsedSecond = parseNumber(second, 3);

  unsigned char new_image[] = {
      getPixel(digitsParsedFirst[0], 1),
      getPixel(digitsParsedFirst[1], 0),
      getPixel(digitsParsedFirst[1], 1),
      getPixel(digitsParsedFirst[2], 0),
      getPixel(digitsParsedFirst[2], 1),
      getPixel(digitsParsedSecond[0], 0),
      getPixel(digitsParsedSecond[0], 1),
      getPixel(digitsParsedSecond[1], 0),
      getPixel(digitsParsedSecond[1], 1),
      getPixel(digitsParsedSecond[2], 0),
      getPixel(digitsParsedSecond[2], 1),
      getPixel(digitsParsedFirst[3], 0),
      getPixel(digitsParsedFirst[3], 1),
      image[12],
      image[13], // С°/F°
      image[14]};

  new_image[4] |= 0b0000000000100000;  // set top dot
  new_image[8] |= 0b0000000000100000;  // set bottom dot
  new_image[10] |= 0b0000000000100000; // set percent symbol

  setData(new_image);

  delete[] digitsParsedFirst;
  delete[] digitsParsedSecond;
}

void EinkDisplay::setLowPowerIndicator(bool isLowPower)
{
  image[13] |= isLowPower ? 0b0000000000010000 : 0b1111111111101111;
}

EinkDisplay::~EinkDisplay()
{
  EPD_1in9_sleep();
  Wire.end();
  Serial.end();
}