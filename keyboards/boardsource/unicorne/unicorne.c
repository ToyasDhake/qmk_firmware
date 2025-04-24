// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"
#include "lib/oled.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    if (is_keyboard_master()) {
        render_layer_state();
        oled_set_cursor(0,5);
        oled_write_ln("WPM", false);
        oled_set_cursor(0,6);
        char buffer[12]; // enough for 32-bit int
        int number = get_current_wpm();
        sprintf(buffer, "%d", number);
        oled_write_ln(buffer, false);
        oled_set_cursor(0,9);
        oled_write_ln("Caps", false);
        oled_set_cursor(0,10);
        led_t led_state = host_keyboard_led_state();
        oled_write_ln(led_state.caps_lock ? "On" : "Off", false);
    } else {
        oled_write_raw_P(bs_logo_img, sizeof(bs_logo_img));
    }
    return false;
}
#endif
