#include QMK_KEYBOARD_H

#include "keymap_german.h"

#define _QWERTY 0
#define _SYMB 1
#define _NAV 2

enum custom_keycodes {
    KC_AE = SAFE_RANGE,
    KC_OE,
    KC_UE
}

/// TODO: SHIFT handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_AE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT("u") "a");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case KC_OE:
      if (record->event.pressed) {
                SEND_STRING(SS_LCTL("ac"));
      }
      break;
    case KC_UE:
      if (record->event.pressed) {
                SEND_STRING(SS_LCTL("ac"));
      }
      break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  KC_EQL,                           KC_BSLS,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   LCTL(KC_1),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_DEL,                           KC_BSPC,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
  LALT(KC_F7),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   MO(1), KC_LGUI,           TG(2),   MO(1),    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
LCTL(KC_SLSH),LSFT(KC_F6),KC_BSPC, KC_GRV,     KC_LCTL,     KC_LSFT, KC_LALT,         KC_RALT,  KC_ENT,      KC_SPC,      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                               KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_NO, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,                           KC_TRNS,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_NO,   KC_NO, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV, KC_TRNS,                           KC_TRNS, KC_PDOT,   KC_P4,   KC_P5,   KC_P6,   KC_NO,   KC_NO, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,   KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_NO,   KC_NO, 
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,     KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT),LCTL(KC_UP),LCTL(KC_DOWN),LCTL(KC_RGHT)
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_NO, KC_MS_U,   KC_NO, KC_WH_U,   KC_NO, KC_TRNS,                           KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,   KC_NO, KC_TRNS,                           KC_TRNS, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO  , KC_NO, KC_TRNS, KC_TRNS,         KC_TRNS,   KC_NO,   KC_NO,   KC_NO, KC_MUTE, KC_VOLU, KC_VOLD,   KC_NO,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
        KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_BTN1,     KC_BTN2, KC_TRNS,         KC_TRNS, KC_TRNS,       KC_NO,    KC__MUTE,KC__VOLUP, KC_VOLD,   KC_NO
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};
