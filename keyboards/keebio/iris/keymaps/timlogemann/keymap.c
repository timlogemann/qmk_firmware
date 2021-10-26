#include QMK_KEYBOARD_H

#define _ KC_NO

/**
 *  Combos
 * */
const uint16_t PROGMEM caplock_combo[] = {KC_LALT, KC_LSFT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(caplock_combo, KC_CAPS)};

/**
 *  Key overrides
 * */
// backspace+shift = delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPACE, KC_DELETE);
// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRAVE));
// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_GUI, KC_ESC, KC_GRAVE);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &tilde_esc_override,
    &grave_esc_override,
    NULL // Null terminate the array of overrides!
};


/**
 *  Layer maps
 * */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default
    [0] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,                               KC_6,       KC_7,   KC_8,  KC_9,    KC_0,   KC_BSPC,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                               KC_Y,    KC_U,      KC_I,   KC_O,   KC_P,    KC_EQUAL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                    KC_H,    KC_J,      KC_K,   KC_L,   LT(2, KC_SCLN), KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_GRAVE, KC_LCTL,  KC_Z,   KC_X,   KC_C,   KC_V,_,     _,               KC_B,    KC_N,    KC_M,   KC_COMM, MT(MOD_RCTL, KC_DOT),  KC_SLSH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_LAPO, KC_LGUI,     LT(3, KC_ENT),    KC_SPC,   LT(1, KC_ENT),      KC_RAPC
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    //
    [1] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRAVE,   KC_F1,   KC_F2,    KC_F3,  KC_F4,     _,                                  _,       KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,      KC_RBRC,      KC_DEL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,  KC_F5,   KC_F6,  KC_F7,  KC_F8,   TT(2),                          KC_VOLU,    KC_PGUP,  KC_UP, KC_PGDN,    _,     KC_MINUS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,   KC_F9,   KC_F10, KC_F11, KC_F12,  _,                                  KC_VOLD,    KC_LEFT, KC_DOWN, KC_RGHT,    _,     KC_PAST,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS, KC_TRNS,   _,       _,       _,       _,       _,                _,    KC_MINUS, KC_HOME,   _,     KC_END, KC_TRNS, KC_BSLASH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                LALT_T(KC_LBRC),    KC_TRNS,    KC_TRNS,            KC_TRNS,     KC_TRNS, RALT_T(KC_RBRC)
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    [2] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            TO(0),     _,    KC_TRNS,    _,       _,     RGB_TOG,                               _,       _,       _,       _,       _,        _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,   _,      _, _, _, _,                              KC_MS_WH_UP, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _, _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,   _,       _,       _,       _,       _,                                KC_MS_WH_DOWN, KC_MS_L, KC_MS_D, KC_MS_R, _,   _,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              _,    KC_LEAD, KC_TRNS,    _,       _,       _,       _,                _,       _,     KC_MS_WH_LEFT, _, KC_MS_WH_RIGHT,    _, _,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            _,      RGB_RMOD,     KC_TRNS,           KC_TRNS,    RGB_MOD,   _
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    [3] = LAYOUT(KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LPRN,KC_LEFT_CURLY_BRACE,KC_LBRC,KC_LEFT_ANGLE_BRACKET,KC_TRNS,KC_TRNS,KC_RIGHT_ANGLE_BRACKET,KC_RBRC,KC_RIGHT_CURLY_BRACE,KC_RPRN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
    [4] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,     _,      _,       _,       _,       _,                                  _,       _,      _,      KC_LBRC, KC_RBRC,   _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,     _,      _,      KC_UP,   _,        _,                                  _,       _,      _,        _,       _,       _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT,    _,    KC_LEFT, KC_DOWN, KC_RGHT,   _,                                  _,       _,       _,       _,       _,       _,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LCTL, KC_TRNS,   _,       _,       _,       _,       _,                _,       _,       _,      _,        _,       _,       _,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_LAPO, KC_LGUI,     KC_SPC,           KC_ENT,         _,      _
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
};
