#include "stdint.h"
#include "cave_story_credits.h"

/**
  VGA - Curso GBA
  Ejemplo 6

  Define un mapa de bits como una matriz y la copia sobre la VRAM (modo 3)
*/

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

int main() {

  uint16_t* DISPCNT = (uint16_t*)0x04000000;
  *DISPCNT = 0x0003 | 0x0400;

  uint16_t* VRAM = (uint16_t*)0x06000000;

  /**
    DMA Transfers

    40000D4h,0D6h - DMA3SAD - DMA 3 Source Address (W) (any memory)
    The most significant address bits are ignored, only the least significant 27 
    or 28 bits are used

    40000D8h,0DAh - DMA3DAD - DMA 3 Destination Address (W) (any memory)
    The most significant address bits are ignored, only the least significant 27 
    or 28 bits are used

    40000DCh - DMA3CNT_L - DMA 3 Word Count (W) (16 bit, 1..10000h)
    Specifies the number of data units to be transferred, each unit is 16bit or 
    32bit depending on the transfer type, a value of zero is treated as max 
    length

    40000DEh - DMA3CNT_H - DMA 3 Control (R/W)
    Bit   Expl.
    0-4   Not used
    5-6   Dest Addr Control  (0=Increment,1=Decrement,2=Fixed,3=Increment/Reload)
    7-8   Source Adr Control (0=Increment,1=Decrement,2=Fixed,3=Prohibited)
    9     DMA Repeat         (0=Off, 1=On) (Must be zero if Bit 11 set)
    10    DMA Transfer Type  (0=16bit, 1=32bit)
    11    Game Pak DRQ       (0=Normal, 1=DRQ <from> Game Pak, DMA3)
    12-13 DMA Start Timing   (0=Immediately, 1=VBlank, 2=HBlank, 3=Special)
            The 'Special' setting (Start Timing=3) depends on the DMA channel:
            DMA0=Prohibited, DMA1/DMA2=Sound FIFO, DMA3=Video Capture
    14    IRQ upon end of Word Count   (0=Disable, 1=Enable)
    15    DMA Enable                   (0=Off, 1=On)
  */
  uint32_t* DMA3SAD = (uint32_t*)0x040000d4;
  uint32_t* DMA3DAD = (uint32_t*)0x040000d8;
  uint16_t* DMA3CNT_L = (uint16_t*)0x040000dc;
  uint16_t* DMA3CNT_H = (uint16_t*)0x040000de;

  *DMA3SAD = (uint32_t)cave_story_creditsBitmap;
  *DMA3DAD = (uint32_t)VRAM;

  /**
    cave_story_creditsBitmapLen given in bytes
  */
  *DMA3CNT_L = cave_story_creditsBitmapLen / 2;

  /**
    Dest Addr Control          => Increment   => 0x0000
    Source Addr Control        => Increment   => 0x0000
    DMA Repeat                 => Off         => 0x0000
    DMA Transfer Type          => 16bit       => 0x0000
    GAME Pak DRQ               => Normal      => 0x0000
    DMA Start Timing           => Immediately => 0x0000
    IRQ upon end of Word Count => Disable     => 0x0000
    DMA Enable                 => On          => 0x8000
  */
  *DMA3CNT_H = 0x8000;

  while (1);

  return 0;
}