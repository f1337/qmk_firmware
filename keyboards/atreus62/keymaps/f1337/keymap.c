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

// tap-dance
// see https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md#example-5-using-tap-dance-for-advanced-mod-tap-and-layer-tap-keys
// and https://www.reddit.com/r/olkb/comments/a69k5q/qmk_multilayer_taphold/ebtebry/
#define TD_LAYER TD(TD_LAYER_SWAP)

typedef struct {
  bool is_press_action;
  int state;
} tap;

static tap tap_state = {
  .is_press_action = true,
  .state = 0
};

enum tapdance_id {
  TD_LAYER_SWAP = 0,
};

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->interrupted || !state->pressed) return DOUBLE_TAP;
    else return 4;
  }
  else return 4;
}

void tap_finished (qk_tap_dance_state_t *state, void *user_data) {
  tap_state.state = cur_dance(state);
  uint8_t layer = biton32(layer_state);

  switch (tap_state.state) {
    case SINGLE_HOLD:
      layer_on(_FN);
      layer_off(_MK);
      break;
    case SINGLE_TAP:
      if (layer == _MK) {
        layer_off(_MK);
      } else {
        layer_on(_MK);
      }
      break;
    case DOUBLE_TAP:
      if (layer == _GAMING) {
        layer_off(_GAMING);
      } else {
        layer_on(_GAMING);
      }
      break;
  }
}

void tap_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (tap_state.state) {
    case SINGLE_HOLD:
      layer_off(_FN);
      break;
  }
  tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LAYER_SWAP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, tap_finished, tap_reset)
};

// end tap-dance

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DVORAK] = LAYOUT( /* dvorak */
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,   KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_EQL,
        KC_LCTL,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_LSFT,  KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SLSH,
        TD_LAYER, _______, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_ESC,   KC_BSPC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______
    ),

    [_GAMING] = LAYOUT( /* gaming overrides, macros */
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, KC_LCTL, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
    ),

    [_MK] = LAYOUT( /* mouse keys */
        _______,  KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX,                     XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX,
        _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  _______, _______, _______, _______, XXXXXXX, _______,  KC_BTN1,  KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
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
