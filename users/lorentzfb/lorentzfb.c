#include "lorentzfb.h"

#ifdef NUM_WORD_ENABLE
#   include "features/num_word.h"
#endif

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

// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }

//     host_os = detected_os;
//     return true;
// }
