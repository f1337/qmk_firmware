// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _GAMING 1
#define _MK 2
#define _FN 3

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT( /* dvorak */
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQL,
        KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
        MO(_FN),  TG(_MK), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_ESC,   KC_BSPC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TG(_GAMING)
    ),

    [_GAMING] = LAYOUT( /* gaming overrides, macros */
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, KC_LCTL, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
    ),

    [_MK] = LAYOUT( /* mouse keys */
        _______,  KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, KC_WH_U, _______, _______,                     _______, _______, KC_MS_U, _______, _______, _______,
        _______,  _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,                     _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______,  _______,  KC_BTN1, KC_BTN1, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT( /* FN keys, symbols */
        _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, KC_LCBR, KC_RCBR, _______, KC_F12,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, KC_LBRC, KC_RBRC, _______, KC_F13,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_F14,
        _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
    ),

    // [_EMOJI] = LAYOUT(
    //     X(HART2), X(CRY2),X(WEARY),X(EYERT),X(SMIRK), X(TJOY),X(RECYC),X(UNAMU),X(MUSIC),X(OKHND),X(PENSV), X(PHEW),
    //     X(THMUP), X(PRAY),X(SMILE),X(SMIL2),X(FLUSH), X(GRIN),X(HEART),  X(BYE), X(KISS),X(CELEB), X(COOL),X(NOEVS),
    //     X(THMDN),X(SLEEP), X(CLAP),  X(CRY),  X(VIC),X(BHART),  X(SUN),X(SMEYE), X(WINK), X(MOON),X(CONFU),X(NOEVH),
    //     X(POO), X(EYES), X(HUNRD),_______, X(SKULL),X(HORNS), X(HALO), X(FEAR),_______,X(YUMMY),X(DISAP),X(NOEVK),
    // ),

};

// const uint16_t PROGMEM fn_actions[] = {

// };
