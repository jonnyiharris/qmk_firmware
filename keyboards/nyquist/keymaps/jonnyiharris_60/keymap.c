#include QMK_KEYBOARD_H
#include "pointing_device.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define COLEMAK 0
#define NUM 1
#define VIM 2
#define COM 3

enum custom_keycodes {
  BS_MS_L = SAFE_RANGE,
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
  COM_THE,
  COM_OF,
  COM_AND,
  COM_TO,
  COM_IN,
  COM_THAT,
  COM_WAS,
  COM_WITH,
  COM_FOR,
  COM_HAD,
  COM_YOU,
  COM_WHICH,
  COM_HAVE,
  COM_FROM,
  COM_THIS,
  COM_ARE,
  COM_WILL,
  COM_WOULD,
  COM_THERE,
  COM_COULD,
  COM_SHOULD,
};

#include "dynamic_macro.h"

enum tapdance_codes {
  F1_PAUS = 0,
  F2_RCTL,
  F3_NO,
  F4_NO,
  F5_PRSC,
  F6_NO,
  F7_MPRV,
  F8_MPLY,
  F9_MNXT,
  F10_MUTE,
  F11_VOLD,
  F12_VOLU,
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
//#define M_REC   DYN_REC_START1
//#define M_STOP  DYN_REC_STOP
#define M_REC   DYN_REC_STOP
#define M_PLAY  DYN_MACRO_PLAY1

qk_tap_dance_action_t tap_dance_actions[] = {
  [F1_PAUS]   = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_PAUS),
  [F2_RCTL]   = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_RCTL),
  [F3_NO]     = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_NO),
  [F4_NO]     = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_NO),
  [F5_PRSC]   = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_PSCR),
  [F6_NO]     = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_NO),  
  [F7_MPRV]   = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_MPRV),
  [F8_MPLY]   = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_MPLY),
  [F9_MNXT]   = ACTION_TAP_DANCE_DOUBLE(KC_F9,  KC_MNXT),
  [F10_MUTE]  = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_MUTE),
  [F11_VOLD]  = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_VOLD),
  [F12_VOLU]  = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_VOLU),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[COLEMAK] = LAYOUT( \
  KC_TAB,         KC_Q,           KC_W,           KC_F,           KC_P,           KC_G,           KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCLN,        KC_BSPC, \
  OSL(NUM),       LT(VIM,KC_A),   LGUI_T(KC_R),   LALT_T(KC_S),   LCTL_T(KC_T),   KC_D,           KC_H,           RCTL_T(KC_N),   RALT_T(KC_E),   RGUI_T(KC_I),   LT(VIM,KC_O),   OSL(NUM),  \
  KC_ESC,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_K,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_ENT,                \
  X,              X,              X,              X,              _______,        OSM(MOD_LSFT),  KC_SPC,         KC_LEAD,        X,              X,              X,              X,           \
  X,              X,              X,              X,              X,              X,              X,              X,              X,              X,              X,              X        \
),

[NUM] = LAYOUT( \
  KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_DQUO,        \
  KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_QUOT,        \
  _______,        KC_PIPE,        KC_PLUS,        KC_UNDS,        KC_LCBR,        KC_RCBR,        KC_LBRC,        KC_RBRC,        KC_MINS,        KC_EQL,         KC_BSLS,        _______,        \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______  \
),
/*
[NUM] = LAYOUT( \
  KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PIPE,        KC_GRV,         KC_1,           KC_2,           KC_3,           KC_4,           KC_BSLS, \
  KC_TRNS,        KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_DQUO,        KC_QUOT,        KC_5,           KC_6,           KC_7,           KC_8,           KC_TRNS, \
  KC_LCBR,        KC_LPRN,        KC_RPRN,        KC_UNDS,        KC_PLUS,        KC_RCBR,        KC_LBRC,        KC_9,           KC_0,           KC_MINS,        KC_EQL,         KC_RBRC,  \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______  \
),
*/

[VIM] = LAYOUT( \
  TD(F7_MPRV),    TD(F8_MPLY),    TD(F9_MNXT),    TD(F10_MUTE),   TD(F11_VOLD),   TD(F12_VOLU),   KC_HOME,        KC_PGDN,        KC_PGUP,        KC_END,         _______,        _______, \
  _______,        KC_TRNS,        KC_LGUI,        KC_LALT,        KC_LCTL,        _______,        KC_LEFT,        KC_DOWN,        KC_UP,          KC_RGHT,        KC_TRNS,        _______, \
  TD(F1_PAUS),    TD(F2_RCTL),    TD(F3_NO),      TD(F4_NO),      TD(F5_PRSC),    TD(F6_NO),      M_REC,          LCTL(KC_INS),   LSFT(KC_INS),   M_PLAY,         _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______  \
),

[COM] = LAYOUT( \
  _______,        COM_TO,         COM_WITH,       COM_FOR,        _______,        _______,        _______,        COM_WILL,       COM_WOULD,      COM_YOU,        _______,        _______, \
  _______,        COM_AND,        COM_ARE,        COM_WAS,        COM_THE,        COM_HAD,        COM_THAT,       COM_IN,         COM_THERE,      COM_THIS,       _______,        _______, \
  _______,        COM_SHOULD,     COM_OF,         COM_COULD,      COM_HAVE,       COM_WHICH,      _______,        COM_FROM,       _______,        _______,        _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______, \
  _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______,        _______  \
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
#define MODS_SHIFT_MASK (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
bool insert_space = true;


void matrix_scan_user(void){
	LEADER_DICTIONARY(){
		leading = false;

		leader_last_sequence_index = 0;

		switch (leader_sequence[leader_last_sequence_index]) {
			case KC_A:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_D:
						SEND_STRING("and");
						break;
					case KC_N:
						SEND_STRING("an");
						break;
					case KC_R:
						SEND_STRING("are");
						break;
					case KC_S:
						SEND_STRING("as");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("a");
						break;
				}
				break;
			case KC_B:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_C:
						SEND_STRING("because");
						break;
					case KC_U:
						SEND_STRING("but");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("be");
						break;
				}
				break;
			case KC_C:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_D:
						SEND_STRING("could");
						break;
					case KC_H:
						SEND_STRING("could have");
						break;
					case KC_N:
						SEND_STRING("can");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("can");
						break;
				}
				break;
			case KC_D:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_D:
						SEND_STRING("did");
						break;
					case KC_N:
						SEND_STRING("done");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("do");
						break;
				}
				break;
			case KC_E:
				SEND_STRING("the");
				break;
			case KC_F:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_M:
						SEND_STRING("from");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("for");
						break;
				}
				break;
			case KC_H:
				SEND_STRING("had");
				break;
			case KC_I:
				SEND_STRING("in");
				break;
			case KC_K:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_R:
						SEND_STRING("Kind regards,\nJonathan");
						break;
					default:
						leader_last_sequence_index=-1;
						break;
				}
				break;
			case KC_O:
				SEND_STRING("on");
				break;
			case KC_S:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_D:
						SEND_STRING("should");
						break;
					case KC_H:
						SEND_STRING("should have");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("so");
						break;
				}
				break;
			case KC_T:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_R:
						SEND_STRING("there");
						break;
					case KC_S:
						SEND_STRING("this");
						break;
					case KC_T:
						SEND_STRING("that");
						break;
					default:
						--leader_last_sequence_index;
						SEND_STRING("to");
						break;
				}
				break;
			case KC_W:
				++leader_last_sequence_index;
				switch (leader_sequence[leader_last_sequence_index]) {
					case KC_C:
						SEND_STRING("which");
						break;
					case KC_D:
						SEND_STRING("would");
						break;
					case KC_E:
						SEND_STRING("were");
						break;
					case KC_H:
						SEND_STRING("would have");
						break;
					case KC_I:
						SEND_STRING("with");
						break;
					case KC_L:
						SEND_STRING("will");
						break;
					case KC_R:
						SEND_STRING("where");
						break;
					case KC_S:
						SEND_STRING("was");
						break;
					case KC_T:
						SEND_STRING("what");
						break;
					default:
						leader_last_sequence_index=-1;
						break;
				}
				break;
			default:
				leader_last_sequence_index=-1;
				break;
		}

		leader_end();
	}
}

void leader_start(void){
        if ( insert_space && !(get_oneshot_mods() & MODS_SHIFT_MASK) ) tap_code(KC_SPC);
	leader_last_sequence_index = -1;
}


void leader_end(void){
	uint8_t i;
	if (leader_last_sequence_index >= 0) {
		tap_code(KC_SPC);
		insert_space = 0; /* So that we do not enter two spaces when two macros are called consecutively. */
	}
	for (i=leader_last_sequence_index+1; i<leader_sequence_size; i++){
		tap_code(leader_sequence[i]);
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
/*
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  if ( !process_binary_search(keycode,record) ) {
    return false;
  }
*/
  if (record->event.pressed && keycode != OSL(COM)) {
    switch (keycode) {
      case COM_THE:
      case COM_WHICH:
      case COM_TO:
      case COM_OF:
      case COM_AND:
      case COM_YOU:
      case COM_THAT:
      case COM_WAS:
      case COM_ARE:
      case COM_WITH:
      case COM_HAVE:
      case COM_HAD:
      case COM_FOR:
      case COM_IN:
      case COM_THIS:
      case COM_FROM:
      case COM_WILL:
      case COM_WOULD:
      case COM_THERE:
      case COM_COULD:
      case COM_SHOULD:
        if ( insert_space && !(get_oneshot_mods() & MODS_SHIFT_MASK) ) SEND_STRING(" ");
        /* fall through */
      case KC_SPC: /* If the previous key was whitespace, then we don't want to insert it for the next one */
      case KC_ENT:
      case KC_TAB:
	insert_space = false;
	break;
      case KC_LEAD:
	/* Pressing the leader key should not have any impact on whether we insert a space */
	break;
      default:
	insert_space = true;
	break;
    }
    switch (keycode) {
      case COM_THE:
        SEND_STRING("the ");
        break;

      case COM_WHICH:
        SEND_STRING("which ");
        break;

      case COM_TO:
        SEND_STRING("to ");
        break;

      case COM_OF:
        SEND_STRING("of ");
        break;

      case COM_AND:
        SEND_STRING("and ");
        break;

      case COM_YOU:
        SEND_STRING("you ");
        break;

      case COM_THAT:
        SEND_STRING("that ");
        break;

      case COM_WAS:
        SEND_STRING("was ");
        break;

      case COM_ARE:
        SEND_STRING("are ");
        break;

      case COM_WITH:
        SEND_STRING("with ");
        break;

      case COM_HAVE:
	SEND_STRING("have ");
        break;

      case COM_HAD:
	SEND_STRING("had ");
        break;

      case COM_FOR:
	SEND_STRING("for ");
        break;

      case COM_IN:
	SEND_STRING("in ");
        break;

      case COM_THIS:
	SEND_STRING("this ");
        break;

      case COM_FROM:
	SEND_STRING("from ");
        break;

      case COM_WILL:
	SEND_STRING("will ");
        break;

      case COM_WOULD:
	SEND_STRING("would ");
        break;

      case COM_THERE:
	SEND_STRING("there ");
        break;

      case COM_COULD:
	SEND_STRING("could ");
        break;

      case COM_SHOULD:
	SEND_STRING("should ");
        break;

    }
  }
  return true;
}
