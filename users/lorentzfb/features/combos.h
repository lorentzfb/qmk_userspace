#pragma once

#include <stdint.h>
#include "lorentzfb.h"

///////////////////////////////////////////////////////////////////////////////
// Combos (https://docs.qmk.fm/features/combo)
///////////////////////////////////////////////////////////////////////////////

enum combos {
    EF_CW,    // C and , => activate Caps Word.
    SPCENT_NUMW, // Toggle num word
    SD_LCBR,     // {
    // XC_LABK,     // <
    DF_LPRN,     // (
    CV_LBRC,     // [
    JK_RPRN,     // )
    MCOMM_RBRC,  // ]
    KL_RCBR,     // }
    // CDOT_RABK    // >
};

const uint16_t combo_E_F[] PROGMEM = {KC_E, HRM_F, COMBO_END};
const uint16_t combo_SPC_ENT[] PROGMEM = {KC_SPC, KC_ENT, COMBO_END};

const uint16_t combo_S_D[] PROGMEM = {HRM_S, HRM_D, COMBO_END};
// const uint16_t combo_X_C[] PROGMEM = {KC_X, KC_C, COMBO_END};

const uint16_t combo_D_F[] PROGMEM = {HRM_D, HRM_F, COMBO_END};
const uint16_t combo_C_V[] PROGMEM = {KC_C, MEH_V, COMBO_END};

const uint16_t combo_J_K[] PROGMEM = {HRM_J, HRM_K, COMBO_END};
const uint16_t combo_M_COMM[] PROGMEM = {KC_M, KC_COMM, COMBO_END};

const uint16_t combo_K_L[] PROGMEM = {HRM_K, HRM_L, COMBO_END};
// const uint16_t combo_COMM_DOT[] PROGMEM = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [EF_CW] = COMBO(combo_E_F, CW_TOGG),
    [SPCENT_NUMW] = COMBO(combo_SPC_ENT, NW_TOGG),
    [SD_LCBR] = COMBO(combo_S_D, KC_LCBR),
    // [XC_LABK] = COMBO(combo_X_C, KC_LABK),
    [DF_LPRN] = COMBO(combo_D_F, KC_LPRN),
    [CV_LBRC] = COMBO(combo_C_V, KC_LBRC),
    [JK_RPRN] = COMBO(combo_J_K, KC_RPRN),
    [MCOMM_RBRC] = COMBO(combo_M_COMM, KC_RBRC),
    [KL_RCBR] = COMBO(combo_K_L, KC_RCBR),
    // [CDOT_RABK] = COMBO(combo_COMM_DOT, KC_RABK),
};
