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
    [_MAC] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
        KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        KC_TAB,   MAC_A,   MAC_S,   MAC_D,   MAC_F,    KC_G,           KC_H,   MAC_J,   MAC_K,   MAC_L, MAC_SCN, KC_QUOT,
      OSL_FUNC,   MED_Z,    KC_X,  HYPR_C,   MEH_V,    KC_B,           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_HYPR,
//                              +--------+--------+--------+      +--------+--------+--------+
                    NUM_ESC, LT(_MAC_BTN, KC_BSPC),  KC_SPC,         KC_ENT,SYM_MINS,  QK_REP
    ),

    [_WIN] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
        KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        KC_TAB,   WIN_A,   WIN_S,   WIN_D,   WIN_F,    KC_G,           KC_H,   WIN_J,   WIN_K,   WIN_L, WIN_SCN, KC_QUOT,
      OSL_FUNC,   MED_Z,    KC_X,  HYPR_C,   MEH_V,    KC_B,           KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LWIN,
//                              +--------+--------+--------+      +--------+--------+--------+
                     NUM_ESC, LT(_WIN_BTN, KC_BSPC), KC_SPC,         KC_ENT,SYM_MINS,  QK_REP
    ),

    [_MAC_BTN] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, G(KC_S), ___X___, ___X___, ___X___,        ___X___, WS_DECR,  WS_INC, ___X___,MAC_PRNT, ___X___,
       ___X___, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_CAPS,        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___X___, ___X___,
       ___X___, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), ___X___,         TG_NOR, G(KC_MINS),G(KC_PLUS), ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,          RAYCA,  MO_ADJ, ___X___
    ),

    [_WIN_BTN] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, C(KC_S), ___X___, ___X___, ___X___,        ___X___, WS_DECR,  WS_INC, ___X___,WIN_PRNT, ___X___,
       ___X___, KC_LCTL, KC_LALT, KC_LCTL, KC_LSFT, KC_CAPS,        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, ___X___, ___X___,
       ___X___, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), ___X___,         TG_NOR,C(KC_MINS),C(KC_PLUS), ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,          RAYCA,  MO_ADJ, ___X___
    ),

    [_NORWEGIAN] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,   NO_AA,
       _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, NO_OSTR,   NO_AE,
       _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, KC_QUOT,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  _______, _______, _______,        _______, _______, KC_SCLN
    ),

// 1337 number layer
//     [_NUMBER] = LAYOUT_wrapper(
// //   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
//        ___X___, ___X___, ___X___, KC_CIRC, ___X___, ___X___,        _______,    KC_J,    KC_K, KC_PERC, _______, KC_BSPC,
//        ___X___,    KC_6,    KC_4,    KC_0,    KC_2,   SFT_G,        KC_ASTR,    KC_3,    KC_1,    KC_5,    KC_7, ___X___,
//        ___X___, ___X___, _______, KC_PLUS,    KC_8, ___X___,        ___X___,    KC_9, _______, _______, _______, ___X___,
// //                              +--------+--------+--------+      +--------+--------+--------+
//                                    CANCEL, KC_BSPC, _______,         KC_EQL, _______, KC_UNDS
//     ),

    [_NUMBER] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, KC_CIRC, ___X___, ___X___,        _______,    KC_7,    KC_8,    KC_9, KC_PERC, KC_BSPC,
       _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,   SFT_G,        KC_ASTR,    KC_4,    KC_5,    KC_6, KC_PLUS, KC_MINS,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___,    KC_1,TD(TD_2_COMM),TD(TD_3_DOT), KC_SLSH, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,         KC_EQL,    KC_0, KC_UNDS
    ),

    [_SYMBOL] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, KC_CIRC, ___X___, ___X___,        ___X___, ___X___, ___X___, KC_PERC, KC_PERC, KC_BSPC,
       ___X___,   KC_AT, KC_TILD,  KC_DLR, KC_EXLM, ___X___,        KC_ASTR, KC_AMPR, KC_HASH,  KC_EQL, KC_PLUS,  KC_GRV,
       ___X___, ___X___, ___X___, ___X___,  ARRFAT, ___X___,        ___X___,  ARRSLI, KC_PIPE, ___X___, KC_BSLS, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, KC_BSPC, _______,        ___X___, ___X___, ___X___
    ),

    [_FUNCTION] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___,   KC_F7,   KC_F8,   KC_F9,  KC_F10, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___,   KC_F4,   KC_F5,   KC_F6,  KC_F11, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___,   KC_F1,   KC_F2,   KC_F3,  KC_F12, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
    ),

    [_MEDIA] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, KC_VOLD, KC_VOLU, KC_MUTE, ___X___, ___X___,
       ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,        ___X___, KC_MPRV, KC_MNXT, KC_MPLY, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
  ),

    [_ADJUST] = LAYOUT_wrapper(
//   +--------+--------+--------+--------+--------+--------+      +--------+--------+--------+--------+--------+--------+
       DF_MAC,   DF_WIN, ___X___, ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
       RM_NEXT, RM_HUED, RM_SATD, RM_VALD, ___X___, ___X___,        ___X___, ___X___, ___X___, ___X___, ___X___, ___X___,
//                              +--------+--------+--------+      +--------+--------+--------+
                                  ___X___, ___X___, ___X___,        ___X___, ___X___, ___X___
    )
};

// clang-format on
