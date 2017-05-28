#include "stdint.h"

/**
  VGA - Curso GBA
  Ejercicio 2

  Disene una funcion que dibuje una caja rectangular dados los vertices y un color
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

void m4_draw_rect(int l, int t, int r, int b, uint16_t color) {
  // TODO
}

int main() {

  *DISPCNT = MODE4 | BG02;

  PALMEM[1] = WHITE;
  PALMEM[2] = RED;
  PALMEM[3] = GREEN;
  PALMEM[4] = BLUE;

  m4_draw_rect(0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, RED);
  m4_draw_rect(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2, GREEN);
  m4_draw_rect(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT, BLUE);

  while (1);

  return 0;
}