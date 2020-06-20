#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define COLEMAK 0
#define NUM 1
#define VIM 2

uint8_t match_leaxer_sequence(void);

enum custom_keycodes {
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
  KC_LEAX,
};

#include "dynamic_macro.h"

enum leaxer_match_types {
  LEAX_NO_MATCH = 0,
  LEAX_MATCH,
  LEAX_SEQ_INCOMPLETE,
};

enum tapdance_codes {
  F1_PAUS = 0,
  F2_RCTL,
  F3_NO,
  F4_NO,
  F5_PRSC,
  F6_MPRV,
  F7_MPLY,
  F8_MNXT,
  F9_NO,
  F10_MUTE,
  F11_VOLD,
  F12_VOLU,
};

/*
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
*/

// Fillers to make layering more clear
#define _______ KC_TRNS
#define X KC_NO
#define M_REC   DYN_REC_START1
#define M_STOP  DYN_REC_STOP
#define M_PLAY  DYN_MACRO_PLAY1

qk_tap_dance_action_t tap_dance_actions[] = {
  [F1_PAUS]   = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_PAUS),
  [F2_RCTL]   = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_RCTL),
  [F3_NO]     = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_NO),
  [F4_NO]     = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_NO),
  [F5_PRSC]   = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_PSCR),
  [F6_MPRV]   = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_MPRV),  
  [F7_MPLY]   = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_MPLY),
  [F8_MNXT]   = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_MNXT),
  [F9_NO]     = ACTION_TAP_DANCE_DOUBLE(KC_F9,  KC_NO),
  [F10_MUTE]  = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_MUTE),
  [F11_VOLD]  = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_VOLD),
  [F12_VOLU]  = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_VOLU),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[COLEMAK] = LAYOUT( \
  KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_BSPC,        \
  OSL(NUM),       KC_A,           KC_R,           KC_S,           KC_T,           KC_D,           KC_H,           KC_N,           KC_E,           KC_I,           KC_O,           OSL(NUM),       \
  OSM(MOD_LCTL),  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_K,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        OSM(MOD_RCTL),  \
  OSM(MOD_LGUI),  OSM(MOD_LALT),  KC_LPRN,        KC_LBRC,        OSM(MOD_LSFT),  KC_ENT,         KC_SPC,         OSL(VIM),       KC_RBRC,        KC_RPRN,        OSM(MOD_RALT),  OSM(MOD_RGUI),  \
  X,              X,              X,              X,              X,              X,              X,              X,              X,              X,              X,              X               \
),

[NUM] = LAYOUT( \
  KC_PLUS,        KC_UNDS,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_TILD,        KC_GRV,         KC_7,           KC_8,           KC_9,           KC_MINS,        KC_EQL,         \
  KC_TRNS,        KC_RPRN,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_DQUO,        KC_QUOT,        KC_4,           KC_5,           KC_6,           KC_0,           KC_TRNS,        \
  _______,        KC_PIPE,        KC_EXLM,        KC_AT,          KC_HASH,        _______,        _______,        KC_1,           KC_2,           KC_3,           KC_BSLS,        _______,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______         \
),
/*
[NUM] = LAYOUT( \
  KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DQUO,        \
  KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_QUOT,        \
  _______,        KC_PIPE,        KC_PLUS,        KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_MINS,        KC_EQL,         KC_BSLS,        _______,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______         \
),
*/
/*
[NUM] = LAYOUT( \
  KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PIPE,        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_BSLS,        \
  KC_TRNS,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_DQUO,        KC_QUOT,        KC_5,           KC_6,           KC_7,           KC_8,           KC_TRNS,        \
  KC_LCBR,        KC_LPRN,        KC_RPRN,        KC_UNDS,        KC_PLUS,        KC_RCBR,        KC_LBRC,        KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_RBRC,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______         \
),
*/

[VIM] = LAYOUT( \
  KC_ESC,         TD(F9_NO),      TD(F10_MUTE),   TD(F11_VOLD),   TD(F12_VOLU),   _______,        KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         _______,        KC_DEL,         \
  _______,        TD(F5_PRSC),    TD(F6_MPRV),    TD(F7_MPLY),    TD(F8_MNXT),    _______,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        _______,        _______,        \
  KC_LCTL,        TD(F1_PAUS),    TD(F2_RCTL),    TD(F3_NO),      TD(F4_NO),      _______,        _______,        _______,        _______,        _______,        _______,        KC_RCTL,        \
  _______,        _______,        _______,        KC_LALT,        KC_LGUI,        KC_LSFT,        KC_RSFT,        _______,        KC_RALT,        _______,        _______,        KC_INS,         \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______         \
),

/*
[COLEMAK] = LAYOUT( \
  X,              X,              X,              X,              X,              X,              X,              X,              X,              X,              X,              X,       \
  ALT_T(KC_GRV),  KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_BSLS, \
  CTL_T(KC_ESC),  LSFT_T(KC_A),   KC_R,           KC_S,           KC_T,           KC_D,           KC_H,           KC_N,           KC_E,           KC_I,           RSFT_T(KC_O),   KC_QUOT, \
  KC_LGUI,        KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_K,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_MINS, \
  SH_MON,         X,              KC_LBRC,        KC_RBRC,        NUM_TAB,        VIM_ENT,        KC_SPC,         KC_BSPC,        X,              X,              KC_RCTL,        KC_EQL  \
),

[VIM] = LAYOUT( \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, \
  _______,        M_START,        WD_LEFT,        WD_RGHT,        WD_BSPC,        WD_DEL,         KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         KC_WH_D,        KC_WH_U, \
  _______,        BS_RST,         BS_BTN1,        BS_BTN3,        BS_BTN2,        BS_FINE,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        M_PLAY,         _______, \
  _______,        M_STOP,         KC_DEL,         COPY,           PASTE,          X,              BS_MS_L,        BS_MS_D,        BS_MS_U,        BS_MS_R,        _______,        _______, \
  _______,        _______,        _______,        _______,        RESET,          _______,        _______,        _______,        _______,        _______,        _______,        _______  \
),


[NUM] = LAYOUT( \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, \
  _______,        _______,        TD(F9_NO),      TD(F10_MUTE),   TD(F11_VOLD),   TD(F12_VOLU),   KC_TAB,         KC_7,           KC_8,           KC_9,           _______,        _______, \
  _______,        KC_LSFT,        TD(F5_PRSC),    TD(F6_MPRV),    TD(F7_MPLY),    TD(F8_MNXT),    KC_ENT,         KC_4,           KC_5,           KC_6,           KC_0,           _______, \
  _______,        _______,        TD(F1_PAUS),    TD(F2_RCTL),    TD(F3_NO),      TD(F4_NO),      _______,        KC_1,           KC_2,           KC_3,           _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______  \
),
*/
};

/*
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
*/

LEADER_EXTERNS();
uint8_t leader_last_sequence_index;
int8_t leaxer_sequence_index;
#define LEAXER_SEQUENCE_SIZE 5
uint16_t leaxer_sequence[LEAXER_SEQUENCE_SIZE];
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
bool insert_space = true;
bool leaxer_pressed = false;

void leader_start(void){
        if ( insert_space && !(get_oneshot_mods() & MODS_SHIFT_MASK) ) tap_code(KC_SPC);
	leader_last_sequence_index = -1;
}


void leader_end(void){
	uint8_t i;
	if (leader_last_sequence_index >= 0) {
		tap_code(KC_SPC);
		insert_space = false; /* So that we do not enter two spaces when two macros are called consecutively. */
	}
	for (i=leader_last_sequence_index+1; i<leader_sequence_size; i++){
		/* TODO: this should really only prevent the first space, not all spaces */
		if (leader_sequence[i] != KC_SPC) tap_code(leader_sequence[i]);
	}
}

uint8_t match_leaxer_sequence(){
  if (leaxer_sequence_index < 0) return LEAX_SEQ_INCOMPLETE;
  switch (leaxer_sequence[0]) {
    /*case KC_A:*/
    case LT(VIM,KC_A):
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_D:
          SEND_STRING("and");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("an");
          break;
        /*case KC_R:*/
        case LGUI_T(KC_R):
          SEND_STRING("are");
          break;
        /*case KC_S:*/
        case LALT_T(KC_S):
          SEND_STRING("as");
          break;
        /*case KC_T:*/
        case LCTL_T(KC_T):
          SEND_STRING("at");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_B:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_C:
          SEND_STRING("because");
          break;
        /*case KC_E:*/
        case RALT_T(KC_E):
          SEND_STRING("be");
          break;
        /*case KC_I:*/
        case RGUI_T(KC_I):
          SEND_STRING("being");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("been");
          break;
        case KC_U:
          SEND_STRING("but");
          break;
        case KC_Y:
          SEND_STRING("by");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_C:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_D:
          SEND_STRING("could");
          break;
        case KC_H:
          SEND_STRING("could have");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("can");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_D:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_D:
          SEND_STRING("did");
          break;
        /*case KC_I:*/
        case RGUI_T(KC_I):
          SEND_STRING("doing");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("done");
          break;
        /*case KC_O:*/
        case LT(VIM,KC_O):
          SEND_STRING("do");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    /*case KC_E:*/
    case RALT_T(KC_E):
      SEND_STRING("the");
      break;
    case KC_F:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_M:
          SEND_STRING("from");
          break;
        /*case KC_R:*/
        case LGUI_T(KC_R):
          SEND_STRING("for");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_H:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_D:
          SEND_STRING("had");
          break;
        /*case KC_E:*/
        case RALT_T(KC_E):
          SEND_STRING("he");
          break;
        case KC_M:
          SEND_STRING("him");
          break;
        /*case KC_R:*/
        case LGUI_T(KC_R):
          SEND_STRING("her");
          break;
        /*case KC_S:*/
        case LALT_T(KC_S):
          SEND_STRING("has");
          break;
        case KC_V:
          SEND_STRING("have");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    /*case KC_I:*/
    case RGUI_T(KC_I):
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("in");
          break;
        /*case KC_S:*/
        case LALT_T(KC_S):
          SEND_STRING("is");
          break;
        /*case KC_T:*/
        case LCTL_T(KC_T):
          SEND_STRING("it");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_J:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_H:
          SEND_STRING("Jonathan Harris");
          break;
        case RCTL_T(KC_N):
          SEND_STRING("Jonathan");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_K:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        /*case KC_R:*/
        case LGUI_T(KC_R):
          SEND_STRING("Kind regards,\nJonathan");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_M:
      SEND_STRING("me");
      break;
    /*case KC_N:*/
    case RCTL_T(KC_N):
      SEND_STRING("not");
      break;
    /*case KC_O:*/
    case LT(VIM,KC_O):
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_F:
          SEND_STRING("of");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("on");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    /*case KC_S:*/
    case LALT_T(KC_S):
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_D:
          SEND_STRING("should");
          break;
        /*case KC_E:*/
        case RALT_T(KC_E):
          SEND_STRING("she");
          break;
        case KC_H:
          SEND_STRING("should have");
          break;
        /*case KC_O:*/
        case LT(VIM,KC_O):
          SEND_STRING("so");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    /*case KC_T:*/
    case LCTL_T(KC_T):
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_M:
          SEND_STRING("them");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("than");
          break;
        /*case KC_O:*/
        case LT(VIM,KC_O):
          SEND_STRING("to");
          break;
        /*case KC_R:*/
        case LGUI_T(KC_R):
          SEND_STRING("there");
          break;
        /*case KC_S:*/
        case LALT_T(KC_S):
          SEND_STRING("this");
          break;
        /*case KC_T:*/
        case LCTL_T(KC_T):
          SEND_STRING("that");
          break;
        case KC_Y:
          SEND_STRING("they");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_U:
      SEND_STRING("us");
      break;
    case KC_V:
      SEND_STRING("very");
      break;
    case KC_W:
      if (leaxer_sequence_index < 1) return LEAX_SEQ_INCOMPLETE;
      switch (leaxer_sequence[1]) {
        case KC_C:
          SEND_STRING("which");
          break;
        case KC_D:
          SEND_STRING("would");
          break;
        /*case KC_E:*/
        case RALT_T(KC_E):
          SEND_STRING("were");
          break;
        case KC_H:
          SEND_STRING("would have");
          break;
        /*case KC_I:*/
        case RGUI_T(KC_I):
          SEND_STRING("with");
          break;
        case KC_L:
          SEND_STRING("will");
          break;
        /*case KC_N:*/
        case RCTL_T(KC_N):
          SEND_STRING("when");
          break;
        /*case KC_R:*/
        case LGUI_T(KC_R):
          SEND_STRING("where");
          break;
        /*case KC_S:*/
        case LALT_T(KC_S):
          SEND_STRING("was");
          break;
        /*case KC_T:*/
        case LCTL_T(KC_T):
          SEND_STRING("what");
          break;
        default:
	  return LEAX_NO_MATCH;
      }
      break;
    case KC_Y:
      SEND_STRING("you");
      break;
    default:
      return LEAX_NO_MATCH;
  }
  return LEAX_MATCH;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint8_t i;
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

/*
  if ( !process_binary_search(keycode,record) ) {
    return false;
  }
*/
  if (record->event.pressed) {
    if (leaxer_pressed){
      leaxer_pressed=false;
      ++leaxer_sequence_index;
      if (leaxer_sequence_index < LEAXER_SEQUENCE_SIZE){
        leaxer_sequence[leaxer_sequence_index] = keycode;
	switch (match_leaxer_sequence()) {
	  case LEAX_MATCH:
            tap_code(KC_SPC);
            leaxer_pressed = false;
	    leaxer_sequence_index = -1;
            insert_space = false; /* So that we do not enter two spaces when two macros are called consecutively. */
	    return false;
	  case LEAX_NO_MATCH:
            for (i=0; i<=leaxer_sequence_index; i++){
              tap_code(leaxer_sequence[i]);
            }
            leaxer_pressed = false;
	    leaxer_sequence_index = -1;
	    break;
	  case LEAX_SEQ_INCOMPLETE:
	    /* do nothing. We need to wait for more characters. */
	    return false;
	}
      } else {
        for (i=0; i<leaxer_sequence_index; i++){
          tap_code(leaxer_sequence[i]);
        }
        leaxer_pressed = false;
     }
    }

    switch (keycode) {
      case KC_SPC: /* If the previous key was whitespace, then we don't want to insert it for the next one */
      case KC_BSPC:
      case KC_ENT:
      case KC_TAB:
	insert_space = false;
	break;
      case KC_LEAX:
        if ( insert_space && !(get_oneshot_mods() & MODS_SHIFT_MASK) ) tap_code(KC_SPC);
	/* Pressing the leader key should not have any impact on whether we insert a space */
	leaxer_pressed = true;
	leaxer_sequence_index = -1;
	return false;
      case KC_LEAD:
	/* Pressing the leader key should not have any impact on whether we insert a space */
	break;
      default:
	insert_space = true;
	break;
    }

  }
  return true;
}
