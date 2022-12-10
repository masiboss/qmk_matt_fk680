/* Copyright 2022 ZhaQian
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

#include "fk680.h"

#ifdef RGB_MATRIX_ENABLE 
led_config_t g_led_config = {
{
    // Key Matrix to LED Index
    { 55,     56,     57,     58,     59,     60,     61,     62,     63,    64,     65,     66,       67,    68,   69  },
    { 40,     41,     42,     43,     44,     45,     46,     47,     48,    49,     50,     51,       52,    53,   54  },
    { 26,     27,     28,     29,     30,     31,     32,     33,     34,    35,     36,     37,   NO_LED,    38,   39  },
    { 12,     13,     14,     15,     16,     17,     18,     19,     20,     21,    22, NO_LED,       23,    24,   25  },
    { 0,      1,      2,  NO_LED, NO_LED,      4, NO_LED, NO_LED,      NO_LED,      6,     7,      8,        9,    10,   11  }
}, {
    // LED Index to Physical Position
    // {col, row}

    {  0,  64}, { 16,  64}, { 32,  64}, { 48,  64}, { 64,  64}, { 80,  64}, {144,  64}, {160,  64}, {176,  64}, {192,  64}, {208,  64}, {224,  64}, 
    {  0,  48}, { 16,  48}, { 32,  48}, { 48,  48}, { 64,  48}, { 80,  48}, { 96,  48}, {112,  48}, {128,  48}, {144,  48}, {160,  48}, {192,  48}, {208,  48}, {224,  48}, 
    {  0,  32}, { 16,  32}, { 32,  32}, { 48,  32}, { 64,  32}, { 80,  32}, { 96,  32}, {112,  32}, {128,  32}, {144,  32}, {160,  32}, {176,  32}, {208,  32}, {224,  32}, 
    {  0,  16}, { 16,  16}, { 32,  16}, { 48,  16}, { 64,  16}, { 80,  16}, { 96,  16}, {112,  16}, {128,  16}, {144,  16}, {160, 16}, {176,  16}, {192,  16}, {208,  16}, {224,  16}, 
    {  0,   0}, { 16,   0}, { 32,   0}, { 48,   0}, { 64,   0}, { 80,   0}, { 96,   0}, {112,   0}, {128,   0}, {144,   0}, {160,  0}, {176,   0}, {192,   0}, {208,   0}, {224,   0}, 

}, {
    // LED Index to Flag
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,        // Ctrl, GUI, Alt, light, Space, light,  RAlt, FN, Ctrl, Left, Down, Right
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // LShift, Z, X, C, V, B, N, M, ,, ., /, Shift, Up, Page Down
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // Capslock, A, S, D, F, G, H, J, K, L, ;, ', Enter, Page up
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // Tab, Q, W, E, R, T, Y, U, I, O, P, [, ], backslash , Home
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,  // Esc, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, -, =, Backspace, Delete

    // underglow
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

}
};

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}
#endif