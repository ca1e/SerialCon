# Include LUFA build script makefiles

LUFA_PATH    = ./lufa/LUFA
include $(LUFA_PATH)/Build/lufa_core.mk

$(call ERROR_IF_EMPTY, REAL_BOARD)
$(call ERROR_IF_EMPTY, MEM_SIZE)
$(call ERROR_IF_EMPTY, LEDMASK_TX)
$(call ERROR_IF_EMPTY, LEDMASK_RX)

SETTINGS	+= -DLEDMASK_TX=$(LEDMASK_TX)
SETTINGS	+= -DLEDMASK_RX=$(LEDMASK_RX)
SETTINGS	+= -DMEM_SIZE=$(MEM_SIZE)

MCU          ?= atmega32u4
ARCH         := AVR8
BOARD        := LEONARDO
F_CPU        := 16000000
F_USB        := $(F_CPU)
OPTIMIZATION := s
TARGET       := ./$(REAL_BOARD)/$(REAL_BOARD)
SRC          += Joystick.c LUFADescriptors.c
SRC		 	 += HID.c System.c Common.c
SRC		 	 += EasyCon.c
SRC			 += $(LUFA_SRC_USB)
CC_FLAGS     := -DUSE_LUFA_CONFIG_HEADER -IConfig $(SETTINGS)
LD_FLAGS     :=

# Default target
default: all

mkdir:
	@mkdir -p ./$(REAL_BOARD)

all:mkdir

include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
# include $(LUFA_PATH)/Build/lufa_doxygen.mk
# include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
# include $(LUFA_PATH)/Build/lufa_avrdude.mk
# include $(LUFA_PATH)/Build/lufa_atprogram.mk

.PHONY:mkdir
.PHONY:all