#
# Makefile for gba projects
#

PATH := $(DEVKITARM)/bin:$(PATH)

# --- Project details ---
PROJ    := main
EXT     := gba

CFILES  := main.c input.c

SOBJS   := $(SFILES:.s=.o)
COBJS   := $(CFILES:.c=.o)
OBJS    := $(SOBJS) $(COBJS)

#--- Tool settings ---
CROSS   := arm-none-eabi-
AS      := $(CROSS)as
CC      := $(CROSS)gcc
LD      := $(CROSS)gcc
OBJCOPY := $(CROSS)objcopy


MODEL   := -mthumb-interwork -mthumb
SPECS   := -specs=gba.specs

ASFLAGS := -mthumb-interwork
CFLAGS  := -I./ -I$(UDIR) $(MODEL) -O2 -Wall
LDFLAGS := $(SPECS) $(MODEL)

#--- Build steps ---
build : $(PROJ).$(EXT)

$(PROJ).$(EXT) : $(PROJ).elf
	@$(OBJCOPY) -v -O binary $< $@
	-@gbafix $@

$(PROJ).elf : $(OBJS)
	@$(LD) $^ $(LDFLAGS) -o $@

$(SOBJS) : %.o : %.s
	$(AS) $(ASFLAGS) $< -o $@


# --- Clean ---
.PHONY : clean
clean : 
	@rm -fv $(COBJS) $(SOBJS)
	@rm -fv $(PROJ).$(EXT) 
	@rm -fv $(PROJ).elf	
	@rm -fv $(PROJ).sav
