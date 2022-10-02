# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

RGB_MATRIX_DRIVER = WS2812

COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
SEND_STRING_ENABLE = yes

EXTRAFLAGS += -flto
