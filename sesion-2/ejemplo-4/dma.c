#include "dma.h"

volatile uint32_t* DMA3SAD = (uint32_t*)0x040000d4;
volatile uint32_t* DMA3DAD = (uint32_t*)0x040000d8;
volatile uint16_t* DMA3CNT_L = (uint16_t*)0x040000dc;
volatile uint16_t* DMA3CNT_H = (uint16_t*)0x040000de;

inline void memcpy16(uint32_t src, uint32_t des, uint16_t count) {
  *DMA3SAD = src;
  *DMA3DAD = des;
  *DMA3CNT_L = count;
  *DMA3CNT_H = 0x8000;

  __asm__("nop");
  __asm__("nop");
}