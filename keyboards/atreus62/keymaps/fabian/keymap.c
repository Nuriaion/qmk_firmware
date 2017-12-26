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
  TD_ESC_CAPS = 0,
  TD_COMPLEX = 1
};

void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_COMPLEX] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset)
// Other declarations would go here, separated by commas, if you have them
};

//In Layer declaration, add tap dance item in place of a key code
//TD(TD_ESC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
		{ TD(TD_ESC_CAPS),  KC_1,        KC_2,    KC_3,    KC_4,       KC_5,    KC_TRNS,        KC_6,   KC_7,        KC_8,    KC_9,    KC_0,          CH_QUOT },
		{ KC_TAB,   KC_Q,        KC_W,    KC_E,    KC_R,       KC_T,    KC_TRNS,        KC_Y,   KC_U,        KC_I,    KC_O,    KC_P,          CH_CARR },
		{ KC_LCTRL, KC_A,        KC_S,    KC_D,    KC_F,       KC_G,    KC_TRNS,        KC_H,   KC_J,        KC_K,    KC_L,    CH_OE,         KC_RCTRL },
		{ KC_LSPO,  CH_Y,        KC_X,    KC_C,    KC_V,       KC_B,    KC_BSPC,        KC_N,   KC_M,        KC_COMM, KC_DOT,  KC_SLSH,       KC_RSPC },
		{ KC_LALT,  TD(TD_COMPLEX), KC_LALT, KC_LGUI, OSL(_LEFT), KC_ESC,         KC_ENT, KC_SPC, OSL(_RIGHT), KC_RGUI, KC_QUOT, /*TD(CT_RIGHT)*/KC_1,  CH_ALGR }
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

//**************** Definitions needed for quad function to work *********************//
//Enums used to clearly convey the state of the tap dance
enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
  // Add more enums here if you want for triple, quadruple, etc.
};

typedef struct {
  bool is_press_action;
  int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
    if (state->interrupted || state->pressed==0) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
  //with single tap. In example below, that means to send `xx` instead of `Escape`.
  else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return 6; //magic number. At some point this method will expand to work for more presses
}

//**************** Definitions needed for quad function to work *********************//

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_X); break;
    case SINGLE_HOLD: register_code(KC_LCTRL); break;
    case DOUBLE_TAP: register_code(KC_ESC); break;
    case DOUBLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_X); unregister_code(KC_X); register_code(KC_X);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_X); break;
    case SINGLE_HOLD: unregister_code(KC_LCTRL); break;
    case DOUBLE_TAP: unregister_code(KC_ESC); break;
    case DOUBLE_HOLD: unregister_code(KC_LALT);
    case DOUBLE_SINGLE_TAP: unregister_code(KC_X);
  }
  xtap_state.state = 0;
}
