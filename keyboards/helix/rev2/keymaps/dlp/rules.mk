LTO_ENABLE = yes

SPLIT_KEYBOARD = yes

HELIX_ROWS = 5              # Helix Rows is 4 or 5
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
LED_BACK_ENABLE = yes

OLED_DRIVER_ENABLE = yes
OLED_TIMEOUT = 20000

EXTRAKEY_ENABLE = yes
WPM_ENABLE = yes
RGBLIGHT_ENABLE = yes

include $(strip $(KEYBOARD_LOCAL_FEATURES_MK))
