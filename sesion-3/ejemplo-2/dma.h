#ifndef DMA_H
#define DMA_H

#include "stdint.h"

extern volatile uint32_t* DMA3SAD;
extern volatile uint32_t* DMA3DAD;
extern volatile uint16_t* DMA3CNT_L;

/**
  40000DEh - DMA3CNT_H - DMA 3 Control

  Bit   Expl.
  0-4   Not used
  5-6   Dest Addr Control            (0=Increment,1=Decrement,2=Fixed,3=Increment/Reload)
  7-8   Source Adr Control           (0=Increment,1=Decrement,2=Fixed,3=Prohibited)
  9     DMA Repeat                   (0=Off, 1=On) (Must be zero if Bit 11 set)
  10    DMA Transfer Type            (0=16bit, 1=32bit)
  11    Game Pak DRQ  - DMA3 only -  (0=Normal, 1=DRQ <from> Game Pak, DMA3)
  12-13 DMA Start Timing             (0=Immediately, 1=VBlank, 2=HBlank, 3=Special)
          The 'Special' setting      (Start Timing=3) depends on the DMA channel:
          DMA0=Prohibited, DMA1/DMA2=Sound FIFO, DMA3=Video Capture
  14    IRQ upon end of Word Count   (0=Disable, 1=Enable)
  15    DMA Enable                   (0=Off, 1=On)
*/
extern volatile uint16_t* DMA3CNT_H;

void memcpy16(uint32_t src, uint32_t des, uint16_t count);

#endif