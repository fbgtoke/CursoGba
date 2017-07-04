#ifndef INPUT_H
#define INPUT_H

#include "stdint.h"

#define KEY_A        0x0001
#define KEY_B        0x0002
#define KEY_SELECT   0x0004
#define KEY_START    0x0008
#define KEY_RIGHT    0x0010
#define KEY_LEFT     0x0020
#define KEY_UP       0x0040
#define KEY_DOWN     0x0080
#define KEY_R        0x0100
#define KEY_L        0x0200

#define KEY_MASK     0x03FF

#define KINDEX_A        0x0000
#define KINDEX_B        0x0001
#define KINDEX_SELECT   0x0002
#define KINDEX_START    0x0003
#define KINDEX_RIGHT    0x0004
#define KINDEX_LEFT     0x0005
#define KINDEX_UP       0x0006
#define KINDEX_DOWN     0x0007
#define KINDEX_R        0x0008
#define KINDEX_L        0x0009

extern volatile uint16_t* KEYINPUT;

void key_poll();

uint32_t key_curr_state();
uint32_t key_prev_state();
uint32_t key_is_down(uint32_t key);
uint32_t key_is_up(uint32_t key);
uint32_t key_was_down(uint32_t key);
uint32_t key_was_up(uint32_t key);

uint32_t key_transit(uint32_t key);
uint32_t key_held(uint32_t key);
uint32_t key_hit(uint32_t key);
uint32_t key_released(uint32_t key);

int bit_tribool(uint32_t x, int plus, int minus);

int key_tri_horz();
int key_tri_vert();
int key_tri_shoulder();
int key_tri_fire();

#endif