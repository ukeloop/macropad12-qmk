/* Copyright 2019 monksoffunk
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

#include "rev1/common/oled_helper.h"

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    RGBRST = SAFE_RANGE,
};

enum layer_number {
    _DEFAULT = 0,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT(
        // ,-----------------------------------.
                               KC_MPLY, LT(_ADJUST, KC_MUTE),
        // |--------+--------+--------+--------|
               KC_F1,   KC_F2,   KC_F3,   KC_F4,
        // |--------+--------+--------+--------|
               KC_F5,   KC_F6,   KC_F7,   KC_F8,
        // |--------+--------+--------+--------|
               KC_F9,  KC_F10,  KC_F11,  KC_F12
        // `-----------------------------------'
    ),
    [_ADJUST] = LAYOUT(
        // ,-----------------------------------.
                               XXXXXXX,  _ADJUST,
        // |--------+--------+--------+--------|
             RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX,
        // |--------+--------+--------+--------|
             RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI,
        // |--------+--------+--------+--------|
             RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD
        // `-----------------------------------'
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    }
    return true;
}

#ifdef OLED_DRIVER_ENABLE

void render_status(void) {
    render_logo();
    oled_scroll_left();
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}
#endif

#define L_ADJUST 1

bool encoder_update_user(uint8_t index, bool clockwise) {
#ifdef OLED_DRIVER_ENABLE
    oled_on();
#endif

    if (index == 0) { /* right encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) { /* left encoder */
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    }

    return true;
}
