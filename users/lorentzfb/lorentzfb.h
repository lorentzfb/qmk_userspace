#pragma once

// https://docs.qmk.fm/feature_userspace
// https://github.com/plodah/qmk_userspace/tree/main/users/plodah

#include <stdint.h>
#include QMK_KEYBOARD_H


// #include "os_detection.h"
// #include "quantum/caps_word.h"
#include "quantum.h"
// #include "quantum_keycodes.h"
// #include "action_layer.h"

// #include "keymap_us.h"
// #include "quantum/action.h"
// #include "quantum/quantum_keycodes.h"

enum layers {
    _MAC = 0,
    _WIN,
    _MAC_BTN,
    _WIN_BTN,
    _NORWEGIAN,
    _NUMBER,
    _SYMBOL,
    _FUNCTION,
    _MEDIA,
    _ADJUST
};

#define DF_MAC PDF(0)
#define DF_WIN PDF(1)

// https://docs.qmk.fm/custom_quantum_functions#defining-a-new-keycode
enum keycodes {
    ARRFAT = SAFE_RANGE, // =>
    ARRSLI, // ->
    NW_TOGG,
    CANCEL,
    OS_STR
};

#define ___X___ KC_NO

// https://docs.qmk.fm/mod_tap
// _MAC home row mods

#define MAC_A LCTL_T(KC_A)
#define MAC_S LOPT_T(KC_S)
#define MAC_D CMD_T(KC_D)
#define MAC_F LSFT_T(KC_F)

#define MAC_J RSFT_T(KC_J)
#define MAC_K CMD_T(KC_K)
#define MAC_L ROPT_T(KC_L)
#define MAC_SCN RCTL_T(KC_SCLN)

// _WIN home row mods

#define WIN_A LCTL_T(KC_A)
#define WIN_S LOPT_T(KC_S)
#define WIN_D LCTL_T(KC_D)
#define WIN_F LSFT_T(KC_F)

#define WIN_J RSFT_T(KC_J)
#define WIN_K RCTL_T(KC_K)
#define WIN_L RALT_T(KC_L)
#define WIN_SCN RCTL_T(KC_SCLN)

// Meh = Left Control + Shift + Alt
// Hyper = Left Control + Shift + Alt + Gui/Cmd/Winkey

#define MEH_V MEH_T(KC_V)
#define HYPR_C HYPR_T(KC_C)

// Tap Dance declarations
enum {
    TD_2_COMM,
    TD_3_DOT
};

// Layer changes
// #define BTN_BS LT(_BUTTON, KC_BSPC)
// #define BTN_ESC LT(_BUTTON, KC_ESC)
#define NUM_ESC LT(_NUMBER, KC_ESC)
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
#define CMDI LGUI(KC_PLUS)
#define CMDD LGUI(KC_MINS)

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
