#ifndef OBJ_H
#define OBJ_H

#include "mem.h"
#include "dma.h"

#define NUM_OBJ 128

struct OBJ_ATTR obj_buffer[128];

void oam_init();

void oam_update();

#endif