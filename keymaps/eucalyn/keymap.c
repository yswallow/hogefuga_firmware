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
#define _EUCALYN 0
#define _QWERTY 1
#define _EUCALYN_J 2
#define _QWERTY_J 3
//#define _TRANS 4
#define _LOWER 8
#define _RAISE 9
#define _LOWER_J 10
#define _RAISE_J 11
#define _ARROW 12
#define _MOUSE 13
#define _ADJUST 16

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_____ KC_TRNS
#define KC_RESET RESET
#define KC_B_BK LALT(KC_LEFT) //ブラウザバック
#define KC_ADJUST MO(_ADJUST)
#define ____ KC_TRNS
#define KC_MOUSE MO(_MOUSE)
#define KC_ARROW MO(_ARROW)
#define KC_DF TO(_TRANS)
#define KC_CTL_L LM(_TRANS, KC_LCTL)
#define KC_REDO LCTL(KC_Z)
#define KC_FDEL S(KC_DEL)
//#define KC_MXLM LT(_MOUSE, KC_EXLM)

//Tap Dance Declarations
enum {
    TD_ALT_GUI = 0,
    TD_IME,
    TD_LSHIFT_MOUSE
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  //[TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
  [TD_ALT_GUI]  = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_LGUI),
  [TD_IME] = ACTION_TAP_DANCE_DOUBLE( LCTL(KC_ESC), LCTL(KC_SPC) ),
  [TD_LSHIFT_MOUSE] = ACTION_TAP_DANCE_DUAL_ROLE( KC_LSFT, _MOUSE )
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_EUCALYN] = LAYOUT( \
          LALT_T(KC_Q), KC_MINUS, KC_COMM, KC_DOT, KC_W,       KC_M, KC_Y, KC_K, KC_R, RALT_T(KC_P),
          LCTL_T(KC_A), KC_O, KC_E, KC_I, KC_U,       KC_N, KC_H, KC_J, KC_L, RCTL_T(KC_G),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_F,       KC_S, KC_T, KC_D, KC_B, RSFT_T(KC_Q),
          LCTL_T(KC_ESC), LT(_ARROW, KC_F10), LT(_LOWER, KC_TAB), LT(_LOWER, KC_SPC),    LT(_RAISE, KC_ENT), KC_BSPACE, LCTL(KC_SPC), TD(TD_ALT_GUI)
),

[_QWERTY] = LAYOUT( \
          LALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P),
          LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_MINUS),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), LT(_ARROW, KC_F10), LT(_LOWER, KC_TAB), LT(_LOWER, KC_SPC),    LT(_RAISE, KC_ENT), KC_BSPACE, ____, TD(TD_ALT_GUI)
),

[_EUCALYN_J] = LAYOUT( \
          LALT_T(KC_Q), KC_MINUS, KC_COMM, KC_DOT, KC_W,       KC_M, KC_Y, KC_K, KC_R, RALT_T(KC_P),
          LCTL_T(KC_A), KC_O, KC_E, KC_I, KC_U,       KC_N, KC_H, KC_J, KC_L, RCTL_T(KC_G),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_F,       KC_S, KC_T, KC_D, KC_B, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), LT(_ARROW, KC_F10), LT(_LOWER_J, KC_TAB), LT(_LOWER_J, KC_SPC),    LT(_RAISE_J, KC_ENT), KC_BSPACE, JP_ZHTG, TD(TD_ALT_GUI)
),

[_QWERTY_J] = LAYOUT( \
          LALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T,       KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P),
          LCTL_T(KC_A), KC_S, KC_D, KC_F, KC_G,       KC_H, KC_J, KC_K, KC_L, RCTL_T(KC_MINUS),
          LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B,       KC_N, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_ENT),
          LCTL_T(KC_ESC), LT(_ARROW, KC_F10), LT(_LOWER_J, KC_TAB), LT(_LOWER_J, KC_SPC),    LT(_RAISE_J, KC_ENT), KC_BSPACE, JP_ZHTG, TD(TD_ALT_GUI)
),

[_LOWER] = LAYOUT_kc( \
            EXLM, AT,   HASH, DLR,  PERC,    CIRC, AMPR, ASTR, LPRN, RPRN,
            1,    2,    3,    4,    5,       6,    7,    8,    9,    0,
            MOUSE,REDO, ____, ____, ____,    ____, ____, ____, ____, ____,
            ____,   ____,   ____,   ____,    ADJUST, DELETE, FDEL,  ____
),

[_RAISE] = LAYOUT_kc( \
            LALT, MINUS,COMM, DOT,  LCBR,    RCBR, COLN, DQUO, QUES, PIPE,
            LCTL, NO,   GRV,  EQL,  LBRC,    RBRC, SCLN, QUOT, SLSH, BSLS,
            LSFT, ____, TILD, PLUS, ____,    ____, ____, ____, ____, ENT,
            ESC,    LGUI,   ____, ADJUST,    ____,   ____,   ____,  ____
),

[_LOWER_J] = LAYOUT( \
            KC_EXLM,  JP_AT,   KC_HASH, KC_DLR,  KC_PERC,    JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN,
            KC_1,     KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
            MO(_MOUSE), ____,  ____,    ____,    ____,       ____,    ____,    ____,    ____,    ____,
            ____,        ____,       ____,       ____,       MO(_ADJUST), KC_DELETE,    ____,    ____

),

[_RAISE_J] = LAYOUT( \
            KC_LALT, JP_UNDS,  JP_TILD, JP_PLUS, JP_LCBR,    JP_RCBR, JP_COLN, JP_DQT,  JP_QUES, JP_PIPE,
            KC_LCTL, JP_YEN,  JP_GRV,  JP_EQL,  JP_LBRC,    JP_RBRC, JP_SCLN, JP_QUOT, JP_SLSH, JP_BSLS,
            KC_LSFT, ____,  ____,    ____,    ____,       ____,    ____,    ____,    ____, ____,
            KC_ESC,    KC_LGUI,   ____,   MO(_ADJUST),    ____,       ____,       ____,       ____
),

[_ARROW] = LAYOUT_kc( \
            LALT, F1,   F2,   F3,   F4,      ____, ____, UP,   ____, ____,
            LCTL, F5,   F6,   F7,   F8,      LEFT, LEFT, DOWN, RIGHT, ____,
            LSFT, F9,   F10,  F11,  F12,     HOME, PGDN, PGUP, END,  ____,
            ESC,    LGUI,   ____,   ____,    ____,   ____,   ____,   ____
),

[_MOUSE] = LAYOUT_kc( \
            LALT, ____, ____, ____, ____,    B_BK, WH_U, MS_U, NO,   VOLU,
            LCTL, ____, ____, ____, ____,    MS_L, MS_L, MS_D, MS_R, PSCR,
            LSFT, ____, ____, ____, ____,    MS_BTN1, WH_D, MS_BTN2, NO, VOLD,
            ESC,    LGUI,   ____,   ____,    MS_BTN1, MS_BTN2, NO, NO
),

[_ADJUST] = LAYOUT( \
            DF(_QWERTY), ____, DF(_EUCALYN), ____, ____,    ____, ____, KC_PSCR, KC_VOLU, RESET,
            ____, ____, DF(_EUCALYN), ____, ____,           ____, DF(_QWERTY_J), KC_INS, KC_VOLD, ____,
            ____, ____, ____, ____, ____,                   ____, ____, ____, ____, ____,
            ____,   ____,   ____,   ____,                   ____,   ____,   ____,   ____
)
};
