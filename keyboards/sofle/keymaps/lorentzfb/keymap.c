// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include "keycodes.h"
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAKDH,
    _SYM,
    _BUTTON,
    _NUM,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_COLEMAKDH,
    KC_FATR
};

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////
const uint16_t caps_combo[] PROGMEM = {KC_C, KC_COMM, COMBO_END};
combo_t key_combos[] = {
    COMBO(caps_combo, CW_TOGG),          // J and , => activate Caps Word.
};

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
#define HOME_S LT(_SYM, KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LT(_SYM, KC_L)
#define HOME_SCLN RALT_T(KC_SCLN)

// Aerospace window resizing
#define WS_INC LALT(LSFT(KC_PLUS))
#define WS_DECR LALT(LSFT(KC_MINS))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-------------+------+------+------+------|       |    |       |------+------+------+------+-------------'
 *               |      | Esc  | Bspc |  Spc |       |    |       | ENT  |   -  | Ctrl |  FN  |
 *               |      |(Ctrl)|(RSE) |      |       |    |       |      | (LWR)|      |      |
 *               `------+------+------+------+-------|    |-------|------+------+------+------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_ESC,   HOME_A, HOME_S,  HOME_D,  HOME_F,  KC_G,            KC_H,    HOME_J,  HOME_K,  HOME_L, HOME_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    LT(_NUM, KC_V),    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
        XXXXXXX, LCTL_T(KC_ESC), LT(_BUTTON, KC_BSPC), KC_SPC, XXXXXXX,          XXXXXXX, KC_ENT, LT(_SYM,KC_MINUS), KC_RCTL,XXXXXXX
),

/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAKDH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_TRNS,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_TRNS,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  KC_TRNS,    KC_TRNS,KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SYMBOL (LWR)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   '  |   <  |   >  |   "  |   `  |                    |   &  |  ::  |  [   |   ]  |   %  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   -  |   +  |   =  |   ^  |-------.    ,-------|   |  |  :   |  (   |   )  |   ?  |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |   \  |  /   |  *   |  =>  |   #  |-------|    |-------|   ~  |   $  |  {   |   }  |   @  |      |
 * `-------------+------+------+------+------|       |    |       |------+------+------+------+-------------'
 *               |      | Ctrl | Bspc |  Spc |       |    |       | ENT  |   -  | Ctrl |  FN  |
 *               |      |      |(RSE) |      |       |    |       |      | (LWR)|      |      |
 *               `------+------+------+------+-------|    |-------|------+------+------+------'
 */

[_SYM] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                    _______ , _______ , _______ , _______ ,  _______ , _______,
  _______,  KC_QUOT,  KC_LABK,  KC_RABK,  KC_DQT,  KC_GRV,                      KC_AMPR,  XXXXXXX,  KC_LBRC,  KC_RBRC,    KC_PERC, _______,
  _______,  KC_EXLM,  KC_MINS,  KC_PLUS,  KC_EQL, KC_CIRC,                      KC_PIPE,  KC_COLN,  KC_LPRN,  KC_RPRN,    KC_QUES, _______,
  _______,  KC_BSLS,  KC_SLSH,  KC_ASTR, KC_FATR, KC_HASH, _______,    _______, KC_TILD,   KC_DLR,  KC_LCBR,  KC_RCBR,      KC_AT, _______,
                    _______, _______, _______, _______, _______,       _______, _______, _______,_______, _______
),

/* BUTTON (RSE)
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Esc  | Pscr | Esc |      |      |                    |      |       |      |      |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl | Cmd  |LShift| Caps |-------.    ,-------| Left | Down |  Up  | Rigth|      |      |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      |       |      |     |      | Shift|
 * `-------------+------+------+------+------|       |    |       |------+------+------+------+-------------'
 *               |      | Ctrl | Bspc |  Spc |       |    |       | ENT  |   -  | Ctrl |  FN  |
 *               |      |      |(RSE) |      |       |    |       |      | (LWR)|      |      |
 *               `------+------+------+------+-------|    |-------|------+------+------+------'
 */

[_BUTTON] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  KC_ESC,  KC_PSCR,   KC_ESC,  XXXXXXX, XXXXXXX,                        _______, WS_DECR, WS_INC, XXXXXXX,XXXXXXX, _______,
  _______, KC_LALT,  KC_LCTL, KC_LGUI, KC_LSFT, KC_CAPS,                       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,XXXXXXX, XXXXXXX,
  _______, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), XXXXXXX,  _______,       _______, XXXXXXX, LGUI(KC_MINS), LGUI(KC_PLUS), XXXXXXX,XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |   +  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   .  |   1  |   2  |   3  |   \  | Shift|
 * `-------------+------+------+------+------|       |    |       |------+------+------+------+-------------'
 *               |      | Ctrl | Bspc |  Spc |       |    |       |   =  |  0   |   ,  |  FN  |
 *               |      |      |(RSE) |      |       |    |       |      |      |      |      |
 *               `------+------+------+------+-------|    |-------|------+------+------+------'
 */

[_NUM] = LAYOUT(
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NUM,  XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_CIRC, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MINS, KC_P4,  KC_P5,   KC_P6,   KC_PLUS,  KC_PIPE,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,  KC_DOT,  KC_P1,  KC_P2,   KC_P3,   KC_SLSH, _______,
              _______, MO(_ADJUST), KC_BSPC, _______, _______,            _______, KC_EQL, KC_P0, KC_COMM, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|    |      |      |      |      |                    |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-------------+------+------+------+------|       |    |       |------+------+------+------+-------------'
 *               |      | Ctrl | Bspc |  Spc |       |    |       | ENT  |   -  | Ctrl |  FN  |
 *               |      |      |(RSE) |      |       |    |       |      | (LWR)|      |      |
 *               `------+------+------+------+-------|    |-------|------+------+------+------'
 */

  [_ADJUST] = LAYOUT(
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  QK_BOOT  , XXXXXXX,KC_QWERTY,KC_COLEMAKDH,XXXXXXX,XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_FATR:
            if (record->event.pressed) {
                SEND_STRING("=>");
            }
            return false;
    }
    return true;
}
