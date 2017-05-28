#include "stdint.h"
#include "cave_story_credits.h"

/**
  VGA - Curso GBA
  Ejemplo 5

  Define un mapa de bits como una matriz y la copia sobre la VRAM (modo 3)
*/

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

int main() {

  uint16_t* DISPCNT = (uint16_t*)0x04000000;
  *DISPCNT = 0x0003 | 0x0400;

  uint16_t* VRAM = (uint16_t*)0x06000000;

  int i;
  for (i = 0; i < cave_story_creditsBitmapLen / 2; ++i)
    VRAM[i] = cave_story_creditsBitmap[i];

  while (1);

  return 0;
}