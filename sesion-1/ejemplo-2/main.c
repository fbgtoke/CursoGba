#include "stdint.h"

/**
  VGA - Curso GBA
  Ejemplo 2

  Muestra 3 pixeles de distinto color en pantalla utilizando el modo 3
*/

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

int main() {

  /**
    4000000h - DISPCNT - LCD Control (Read/Write)

    Bit   Expl.
    0-2   BG Mode                    (0-5=Video Mode 0-5, 6-7=Prohibited)
    3     Reserved / CGB Mode        (0=GBA, 1=CGB; can be set only by BIOS)
    4     Display Frame Select       (0-1=Frame 0-1) (for BG Modes 4,5 only)
    5     H-Blank Interval Free      (1=Allow access to OAM during H-Blank)
    6     OBJ Character VRAM Mapping (0=Two dimensional, 1=One dimensional)
    7     Forced Blank               (1=Allow FAST access to VRAM,Palette,OAM)
    8     Screen Display BG0         (0=Off, 1=On)
    9     Screen Display BG1         (0=Off, 1=On)
    10    Screen Display BG2         (0=Off, 1=On)
    11    Screen Display BG3         (0=Off, 1=On)
    12    Screen Display OBJ         (0=Off, 1=On)
    13    Window 0 Display Flag      (0=Off, 1=On)
    14    Window 1 Display Flag      (0=Off, 1=On)
    15    OBJ Window Display Flag    (0=Off, 1=On)
  */
  volatile uint16_t* DISPCNT = (uint16_t*)0x04000000;

  /**
    BG Mode 3          => 0000 0000 0000 0011 => 0x0003
    Screen Display BG2 => 0000 0100 0000 0000 => 0x0400
  */
  *DISPCNT = 0x0003 | 0x0400;

  /**
    BG Mode 3  240x160 pixels, 32768 colors
    
    Two bytes are associated to each pixel, directly defining one of the 32768 
    colors (without using palette data, and thus not supporting a 'transparent' 
    BG color).

    Bit   Expl.
    0-4   Red Intensity   (0-31)
    5-9   Green Intensity (0-31)
    10-14 Blue Intensity  (0-31)
    15    Not used in GBA Mode (in NDS Mode: Alpha=0=Transparent, Alpha=1=Normal)
  */
  volatile uint16_t* VRAM = (uint16_t*)0x06000000;

  /**
  VRAM[xx + yy * SCREEN_WIDTH] = COLOR;
  */
  VRAM[10 + 30 * SCREEN_WIDTH] = 0x001f; // Red:   0000 0000 0001 1111
  VRAM[11 + 30 * SCREEN_WIDTH] = 0x03e0; // Green: 0000 0011 1110 0000
  VRAM[12 + 30 * SCREEN_WIDTH] = 0x7c00; // Blue:  0111 1100 0000 0000

  while (1);

  return 0;
}