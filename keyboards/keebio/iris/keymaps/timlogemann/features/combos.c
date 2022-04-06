#include QMK_KEYBOARD_H

/**
 *  Combos
 * */
const uint16_t PROGMEM caplock_combo[] = {KC_LALT, KC_LSFT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(caplock_combo, KC_CAPS)};
