REAL_BOARD   := Leonardo
MEM_SIZE     := 924
LEDMASK_TX   := LEDS_LED2
LEDMASK_RX   := LEDS_LED1

MCU          := atmega32u4
BOARD        := LEONARDO

MAKE_PATH    = ./mk
include $(MAKE_PATH)/core.mk

.PHONY:leonardo
leonardo:core