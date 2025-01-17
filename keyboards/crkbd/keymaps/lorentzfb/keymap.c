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

// clang-format off
#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// KEYMAP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
       KC_LCTL,   HRM_A,   HRM_S,   HRM_D,   HRM_F,    KC_G,           KC_H,   HRM_J,   HRM_K,   HRM_L, HRM_SCN, KC_QUOT,
      OSL_FUNC,   MED_Z,    KC_X,    KC_C,   MEH_V,    KC_B,           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_HYPR,
//                              +--------+--------+--------+      +--------+--------+--------+
                                   KC_ESC,  BTN_BS,  KC_SPC,         KC_ENT, KC_MINS,  QK_REP
    ),

    [_NORWEGIAN] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
      ___PASS_6____________________________________________,       ___PASS_5___________________________________,   NO_AA,
      ___PASS_6____________________________________________,       ___PASS_4__________________________, NO_OSTR,   NO_AE,
      ___PASS_6____________________________________________,       ___PASS_5___________________________________, KC_QUOT,
//                              +--------+--------+--------+      +--------+--------+--------+
                                 ___PASS_3_________________,        _______, _______, KC_SCLN
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
       ___X___,   KC_AT, KC_TILD,  KC_DLR, KC_EXLM, ___X___,        KC_ASTR, KC_AMPR, KC_HASH, ___X___, KC_PIPE,  KC_GRV,
       ___X___, ___X___, ___X___, KC_PLUS,  ARRFAT, ___X___,        ___X___,  ARRSLI, ___X___, ___X___, KC_BSLS, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, KC_BSPC, _______,         KC_EQL, _______, ___X___
    ),

    [_BUTTON] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___,   SSAVE, ___X___, ___X___, ___X___,        ___X___, WS_DECR,  WS_INC,   PRNT3,   PRNT4,   PRNT5,
       ___X___,    SUND,    SCUT,    SCPY,    SPST, KC_CAPS,        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___X___, ___X___,
       ___X___, ___X___, ___X___, KC_HYPR,  KC_MEH, ___X___,         TG_NOR,    CMDD,    CMDI, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, _______,          RAYCA,  MO_ADJ, ___X___
    ),

    [_FUNCTION] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
      ___X_6_______________________________________________,       ___X_6_______________________________________________,
       ___X___,   KC_F6,   KC_F4,  KC_F10,   KC_F2,  KC_F12,         KC_F11,   KC_F3,   KC_F1,   KC_F5,   KC_F7, ___X___,
       ___X___, ___X___, ___X___, ___X___,   KC_F8, ___X___,        ___X___,   KC_F9, ___X___, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
    ),

    [_MEDIA] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
      ___X_6_______________________________________________,       ___X_6_______________________________________________,
      ___X_6_______________________________________________,        ___X___, KC_VOLD, KC_MUTE, KC_VOLU, ___X___, ___X___,
      ___X_6_______________________________________________,        ___X___, KC_MPRV, KC_MPLY, KC_MNXT, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
  ),

    [_ADJUST] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       CG_TOGG, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___,  OS_STR, ___X___, ___X___,
       RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
    )
};
