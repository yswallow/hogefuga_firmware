#pragma once

#include "../hogefuga.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
//    #include "ws2812.h"
#endif

//void promicro_bootloader_jmp(bool program);
#define LAYOUT( \
  L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, \
  L30,   L31,  L32,   L33,   R30,   R31,  R32,   R33 \
) \
{ \
  { L00, L01, L02, L03, L04 },\
  { L10, L11, L12, L13, L14 },\
  { L20, L21, L22, L23, L24 },\
  { L30, L31,KC_NO,L32, L33 },\
  { R00, R01, R02, R03, R04 }, \
  { R10, R11, R12, R13, R14 }, \
  { R20, R21, R22, R23, R24 }, \
  { R30, R31,KC_NO,R32, R33 } \
}

#define LAYOUT_kc( \
  L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, \
  L30,   L31,  L32,   L33,   R30,   R31,  R32,   R33 \
) \
LAYOUT( \
  KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04,   KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, \
  KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14,   KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, \
  KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24,   KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, \
  KC_##L30,     KC_##L31,    KC_##L32,    KC_##L33,   KC_##R30,    KC_##R31,     KC_##R32,    KC_##R33 \
) \

#define LAYOUT_JP( \
  L00, L01, L02, L03, L04,   R00, R01, R02, R03, R04, \
  L10, L11, L12, L13, L14,   R10, R11, R12, R13, R14, \
  L20, L21, L22, L23, L24,   R20, R21, R22, R23, R24, \
  L30,   L31,  L32,   L33,   R30,   R31,  R32,   R33 \
) \
LAYOUT( \
  JP_##L00, JP_##L01, JP_##L02, JP_##L03, JP_##L04,   JP_##R00, JP_##R01, JP_##R02, JP_##R03, JP_##R04, \
  JP_##L10, JP_##L11, JP_##L12, JP_##L13, JP_##L14,   JP_##R10, JP_##R11, JP_##R12, JP_##R13, JP_##R14, \
  JP_##L20, JP_##L21, JP_##L22, JP_##L23, JP_##L24,   JP_##R20, JP_##R21, JP_##R22, JP_##R23, JP_##R24, \
  JP_##L30,     JP_##L31,    JP_##L32,    JP_##L33,   JP_##R30,    JP_##R31,     JP_##R32,    JP_##R33 \
) \

