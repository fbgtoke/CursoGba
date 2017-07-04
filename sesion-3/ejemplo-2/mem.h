#ifndef MEM_H
#define MEM_H

#include "stdint.h"

/**
  4000000h - DISPCNT - LCD Control (Read/Write)

  Bit   Expl.
  0-2   BG Mode                    (0-5=Video Mode 0-5, 6-7=Prohibited)
  3     Reserved / CGB Mode        (0=GBA, 1=CGB; can be set only by BIOS)
  4     Display Frame Select       (0-1=Frame 0-1) (for BG Modes 4,5 only)
  5     H-Blank Interval Free      (1=Allow access to OAM during H-Blank)
  6     OBJ Character VRAM Mapping (0=Two dimensional, 1=One dimensional)
  7     Forced Blank               (1=Allow FAST access to VRAM,Palette,OAM)
  8     Screen Display BG0         (0=Off, 1=On)
  9     Screen Display BG1         (0=Off, 1=On)
  10    Screen Display BG2         (0=Off, 1=On)
  11    Screen Display BG3         (0=Off, 1=On)
  12    Screen Display OBJ         (0=Off, 1=On)
  13    Window 0 Display Flag      (0=Off, 1=On)
  14    Window 1 Display Flag      (0=Off, 1=On)
  15    OBJ Window Display Flag    (0=Off, 1=On)
*/
extern volatile uint16_t* DISPCNT;

extern volatile uint16_t* VCOUNT;

/**
	40000008h - BGXCNT - BackgroundX Control

	Bit   Expl.
	0-1   Priority                   (0=Draw above everything else, then 1, 
	                                  then 2, then 3)
	2-3   Character block
	4-5   Unused
	6     Mosaic                     (0=Off, 1=On)
	7     Color mode                 (0=4bpp, 1=8bpp)
	8-12  Screen block
	13    Wrap                       (0=Off, 1=On)
	14-15 Size                       (Regular:
	                                    0=32x32, 1=64x32, 2=32x64, 3=64x64
	                                  Affine:
	                                    0=16x16, 1=32x32, 2=64x64, 3=128x128)

	4bit depth (16 colors, 16 palettes)
	Each tile occupies 32 bytes of memory, the first 4 bytes for the topmost row of the tile, and so on. Each byte representing two dots, the lower 4 bits define the color for the left (!) dot, the upper 4 bits the color for the right dot.

	8bit depth (256 colors, 1 palette)
	Each tile occupies 64 bytes of memory, the first 8 bytes for the topmost row of the tile, and so on. Each byte selects the palette entry for each dot.
*/
extern volatile uint16_t* BG0CNT;
extern volatile uint16_t* BG1CNT;
extern volatile uint16_t* BG2CNT;
extern volatile uint16_t* BG3CNT;

extern volatile uint16_t* BG0HOFF;
extern volatile uint16_t* BG0VOFF;

extern volatile uint16_t* BG1HOFF;
extern volatile uint16_t* BG1VOFF;

extern volatile uint16_t* BG2HOFF;
extern volatile uint16_t* BG2VOFF;

extern volatile uint16_t* BG3HOFF;
extern volatile uint16_t* BG3VOFF;

/**
	Color Definitions
  Each color occupies two bytes

  Bit   Expl.
  0-4   Red Intensity   (0-31)
  5-9   Green Intensity (0-31)
  10-14 Blue Intensity  (0-31)
  15    Not used

  Transparent Colors
  Color 0 of all BG and OBJ palettes is transparent. Even though palettes are 
  described as 16 (256) color palettes, only 15 (255) colors are actually 
  visible.

  Backdrop Color
  Color 0 of BG Palette 0 is used as backdrop color. This color is displayed 
  if an area of the screen is not covered by any non-transparent BG or OBJ 
  dots.
*/
extern volatile uint16_t* PALMEM;
extern volatile uint16_t* OBJPALMEM;


extern volatile uint16_t* VRAM;


/**
  Character Block (4bpp)

	  Each character (tile) consists of 8x8 dots (64 dots in total)
	  Each dot has 4 bit color depth (2 dots per 1 byte)

	  64 Dots * 1/2 Bytes/Dot = 32 Bytes/Character
	  512 Characters * 32 Bytes/Character = 16384 Bytes (32KB)
	  32 KB/ScreenBlock => 512 Characters/ScreenBlock

	  CHARBLOCK[x][y] cointains 4 dots


  Character Block (8bpp)

	  Each character (tile) consists of 8x8 dots (64 dots in total)
	  Each dot has 8 bit color depth (1 byte per dot)

	  64 Dots * 1 Bytes/Dot = 64 Bytes/Character
	  256 Characters * 64 Bytes/Character = 16384 Bytes (32KB)

	  32 KB/ScreenBlock => 256 Characters/ScreenBlock

	  CHARBLOCK[x][y] contains 2 dots
*/
extern volatile uint16_t (*CHARBLOCK)[8192];

/**
	Screen Block

		Each screen consists of 32x32 tiles

		SCREENBLOCK[i][y][x] contains one tile entry

	Bit   Expl.
	0-9   Tile ID
	10    Horizontal flip            (0=Off, 1=On)
	11    Verticla flip              (0=Off, 1=On)
	12-15 Pallete Bank               (Only for 4bpp)
*/
extern volatile uint16_t (*SCREENBLOCK)[32][32];

/**
	Object Attribute control

	Attr0
	Bit   Expl.
	0-7   Y coordinate               (top of the sprite)
	8-9   Object mode                (00=Normal, 01=Affine, 10=Hidden,
	                                  11=Affine with double rendering)
	10-11 Flags for graphic effects  (00=Normal, 01=Alpha blending, 
	                                  10=Object part of window, 11=Forbidden)
	12    Mosaic effect              (0=Off, 1=On)
	13    Color mode                 (0=4bpp, 1=8bpp)
	14-15 Sprite shape               (See table below)

	Attr1
	Bit   Expl.
	0-8   X coordinate               (left of the sprite)
	9-13  Affine index               (Only for affine sprites)
	12    Horizontal flip            (0=Off, 1=On  Only for regular sprites)
	13    Vertical flip              (0=Off, 1=On  Only for regular sprites)
	14-15 Sprite size                (See table below)

	Attr2
	Bit   Expl.
	0-9   Tile index of the sprite
	10-11 Priority
	12-15 Pallete bank               (Only for 4bpp)

	Table: Sprite pixel size based on shape and size attributes
	##################################################
	# shape\size #   00   #   01   #   10   #   11   #
	##################################################
	#     00     #  8x8   # 16x16  # 32x32  # 64x64  #
	##################################################
	#     01     # 16x8   #  32x8  # 32x16  # 64x32  #
	##################################################
	#     10     # 8x16   #  8x32  # 16x32  # 32x64  #
	##################################################
*/
struct OBJ_ATTR {
	uint16_t attr0;
	uint16_t attr1;
	uint16_t attr2;
	uint16_t fill;
};

extern volatile struct OBJ_ATTR (*OAM)[128];

#endif