#
#             LUFA Library
#     Copyright (C) Dean Camera, 2014.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------

SHELL = /bin/sh

# Run "make help" for target help.
REAL_BOARD   = Leonardo
MEM_SIZE     = 924
LEDMASK_TX   = LEDS_LED2
LEDMASK_RX   = LEDS_LED1

SETTINGS	+= -DLEDMASK_TX=$(LEDMASK_TX)
SETTINGS	+= -DLEDMASK_RX=$(LEDMASK_RX) 

$(shell mkdir ./$(REAL_BOARD))

# Set the MCU accordingly to your device
# there must be a define of BOARD in LUFA
MCU          = atmega32u4
ARCH         = AVR8
BOARD        = LEONARDO
F_CPU        = 16000000
F_USB        = $(F_CPU)
OPTIMIZATION = s
TARGET       = ./$(REAL_BOARD)/$(REAL_BOARD)
SRC         += Joystick.c LUFADescriptors.c
SRC			+= HID.c System.c
SRC			+= $(LUFA_SRC_USB)
LUFA_PATH    = ./lufa/LUFA
CC_FLAGS     = -DUSE_LUFA_CONFIG_HEADER -DMEM_SIZE=$(MEM_SIZE) -IConfig $(SETTINGS)
LD_FLAGS     =

# Default target
all:

# Include LUFA build script makefiles
include $(LUFA_PATH)/Build/lufa_core.mk
include $(LUFA_PATH)/Build/lufa_sources.mk
include $(LUFA_PATH)/Build/lufa_build.mk
include $(LUFA_PATH)/Build/lufa_cppcheck.mk
include $(LUFA_PATH)/Build/lufa_doxygen.mk
include $(LUFA_PATH)/Build/lufa_dfu.mk
include $(LUFA_PATH)/Build/lufa_hid.mk
include $(LUFA_PATH)/Build/lufa_avrdude.mk
include $(LUFA_PATH)/Build/lufa_atprogram.mk

# Target for LED/buzzer to alert when print is done
with-alert: all
with-alert: CC_FLAGS += -DALERT_WHEN_DONE