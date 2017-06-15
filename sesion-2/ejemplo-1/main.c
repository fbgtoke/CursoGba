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
  Ejemplo 1

  Muestra una escena construida con un tilemap en modo 0
  Colores indexados con 4bpp
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
  count = 5*16;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init screen block
  src = (uint16_t*)tilemap;
  des = (uint16_t*)&SCREENBLOCK[8];
  count = 20*32;
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
    Color mode 4bpp   => 0x0000
    Screen block 8    => 0x0800
    Size 32x32        => 0x0000
  */
  *BG0CNT = 0x0800;

  while (1) { __asm__("nop"); }

  return 0;
}