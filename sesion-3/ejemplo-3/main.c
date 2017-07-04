#include "stdint.h"
#include "mem.h"
#include "dma.h"
#include "obj.h"
#include "quote2d.h"

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

/**
  VGA - Curso GBA
  Ejemplo 3

  Muestra un Sprite de 16x16 pixeles desplazándose por la pantalla
  Utiliza el modo 4bpp
  Utiliza la distribución 2D
*/

int main() {
  /**
    Display Control

    BG Mode 0                => 0x0000
    1D OBJ Character Mapping => 0x0000
    Display OBJ              => 0x1000
  */
  *DISPCNT = 0x1000;

  uint16_t* src;
  uint16_t* des;
  uint16_t count;

  // Init oam
  oam_init();

  // Init palette
  src = (uint16_t*)quote2dPal;
  des = (uint16_t*)&OBJPALMEM[0];
  count = quote2dPalLen / 2;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init sprite
  src = (uint16_t*)quote2dTiles;
  des = (uint16_t*)&CHARBLOCK[4];
  count = quote2dTilesLen / 2;
  memcpy16((uint32_t)src, (uint32_t)des, count);

  // Init oam
  /**
    Attr0
    Y = 80             => 0x0050
    Object mode normal => 0x0000
    No graphic effects => 0x0000
    No mosaic effect   => 0x0000
    4bpp color mode    => 0x0000
    Square shape       => 0x0000
  */
  obj_buffer[0].attr0 = 0x0050;
  /**
    Attr1
    X = 120            => 0x0078
    No horizontal flip => 0x0000
    No vertical flip   => 0x0000
    16x16 pixels       => 0x4000
  */
  obj_buffer[0].attr1 = 0x4078;
  /**
    Attr2
    Tile index 0       => 0x0000
    Priority 0         => 0x0000
    Pallete bank 0     => 0x0000
  */
  obj_buffer[0].attr2 = 0x0000;

  uint16_t posy = 0;
  uint16_t posx = 0;

  uint32_t FRAME = 0;

  while (1) {

    while (*VCOUNT > 160) __asm__("nop");
    while (*VCOUNT < 160) __asm__("nop");

    if (FRAME % 5 == 0)
      posx++;

    if (FRAME % 15 == 0)
      posy++;

    obj_buffer[0].attr0 = 0x0000 | (posy & 0x00ff);
    obj_buffer[0].attr1 = 0x4000 | (posx & 0x01ff);

    // Update oam
    oam_update();
    
    FRAME++;
  }

  return 0;
}