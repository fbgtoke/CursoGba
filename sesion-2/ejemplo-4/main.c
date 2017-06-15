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
  Ejemplo 4

  Muestra una escena construida con dos tilemaps en modo 0
  Colores indexados con 8bpp
  Cada tilemap se desplaza independientemente
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
  src = (uint16_t*)tilemap0;
  des = (uint16_t*)&SCREENBLOCK[8];
  count = 10*32;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init screen block
  src = (uint16_t*)tilemap1;
  des = (uint16_t*)&SCREENBLOCK[9];
  count = 10*32;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  /**
    Display Control

    BG Mode 0          => 0x0000
    Screen Display GB0 => 0x0100
    Screen Display GB1 => 0x0200
  */
  *DISPCNT = 0x0300;

  /**
    Background 0 Control

    Character block 0 => 0x0000
    Color mode 8bpp   => 0x0080
    Screen block 8    => 0x0800
    Size 32x32        => 0x0000
  */
  *BG0CNT = 0x0880;

  /**
    Background 1 Control

    Character block 0 => 0x0000
    Color mode 4bpp   => 0x0080
    Screen block 9    => 0x0900
    Size 32x32        => 0x0000
  */
  *BG1CNT = 0x0980;

  uint32_t FRAME = 0;
  uint16_t h_offset0 = 0;
  uint16_t h_offset1 = 0;
  while (1) {

    while (*VCOUNT < 160) __asm__("nop");

    if (FRAME % 120 == 0) {
      *BG0HOFF = ++h_offset0;
      *BG1HOFF = --h_offset1;
    }

    FRAME++;
  }

  return 0;
}
