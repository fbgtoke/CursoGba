#include "stdint.h"

/**
  VGA - Curso GBA
  Ejemplo 3

  Muestra 2 pixeles de distinto color en pantalla utilizando el modo 4
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
  uint16_t* DISPCNT = (uint16_t*)0x04000000;

  /**
    BG Mode 4          => 0000 0000 0000 0100 => 0x0004
    Screen Display BG2 => 0000 0100 0000 0000 => 0x0400
  */
  *DISPCNT = 0x0004 | 0x0400;

  /**
    Color Definitions
    Each color occupies two bytes (same as for 32768 color BG modes):

    Bit   Expl.
    0-4   Red Intensity   (0-31)
    5-9   Green Intensity (0-31)
    10-14 Blue Intensity  (0-31)
    15    Not used

    Transparent Colors
    Color 0 of all BG and OBJ palettes is transparent. Even though palettes are 
    described as 16 (256) color palettes, only 15 (255) colors are actually 
    visible.

    Backdrop Color
    Color 0 of BG Palette 0 is used as backdrop color. This color is displayed 
    if an area of the screen is not covered by any non-transparent BG or OBJ 
    dots.
  */
  uint16_t* PALMEM = (uint16_t*)0x05000000;

  PALMEM[1] = 0x7fff; // White
  PALMEM[2] = 0x001f; // Red
  PALMEM[3] = 0x03e0; // Green
  PALMEM[4] = 0x7c00; // Blue

  /**
    BG Mode 4 - 240x160 pixels, 256 colors (out of 32768 colors)
    
    One byte is associated to each pixel, selecting one of the 256 palette 
    entries. Color 0 (backdrop) is transparent, and OBJs may be displayed behind 
    the bitmap.
    The first 240 bytes define the topmost line, the next 240 the next line, and 
    so on. The background occupies 37.5 KBytes, allowing two frames to be used 
    (06000000-060095FF for Frame 0, and 0600A000-060135FF for Frame 1).
  */
  uint16_t* VRAM = (uint16_t*)0x06000000;

  /**
    Remeber: must use 16bit writes for VRAM!
  */
  VRAM[10 + 30 * SCREEN_WIDTH] = 0x0201;
  VRAM[11 + 30 * SCREEN_WIDTH] = 0x0403;

  while (1);

  return 0;
}