#include "mem.h"

volatile uint16_t* DISPCNT = (uint16_t*)0x04000000;

volatile uint16_t* VCOUNT = (uint16_t*)0x04000006;

volatile uint16_t* BG0CNT = (uint16_t*)0x4000008;
volatile uint16_t* BG1CNT = (uint16_t*)0x400000A;
volatile uint16_t* BG2CNT = (uint16_t*)0x400000C;
volatile uint16_t* BG3CNT = (uint16_t*)0x400000E;

volatile uint16_t* BG0HOFF = (uint16_t*)0x04000010;
volatile uint16_t* BG0VOFF = (uint16_t*)0x04000012;

volatile uint16_t* BG1HOFF = (uint16_t*)0x04000014;
volatile uint16_t* BG1VOFF = (uint16_t*)0x04000016;

volatile uint16_t* BG2HOFF = (uint16_t*)0x04000018;
volatile uint16_t* BG2VOFF = (uint16_t*)0x0400001A;

volatile uint16_t* BG3HOFF = (uint16_t*)0x0400001C;
volatile uint16_t* BG3VOFF = (uint16_t*)0x0400001E;

volatile uint16_t* PALMEM = (uint16_t*)0x05000000;
volatile uint16_t* OBJPALMEM = (uint16_t*)0x05000200;


volatile uint16_t* VRAM = (uint16_t*)0x06000000;

volatile uint16_t (*CHARBLOCK)[8192] = (uint16_t(*)[8192])0x06000000;

volatile uint16_t (*SCREENBLOCK)[32][32] = (uint16_t(*)[32][32])0x06000000;

volatile struct OBJ_ATTR (*OAM)[128] = (struct OBJ_ATTR(*)[128])0x07000000;