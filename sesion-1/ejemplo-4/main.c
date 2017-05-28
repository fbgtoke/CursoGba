#include "stdint.h"

/**
  VGA - Curso GBA
  Ejemplo 4

  Muestra 2 pixeles de distinto color en pantalla utilizando el modo 5
  Alterna de frame periodicamente
*/

#define SCREEN_WIDTH  160
#define SCREEN_HEIGHT 128

void page_flip() {
  *(uint16_t*)0x04000000 ^= (uint16_t) 0x0010;
}

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
    BG Mode 5          => 0000 0000 0000 0101 => 0x0005
    Screen Display BG2 => 0000 0100 0000 0000 => 0x0400
  */
  *DISPCNT = 0x0005 | 0x0400;

  /**
    BG Mode 5 - 160x128 pixels, 32768 colors
    
    Colors are defined as for Mode 3 (see above), but horizontal and vertical 
    size are cut down to 160x128 pixels only - smaller than the physical 
    dimensions of the LCD screen.
    The background occupies exactly 40 KBytes, so that BG VRAM may be split into 
    two frames (06000000-06009FFF for Frame 0, and 0600A000-06013FFF for 
    Frame 1).
  */
  uint16_t* VRAM_FRAME_0 = (uint16_t*)0x06000000;
  uint16_t* VRAM_FRAME_1 = (uint16_t*)0x0600A000;

  VRAM_FRAME_0[10 + 30 * SCREEN_WIDTH] = 0x001f;
  VRAM_FRAME_0[11 + 30 * SCREEN_WIDTH] = 0x001f;
  VRAM_FRAME_0[10 + 31 * SCREEN_WIDTH] = 0x001f;
  VRAM_FRAME_0[11 + 31 * SCREEN_WIDTH] = 0x001f;

  VRAM_FRAME_0[20 + 30 * SCREEN_WIDTH] = 0x03e0;
  VRAM_FRAME_0[21 + 30 * SCREEN_WIDTH] = 0x03e0;
  VRAM_FRAME_0[20 + 31 * SCREEN_WIDTH] = 0x03e0;
  VRAM_FRAME_0[21 + 31 * SCREEN_WIDTH] = 0x03e0;

  VRAM_FRAME_1[10 + 30 * SCREEN_WIDTH] = 0x03e0;
  VRAM_FRAME_1[11 + 30 * SCREEN_WIDTH] = 0x03e0;
  VRAM_FRAME_1[10 + 31 * SCREEN_WIDTH] = 0x03e0;
  VRAM_FRAME_1[11 + 31 * SCREEN_WIDTH] = 0x03e0;

  VRAM_FRAME_1[20 + 30 * SCREEN_WIDTH] = 0x001f;
  VRAM_FRAME_1[21 + 30 * SCREEN_WIDTH] = 0x001f;
  VRAM_FRAME_1[20 + 31 * SCREEN_WIDTH] = 0x001f;
  VRAM_FRAME_1[21 + 31 * SCREEN_WIDTH] = 0x001f;

  int FRAME = 0;
  while (1) {
    
    if (FRAME % 5000 == 0)
      page_flip();

    FRAME++;
  }

  return 0;
}