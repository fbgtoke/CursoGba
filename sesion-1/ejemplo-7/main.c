#include "stdint.h"
#include "cave_story_video.h"

/**
  VGA - Curso GBA
  Ejemplo 7

  Muestra un cortrometraje utilizando mapas de bits en modo 3
*/

uint16_t* DISPCNT = (uint16_t*)0x04000000;
uint16_t* VRAM = (uint16_t*)0x06000000;

uint32_t* DMA3SAD = (uint32_t*)0x040000d4;
uint32_t* DMA3DAD = (uint32_t*)0x040000d8;
uint16_t* DMA3CNT_L = (uint16_t*)0x040000dc;
uint16_t* DMA3CNT_H = (uint16_t*)0x040000de;

volatile uint16_t* VCOUNT = (uint16_t*)0x04000006;

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

inline void memcpy16(uint32_t src, uint32_t des, uint16_t count) {
  *DMA3SAD = src;
  *DMA3DAD = des;
  *DMA3CNT_L = count;
  *DMA3CNT_H = 0x8000;

  __asm__("nop");
  __asm__("nop");
}

int main() {

  *DISPCNT = 0x0003 | 0x0400;

  const uint16_t* src = cave_story_videoBitmap;
  uint16_t* des = VRAM;

  int FRAME = 0;

  while (1) {
  	while(*VCOUNT < 160) __asm__("nop");

  	if (!(FRAME % 16)) {
	  	memcpy16((uint32_t)src, (uint32_t)des, SCREEN_WIDTH * SCREEN_HEIGHT);

	  	src += SCREEN_WIDTH * SCREEN_HEIGHT;
	  }

  	FRAME++;
  }

  return 0;
}