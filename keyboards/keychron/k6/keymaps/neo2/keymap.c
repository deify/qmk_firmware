/*
Copyright 2020 Dimitris Mantzouranis
Copyright 2022 Philip Mourdjis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H
#include "keymap_german.h"

// clang-format off

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
typedef enum layer_names {
    _QWERTZ,
    _NEO,
    _NEO3,
    _NEO4,
    _NEO5,
    _NEO6,
    _FNQ1,
    _FNQ2
} layer_names_t;



// NEO Layer2 symbols

#define NEO_LGLM ALGR(DE_Y)
#define NEO_RGLM ALGR(DE_X)

#define NEO_LGQT ALGR(DE_V)
#define NEO_RGQ1 ALGR(DE_B)
#define NEO_RGQ2 ALGR(DE_N)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* _QWERTZ Base ISO layout
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ß │ ´ │       │MOD│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │ Q │ W │ E │ R │ T │ Z │ U │ I │ O │ P │ Ü │ + │     │HOM│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Ö │ Ä │ # │    │PUP│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │ < │ Y │ X │ C │ V │ B │ N │ M │ , │ . │ - │      │UP │PDN│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│WIN │ALT │                        │ALT│FN1│FN2│LFT│DWN│RGT│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
  [_QWERTZ] = { {   KC_GESC,   DE_1,      DE_2,      DE_3,    DE_4,    DE_5,    DE_6,     DE_7,    DE_8,    DE_9,      DE_0,      DE_SS,     DE_ACUT,   KC_BSPC,   KC_NO,     RGB_MOD    },
                {   KC_TAB,    DE_Q,      DE_W,      DE_E,    DE_R,    DE_T,    DE_Z,     DE_U,    DE_I,    DE_O,      DE_P,      DE_UDIA,   DE_PLUS,   KC_NO,     KC_NO,     KC_HOME    },
                {   KC_CAPS,   DE_A,      DE_S,      DE_D,    DE_F,    DE_G,    DE_H,     DE_J,    DE_K,    DE_L,      DE_ODIA,   DE_ADIA,   DE_HASH,   KC_ENT,    KC_NO,     KC_PGUP    },
                {   KC_LSFT,   DE_LABK,   DE_Y,      DE_X,    DE_C,    DE_V,    DE_B,     DE_N,    DE_M,    DE_COMM,   DE_DOT,    DE_MINS,   KC_NO,     KC_RSFT,   KC_UP,     KC_PGDN    },
                {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     KC_RALT,   MO(_FNQ1), MO(_FNQ2), KC_LEFT,   KC_DOWN,   KC_RGHT    }
              },
/* _NEO Base ISO layout
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│       │MOD│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │ X │ V │ L │ C │ W │ K │ H │ G │ F │ Q │ ẞ │ ´ │     │HOM│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │ M3   │ U │ I │ A │ E │ O │ S │ N │ R │ T │ D │ Y │ M3│    │PUP│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │ M2 │ M4│ Ü │ Ö │ Ä │ P │ Z │ B │ M │ , │ . │ J │   M2 │UP │PDN│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│WIN │ALT │                        │ M4│FN1│FN2│LFT│DWN│RGT│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
     [_NEO] = { {   KC_GESC,   KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_BSPC,   KC_NO,     RGB_MOD    },
                {   KC_TAB,    DE_X,      DE_V,      DE_L,    DE_C,    DE_W,    DE_K,     DE_H,    DE_G,    DE_F,      DE_Q,      DE_SS,     DE_ACUT,   KC_NO,     KC_NO,     KC_HOME    },
                {   MO(_NEO3), DE_U,      DE_I,      DE_A,    DE_E,    DE_O,    DE_S,     DE_N,    DE_R,    DE_T,      DE_D,      DE_Y,      MO(_NEO3), KC_ENT,    KC_NO,     KC_PGUP    },
                {   KC_LSFT,   MO(_NEO4), DE_UDIA,   DE_ODIA, DE_ADIA, DE_P,    DE_Z,     DE_B,    DE_M,    DE_COMM,   DE_DOT,    DE_J,      KC_NO,     KC_RSFT,   KC_UP,     KC_PGDN    },
                {   KC_LCTL,   KC_LGUI,   KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,   KC_NO,   KC_NO,   KC_NO,     MO(_NEO4), MO(_FNQ1), MO(_FNQ2), KC_LEFT,   KC_DOWN,   KC_RGHT    }
              },
/* _NEO LAYER3 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │      │   │   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │   │   │   │   │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6          7        8        9          10         11         12         13         14         15        */
    [_NEO3] = { {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_NO,     KC_NO,     DE_UNDS,   DE_LBRC, DE_RBRC, DE_CIRC, DE_EXLM,   DE_LABK, DE_RABK, DE_EQL,    DE_AMPR,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   DE_BSLS,   DE_SLSH,   DE_LCBR, DE_RCBR, DE_ASTR, DE_QUES,   DE_LPRN, DE_RPRN, DE_MINS,   DE_COLN,   DE_AT,     KC_TRNS,   KC_ENT,    KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   DE_HASH,   DE_DLR,  DE_PIPE, DE_TILD, S(DE_ACUT),DE_PLUS, DE_PERC, DE_DQUO,   DE_QUOT,   DE_SCLN,   KC_NO,     KC_TRNS,   KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_SPACE,  KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_NO,     KC_NO      }
              },

/* _NEO LAYER4 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │      │   │   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │   │   │   │   │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5          6         7        8        9          10         11         12         13         14         15        */
    [_NEO4] = { {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,   KC_NO,   DE_SLSH,   DE_ASTR,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_NO,     KC_PGUP,   KC_BSPC,   KC_UP,   KC_DEL,  KC_PGDN,   KC_NO,    KC_KP_7, KC_KP_8, KC_KP_9,   DE_PLUS,   DE_MINS,   KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_HOME,   KC_LEFT,   KC_DOWN, KC_RIGHT,KC_END,    KC_NO,    KC_KP_4, KC_KP_5, KC_KP_6,   DE_COMM,   DE_DOT,    KC_TRNS,   KC_ENT,    KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_ESC,    KC_TAB,  KC_NO,   KC_ENT,    KC_NO,    KC_COLN, KC_KP_1, KC_KP_2,   KC_KP_3,   DE_SCLN,   KC_NO,     KC_TRNS,   KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,     KC_KP_0,  KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_NO,     KC_NO      }
              },
/* _NEO LAYER5 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │      │   │   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │   │   │   │   │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
    [_NEO5] = { {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_NO,     KC_NO      }
              },

/* _NEO LAYER6 
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │   │   │   │   │   │   │   │   │   │   │   │   │       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │      │   │   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │   │   │   │   │
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
    [_NEO6] = { {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_NO,     KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_TRNS,   KC_NO,     KC_NO      },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,     KC_NO,     KC_NO      }
              },

#define FN_WUP LGUI(KC_UP)
#define FN_WDN LGUI(KC_DOWN)
#define FN_WLF LGUI(KC_LEFT)
#define FN_WRI LGUI(KC_RIGHT)

/* _FNQ1 Settings
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │BR+│BR-│   │   │VAD│VAI│PRV│PLY│NXT│MTE│VL-│VL+│       │TOG│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │WUP│   │   │   │   │   │   │   │INS│DEL│END│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │WLF│WDN│WRI│   │   │   │   │   │   │   │   │   │    │HUI│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │NKR│   │   │   │   │      │SPI│HUD│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │FN1│FN2│VAD│SPD│VAI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
    [_FNQ1] = { {   DE_CIRC,   KC_BRIU,   KC_BRID,   KC_NO,   KC_NO,   RGB_VAD, RGB_VAI,  KC_MPRV, KC_MPLY, KC_MNXT,   KC_MUTE,   KC_VOLD,   KC_VOLU,   KC_NO,     KC_NO,     RGB_TOG    },
                {   KC_NO,     KC_NO,     KC_NO,     FN_WUP,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_INS,    KC_DEL,    KC_END,    KC_NO,     KC_NO,     RGB_M_P    },
                {   KC_NO,     KC_NO,     FN_WLF,    FN_WDN,  FN_WRI,KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_HUI    },
                {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    NK_ON,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_SPI,   RGB_HUD    },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_RGUI,   KC_NO,     KC_NO,     RGB_VAD,   RGB_SPD,   RGB_VAI    }
              },
/* _FNQ2 MOD Keys (common to mac / win)
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │ F1│ F2│ F3│ F4│ F5│ F6│ F7│ F8│ F9│F10│F11│F12│ RESET │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┤
 * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │HUI│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │    │   │   │   │   │   │   │   │   │   │   │   │      │SPI│HUD│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │                        │   │   │FN2│SAD│SPD│SAI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *      Row:        0          1          2          3        4        5        6         7        8        9          10         11         12         13         14         15        */
    [_FNQ2] = { {   DE_DEG,    KC_F1,     KC_F2,     KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    RESET,     KC_NO,     RGB_RMOD   },
                {   KC_NO,     KC_NO,     KC_NO,     FN_WUP,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_M_P    },
                {   KC_NO,     KC_NO,     FN_WLF,    FN_WDN,  FN_WRI,  KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_HUI    },
                {   KC_TRNS,   KC_NO,     KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_SPI,   RGB_HUD    },
                {   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,     KC_RALT,   KC_NO,     KC_NO,     RGB_SAD,   RGB_SPD,   RGB_SAI    }
              }
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

combo_t key_combos[COMBO_COUNT] = {
    COMBO(caps_combo, KC_CAPS),
};

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

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable=true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }
