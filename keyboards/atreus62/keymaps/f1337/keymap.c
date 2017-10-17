// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _GAMING 1
#define _FN 2

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = { /* dvorak */
        { KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   _______, KC_6,   KC_7,    KC_8,    KC_9,  KC_0,    KC_SLSH     },
        { KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,   _______, KC_F,   KC_G,    KC_C,    KC_R,  KC_L,    KC_EQL      },
        { KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,   _______, KC_D,   KC_H,    KC_T,    KC_N,  KC_S,    KC_MINS     },
        { KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,   KC_ESC,  KC_B,   KC_M,    KC_W,    KC_V,  KC_Z,    KC_BSLS     },
        { MO(_FN),  XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_BSPC, KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, TG(_GAMING) }
    },

    [_GAMING] = { /* gaming overrides, macros */
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ },
        { _______,  _______, _______, _______, KC_LCTL, _______, _______,  _______, _______, _______, _______, _______, _______ }
    },

    [_FN] = { /* shared FN keys, symbols */
        { _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11  },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, KC_LCBR, KC_RCBR, _______, KC_F12  },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, KC_LBRC, KC_RBRC, _______, KC_F13  },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, KC_F14  },
        { _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______ }
    },

};

const uint16_t PROGMEM fn_actions[] = {

};
