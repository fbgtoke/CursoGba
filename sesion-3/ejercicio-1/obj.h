#ifndef OBJ_H
#define OBJ_H

#include "mem.h"
#include "dma.h"

#define NUM_OBJ 128

struct OBJ_ATTR obj_buffer[128];

void oam_init();

void oam_update();

/**
  OBJ_ATTR constants and operations
*/
#define OBJ_NORMAL 0x0000
#define OBJ_HIDDEN 0x0200
#define OBJ_4BPP 0x0000
#define OBJ_8BPP 0x2000

#define OBJ_SQUARE 0x0000
#define OBJ_TALL 0x4000
#define OBJ_LONG 0x8000

#define OBJ_HFLIP 0x1000
#define OBJ_VFLIP 0x2000

#define OBJ_S 0x0000
#define OBJ_M 0x4000
#define OBJ_L 0x8000
#define OBJ_XL 0xC000


#define ATTR0_SET_Y(attr0, y) ((attr0 & 0xff00) | (y & 0x00ff))
#define ATTR0_SET_OBJ_MODE(attr0, obj_mode) (/**/)
#define ATTR0_SET_COLOR_MODE(attr0, color_mode) (/**/)
#define ATTR0_SET_SHAPE(attr0, shape) (/**/)
#define ATTR0_SET(attr0, y, obj_mode, color_mode, shape) (/**/)


#define ATTR1_SET_X(attr1, x) ((attr1 & 0xfe00) | (x & 0x01ff))
#define ATTR1_SET_HFLIP(attr1, hflip) (/**/)
#define ATTR1_SET_VFLIP(attr1, vflip) (/**/)
#define ATTR1_SET_SIZE(attr1, size) (/**/)
#define ATTR1_SET(attr1, x, hflip, vflip, size) (/**/)

#endif