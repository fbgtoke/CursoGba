#include "stdint.h"

/**
  VGA - Curso GBA
  Ejercicio 3

  Revise la descripcion del registro DISPCNT para encontrar la configuracion del 
  page-flipping. Posteriormente, escriba un programa que utilice esta 
  funcionalidad alternando entre las dos ventanas de manera periodica.
*/

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

#define DISPCNT (uint16_t*)(0x04000000)
#define PALMEM ((uint16_t*)0x05000000)
#define VRAM ((uint16_t*)0x06000000)

#define MODE4 0x0004
#define BG02  0x0400

#define WHITE 0x7fff
#define RED   0x001f
#define GREEN 0x03e0
#define BLUE  0x7c00

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
  *DISPCNT = MODE4 | BG02;

  PALMEM[1] = WHITE;
  PALMEM[2] = RED;
  PALMEM[3] = GREEN;
  PALMEM[4] = BLUE;

  while (1);

  return 0;
}