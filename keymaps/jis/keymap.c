#include QMK_KEYBOARD_H
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif

#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 2
#define _RAISE 4
#define _ARROW 6
#define _MOUSE 8
#define _ADJUST 16


#define KC_____ KC_TRNS
#define KC_RESET RESET
#define KC_B_BK LALT(KC_LEFT) //ブラウザバック
#define KC_ADJUST MO(_ADJUST)
#define ____ KC_TRNS
#define KC_MOUSE MO(_MOUSE)

#define JP_____ KC_TRNS
#define JP_ADJUST MO(_ADJUST)

//Tap Dance Declarations
enum {
    TD_ALT_GUI = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  //[TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  [TD_ALT_GUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT( \
          LALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P),
          LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_MINS),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), LT(_ARROW, JP_ZHTG), LT(_LOWER, KC_TAB), LT(_LOWER, KC_SPC),    LT(_RAISE, KC_ENT), KC_BSPC, KC_APP, TD(TD_ALT_GUI)
),

[_LOWER] = LAYOUT( \
            KC_EXLM,  JP_AT,   KC_HASH, KC_DLR,  KC_PERC,    JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN,
            KC_1,     KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
            MO(_MOUSE), ____,  ____,    ____,    ____,       ____,    ____,    ____,    ____,    ____,
            ____,        ____,       ____,       ____,       MO(_ADJUST), KC_DELETE,    ____,    ____
),

[_RAISE] = LAYOUT( \
            KC_LALT, ____,  JP_TILD, JP_PLUS, JP_LCBR,    JP_RCBR, JP_COLN, JP_DQT, JP_QUES, JP_PIPE,
            KC_LCTL, ____,  JP_GRV,  JP_EQL,  JP_LBRC,    JP_RBRC, JP_SCLN, JP_QUOT, JP_SLSH, JP_BSLS,
            KC_LSFT, ____,  ____,    ____,    ____,       ____,    ____,    ____,    ____,    JP_YEN,
            KC_ESC,    KC_LGUI,   ____,   MO(_ADJUST),    ____,       ____,       ____,       ____
),

[_ARROW] = LAYOUT_kc( \
            LALT, F1,   F2,   F3,   F4,      ____, ____, ____, ____, ____,
            LCTL, F5,   F6,   F7,   F8,      LEFT, DOWN, UP,  RIGHT, ____,
            LSFT, F9,   F10,  F11,  F12,     HOME, PGDN, PGUP, END,  ____,
            ESC,    LGUI,   ____,   ____,    ____,   ____,   ____,   ____
),

[_MOUSE] = LAYOUT_kc( \
            LALT, ____, ____, ____, ____,    B_BK, WH_U, WH_U, NO,   ____,
            LCTL, ____, ____, ____, ____,    MS_L, MS_D, MS_U, MS_R, ____,
            LSFT, ____, ____, ____, ____,    MS_BTN1, WH_D, MS_BTN2, ____, ____,
            ESC,    LGUI,   ____,   ____,    MS_BTN1, MS_BTN2, ____, ____
),

[_ADJUST] = LAYOUT( \
            ____, ____, ____, ____, ____,    ____, ____, KC_PSCR, KC_VOLU, RESET,
            ____, ____, ____, ____, ____,    ____, ____, ____, KC_VOLD, ____,
            ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____,
            ____,   ____,   ____,   ____,    ____,   ____,   ____,   ____
)
};
