#include <Arduino.h>
#include <stdio.h>
#include <Wire.h>
#include "EPD_1in9.h"

unsigned char DSPNUM_1in9[][15] = {
    {
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
        0xff,
    }, // all black
    {
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
        0x00,
        0x00,
    }, // all white
    {
        0x00,
        0xbf,
        0x1f,
        0xbf,
        0x1f,
        0xbf,
        0x1f,
        0xbf,
        0x1f,
        0xbf,
        0x1f,
        0xbf,
        0x1f,
        0x00,
        0x00,
    }, // 0
    {
        0xff,
        0x1f,
        0x00,
        0x1f,
        0x00,
        0x1f,
        0x00,
        0x1f,
        0x00,
        0x1f,
        0x00,
        0x1f,
        0x00,
        0x00,
        0x00,
    }, // 1
    {
        0x00,
        0xfd,
        0x17,
        0xfd,
        0x17,
        0xfd,
        0x17,
        0xfd,
        0x17,
        0xfd,
        0x17,
        0xfd,
        0x37,
        0x00,
        0x00,
    }, // 2
    {
        0x00,
        0xf5,
        0x1f,
        0xf5,
        0x1f,
        0xf5,
        0x1f,
        0xf5,
        0x1f,
        0xf5,
        0x1f,
        0xf5,
        0x1f,
        0x00,
        0x00,
    }, // 3
    {
        0x00,
        0x47,
        0x1f,
        0x47,
        0x1f,
        0x47,
        0x1f,
        0x47,
        0x1f,
        0x47,
        0x1f,
        0x47,
        0x3f,
        0x00,
        0x00,
    }, // 4
    {
        0x00,
        0xf7,
        0x1d,
        0xf7,
        0x1d,
        0xf7,
        0x1d,
        0xf7,
        0x1d,
        0xf7,
        0x1d,
        0xf7,
        0x1d,
        0x00,
        0x00,
    }, // 5
    {
        0x00,
        0xff,
        0x1d,
        0xff,
        0x1d,
        0xff,
        0x1d,
        0xff,
        0x1d,
        0xff,
        0x1d,
        0xff,
        0x3d,
        0x00,
        0x00,
    }, // 6
    {
        0x00,
        0x21,
        0x1f,
        0x21,
        0x1f,
        0x21,
        0x1f,
        0x21,
        0x1f,
        0x21,
        0x1f,
        0x21,
        0x1f,
        0x00,
        0x00,
    }, // 7
    {
        0x00,
        0xff,
        0x1f,
        0xff,
        0x1f,
        0xff,
        0x1f,
        0xff,
        0x1f,
        0xff,
        0x1f,
        0xff,
        0x3f,
        0x00,
        0x00,
    }, // 8
    {
        0x00,
        0xf7,
        0x1f,
        0xf7,
        0x1f,
        0xf7,
        0x1f,
        0xf7,
        0x1f,
        0xf7,
        0x1f,
        0xf7,
        0x1f,
        0x00,
        0x00,
    }, // 9
    {
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
        0xFF,
    } // All black font
};

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  Serial.println("e-Paper init and clear");
  GPIOInit();
  EPD_1in9_init();

  EPD_1in9_lut_5S();
  EPD_1in9_Write_Screen(DSPNUM_1in9[0]);
  delay(500);

  EPD_1in9_lut_GC();

  EPD_1in9_Write_Screen(DSPNUM_1in9[1]); // TODO test 0x03
  delay(500);

  EPD_1in9_Write_Screen(DSPNUM_1in9[0]);
  delay(500);

  EPD_1in9_lut_DU_WB();
}

void loop()
{
  for (unsigned int i = 2; i <= 14; i++)
  {
    EPD_1in9_Write_Screen(DSPNUM_1in9[i]);
    delay(500);
  }

  // Before shutdown
  // EPD_1in9_sleep();
  // Serial.end();
  // Wire.end();
}
