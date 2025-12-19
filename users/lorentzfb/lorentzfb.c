#include "lorentzfb.h"
#include "quantum.h"
#include "features/combos.c"

#ifdef NUM_WORD_ENABLE
#   include "features/num_word.h"
#endif

// typedef enum {
//     OS_MAC = 0,
//     OS_WIN = 1,
//     OS_LINUX = 2
// } os_type_t;

// typedef union {
//   uint32_t raw;
//   struct {
//     os_type_t os_type :2;
//   };
// } user_config_t;

// user_config_t user_config;

// void keyboard_post_init_user(void) {
//   // Read the user config from EEPROM
//   user_config.raw = eeconfig_read_user();

//   // Check if os_type is a valid enum value
//     if (user_config.os_type > OS_LINUX) {
//         // Invalid: set to default and save it
//         user_config.os_type = OS_MAC;
//         eeconfig_update_user(user_config.raw);
//     }
// }

// void update_os_type_eeconfig(os_type_t os_type) {
//     user_config.os_type = os_type;
//     eeconfig_update_user(user_config.raw);
// }



// Keeps track of the detected OS
// static os_variant_t host_os = OS_UNSURE;

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef NUM_WORD_ENABLE
    if (!process_num_word(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case NW_TOGG:
            process_num_word_activation(record);
            return false;
        case CANCEL:
            layer_off(_NUMBER);
            return false;
    }
    #endif // NUM_WORD_ENABLE

    #ifdef CUSTOM_SEQUENCES_ENABLE
    switch (keycode) {
        case ARRFAT:
            if (record->event.pressed) {
                SEND_STRING(" => ");
            }
            return false;
        case ARRSLI:
            if (record->event.pressed) {
                SEND_STRING(" -> ");
            }
            return false;
        // case OS_STR:
        //     if (record->event.pressed) {
        //         switch (host_os) {
        //             case OS_MACOS:
        //                 SEND_STRING("MAC");
        //                 break;
        //             case OS_IOS:
        //                 SEND_STRING("IOS");
        //                 break;
        //             case OS_WINDOWS:
        //                 SEND_STRING("WIN");
        //                 break;
        //             case OS_LINUX:
        //                 SEND_STRING("LINUX");
        //                 break;
        //             case OS_UNSURE:
        //                 SEND_STRING("UNSURE");
        //                 break;
        //         }
        //     }
        //     return false;
    }
    #endif // CUSTOM_SEQUENCES_ENABLE

    return process_record_keymap(keycode, record);
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_2_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_COMM),
    [TD_3_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_DOT)
};

// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }

//     host_os = detected_os;
//     return true;
// }
