#include "input.h"

uint16_t last_state    = 0;
uint16_t current_state = 0;

volatile uint16_t* KEYINPUT = (uint16_t*)0x04000130;

inline void key_poll() {
	last_state = current_state;
	current_state = ~(*KEYINPUT) & KEY_MASK;
}

// Basic funtions
inline uint32_t key_curr_state()         	{   return  current_state;       }
inline uint32_t key_prev_state()         	{   return  last_state;          }
inline uint32_t key_is_down(uint32_t key)   {   return  current_state & key; }
inline uint32_t key_is_up(uint32_t key)     {   return ~current_state & key; }
inline uint32_t key_was_down(uint32_t key)  {   return  last_state & key;    }
inline uint32_t key_was_up(uint32_t key)    {   return ~last_state & key;    }


// Key is changing state
inline uint32_t key_transit(uint32_t key) {   return ( current_state ^  last_state) & key;   }

// Key is held (down now and before)
inline uint32_t key_held(uint32_t key)
{   return ( current_state &  last_state) & key;  }

// Key is being hit (down now, but not before)
inline uint32_t key_hit(uint32_t key)
{   return ( current_state &~ last_state) & key;  }

// Key is being released (up now but down before)
inline uint32_t key_released(uint32_t key)
{   return (~current_state &  last_state) & key;  }

// Returns tribool output (-1, 0, or 1) from the bits "plus" and "minus" in "x"
inline int bit_tribool(uint32_t x, int plus, int minus)
{   return ((x>>plus)&1) - ((x>>minus)&1);  }

// --- TRISTATES ---
inline int key_tri_horz()       // right/left : +/-
{   return bit_tribool(current_state, KINDEX_RIGHT, KINDEX_LEFT);  }

inline int key_tri_vert()       // down/up : +/-
{   return bit_tribool(current_state, KINDEX_DOWN, KINDEX_UP);     }

inline int key_tri_shoulder()   // R/L : +/-
{   return bit_tribool(current_state, KINDEX_R, KINDEX_L);         }

inline int key_tri_fire()       // B/A : -/+
{   return bit_tribool(current_state, KINDEX_A, KINDEX_B);         }