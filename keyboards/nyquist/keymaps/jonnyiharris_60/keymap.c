#include QMK_KEYBOARD_H
#include "pointing_device.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _VIM 1
#define _NUM 2

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
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
  BS_RST,
  BS_FINE,
  DYNAMIC_MACRO_RANGE,
};

#include "dynamic_macro.h"

enum tapdance_codes {
  TD_F1 = 0,
  TD_F2,
  TD_F3,
  TD_F4,
  TD_F5,
  TD_F6,
  TD_F7,
  TD_F8,
  TD_F9,
  TD_F10,
  TD_F11,
  TD_F12,
};

#define BS_FACTOR_NUM 1
#define BS_FACTOR_DEN 2
#define MAX_DELTA 127

#define FINE_DELTA 16
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
	{{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}},
	{{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}},
	{{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}},
	{{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}},
	{{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}},
	{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}},
	{{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}},
	{{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}},
	{{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}},
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define X KC_NO
#define WD_BSPC LCTL(KC_BSPC)
#define WD_DEL LCTL(KC_DEL)
#define COPY LCTL(KC_INS)
#define PASTE LSFT(KC_INS)
#define WD_RGHT LCTL(KC_RGHT)
#define WD_LEFT LCTL(KC_LEFT)
#define M_START DYN_REC_START1
#define M_STOP  DYN_REC_STOP
#define M_PLAY  DYN_MACRO_PLAY1
#define VIM_TAB LT(_VIM,KC_TAB)
#define NUM_ENT LT(_NUM,KC_ENT)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_F1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_PAUS),
  [TD_F2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_RCTL),
  [TD_F3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_NO),
  [TD_F4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_NO),
  [TD_F5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_NO),
  [TD_F6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_PSCR),
  [TD_F7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_MPRV),
  [TD_F8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_MPLY),
  [TD_F9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_MNXT),
  [TD_F10] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_MUTE),
  [TD_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_VOLD),
  [TD_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_VOLU),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT( \
  X,             X,            X,            X,            X,            X,       X,       X,            X,            X,            X,            X,       \
  KC_GRV,        KC_Q,         KC_W,         KC_F,         KC_P,         KC_G,    KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSLS, \
  KC_ESC,        LSFT_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LCTL_T(KC_T), KC_D,    KC_H,    LCTL_T(KC_N), LALT_T(KC_E), LGUI_T(KC_I), LSFT_T(KC_O), KC_QUOT, \
  KC_LBRC,       KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,    KC_K,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RBRC, \
  M_START,       M_STOP,       M_PLAY,       SH_MON,       VIM_TAB,      KC_BSPC, KC_SPC,  NUM_ENT,      SH_MON,       KC_DEL,       KC_MINS,      KC_EQL  \
),

[_VIM] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______, \
  _______, BS_RST,  BS_BTN1, BS_BTN3, BS_BTN2, BS_FINE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  _______, _______, _______, COPY,    PASTE,   _______, BS_MS_L, BS_MS_D, BS_MS_U, BS_MS_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),


[_NUM] = LAYOUT( \
  _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, \
  TD(TD_F7),  TD(TD_F8),  TD(TD_F9),  TD(TD_F10), TD(TD_F11), TD(TD_F12), _______, KC_7,    KC_8,    KC_9,    _______, _______, \
  _______,    KC_LSFT,    KC_LGUI,    KC_LALT,    KC_LCTL,    _______,    _______, KC_4,    KC_5,    KC_6,    KC_0,    _______, \
  TD(TD_F1),  TD(TD_F2),  TD(TD_F3),  TD(TD_F4),  TD(TD_F5),  TD(TD_F6),  _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______,    _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______  \
),

/*
[_COLEMAK] = LAYOUT( \
  X,             X,            X,       X,       X,       X,       X,       X,               X,       X,       X,            X,       \
  ALT_T(KC_GRV), KC_Q,         KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,            KC_U,    KC_Y,    KC_SCLN,      KC_BSLS, \
  CTL_T(KC_ESC), LSFT_T(KC_A), KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,            KC_E,    KC_I,    RSFT_T(KC_O), KC_QUOT, \
  KC_LGUI,       KC_Z,         KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,            KC_COMM, KC_DOT,  KC_SLSH,      KC_MINS, \
  SH_MON,        X,            KC_LBRC, KC_RBRC, NUM_TAB, VIM_ENT, KC_SPC,  KC_BSPC,         X,       X,       KC_RCTL,      KC_EQL  \
),

[_VIM] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, M_START, WD_LEFT, WD_RGHT, WD_BSPC, WD_DEL,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_WH_D, KC_WH_U, \
  _______, BS_RST,  BS_BTN1, BS_BTN3, BS_BTN2, BS_FINE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, M_PLAY,  _______, \
  _______, M_STOP,  KC_DEL,  COPY,    PASTE,   X,       BS_MS_L, BS_MS_D, BS_MS_U, BS_MS_R, _______, _______, \
  _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______  \
),


[_NUM] = LAYOUT( \
  _______, _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______, \
  _______, _______,    TD(TD_F9),  TD(TD_F10), TD(TD_F11), TD(TD_F12), KC_TAB,  KC_7,    KC_8,    KC_9,    _______, _______, \
  _______, KC_LSFT,    TD(TD_F5),  TD(TD_F6),  TD(TD_F7),  TD(TD_F8),  KC_ENT,  KC_4,    KC_5,    KC_6,    KC_0,    _______, \
  _______, _______,    TD(TD_F1),  TD(TD_F2),  TD(TD_F3),  TD(TD_F4),  _______, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______,    _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______, _______  \
),
*/
};

int8_t delta = MAX_DELTA;
int16_t prev_dir = 0;
// The below does not actually have to be a global. We only define it this way to save space.
report_mouse_t currentReport;

bool process_binary_search_accel( uint16_t keycode, keyrecord_t *record ) {
  switch ( keycode ){
    case BS_RST:
      delta = MAX_DELTA;
      prev_dir = 0;
      break;
    case BS_FINE:
      delta = FINE_DELTA;
      prev_dir = 0;
      break;
    default:
      return true;
  }
  return false;
}
bool process_binary_search_click( uint16_t keycode, keyrecord_t *record ) {
  int8_t button;
  switch ( keycode ){
    case BS_BTN1:
      button = MOUSE_BTN1;
      break;
    case BS_BTN2:
      button = MOUSE_BTN2;
      break;
    case BS_BTN3:
      button = MOUSE_BTN3;
      break;
    default:
      return true;
  }

  delta = MAX_DELTA;
  prev_dir = 0;

  currentReport = pointing_device_get_report();
  if (record->event.pressed){
    currentReport.buttons |= button;
  } else {
    currentReport.buttons &= ~button;
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
  currentReport = pointing_device_get_report();
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



  if ( prev_dir != keycode && prev_dir != 0){
    delta = delta * BS_FACTOR_NUM / BS_FACTOR_DEN + 1;
  }

  currentReport = pointing_device_get_report();
  switch ( keycode ){
    case BS_MS_L:
      currentReport.x = -delta;
      break;
    case BS_MS_R:
      currentReport.x = delta;
      break;
    case BS_MS_U:
      currentReport.y = -delta;
      break;
    case BS_MS_D:
      currentReport.y = delta;
      break;
  }
  pointing_device_set_report( currentReport );

  prev_dir = keycode;
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
  return true;
}
