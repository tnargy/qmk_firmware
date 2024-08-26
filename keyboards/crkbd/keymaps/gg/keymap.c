#include QMK_KEYBOARD_H

enum layer_names {
	_DEFAULT,
	_GAMING,
	_NUMBER,
	_SYMBOL,
	_ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, QK_REP, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT, KC_ESC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_ENT, KC_SPC, MO(_NUMBER), MO(_SYMBOL), KC_SPC, KC_ENT),
	[_GAMING] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC, KC_LALT, KC_SPC, MO(_NUMBER), MO(_SYMBOL), KC_SPC, KC_ENT),
	[_NUMBER] = LAYOUT_split_3x6_3(KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_PGUP, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_END, KC_HOME, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT, KC_SPC, KC_TRNS, MO(_ADJUST), KC_SPC, KC_ENT),
	[_SYMBOL] = LAYOUT_split_3x6_3(KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD, KC_ENT, KC_SPC, MO(_ADJUST), KC_TRNS, KC_SPC, KC_ENT),
	[_ADJUST] = LAYOUT_split_3x6_3(QK_BOOT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO, KC_P7, KC_P8, KC_P9, KC_PSLS, KC_PAST, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_P4, KC_P5, KC_P6, KC_PMNS, KC_PPLS, TG(1), KC_F11, KC_F12, KC_NO, KC_NO, KC_NO, KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, KC_NO, KC_ENT, KC_SPC, KC_TRNS, KC_TRNS, KC_SPC, KC_ENT)
};

#ifdef OLED_ENABLE
// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

bool oled_task_user() {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("Layer: "), false);
		switch (get_highest_layer(layer_state)) {
			case _DEFAULT :
				oled_write("Default\n", false);
				break;
			case _GAMING :
				oled_write("Gaming\n", false);
				break;
			case _NUMBER :
				oled_write("Numbers\n", false);
				break;
			case _SYMBOL :
				oled_write("Symbols\n", false);
				break;
			case _ADJUST :
				oled_write("Adjust\n", false);
				break;
			default:
				oled_write("Undef\n", false);
		}
		
    } else {
		static const  char PROGMEM gg_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,240,240,240,240,240,240,240,240,240,240,240,240,240,240,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192,192,192,192,192,192,  0,  0,  0,192,192,192,192,192,192,192,  0,  0,  0,  0,  0,192,192,  0,  0,  0,  0,  0,192,192,  0,  0,  0,  0,192,192,  0,  0,192,192,192,192,192,192,192,  0,  0,  0,192,192,192,  0,  0,  0,  0,192,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 60,126,195,129,129,255,255,131,125,125, 93, 25,255,131,125,125, 93, 25,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,  0,  0,  0,  0,192,195,195,  0,255,255,  0,  0,  0,  0,192,195,195,  0,  0,252,255,195,192,192,195,255,252,  0,  0,255,255, 12, 48, 48,192,255,255,  0,  0,255,255,  0,  0,  0,  0,  0,255,255,  0,  3,  3, 15, 28,240,240, 28, 15,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3, 12, 12, 12, 12, 12, 15, 15,  0,  3,  3, 12, 12, 12, 12, 12, 12, 15,  0,  0, 15, 15,  0,  0,  0,  0, 15, 15,  0,  0, 15, 15,  0,  0,  0,  0, 15, 15,  0,  0, 15, 15, 12, 12, 12, 12, 12,  3,  3,  0,  0,  0,  0,  0, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
		oled_write_raw_P(gg_logo, sizeof(gg_logo));
	}
	return false;
}

#endif

enum combos { 
  J_K_ESC,
  
};

const uint16_t PROGMEM j_k_esc[] = { KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [J_K_ESC] = COMBO(j_k_esc, KC_ESC),
  
};
