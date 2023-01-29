#ifndef _EPD_1in9_H_
#define _EPD_1in9_H_

#include <Arduino.h>
#include <Wire.h>
#include <stdlib.h>
// address
#define adds_com 0x3C
#define adds_data 0x3D

extern unsigned char DSPNUM_9in1_off[];

void GPIOInit(void);
void EPD_1in9_Reset(void);
void EPD_1in9_SendCommand(unsigned char Reg);
void EPD_1in9_SendData(unsigned char Data);
unsigned char EPD_1in9_readCommand(unsigned char Reg);
unsigned char EPD_1in9_readData(unsigned char Data);
void EPD_1in9_ReadBusy(void);
void EPD_1in9_lut_DU_WB(void);
void EPD_1in9_lut_GC(void);
void EPD_1in9_lut_5S(void);
void EPD_1in9_Temperature(void);
void EPD_1in9_init(void);
void EPD_1in9_Write_Screen(unsigned char *image);
void EPD_1in9_sleep(void);

#endif
