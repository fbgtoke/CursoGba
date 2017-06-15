#include "tilemap.h"

const uint16_t tilemap[2][32*32] = {

{
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,02,03,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,18,19,18,19,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,02,03,00,00,00,00,02,03,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,18,19,00,00,00,00,18,19,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,02,03,00,00,00,00,00,00,00,00,02,03,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,18,19,00,00,00,00,00,00,00,00,18,19,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,02,03,00,00,00,00,00,00,00,00,00,00,00,00,02,03,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,18,19,00,00,00,00,00,00,00,00,00,00,00,00,18,19,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,02,03,00,00,00,00,00,00,
00,00,00,00,00,00,18,19,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,18,19,00,00,00,00,00,00,
00,00,00,00,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,02,03,00,00,00,00,
00,00,00,00,18,19,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,18,19,00,00,00,00,
00,00,02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,02,03,00,00,
00,00,18,19,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,18,19,00,00,
02,03,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,02,03,
18,19,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,18,19,
32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,
48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
},

{
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,38,39,38,39,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,54,55,54,55,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,38,39,00,00,00,00,38,39,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,54,55,00,00,00,00,54,55,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,38,39,00,00,00,00,00,00,00,00,38,39,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,54,55,00,00,00,00,00,00,00,00,54,55,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,38,39,00,00,00,00,00,00,00,00,00,00,00,00,38,39,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,54,55,00,00,00,00,00,00,00,00,00,00,00,00,54,55,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,38,39,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,38,39,00,00,00,00,00,00,
00,00,00,00,00,00,54,55,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,54,55,00,00,00,00,00,00,
00,00,00,00,38,39,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,38,39,00,00,00,00,
00,00,00,00,54,55,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,54,55,00,00,00,00,
00,00,38,39,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,38,39,00,00,
00,00,54,55,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,54,55,00,00,
38,39,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,38,39,
54,55,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,54,55,
32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,32,33,
48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,48,49,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,
00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00
}

};