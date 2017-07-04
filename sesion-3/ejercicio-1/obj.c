#include "obj.h"

void oam_init() {
  for (int i = 0; i < 128; ++i) {
    obj_buffer[i].attr0 = 0x0200;
    obj_buffer[i].attr1 = 0x0000;
    obj_buffer[i].attr2 = 0x0000;
  }

  oam_update();
}

void oam_update() {
	memcpy16((uint32_t)obj_buffer, (uint32_t)OAM, NUM_OBJ * 4);
}