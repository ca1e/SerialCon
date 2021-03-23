#
#             LUFA Library
#     Copyright (C) Dean Camera, 2021.
#
#  dean [at] fourwalledcubicle [dot] com
#           www.lufa-lib.org
#
# --------------------------------------
#         LUFA Project Makefile.
# --------------------------------------
#     Author cale, 2021.

# Run "make help" for target help.

REAL_BOARD   := Leonardo
#MCU          := atmega32u4
BOARD        := LEONARDO

#REAL_BOARD   := Beetle
#BOARD        := LEONARDO

#REAL_BOARD   := UNO
#MCU          := atmega16u2
#BOARD        := UNO

#REAL_BOARD   := Teensy2
#BOARD        := TEENSY2

#REAL_BOARD   := TEENSY2pp
#MCU          := at90usb1286
#BOARD        := TEENSY2

#ifeq($(CC),gcc)
#ifdef foo
 #frobozz=yes
#else
 #libs=$(normal_libs)
#endif

all:
include makefile.core.mk
