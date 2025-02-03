#pragma once

#include <stdint.h>
#include QMK_KEYBOARD_H


// #include "os_detection.h"
// #include "quantum/caps_word.h"
// #include "quantum.h"
// #include "quantum_keycodes.h"
// #include "action_layer.h"

// #include "keymap_us.h"
// #include "quantum/action.h"
// #include "quantum/quantum_keycodes.h"

enum layers {
    _QWERTY = 0,
    FIRST_DEFAULT_LAYER = 0,
    _NORWEGIAN,
    _NUMBER,
    _SYMBOL,
    _BUTTON,
    _FUNCTION,
    _MEDIA,
    _ADJUST
};

// https://docs.qmk.fm/custom_quantum_functions#defining-a-new-keycode
enum keycodes {
    ARRFAT = SAFE_RANGE, // =>
    ARRSLI, // ->
    NW_TOGG,
    CANCEL,
    OS_STR,
};

#define ___X___ KC_NO

//      _1______, 2______, 3______,
#define ___X_3____________________ ___X___, ___X___, ___X___
#define ___PASS_3_________________ _______, _______, _______

//      _1______, 2______, 3______, 4______,
#define ___X_4_____________________________ ___X___, ___X___, ___X___, ___X___
#define ___PASS_4__________________________ _______, _______, _______, _______

//      _1______, 2______, 3______, 4______, 5______,
#define ___X_5______________________________________ ___X___, ___X___, ___X___, ___X___, ___X___
#define ___PASS_5___________________________________ _______, _______, _______, _______, _______

//      _1______, 2______, 3______, 4______, 5______, 6______,
#define ___X_6_______________________________________________ ___X___, ___X___, ___X___, ___X___, ___X___, ___X___
#define ___PASS_6____________________________________________ _______, _______, _______, _______, _______, _______

// https://docs.qmk.fm/mod_tap

// Left-hand home row mods
#define HRM_A RCTL_T(KC_A)
#define HRM_S LALT_T(KC_S)
#define HRM_D LGUI_T(KC_D)
#define HRM_F LSFT_T(KC_F)

// Meh = Left Control + Shift + Alt
// Hyper = Left Control + Shift + Alt + Gui/Cmd/Winkey

// MEH on V
#define MEH_V MEH_T(KC_V)
#define HYPR_C HYPR_T(KC_C)

// Right-hand home row mods
#define HRM_J RSFT_T(KC_J)
#define HRM_K LGUI_T(KC_K)
#define HRM_L RALT_T(KC_L)
#define HRM_SCN RCTL_T(KC_SCLN)

// Layer changes
#define BTN_BS LT(_BUTTON, KC_BSPC)
#define SYM_MINS LT(_SYMBOL, KC_MINS)
#define MED_Z LT(_MEDIA, KC_Z)
#define OSL_FUNC OSL(_FUNCTION)
#define TG_NOR TG(_NORWEGIAN)
#define MO_ADJ MO(_ADJUST)

// Aerospace window resizing
#define WS_INC LALT(LSFT(KC_PLUS))
#define WS_DECR LALT(LSFT(KC_MINS))

// Mac print screen
// #define PRNT3 LSFT(LGUI(KC_3))
#define PRNT4 LSFT(LGUI(KC_4))
// #define PRNT5 LSFT(LGUI(KC_5))

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
#define SFT_G LSFT(KC_G)
