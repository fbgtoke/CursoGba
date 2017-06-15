#include "stdint.h"
#include "mem.h"
#include "dma.h"

#include "tilemap.h"

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

/**
  VGA - Curso GBA
  Ejercicio 1

  Cree un programa que haga uso del modo 0 para pintar una escena utilizando 4 
  backrounds de manera simultanea.
*/
int main() {

  /**
    Display Control

    BG Mode 0          => 0x0000
    Screen Display GB0 => 0x0100
    Screen Display GB1 => 0x0200
    Screen Display GB2 => 0x0400
    Screen Display GB3 => 0x0800
  */
  *DISPCNT = 0x0F00;

  while (1) {

    while (*VCOUNT < 160) __asm__("nop");
    
  }

  return 0;
}