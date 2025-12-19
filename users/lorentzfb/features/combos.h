#pragma once

#include <stdint.h>
#include "lorentzfb.h"
#include "combos.h"

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////

enum combos {
    // SPCENT_NUMW, // Toggle num word
    MAC_EF_CW,       // E + F => activate Caps Word.
    MAC_SD_LCBR,     // {
    MAC_DF_LPRN,     // (
    MAC_JK_RPRN,     // )
    MAC_KL_RCBR,     // }
    WIN_EF_CW,       // E + F => activate Caps Word.
    WIN_SD_LCBR,     // {
    WIN_DF_LPRN,     // (
    WIN_JK_RPRN,     // )
    WIN_KL_RCBR,     // }
    CV_LBRC,         // [
    MCOMM_RBRC,      // ]
};

// const uint16_t combo_SPC_ENT[] PROGMEM = {KC_SPC, KC_ENT, COMBO_END};

// _MAC home row mod
const uint16_t combo_mac_E_F[] PROGMEM = {KC_E, MAC_F, COMBO_END};
const uint16_t combo_mac_S_D[] PROGMEM = {MAC_S, MAC_D, COMBO_END};
const uint16_t combo_mac_D_F[] PROGMEM = {MAC_D, MAC_F, COMBO_END};
const uint16_t combo_mac_J_K[] PROGMEM = {MAC_J, MAC_K, COMBO_END};
const uint16_t combo_mac_K_L[] PROGMEM = {MAC_K, MAC_L, COMBO_END};

// _MAC home row mod
const uint16_t combo_win_E_F[] PROGMEM = {KC_E, WIN_F, COMBO_END};
const uint16_t combo_win_S_D[] PROGMEM = {WIN_S, WIN_D, COMBO_END};
const uint16_t combo_win_D_F[] PROGMEM = {WIN_D, WIN_F, COMBO_END};
const uint16_t combo_win_J_K[] PROGMEM = {WIN_J, WIN_K, COMBO_END};
const uint16_t combo_win_K_L[] PROGMEM = {WIN_K, WIN_L, COMBO_END};

const uint16_t combo_M_COMM[] PROGMEM = {KC_M, KC_COMM, COMBO_END};
const uint16_t combo_C_V[] PROGMEM = {HYPR_C, MEH_V, COMBO_END};

combo_t key_combos[] = {
    // [SPCENT_NUMW] = COMBO(combo_SPC_ENT, NW_TOGG),
    [MAC_EF_CW] = COMBO(combo_mac_E_F, CW_TOGG),
    [MAC_SD_LCBR] = COMBO(combo_mac_S_D, KC_LCBR),
    [MAC_DF_LPRN] = COMBO(combo_mac_D_F, KC_LPRN),
    [MAC_JK_RPRN] = COMBO(combo_mac_J_K, KC_RPRN),
    [MAC_KL_RCBR] = COMBO(combo_mac_K_L, KC_RCBR),

    [WIN_EF_CW] = COMBO(combo_win_E_F, CW_TOGG),
    [WIN_SD_LCBR] = COMBO(combo_win_S_D, KC_LCBR),
    [WIN_DF_LPRN] = COMBO(combo_win_D_F, KC_LPRN),
    [WIN_JK_RPRN] = COMBO(combo_win_J_K, KC_RPRN),
    [WIN_KL_RCBR] = COMBO(combo_win_K_L, KC_RCBR),

    [CV_LBRC] = COMBO(combo_C_V, KC_LBRC),
    [MCOMM_RBRC] = COMBO(combo_M_COMM, KC_RBRC),
};
