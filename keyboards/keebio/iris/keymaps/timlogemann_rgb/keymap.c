#include QMK_KEYBOARD_H

#define _ KC_NO

#define _QWERTY 0
#define _MEDIA_ARROWS 1
#define _MOUSE 2
#define _BRACKETS 3
#define _GAME 4


/**
 *  RGB Layers
 * */
const rgblight_segment_t PROGMEM rgb_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM rgb_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_CYAN},
    {6, 6, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM rgb_media_arrows_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_PURPLE},
    {6, 6, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM rgb_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_ORANGE},
    {6, 6, HSV_ORANGE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_capslock_layer,
    rgb_qwerty_layer,
    rgb_media_arrows_layer,
    rgb_mouse_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _MEDIA_ARROWS));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MOUSE));
    return state;
}

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
    [_QWERTY] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,                               KC_6,       KC_7,   KC_8,  KC_9,    KC_0,   KC_BSPC,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                               KC_Y,    KC_U,      KC_I,   KC_O,   KC_P,    KC_EQUAL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                    KC_H,    KC_J,      KC_K,   KC_L,   LT(_MOUSE, KC_SCLN), KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_GRAVE, KC_LCTL,  KC_Z,   KC_X,   KC_C,   KC_V,KC_TRNS,     KC_TRNS,               KC_B,    KC_N,    KC_M,   KC_COMM, MT(MOD_RCTL, KC_DOT),  KC_SLSH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_LAPO, KC_LGUI,     LT(_BRACKETS, KC_ENT),    KC_SPC,       MO(_MEDIA_ARROWS),  KC_RAPC
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    //
    [_MEDIA_ARROWS] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRAVE,   KC_F1,   KC_F2,    KC_F3,  KC_F4,     KC_TRNS,                                  KC_TRNS,       KC_MEDIA_PREV_TRACK,    KC_MEDIA_PLAY_PAUSE,    KC_MEDIA_NEXT_TRACK,      KC_RBRC,      KC_DEL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,  KC_F5,   KC_F6,  KC_F7,  KC_F8,   TT(_MOUSE),                          KC_VOLU,    KC_PGUP,  KC_UP, KC_PGDN,    KC_TRNS,     KC_MINUS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,   KC_F9,   KC_F10, KC_F11, KC_F12,  KC_TRNS,                                  KC_VOLD,    KC_LEFT, KC_DOWN, KC_RGHT,    KC_TRNS,     KC_PAST,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS, KC_TRNS,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                KC_TRNS,    KC_MINUS, KC_HOME,   KC_TRNS,     KC_END, KC_TRNS, KC_BSLASH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                LALT_T(KC_LBRC),    KC_TRNS,    KC_TRNS,            KC_TRNS,     KC_TRNS, RALT_T(KC_RBRC)
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    [_MOUSE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            TO(_QWERTY),     KC_TRNS,    KC_TRNS,    KC_TRNS,       KC_TRNS,     RGB_TOG,                               KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,   KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                              KC_MS_WH_UP, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_TRNS, KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_CAPS_LOCK,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                KC_MS_WH_DOWN, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,   KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              KC_TRNS,    KC_LEAD, KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                KC_TRNS,       KC_TRNS,     KC_MS_WH_LEFT, KC_TRNS, KC_MS_WH_RIGHT,    KC_TRNS, KC_TRNS,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_TRNS,      RGB_RMOD,     KC_TRNS,           KC_TRNS,    RGB_MOD,   KC_TRNS
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    [_BRACKETS] = LAYOUT(KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_LPRN,KC_LEFT_CURLY_BRACE,KC_LBRC,KC_LEFT_ANGLE_BRACKET,KC_TRNS,KC_TRNS,KC_RIGHT_ANGLE_BRACKET,KC_RBRC,KC_RIGHT_CURLY_BRACE,KC_RPRN,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
    [_GAME] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,     KC_TRNS,      KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                                  KC_TRNS,       KC_TRNS,      KC_TRNS,      KC_LBRC, KC_RBRC,   KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,     KC_TRNS,      KC_TRNS,      KC_UP,   KC_TRNS,        KC_TRNS,                                  KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT,    KC_TRNS,    KC_LEFT, KC_DOWN, KC_RGHT,   KC_TRNS,                                  KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LCTL, KC_TRNS,   KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,                KC_TRNS,       KC_TRNS,       KC_TRNS,      KC_TRNS,        KC_TRNS,       KC_TRNS,       KC_TRNS,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_LAPO, KC_LGUI,     KC_SPC,           KC_ENT,         KC_TRNS,      KC_TRNS
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
};
