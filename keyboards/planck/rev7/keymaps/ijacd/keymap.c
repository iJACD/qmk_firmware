/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _LOWER, _RAISE, _MIDDLE, _ADJUST };

enum planck_keycodes { QWERTY = SAFE_RANGE, 
                       BACKLIT,  
                       WHO_R_U,
                       MOD_LEFT,
                       MOD_RIGHT,
                       MOD_UP,
                       MOD_DOWN,
                       SCRN_SHOT,
                       EMOJI   
                    };

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MIDDLE MO(_MIDDLE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Middle|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BL Tog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise |Pg Up |Pg Dn | Home |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MIDDLE,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    BL_TOGG, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_PGUP, KC_PGDN, KC_HOME, KC_END
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  F1  | Home |  Up  | End  |  F2  |  F3  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F4  | Left | Down |Right |  F5  |  F6  |   4  |   5  |   6  |   +  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Atl | GUI  |      |             |      |   0  |   .  |   ,  |  =   |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_GRV,  KC_F1,   KC_HOME, KC_UP,   KC_END,  KC_F2,   KC_F3,   KC_7,    KC_8,  KC_9,   KC_0,    KC_BSPC,
    KC_TAB,  KC_F4,   KC_LEFT, KC_DOWN, KC_RGHT, KC_F5,   KC_F6,   KC_4,    KC_5,  KC_6,   KC_PLUS, KC_MINS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,  KC_3,   KC_SLSH, KC_TRNS,
    KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,  KC_DOT, KC_COMM, KC_EQL
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   {  |   [  |   %  |   &  |   #  |   +  |   _  |   =  |   ]  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   \  |   -  |   <  |   >  |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |  Atl | GUI  |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
    KC_TAB,  KC_LCBR, KC_LBRC, KC_PERC, KC_AMPR, KC_HASH, KC_PLUS, KC_UNDS, KC_EQL,  KC_RBRC, KC_RCBR, KC_PIPE, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSLS, KC_MINS, KC_LABK, KC_RABK, KC_PIPE, KC_TRNS,
    BL_STEP, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Middle
 * ,-----------------------------------------------------------------------------------.
 * | Mute |Vol Up|      |Mod Up|ScrnSh|      |      | Home |  Up  | End  |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Vol Dn| Mod L|Mod Dn|Mod R |      |      | Left | Down | Right|      |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Emoji    |      | Play | Prev | Next | Stop |
 * `-----------------------------------------------------------------------------------'
 */
[_MIDDLE] = LAYOUT_planck_grid(
    KC_MUTE, KC_VOLU,  _______,  MOD_UP,   SCRN_SHOT, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, KC_DEL,
    _______, KC_VOLD,  MOD_LEFT, MOD_DOWN, MOD_RIGHT, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_BSLS,
    _______, _______,  _______,  _______,  _______,   _______, _______, _______, _______, _______, _______, WHO_R_U,
    _______, _______,  _______,  _______,  _______,   EMOJI,   EMOJI,   _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  _______,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] =   { ENCODER_CCW_CW(KC_A, KC_B) },
    [_LOWER] =  { ENCODER_CCW_CW(KC_C, KC_D) },
    [_RAISE] =  { ENCODER_CCW_CW(KC_E, KC_F)  },
    [_MIDDLE] = { ENCODER_CCW_CW(KC_E, KC_F)  },
    [_ADJUST] =  { ENCODER_CCW_CW(KC_E, KC_F)  }
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
        case WHO_R_U: 
            if (record->event.pressed) {
                // TODO: Update here.
                register_code(KC_LSFT);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
                tap_code(KC_ASTR);
            } else {
                unregister_code(KC_LSFT);
            }
            return false;
            break; 
        case MOD_UP:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_UP);
            } else {
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case MOD_DOWN:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_DOWN);
            } else {
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case MOD_LEFT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_LEFT);
            } else {
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case MOD_RIGHT:
            if (record->event.pressed) {
                register_code(KC_LCTL);
                tap_code(KC_RIGHT);
            } else {
                unregister_code(KC_LCTL);
            }
            return false;
            break;
        case SCRN_SHOT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                tap_code(KC_4);
            } else {
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
    }
    return true;
};

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}