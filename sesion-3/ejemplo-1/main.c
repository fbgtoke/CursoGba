#include "stdint.h"
#include "mem.h"
#include "dma.h"
#include "quote1d.h"

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

/**
  VGA - Curso GBA
  Ejemplo 1

  
*/

struct OBJ_ATTR obj_buffer[128];

int main() {

  volatile uint16_t* src;
  volatile uint16_t* des;
  volatile uint16_t count;

  // Init palette
  src = (uint16_t*)quote1dPal;
  des = (uint16_t*)&OBJPALMEM[0];
  count = quote1dPalLen;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init sprite
  src = (uint16_t*)quote1dTiles;
  des = (uint16_t*)&CHARBLOCK[4];
  count = quote1dTilesLen;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init oam
  /**
    Attr0
    Y = 0              => 0x0000
    Object mode normal => 0x0000
    No graphic effects => 0x0000
    No mosaic effect   => 0x0000
    4bpp color mode    => 0x0000
    Square shape       => 0x0000
  */
  obj_buffer[0].attr0 = 0x0000;
  /**
    Attr1
    X = 0              => 0x0000
    No horizontal flip => 0x0000
    No vertical flip   => 0x0000
    16x16 pixels       => 0x4000
  */
  obj_buffer[0].attr1 = 0x4000;
  /**
    Attr2
    Tile index 0       => 0x0000
    Priority 0         => 0x0000
    Pallete bank 0     => 0x0000
  */
  obj_buffer[0].attr2 = 0x0000;


  /**
    Display Control

    BG Mode 0                => 0x0000
    1D OBJ Character Mapping => 0x0040
    Display OBJ              => 0x7000
  */
  *DISPCNT = 0x7040;

  while (1) {

    while (*VCOUNT < 160) __asm__("nop");

    // Update oam
    src = (uint16_t*)obj_buffer;
    des = (uint16_t*)&OAM[0];
    count = 4;
    memcpy16((uint32_t)src, (uint32_t)des, count);
    
  }

  return 0;
}