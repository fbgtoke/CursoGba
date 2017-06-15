#include "stdint.h"
#include "mem.h"
#include "dma.h"

#include "palette.h"
#include "tilesheet.h"
#include "tilemap.h"

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

/**
  VGA - Curso GBA
  Ejemplo 3

  Muestra una escena construida con un tilemap en modo 0
  Colores indexados con 8bpp
  La escena se desplaza en horizontal
*/
int main() {

  volatile uint16_t* src;
  volatile uint16_t* des;
  volatile uint16_t count;

  // Init palette
  src = (uint16_t*)palette;
  des = (uint16_t*)&PALMEM[0];
  count = 5;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init character block
  src = (uint16_t*)tilesheet;
  des = (uint16_t*)&CHARBLOCK[0];
  count = 5*32;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init screen block
  src = (uint16_t*)tilemap;
  des = (uint16_t*)&SCREENBLOCK[8];
  count = 10*32;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  /**
    Display Control

    BG Mode 0          => 0x0000
    Screen Display GB0 => 0x0100
  */
  *DISPCNT = 0x0100;

  /**
    Background 0 Control

    Character block 0 => 0x0000
    Color mode 8bpp   => 0x0080
    Screen block 8    => 0x0800
    Size 32x32        => 0x0000
  */
  *BG0CNT = 0x0880;

  uint32_t FRAME = 0;
  uint16_t h_offset = 0;
  while (1) {

    while (*VCOUNT < 160) __asm__("nop");

    if (FRAME % 120 == 0)
      *BG0HOFF = ++h_offset;

    FRAME++;
  }

  return 0;
}