#include QMK_KEYBOARD_H
#include "split_util.h"
#include "raw_hid.h"


enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
    _HUM
};

enum hum_codes {
  C0_UP = SAFE_RANGE,
  C0_DOWN,
  C0_MUTE,
  C1_UP, 
  C1_DOWN,
  C1_MUTE,
  C2_UP, 
  C2_DOWN,
  C2_MUTE,
  C3_UP, 
  C3_DOWN,
  C3_MUTE,
  C4_UP, 
  C4_DOWN,
  C4_MUTE,
  C5_UP, 
  C5_DOWN,
  C5_MUTE,

  HUM_START = C0_UP,
  HUM_END = C5_MUTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   [  |   ]  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl | GUI  | Alt  |      |Lower |Lower |Space |Space |Raise |Raise |Left  | Down |  Up  |Right |
   * `------------------------------------------------+------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                         KC_6,      KC_7,       KC_8,    KC_9,    KC_0,    KC_DEL, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,                         KC_Y,      KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC, \
      KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,                         KC_H,      KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,      KC_LBRC,  KC_RBRC, KC_N,      KC_M,       KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT), \
      KC_LCTL, KC_LGUI, KC_LALT, MO(_HUM),MO(_LOWER),MO(_LOWER),KC_SPC,   KC_SPC,  MO(_RAISE),MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |   (  |   )  |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |   _  |   +  |   {  |   }  |  |   |
   * +------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  (   |   )  |      |      | PSCR | Home | End  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,    KC_PERC,                      KC_CIRC,   KC_AMPR,    KC_ASTR, KC_LPRN, KC_RPRN, _______, \
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,    KC_PERC,                      KC_CIRC,   KC_AMPR,    KC_ASTR, KC_LPRN, KC_RPRN, _______, \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,                        _______,   KC_UNDS,    KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
      KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,    KC_LPRN,  KC_RPRN, _______,   _______,    KC_PSCR, KC_HOME, KC_END,  KC_ENT, \
      _______, _______, _______, MO(_HUM),MO(_LOWER),MO(_LOWER),_______,  _______, MO(_RAISE),MO(_RAISE), _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |      |   -  |   =  |   [  |   ]  |  \   |
   * +------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      | PSCR |Pg Up |Pg Dn | Play |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | Prev | Vol- | Vol+ | Next |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                        KC_6,      KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC, \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,                        KC_6,      KC_7,       KC_8,    KC_9,    KC_0,    KC_DEL, \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,                       _______,   KC_MINS,    KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12,    _______, _______, _______,   _______,    KC_PSCR, KC_PGUP, KC_PGDN, KC_MPLY, \
      _______, _______, _______, MO(_HUM),MO(_LOWER),MO(_LOWER),_______, _______, MO(_RAISE),MO(_RAISE), KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT \
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|      |      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6,                       KC_F7,    KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12, \
      _______, QK_BOOT, _______, _______, _______,   _______,                     _______,  _______,    _______, _______, _______, KC_DEL, \
      _______, _______, _______, _______, _______,   _______,                     _______,  _______,    _______, _______, _______, _______, \
      _______, _______, _______, _______, _______,   _______,   _______, _______, _______,  _______,    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      _______, _______, _______, MO(_HUM),MO(_LOWER),MO(_LOWER),_______, _______, MO(_RAISE),MO(_RAISE),RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
      ),

  [_HUM] =  LAYOUT( \
      _______, _______, _______, _______, _______,   _______,                      _______,   _______,   _______, _______, _______, _______, \
      _______, _______, _______, _______, _______,   _______,                      C0_UP,     C1_UP,     C2_UP,   C3_UP,   C4_UP,   C5_UP,  \
      _______, _______, _______, _______, _______,   _______,                      C0_DOWN,   C1_DOWN,   C2_DOWN, C3_DOWN, C4_DOWN, C5_DOWN,\
      _______, _______, _______, _______, _______,   _______,   _______,  _______, C0_MUTE,   C1_MUTE,   C2_MUTE, C3_MUTE, C4_MUTE, C5_MUTE, \
      _______, _______, _______, MO(_HUM),MO(_LOWER),MO(_LOWER),_______,  _______, MO(_RAISE),MO(_RAISE),_______, _______, _______, _______ \
      )
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

void hum_send_info(void) {
    uint8_t send_data[32] = {0};

    // INFO
    send_data[0] = 0x01;
    // Absolute Channels
    send_data[1] = 0x00;
    // Relative Channels
    send_data[1] = (HUM_END - HUM_START) / 2;

    raw_hid_send(send_data, sizeof(send_data));
}

void hum_state(void) {
    uint8_t send_data[32] = {0};

    send_data[0] = 0x02;

    raw_hid_send(send_data, sizeof(send_data));
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    switch (data[0]) {
        case 0x01:
            hum_send_info();
            break;
        case 0x02:
            hum_state();
            break;
        default:
            break;
    }

    return;
}

void process_record_hum(uint16_t keycode) {
    uint8_t chan          = (keycode - HUM_START) / 3;
    uint8_t state         = ((keycode - HUM_START) % 3);
    uint8_t send_data[32] = {0};

    send_data[0] = 0x11;
    send_data[1] = chan;
    send_data[2] = state == 2 ? 0xFF : !state;

    raw_hid_send(send_data, sizeof(send_data));
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= HUM_START && keycode <= HUM_END) {
        if (record->event.pressed) process_record_hum(keycode);
        return false;
    }
    return true;
}