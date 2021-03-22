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

include ./boards/LEONARDO.mk
# include  ./boards/UNO.mk
# include ./boards/BEETLE.mk
# include ./boards/TEENSY2.mk
# include ./boards/Teensy2pp.mk


#ifeq($(CC),gcc)
#ifdef foo
 #frobozz=yes
#else
 #libs=$(normal_libs)
#endif

all:
include makefile.core.mk
