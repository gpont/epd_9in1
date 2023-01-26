#include <Arduino.h>
#include <stdio.h>
#include <Wire.h>
#include "EPD_1in9.h"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Wire.begin();
  Serial.println("e-Paper init and clear");
  GPIOInit();
  EPD_1in9_init();

  EPD_1in9_lut_5S();
  EPD_1in9_Write_Screen(DSPNUM_1in9_off);
  delay(500);

  EPD_1in9_lut_GC();

  EPD_1in9_Write_Screen1(DSPNUM_1in9_on);
  delay(500);

  EPD_1in9_Write_Screen(DSPNUM_1in9_off);
  delay(500);

  EPD_1in9_lut_DU_WB();
  EPD_1in9_Write_Screen(DSPNUM_1in9_W0);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W1);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W2);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W3);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W4);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W5);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W6);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W7);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W8);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_W9);
  delay(500);
  EPD_1in9_Write_Screen(DSPNUM_1in9_WB);
  delay(500);

  EPD_1in9_sleep();
  Serial.end();
  Wire.end();
}

void loop()
{
}
