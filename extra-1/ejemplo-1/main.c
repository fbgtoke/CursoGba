/**
  VGA - Curso GBA
  Ejemplo 1

  Este programa muestra la implementacion y uso de un sistema 
  de input sincrono para la Game Boy Advance
*/

#include "stdint.h"
#include "input.h"

// Ver "input.c" y "input.h" para el sistema de input

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

int main() {

  // Inicialicacion (ver sesion-1)  
  uint16_t* DISPCNT = (uint16_t*)0x04000000;
  *DISPCNT = 0x0003 | 0x0400;

  volatile uint16_t* VCOUNT = (uint16_t*)0x04000006;
  volatile uint16_t* VRAM = (uint16_t*)0x06000000;

  int x = SCREEN_WIDTH/2, y = SCREEN_HEIGHT/2;

  while (1) {
    while(*VCOUNT < 160) __asm__("nop");

    // Actualizar el estado del input
    key_poll();

    // Dibujar el rastro del punto
    VRAM[x+ y * SCREEN_WIDTH] = 0x001f; 

    // Actualizar posicion del punto
    if (key_hit(KEY_LEFT)) --x;
    else if (key_hit(KEY_RIGHT)) ++x;

    if (key_hit(KEY_UP)) --y;
    else if (key_hit(KEY_DOWN)) ++y;

    x = (x+SCREEN_WIDTH) % SCREEN_WIDTH;
    y = (y+SCREEN_WIDTH) % SCREEN_WIDTH;

    // Dibujar punto verde
    VRAM[x+ y * SCREEN_WIDTH] = 0x0FE0; 
  }

  return 0;
}