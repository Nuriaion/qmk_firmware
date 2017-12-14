// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"
#include "keymap_german_ch.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _LEFT 1
#define _RIGHT 2
#define _RESET 3

#define LCTRLP MT(KC_LCTRL, CH_LPRN)

//Tap Dance Declarations
enum {
    TD_CTRL_PO = 0
  , CT_LEFT
  , CT_RIGHT
};

void dance_left_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
		// {
    register_code (KC_RALT);
    register_code (CH_AE);
  } else if(state->count == 2) {
		// <
    register_code (CH_LESS);
  } else {
		// [
    register_code (KC_RALT);
    register_code (CH_UE);
  }
}

void dance_left_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
		// {
    unregister_code (KC_RALT);
    unregister_code (CH_AE);
  } else if(state->count == 2) {
		// <
    unregister_code (CH_LESS);
  } else {
		// [
    unregister_code (KC_RALT);
    unregister_code (CH_UE);
  }
}

void dance_right_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
		// }
    register_code (KC_RALT);
    register_code (CH_DLR);
  } else if(state->count == 2) {
		// >
    register_code (KC_LSHIFT);
    register_code (CH_LESS);
  } else {
		// ]
    register_code (KC_RALT);
    register_code (CH_DIER);
  }
}

void dance_right_reset (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
		// }
    unregister_code (KC_RALT);
    unregister_code (CH_DLR);
  } else if(state->count == 2) {
		// >
    unregister_code (KC_LSHIFT);
    unregister_code (CH_LESS);
  } else {
		// ]
    unregister_code (KC_RALT);
    unregister_code (CH_DIER);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
    [TD_CTRL_PO]  = ACTION_TAP_DANCE_DOUBLE(CH_LCBR, KC_ENTER)
  , [CT_LEFT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_left_finished, dance_left_reset)
  , [CT_RIGHT] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_right_finished, dance_right_reset)

// Other declarations would go here, separated by commas, if you have them
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
		{ CH_PARA,  KC_1,        KC_2,    KC_3,    KC_4,       KC_5,    KC_TRNS,        KC_6,   KC_7,        KC_8,    KC_9,    KC_0,          CH_QUOT },
		{ KC_TAB,   KC_Q,        KC_W,    KC_E,    KC_R,       KC_T,    KC_TRNS,        KC_Y,   KC_U,        KC_I,    KC_O,    KC_P,          CH_CARR },
		{ KC_LCTRL, KC_A,        KC_S,    KC_D,    KC_F,       KC_G,    KC_TRNS,        KC_H,   KC_J,        KC_K,    KC_L,    CH_OE,         KC_RCTRL },
		{ KC_LSPO,  CH_Y,        KC_X,    KC_C,    KC_V,       KC_B,    KC_BSPC,        KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH,       KC_RSPC },
		{ KC_LALT,  TD(CT_LEFT), KC_LALT, KC_LGUI, OSL(_LEFT), KC_ESC,         KC_ENT, KC_SPC, OSL(_RIGHT), KC_RGUI, KC_QUOT, TD(CT_RIGHT),  CH_ALGR }
},

[_LEFT] = { 
		{ TO(_RESET), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS  },
		{ KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CH_UE },
		{ KC_TRNS,    CH_LCBR, CH_LESS, CH_LBRC, KC_PGDN, KC_PGUP, KC_TRNS,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CH_OE,   CH_AE },
		{ KC_TRNS,    CH_RING, KC_1,    KC_MUTE, KC_VOLU, KC_VOLD, KC_DEL,            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},

[_RIGHT] = {
		{ KC_TRNS,  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_TRNS,            KC_F16,  KC_F17,  KC_F18,  KC_F19,     KC_F20,  KC_TRNS },
		{ KC_TRNS,  CH_PAST, CH_HASH, CH_PLUS, CH_MINS, CH_AMPR, KC_TRNS,            CH_DQOT, CH_QUOT, CH_BSLS, CH_SLSH,    CH_QST,  CH_EXLM },
		{ KC_TRNS,  CH_RCBR, CH_MORE, CH_RBRC, KC_PGDN, KC_PGUP, KC_TRNS,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,    CH_AT,   CH_DLR },
		{ KC_TRNS,  CH_PERC, CH_LBRC, CH_RBRC, KC_TRNS, CH_TILD, KC_DEL,             CH_BRBR, CH_GRV,  CH_ACUT, CH_EQL,     KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS }
},

[_RESET] = {
		{ TO(_DEFAULT),  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   },
		{ KC_NO  ,       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , RESET }
}


/*
[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

/*const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};*/
