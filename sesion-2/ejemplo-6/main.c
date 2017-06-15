#include "stdint.h"
#include "mem.h"
#include "dma.h"

#include "mario_world.h"
#include "tilemap.h"

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

/**
  VGA - Curso GBA
  Ejemplo 6

  Muestra una escena construida con un tilemap en modo 0
  Colores indexados con 8bpp
  El background mide 64x32 tiles
*/
int main() {

  volatile uint16_t* src;
  volatile uint16_t* des;
  volatile uint16_t count;

  // Init palette
  src = (uint16_t*)mario_worldPal;
  des = (uint16_t*)&PALMEM[0];
  count = mario_worldPalLen;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init character block
  src = (uint16_t*)mario_worldTiles;
  des = (uint16_t*)&CHARBLOCK[0];
  count = mario_worldTilesLen;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init screen block
  src = (uint16_t*)tilemap;
  des = (uint16_t*)&SCREENBLOCK[8];
  count = 2*32*32;
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
    Size 64x32        => 0x4000
  */
  *BG0CNT = 0x4880;

  uint32_t FRAME = 0;
  uint16_t h_offset0 = 0;
  while (1) {

    while (*VCOUNT < 160) __asm__("nop");

    if (FRAME % 120 == 0) {
      *BG0HOFF = ++h_offset0;
    }

    FRAME++;
  }

  return 0;
}