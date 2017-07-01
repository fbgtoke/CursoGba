#include "stdint.h"
#include "mem.h"
#include "dma.h"

#include "tilemap.h"

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

/**
  VGA - Curso GBA
  Ejercicio 3

  Construya un mapa de un tamano mayor a 64x64 tiles y disene un programa que 
  desplace la ventana de vision por el mismo.
*/
int main() {

  /**
    Display Control

    BG Mode 0          => 0x0000
    Screen Display GB0 => 0x0100
  */
  *DISPCNT = 0x0100;

  while (1) {

    while (*VCOUNT < 160) __asm__("nop");
    
  }

  return 0;
}