#include <math.h>
#include <Wire.h>
#include "EinkDisplay.h"

EinkDisplay::EinkDisplay() : image{
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
                                 0x00, // TODO
                                 0x05, // С°
                                 0x00}
{
  Serial.begin(115200);
  Wire.begin();
  GPIOInit();
  EPD_1in9_init();

  // Clear screen
  EPD_1in9_lut_5S();
  EPD_1in9_Write_Screen(DSPNUM_1in9_off);
  delay(500);
  EPD_1in9_lut_GC();
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

unsigned char getPixel(int number, int order)
{
  return number == -1 ? EMPTY : DIGITS[number][order];
}

boolean isNaN(float a)
{
  return a != a;
}

int *parseNumber(float number, int digitsCount)
{
  int *digits = new int[digitsCount];
  for (int i = 0; i < digitsCount; i++)
  {
    if (isNaN(number))
    {
      digits[i] = -1;
    }
    else
    {
      digits[i] = (int)(number / pow(10, (digitsCount - i) - 2)) % 10;

      if (digits[i] == 0 && (i == 0 || digits[i - 1] == -1))
      {
        digits[i] = -1;
      }
    }
  }

  return digits;
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
      image[13], // С°
      image[14]};

  setData(new_image);

  delete[] digitsParsedFirst;
  delete[] digitsParsedSecond;
}

EinkDisplay::~EinkDisplay()
{
  EPD_1in9_sleep();
  Wire.end();
  Serial.end();
}