#include QMK_KEYBOARD_H

#define _ KC_NO

/* Combos */
const uint16_t PROGMEM caplock_combo[] = {KC_LAPO, KC_LSFT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(caplock_combo, KC_CAPS)};


// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        static bool delkey_registered;
        if (record->event.pressed) {
            // Detect the activation of either shift keys
            if (mod_state & MOD_MASK_SHIFT) {
                // First temporarily canceling both shifts so that
                // shift isn't applied to the KC_DEL keycode
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                // Update the boolean variable to reflect the status of KC_DEL
                delkey_registered = true;
                // Reapplying modifier state so that the held shift key(s)
                // still work even after having tapped the Backspace/Delete key.
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            // In case KC_DEL is still being sent even after the release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;
    }

    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default
    [0] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_ESC,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,                               KC_6,       KC_7,   KC_8,  KC_9,    KC_0,   KC_BSPC,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,                               KC_Y,    KC_U,      KC_I,   KC_O,   KC_P,    KC_EQUAL,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            MT(MOD_LSFT, KC_TAB), KC_A,    KC_S,    KC_D,   KC_F,   KC_G,                               KC_H,    KC_J,      KC_K,   KC_L,   KC_SCLN, KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            KC_LSFT, MT(MOD_LCTL, KC_GRAVE),  KC_Z,   KC_X,   KC_C,   KC_V,       _,                _,    KC_B,    KC_N,      KC_M,   KC_COMM, KC_DOT,  KC_SLSH,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            KC_LAPO, KC_LGUI,     LT(3, KC_ENT), KC_SPC,   TT(1), LT(4,  KC_LBRC)
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
            KC_TRNS,   _,      MAGIC_TOGGLE_CTL_GUI, _, _, _,                              KC_MS_WH_UP, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, _, _,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
            KC_TRNS,   _,       _,       _,       _,       _,                                KC_MS_WH_DOWN, KC_MS_L, KC_MS_D, KC_MS_R, _,   _,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
              _,    KC_LEAD, KC_TRNS,    _,       _,       _,       _,                _,       _,     KC_MS_WH_LEFT, _, KC_MS_WH_RIGHT,    _, _,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┤        ┤        ├        ┼────┬───┴───┬────┴───┬────┴────────┴────────┴────────┘
                                            _,      RGB_RMOD,     KC_TRNS,           KC_TRNS,    RGB_MOD,   _
                                       //└────────┴────────┘    └────────┘        └────────┘    └───────┴────────┘
        ),
    [3] = LAYOUT(KC_TRNS,KC_TRNS,KC_KP_7,KC_KP_8,KC_KP_9,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_4,KC_KP_5,KC_KP_6,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_1,KC_KP_2,KC_KP_3,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_KP_0,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS),
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
