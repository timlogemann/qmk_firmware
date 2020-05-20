#include QMK_KEYBOARD_H

#define _1L 0
#define _2L 1
#define _3L 2
// #define _G_AC 3

#define HP_GR HYPR_T(KC_GRAVE)
#define MH_DT MEH_T(KC_DOT)
#define SHFT_CPS LSFT_T(OSM(MOD_LSFT))
#define SHFT_QT RSFT_T(KC_QUOT)
#define L_ALT KC_LAPO
#define R_ALT KC_RAPC
#define CTL_OSL MT(MOD_LCTL, OSL(_2L))
#define TAB_DANCE LT(2, KC_TAB)
#define _ KC_NO

#define VOLDOWN KC__VOLDOWN
#define VOLUP KC__VOLUP
#define PLPS KC_MEDIA_PLAY_PAUSE
#define FWD KC_MEDIA_FAST_FORWARD
#define RWD KC_MEDIA_REWIND

// Mouse keys
#define MS_UP KC_MS_UP
#define MS_DN KC_MS_D
#define MS_LT KC_MS_L
#define MS_RT KC_MS_R
#define MS_B1 KC_MS_BTN1
#define MS_B2 KC_MS_BTN2
#define MS_B3 KC_MS_BTN3
#define MS_B4 KC_MS_BTN4
#define MS_B5 KC_MS_BTN5
#define MS_SU KC_MS_WH_UP
#define MS_SD KC_MS_WH_DOWN
#define MS_SL KC_MS_WH_LEFT
#define MS_SR KC_MS_WH_RIGHT


typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum { SINGLE_TAP = 1, SINGLE_HOLD = 2, DOUBLE_TAP = 3, DOUBLE_HOLD = 4, DOUBLE_SINGLE_TAP = 5, TRIPLE_TAP = 6, TRIPLE_HOLD = 7 };

// Tap dance enums
enum { X_LALT = 0 };

int cur_dance(qk_tap_dance_state_t *state);

//for the x tap dance. Put it here so it can be used in any keymap
void x_finished (qk_tap_dance_state_t *state, void *user_data);
void x_reset (qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_1L] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,                               KC_6,    KC_7,      KC_8,   KC_9,   KC_0,    KC_BSPC,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                               KC_Y,    KC_U,      KC_I,   KC_O,   KC_P,    KC_EQUAL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            SHFT_CPS, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                               KC_H,    KC_J,      KC_K,   KC_L,   KC_SCLN, KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            CTL_OSL, HP_GR,    KC_Z,    KC_X,   KC_C,   KC_V,       _,                _,    KC_B,    KC_N,      KC_M,   KC_COMM, MH_DT,  KC_SLSH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            L_ALT, TD(X_LALT),     KC_ENT,          KC_SPC,      TT(_2L), R_ALT
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),

    [_2L] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GESC, KC_F1,    KC_F2, KC_F3,    KC_F4,  KC_F5,                                 KC_F6,   KC_F7,  KC_F8,  KC_F9,  KC_F10,   KC_DEL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,  KC_F11, KC_F12,  VOLUP,    _,    TO(_3L),                               _,    KC_PGUP,   KC_UP, KC_PGDN,    _,     KC_MINUS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,  _,       RWD,     PLPS,    FWD,      _,                                  _,    KC_LEFT, KC_DOWN, KC_RGHT,    _,     KC_PAST,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS, KC_TRNS,   _,    VOLDOWN,    _,      +KC_PLUS, _,                _,    KC_MINUS, KC_HOME, _,       KC_END, KC_TRNS, KC_BSLASH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                LALT_T(KC_LBRC),    KC_TRNS,    KC_TRNS,            KC_TRNS,     KC_TRNS, RALT_T(KC_RBRC)
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    [_3L] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            TO(_1L), KC_1,    KC_2,     KC_3,   _,          _,                                  _,       _,      _,      _,          _,      _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS, KC_4,      KC_5,   KC_6,   _,          _,                              MS_SU,      MS_SL, MS_UP,   MS_SR,      _,      _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS, KC_7,      KC_8,   KC_9,   _,          _,                              MS_SD,      MS_LT, MS_DN,   MS_RT,      _,      _,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              _,    KC_MINUS,   KC_0,   KC_PLUS, _,         _,      _,                  _,  _,          MS_B1, MS_B2,   MS_B3,  MS_B4,      _,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            _,        _,          KC_TRNS,              _,          _,      _
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),

    // [_G_AC] = LAYOUT(
    //     //┌────────┬────────┬────────┬────────┬────────┬────────┐
    //         KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,  KC_GRAVE,                            _, _, _, _, _, _,
    //     //├────────┼────────┼────────┼────────┼────────┼────────┤
    //         KC_T,     KC_G,    KC_Q,    KC_W,    KC_E,    KC_R,                              _, _, _, _, _, _,
    //     //├────────┼────────┼────────┼────────┼────────┼────────┤
    //           _,       _,      KC_A,    KC_S,    KC_D,     _,                              _, _, _, _, _, _,
    //     //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
    //           KC_M,    KC_Z,   KC_X,    KC_C,     KC_X,     KC_V,      _,                  _, _, _, _, _, _, _,
    //     //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤
    //                                         KC_F,     KC_SPACE,     KC_LSHIFT,              TO(_1L), _, _
                                       //└────────┴────────┘    └────────┘
    )

};

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8; //magic number. At some point this method will expand to work for more presses
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    case SINGLE_TAP: register_code(KC_LPRN); break;
    case SINGLE_HOLD: register_code(KC_LALT); break;
    case DOUBLE_TAP: register_code(KC_LCBR); break;
    case DOUBLE_HOLD: register_code(KC_LCBR); unregister_code(KC_LCBR); register_code(KC_LCBR); break;
    case DOUBLE_SINGLE_TAP: register_code(KC_LPRN); unregister_code(KC_LPRN); register_code(KC_LPRN);
    //Last case is for fast typing. Assuming your key is `f`:
    //For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
    //In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
  }
}

void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case SINGLE_TAP: unregister_code(KC_LPRN); break;
    case SINGLE_HOLD: unregister_code(KC_LALT); break;
    case DOUBLE_TAP: unregister_code(KC_LCBR); break;
    case DOUBLE_HOLD: unregister_code(KC_LCBR); break;
    case DOUBLE_SINGLE_TAP: unregister_code(KC_LPRN);
  }
  xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [X_LALT]     = ACTION_TAP_DANCE_FN_ADVANCED(NULL,x_finished, x_reset)
};
