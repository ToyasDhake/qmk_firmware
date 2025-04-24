// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "oled.h"

void render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln("Def", false);
            break;
        case 1:
            oled_write_ln("Med", false);
            break;
        case 2:
            oled_write_ln("Nav", false);
            break;
        case 3:
            oled_write_ln("Brk", false);
            break;
        case 4:
            oled_write_ln("Sym", false);
            break;
        case 5:
            oled_write_ln("Num", false);
            break;
        case 6:
            oled_write_ln("Fun", false);
            break;
    }
}
