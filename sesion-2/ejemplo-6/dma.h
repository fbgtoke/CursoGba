#ifndef DMA_H
#define DMA_H

#include "stdint.h"

extern volatile uint32_t* DMA3SAD;
extern volatile uint32_t* DMA3DAD;
extern volatile uint16_t* DMA3CNT_L;
extern volatile uint16_t* DMA3CNT_H;

void memcpy16(uint32_t src, uint32_t des, uint16_t count);

#endif