#include QMK_KEYBOARD_H

enum layer_number {
    _QW = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// Layers 
// https://docs.qmk.fm/features/tri_layer
#define LOWER    TL_LOWR
#define RAISE    TL_UPPR
// https://docs.qmk.fm/feature_layers#switching-and-toggling-layers
#define SPC_LWR  LT(_LOWER, KC_SPC)
#define SPC_RSE  LT(_RAISE, KC_SPC)

// Shift enter
#define SFT_ENT  RSFT_T(KC_ENT)

// Home row mods
#define MY_A     MT(MOD_LGUI, KC_A)
#define MY_S     MT(MOD_LALT, KC_S)
#define MY_D     MT(MOD_LCTL, KC_D)
#define MY_F     MT(MOD_LSFT, KC_F)

#define MY_J     MT(MOD_RSFT, KC_J)
#define MY_K     MT(MOD_RCTL, KC_K)
#define MY_L     MT(MOD_LALT, KC_L)
#define MY_SCLN  MT(MOD_RGUI, KC_SCLN)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//  	_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	[_QW] = LAYOUT_ortho_5x15(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, 
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______, _______, _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, 
		KC_ESC,  MY_A,    MY_S,    MY_D,    MY_F,    KC_G,    _______, _______, _______, KC_H,    MY_J,    MY_K,    MY_L,    MY_SCLN, KC_QUOT, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, _______, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT, 
		KC_LCTL, KC_LGUI, KC_LALT, _______, KC_BSPC, LOWER,   SPC_LWR, KC_SPC,  SPC_RSE, RAISE,   KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
	),
	[_LOWER] = LAYOUT_ortho_5x15(
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
		KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
		KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LPRN, _______, KC_RPRN, _______, _______, KC_PSCR, KC_HOME, KC_END,  KC_ENT, 
		_______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______
	),
	[_RAISE] = LAYOUT_ortho_5x15(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
		KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, KC_PSCR, KC_PGUP, KC_PGDN, KC_MPLY,
		_______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, KC_DEL,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
	),
	[_ADJUST] = LAYOUT_ortho_5x15(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,     KC_F6, _______, _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
		_______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, 
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD
	)
};

