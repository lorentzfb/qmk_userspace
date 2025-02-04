/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "lorentzfb.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
        KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        KC_TAB,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G,           KC_H,   HRM_J,   HRM_K,   HRM_L, HRM_SCN, KC_QUOT,
      OSL_FUNC,   MED_Z,    KC_X,  HYPR_C,   MEH_V,    KC_B,           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_HYPR,
//                              +--------+--------+--------+      +--------+--------+--------+
                                   KC_ESC,  BTN_BS,  KC_SPC,         KC_ENT,SYM_MINS,  QK_REP
    ),

    [_NORWEGIAN] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,   NO_AA,
       _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, NO_OSTR,   NO_AE,
       _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, KC_QUOT,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  _______, _______, _______,        _______, _______, KC_SCLN
    ),

    [_NUMBER] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, KC_CIRC, ___X___, ___X___,        _______,    KC_J,    KC_K, KC_PERC, _______, KC_BSPC,
       ___X___,    KC_6,    KC_4,    KC_0,    KC_2,   SFT_G,        KC_ASTR,    KC_3,    KC_1,    KC_5,    KC_7, ___X___,
       ___X___, ___X___, _______, KC_PLUS,    KC_8, ___X___,        ___X___,    KC_9, _______, _______, _______, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                   CANCEL, KC_BSPC, _______,         KC_EQL, _______, KC_UNDS
    ),

    [_SYMBOL] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, KC_CIRC, ___X___, ___X___,        ___X___, ___X___, ___X___, KC_PERC, ___X___, KC_BSPC,
       ___X___,   KC_AT, KC_TILD,  KC_DLR, KC_EXLM, ___X___,        KC_ASTR, KC_AMPR, KC_HASH,  KC_EQL, KC_PIPE,  KC_GRV,
       ___X___, ___X___, ___X___, KC_PLUS,  ARRFAT, ___X___,        ___X___,  ARRSLI, ___X___, ___X___, KC_BSLS, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, KC_BSPC, _______,        ___X___, ___X___, ___X___
    ),

    [_BUTTON] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___,   SSAVE, ___X___, ___X___,   PRNT4,        ___X___, WS_DECR,  WS_INC, ___X___, ___X___, ___X___,
       ___X___,    SUND,    SCUT,    SCPY,    SPST, KC_CAPS,        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___X___, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,         TG_NOR,    CMDD,    CMDI, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, _______,          RAYCA,  MO_ADJ, ___X___
    ),

    [_FUNCTION] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       CG_LNRM, CG_LSWP, ___X___, ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       ___X___,   KC_F6,   KC_F4,  KC_F10,   KC_F2,  KC_F12,         KC_F11,   KC_F3,   KC_F1,   KC_F5,   KC_F7, ___X___,
       ___X___, ___X___, ___X___, ___X___,   KC_F8, ___X___,        ___X___,   KC_F9, ___X___, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
    ),

    [_MEDIA] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, KC_VOLD, KC_MUTE, KC_VOLU, ___X___, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, KC_MPRV, KC_MPLY, KC_MNXT, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
  ),

    [_ADJUST] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___,  OS_STR, ___X___, ___X___,
       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
    )
};

// clang-format on
