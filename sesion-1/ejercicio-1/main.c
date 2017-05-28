#include "stdint.h"

/**
  VGA - Curso GBA
  Ejercicio 1

  Disene una funcion que dibuje una caja rectangular dados los vertices y un color
*/

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

#define DISPCNT (uint16_t*)(0x04000000)
#define VRAM ((uint16_t*)0x06000000)

#define MODE3 0x0003
#define BG02  0x0400

#define RED   0x001f
#define GREEN 0x03e0
#define BLUE  0x7c00

void m3_draw_rect(int l, int t, int r, int b, uint16_t color) {
  // TODO
}

int main() {

  *DISPCNT = MODE3 | BG02;

  m3_draw_rect(0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, RED);
  m3_draw_rect(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2, GREEN);
  m3_draw_rect(0, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT, BLUE);

  while (1);

  return 0;
}