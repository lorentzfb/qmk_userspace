#pragma once

#include QMK_KEYBOARD_H

#include "keymap_us.h"
#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"

enum layer_names {
    _BL,
    _NOR,
    _NUM,
    _SYM,
    _BTN,
    _FN,
    _AERO,
    _MED,
    _ADJ
};

// https://docs.qmk.fm/custom_quantum_functions#defining-a-new-keycode
enum custom_keycodes {
    ARRFAT = QK_USER, // =>
    ARRSL, // ->
    NUMWO,
    CANCEL,
    OS_STR,
};

// Left-hand home row mods
#define HOME_A LALT_T(KC_A)
// #define HOME_S LT(_SYM, KC_S)
#define HOME_S LGUI_T(KC_S)
#define HOME_D LT(_SYM, KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
// #define HOME_K RGUI_T(KC_K)
#define HOME_K LT(_SYM, KC_K)
// #define HOME_L LT(_SYM, KC_L)
#define HOME_L RGUI_T(KC_L)
#define HOME_SCN RALT_T(KC_SCLN)

// Layer toggles
#define _BTN_BS LT(_BTN, KC_BSPC)
#define _NUM_V LT(_NUM, KC_V)
#define _MED_Z LT(_MED, KC_Z)

// Aerospace window resizing
#define WS_INC LALT(LSFT(KC_PLUS))
#define WS_DECR LALT(LSFT(KC_MINS))

// Mac print screen
#define PRNT3 LSFT(LGUI(KC_3))
#define PRNT4 LSFT(LGUI(KC_4))
#define PRNT5 LSFT(LGUI(KC_5))

// Cut, Copy, Paste, Undo
// Moved to home row
#define SCUT LGUI(KC_X)
#define SCPY LGUI(KC_C)
#define SPST LGUI(KC_V)
#define SUND LGUI(KC_Z)

// Raycast or spotlight (MEH: Hold Left Control, Shift and Alt)
#define RAYCA MEH(KC_R)

// Increase/decrease buffer size
#define CMDI LGUI(KC_MINS)
#define CMDD LGUI(KC_PLUS)

// Save/write
#define SSAVE LGUI(KC_S)

// Norwegian (When using EurKEY on mac/win/linux)
#define NO_AE ALGR(KC_Q)   // æ
#define NO_OSTR ALGR(KC_L) // ø
#define NO_AA ALGR(KC_W)   // å

// Norwegian (When using US International on mac)
// #define NO_AE LALT(KC_QUOT) // æ
// #define NO_O LALT(KC_O)     // ø
// #define NO_AA RALT(KC_A)    // å

// Norwegian (When using US International on windows)
// #define NO_AE_WIN ALGR(KC_Z) // æ
// #define NO_O_WIN ALGR(KC_L)  // ø
// #define NO_AA_WIN ALGR(KC_W) // å

// Shift-g for Vim goto line
#define NUM_G LSFT(KC_G)
