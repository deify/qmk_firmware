/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"

// clang-format off

enum layers {
	_QWERTZ,
	_NEO,
	_NEO3,
	_NEO4,
	_NEO5,
	_NEO6,
	_FN1,
	_FN2,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// NEO Layer2 symbols

#define NEO_LGLM ALGR(DE_Y)
#define NEO_RGLM ALGR(DE_X)

#define NEO_LGQT ALGR(DE_V)
#define NEO_RGQ1 ALGR(DE_B)
#define NEO_RGQ2 ALGR(DE_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTZ] = LAYOUT_iso_62(
		KC_ESC,  DE_1,     DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,     DE_SS,    DE_ACUT,  KC_BSPC,
		KC_TAB,  DE_Q,     DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,     DE_UDIA,  DE_PLUS,
		KC_CAPS, DE_A,     DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA,  DE_ADIA,  DE_HASH,  KC_ENT,
		KC_LSFT, DE_LABK,  DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,   DE_MINS,            KC_RSFT,
		KC_LCTL, KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  MO(_FN1), MO(_FN2), KC_RCTL),

	[_NEO] = LAYOUT_iso_62(
		KC_ESC,    KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,   KC_F12,    KC_BSPC,
		KC_TAB,    DE_X,      DE_V,    DE_L,    DE_C,    DE_W,    DE_K,    DE_H,    DE_G,    DE_F,    DE_Q,      DE_SS,    DE_ACUT,
		MO(_NEO3), DE_U,      DE_I,    DE_A,    DE_E,    DE_O,    DE_S,    DE_N,    DE_R,    DE_T,    DE_D,      DE_Y,     MO(_NEO3), KC_ENT,
		KC_LSFT,   MO(_NEO4), DE_UDIA, DE_ODIA, DE_ADIA, DE_P,    DE_Z,    DE_B,    DE_M,    DE_COMM, DE_DOT,    DE_J,                KC_RSFT,
		KC_LCTL,   KC_LWIN,   KC_LALT,                            KC_SPC,                             MO(_NEO4), MO(_FN1), MO(_FN2),  KC_RCTL),

	[_NEO3] = LAYOUT_iso_62(
		KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
		KC_NO,   KC_NO,    DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM,    DE_LABK, DE_RABK, DE_EQL,  DE_AMPR,  KC_NO,    KC_NO,
		_______, DE_BSLS,  DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES,    DE_LPRN, DE_RPRN, DE_MINS, DE_COLN,  DE_AT,    _______,  KC_ENT,
		_______, _______,  DE_HASH, DE_DLR,  DE_PIPE, DE_TILD, S(DE_ACUT), DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT,  DE_SCLN,            _______,
		_______, _______,  _______,                            KC_SPC,                                _______,  _______,  _______,  _______),

	[_NEO4] = LAYOUT_iso_62(
		KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
		KC_NO,   KC_PGUP,  KC_BSPC, KC_UP,   KC_DEL,   KC_PGDN, KC_NO,    KC_KP_7, KC_KP_8, KC_KP_9, DE_PLUS,  DE_MINS,  KC_NO,
		_______, KC_HOME,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,  KC_NO,    KC_KP_4, KC_KP_5, KC_KP_6, DE_COMM,  DE_DOT,   _______,  KC_ENT,
		_______, _______,  KC_ESC,  KC_TAB,  KC_NO,    KC_ENT,  KC_NO,    KC_COLN, KC_KP_1, KC_KP_2, KC_KP_3,  DE_SCLN,            _______,
		_______, _______,  _______,                             KC_KP_0,                             _______,  _______,  _______,  _______),

	[_NEO5] = LAYOUT_iso_62(
		KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
		KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
		_______, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    _______,  KC_ENT,
		_______, _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,              _______,
		_______, _______,  _______,                            KC_SPC,                              _______,  _______,  _______,  _______),

	[_NEO6] = LAYOUT_iso_62(
		KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,
		KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
		_______, KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    _______,  KC_ENT,
		_______, _______,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,              _______,
		_______, _______,  _______,                            KC_SPC,                              _______,  _______,  _______,  _______),

	[_FN1] = LAYOUT_iso_62(
		KC_GRV,  KC_BRID,  KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
		RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  KC_HOME,
		_______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   KC_PSCR, KC_PGDN,  KC_END,   _______,  _______,
		_______, _______,  _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
		_______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

	[_FN2] = LAYOUT_iso_62(
		KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   QK_BOOT,
		RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,
		_______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,  _______,  _______,
		_______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
		_______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______)
};

// clang-format on

// GUI + Fx = GUi + x
const key_override_t ovr_f1_gui  = ko_make_basic(MOD_MASK_GUI, KC_F1, LGUI(KC_1));
const key_override_t ovr_f2_gui  = ko_make_basic(MOD_MASK_GUI, KC_F2, LGUI(KC_2));
const key_override_t ovr_f3_gui  = ko_make_basic(MOD_MASK_GUI, KC_F3, LGUI(KC_3));
const key_override_t ovr_f4_gui  = ko_make_basic(MOD_MASK_GUI, KC_F4, LGUI(KC_4));
const key_override_t ovr_f5_gui  = ko_make_basic(MOD_MASK_GUI, KC_F5, LGUI(KC_5));
const key_override_t ovr_f6_gui  = ko_make_basic(MOD_MASK_GUI, KC_F6, LGUI(KC_6));
const key_override_t ovr_f7_gui  = ko_make_basic(MOD_MASK_GUI, KC_F7, LGUI(KC_7));
const key_override_t ovr_f8_gui  = ko_make_basic(MOD_MASK_GUI, KC_F8, LGUI(KC_8));
const key_override_t ovr_f9_gui  = ko_make_basic(MOD_MASK_GUI, KC_F9, LGUI(KC_9));
const key_override_t ovr_f10_gui = ko_make_basic(MOD_MASK_GUI, KC_F10, LGUI(KC_0));

// Shift + Fx NeoLayer2
// const key_override_t ovr_f1_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F1, LGUI(KC_1));
// const key_override_t ovr_f2_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F2, LGUI(KC_2));
// const key_override_t ovr_f3_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F3, LGUI(KC_3));
const key_override_t ovr_f4_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F4, NEO_LGLM);
const key_override_t ovr_f5_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F5, NEO_RGLM);
const key_override_t ovr_f6_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F6, DE_DLR);
const key_override_t ovr_f7_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F7, DE_EURO);
const key_override_t ovr_f8_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F8, NEO_LGQT);
const key_override_t ovr_f9_shift  = ko_make_basic(MOD_MASK_SHIFT, KC_F9, NEO_RGQ1);
const key_override_t ovr_f10_shift = ko_make_basic(MOD_MASK_SHIFT, KC_F10, NEO_RGQ1);

const key_override_t **key_overrides = (const key_override_t *[]){
	&ovr_f1_gui, &ovr_f2_gui, &ovr_f3_gui, &ovr_f4_gui, &ovr_f5_gui, &ovr_f6_gui, &ovr_f7_gui, &ovr_f8_gui, &ovr_f9_gui, &ovr_f10_gui, &ovr_f4_shift, &ovr_f5_shift, &ovr_f6_shift, &ovr_f7_shift, &ovr_f8_shift, &ovr_f9_shift, &ovr_f10_shift, NULL,
};

const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};


combo_t key_combos[] = {
	COMBO(caps_combo, KC_CAPS),
};


uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

bool dip_switch_update_user(uint8_t index, bool active) {
	switch (index) {
		case 0:            // macos/windows togggle
			if (active) {  // macos -> NEO
				layer_off(_QWERTZ);
				layer_on(_NEO);
			} else {  // windows -> QWERTZ
				layer_on(_QWERTZ);
				layer_off(_NEO);
			}
			break;
	}
	return true;
}

void led_set_user(uint8_t usb_led) {
  if (!(usb_led & (1<<USB_LED_NUM_LOCK))) {
    tap_code(KC_NUM_LOCK);
  }
}
