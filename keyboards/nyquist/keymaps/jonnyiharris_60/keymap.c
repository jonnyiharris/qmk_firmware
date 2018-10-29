#include QMK_KEYBOARD_H
#include "pointing_device.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _VIM 2
#define _MOUSE 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  VIM,
  MOUSE,
  BS_MS_L,
  BS_MS_R,
  BS_MS_U,
  BS_MS_D,
  BS_WH_U,
  BS_WH_D,
  BS_WH_L,
  BS_WH_R,
  BS_BTN1,
  BS_BTN2,
  BS_BTN3,
  BS_ACL0,
  BS_ACL1,
  BS_ACL2,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define X KC_NO
#define WD_BSPC LCTL(KC_BSPC)
#define COPY LCTL(KC_INS)
#define PASTE LSFT(KC_INS)
#define WD_RGHT LCTL(KC_RGHT)
#define WD_LEFT LCTL(KC_LEFT)
#define M_START DYN_REC_START1
#define M_STOP  DYN_REC_STOP
#define M_PLAY  DYN_MACRO_PLAY1

#define BS_FACTOR_NUM 1
#define BS_FACTOR_DEN 2
#define MAX_DELTA 127

#define FIXED_DELTA_0 1
#define FIXED_DELTA_1 4
#define FIXED_DELTA_2 8
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LBRC, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC, \
  KC_GRV,  MOUSE,   KC_LGUI, KC_LALT, KC_LSFT, VIM,     KC_SPC,  KC_RSFT, X,       X,       X,       COLEMAK  \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, \
  _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______, \
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_VIM] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, M_START, WD_BSPC, KC_END,  X,       X,       COPY,    KC_PGUP, X,       X,       PASTE,   KC_ESC,  \
  _______, KC_HOME, X,       KC_PGDN, WD_RGHT, X,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, X,       KC_ENT,  \
  _______, M_STOP,  KC_DEL,  X,       X,       WD_LEFT, X,       X,       X,       M_PLAY,  X,       _______, \
  _______, _______, _______, _______, _______, _______, KC_BSPC, _______, KC_RALT, KC_RCTL, KC_VOLD, KC_VOLU  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, BS_WH_L, BS_WH_D, BS_WH_U, BS_WH_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, BS_MS_L, BS_MS_D, BS_MS_U, BS_MS_R, _______, _______, \
  _______, _______, BS_BTN1, BS_BTN2, BS_BTN3, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, BS_ACL2, BS_ACL0, _______, _______, _______, _______, _______  \
),


};

int16_t prev_delta = MAX_DELTA;
int16_t prev_dir = 0;
int16_t fixed_delta = 0;

bool process_binary_search_accel( uint16_t keycode, keyrecord_t *record ) {
  switch ( keycode ){
    case BS_ACL0:
      if ( record->event.pressed ){
        fixed_delta = FIXED_DELTA_0;
      } else {
        fixed_delta = 0;
      }
      break;
    case BS_ACL1:
      if ( record->event.pressed ){
        fixed_delta = FIXED_DELTA_1;
      } else {
        fixed_delta = 0;
      }
      break;
    case BS_ACL2:
      if ( record->event.pressed ){
        fixed_delta = FIXED_DELTA_2;
      } else {
        fixed_delta = 0;
      }
      break;
    default:
      return true;
  }
  return false;
}
bool process_binary_search_click( uint16_t keycode, keyrecord_t *record ) {
  switch ( keycode ){
    case BS_BTN1:
    case BS_BTN2:
    case BS_BTN3:
      break;
    default:
      return true;
  }

  prev_delta = MAX_DELTA;
  prev_dir = 0;

  report_mouse_t currentReport = pointing_device_get_report();
  switch ( keycode ){
    case BS_BTN1:
      if (record->event.pressed){
        currentReport.buttons |= MOUSE_BTN1;
      } else {
        currentReport.buttons &= ~MOUSE_BTN1;
      }
      break;
    case BS_BTN2:
      if (record->event.pressed){
        currentReport.buttons |= MOUSE_BTN2;
      } else {
        currentReport.buttons &= ~MOUSE_BTN2;
      }
      break;
    case BS_BTN3:
      if (record->event.pressed){
        currentReport.buttons |= MOUSE_BTN3;
      } else {
        currentReport.buttons &= ~MOUSE_BTN3;
      }
      break;
  }
  pointing_device_set_report( currentReport );
  return false;
}
bool process_binary_search_scroll( uint16_t keycode, keyrecord_t *record ) {
  switch ( keycode ){
    case BS_WH_U:
    case BS_WH_D:
    case BS_WH_L:
    case BS_WH_R:
      break;
    default:
      return true;
  }

  if (!record->event.pressed) return false;
  report_mouse_t currentReport = pointing_device_get_report();
  switch ( keycode ){
    case BS_WH_U:
      currentReport.v = 3;
      break;
    case BS_WH_D:
      currentReport.v = -3;
      break;
    case BS_WH_L:
      currentReport.h = -3;
      break;
    case BS_WH_R:
      currentReport.h = 3;
      break;
  }
  pointing_device_set_report( currentReport );
  return false;
}
bool process_binary_search_move( uint16_t keycode, keyrecord_t *record ) {
  int16_t delta = prev_delta;
  int16_t delta_to_go;
  int16_t tmp_delta;
  report_mouse_t currentReport;
  switch ( keycode ){
    case BS_MS_L:
    case BS_MS_R:
    case BS_MS_U:
    case BS_MS_D:
      break;
    default:
      return true;
  }

  if (!record->event.pressed) return false;



  if ( fixed_delta != 0 ){
    delta = fixed_delta;
  } else if ( prev_dir != keycode && prev_dir != 0){
    delta = prev_delta * BS_FACTOR_NUM / BS_FACTOR_DEN + 1;
  }

  delta_to_go = delta;
  while ( delta_to_go > 0 ){
    tmp_delta = delta_to_go > 127 ? 127 : delta_to_go;
    delta_to_go = delta_to_go - tmp_delta;
    currentReport = pointing_device_get_report();
    switch ( keycode ){
      case BS_MS_L:
        currentReport.x = -tmp_delta;
        break;
      case BS_MS_R:
        currentReport.x = tmp_delta;
        break;
      case BS_MS_U:
        currentReport.y = -tmp_delta;
        break;
      case BS_MS_D:
        currentReport.y = tmp_delta;
        break;
    }
    pointing_device_set_report( currentReport );
  }

  prev_dir = keycode;
  prev_delta = delta;
  return false;
}
bool process_binary_search( uint16_t keycode, keyrecord_t *record ){
  if ( !process_binary_search_move(keycode,record) ){
    return false;
  }
  if ( !process_binary_search_scroll(keycode,record) ){
    return false;
  }
  if ( !process_binary_search_accel(keycode,record) ){
    return false;
  }
  if ( !process_binary_search_click(keycode,record) ){
    return false;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if ( !process_binary_search(keycode,record) ) {
    return false;
  }
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        layer_invert(_COLEMAK);
      }
      return false;
    case VIM:
      if (record->event.pressed) {
        layer_on(_VIM);
      } else {
        layer_off(_VIM);
      }
      return false;
    case MOUSE:
      if (record->event.pressed) {
        prev_delta = MAX_DELTA;
        prev_dir = 0;
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
  }
  return true;
}
