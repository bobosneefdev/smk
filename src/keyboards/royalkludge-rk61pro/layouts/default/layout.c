#include "kbdef.h"
#include "layout.h"
#include "user_layout.h"
#include "report.h"
#include "delay.h"
#include <stdint.h>

// clang-format off

#define LAYOUT_60( \
    K00_0, K01_0, K02_0, K03_0, K04_0, K05_0, K06_0, K07_0, K08_0, K09_0, K10_0, K11_0, K12_0, K13_0, \
    K00_1, K01_1, K02_1, K03_1, K04_1, K05_1, K06_1, K07_1, K08_1, K09_1, K10_1, K11_1, K12_1, K13_1, \
    K00_2, K01_2, K02_2, K03_2, K04_2, K05_2, K06_2, K07_2, K08_2, K09_2, K10_2, K11_2,        K13_2, \
    K00_3, K01_3, K02_3, K03_3, K04_3, K05_3, K06_3, K07_3, K08_3, K09_3, K10_3,               K13_3, \
    K00_4, K01_4, K02_4,               K05_4,               K08_4, K09_4, K10_4,               K13_4 \
) { \
    { K00_0, K01_0, K02_0, K03_0, K04_0, K05_0, K06_0, K07_0, K08_0, K09_0, K10_0, K11_0, K12_0, K13_0 }, \
    { K00_1, K01_1, K02_1, K03_1, K04_1, K05_1, K06_1, K07_1, K08_1, K09_1, K10_1, K11_1, K12_1, K13_1 }, \
    { K00_2, K01_2, K02_2, K03_2, K04_2, K05_2, K06_2, K07_2, K08_2, K09_2, K10_2, K11_2, KC_NO, K13_2 }, \
    { K00_3, K01_3, K02_3, K03_3, K04_3, K05_3, K06_3, K07_3, K08_3, K09_3, K10_3, KC_NO, KC_NO, K13_3 }, \
    { K00_4, K01_4, K02_4, KC_NO, KC_NO, K05_4, KC_NO, KC_NO, K08_4, K09_4, K10_4, KC_NO, KC_NO, K13_4 } \
}

#define WINDOWS 0
#define WINDOWS_FN 1

enum custom_keycodes {
    // Toggle Windows key lock - press Fn + Windows key to toggle
    WINDOWS_LOCK = SAFE_RANGE
};

// 1u = 4 spaces in diagram
const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* WINDOWS
     * ,------------------------------------------------------------.
     * | Esc   1   2   3   4   5   6   7   8   9   0   -   =  Backsp|
     * |------------------------------------------------------------|
     * |   Tab   Q   W   E   R   T   Y   U   I   O   P   [   ]     \|
     * |------------------------------------------------------------|
     * |   Caps   A   S   D   F   G   H   J   K   L   ;   '    Enter|
     * |------------------------------------------------------------|
     * |    Shift   Z   X   C   V   B   N   M   ,   .   /      Shift|
     * |------------------------------------------------------------|
     * | Ctrl  Win  Alt                    Space  Alt  App Ctrl   Fn|
     * `------------------------------------------------------------'
     */
    [WINDOWS] = LAYOUT_60(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,   KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,             KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH,                      KC_RSFT,
        KC_LCTL, KC_LWIN, KC_LALT,                   KC_SPC,                   KC_RALT, KC_APP,  KC_LCTL,                       MO(WINDOWS_FN)
    ),

    /* WINDOWS_FN
     * ,------------------------------------------------------------.
     * |   `  F1  F2  F3  F4  F5  F6  F7  F8  F9 F10 F11 F12     Del|
     * |------------------------------------------------------------|
     * |     _   _   _   _   _   _   _   _   _   _   _   _   _     _|
     * |------------------------------------------------------------|
     * |      _   _   _   _   _   _   _ MPT MPP MNT  V-  V+        _|
     * |------------------------------------------------------------|
     * |        _   _   _   _   _   _   _   _ Hme End   U          _|
     * |------------------------------------------------------------|
     * |    _    _    _                        _    L    D    R    _|
     * `------------------------------------------------------------'
     */
    [WINDOWS_FN] = LAYOUT_60(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,               KC_F8,               KC_F9,               KC_F10,            KC_F11,          KC_F12,  KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, _______,             _______,             _______,             _______,           _______,         _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_VOLD,           KC_VOLU,                  _______,
        _______, _______, _______, _______, _______, _______, _______, _______,             KC_HOME,             KC_END,              KC_UP,                                       _______,
        _______, _______, _______,                   _______,                               KC_LEFT,             KC_DOWN,             KC_RIGHT,                                    _______
    ),
};

// clang-format on

void key_action(uint16_t keycode)
{
    delay_ms(5);
    add_key(keycode);
    send_keyboard_report();

    delay_ms(5);
    del_key(keycode);
    send_keyboard_report();
}

bool layout_process_record(uint16_t keycode, bool key_pressed)
{
    static bool windows_locked = false;
    switch (keycode) {
        case WINDOWS_LOCK:
            if (key_pressed) {
                windows_locked = !windows_locked;
            }
            return false;

        case KC_LWIN:
            if (windows_locked) {
                return false;
            }
            return true;

        default:
            return true;
    }
}
