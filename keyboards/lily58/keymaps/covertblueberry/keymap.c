#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _SYM,
  _MEDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |  A⇧  |  S⌥  |  D🍎 |  F 1 |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |Del   | /Space  /       \Enter \  |Bksp  | RGUI | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,         KC_2,         KC_3,         KC_4,       KC_5,                     KC_6,         KC_7,       KC_8,         KC_9,         KC_0,             KC_MINS, \
  KC_TAB,   KC_Q,         KC_W,         KC_E,         KC_R,       KC_T,                     KC_Y,         KC_U,       KC_I,         KC_O,         KC_P,             KC_BSLS, \
  KC_GRAVE, LSFT_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LT(1,KC_F), LCTL_T(KC_G),             RCTL_T(KC_H), LT(1,KC_J), RGUI_T(KC_K), RALT_T(KC_L), RSFT_T(KC_SCOLON),KC_QUOTE,
  KC_LSFT,  KC_Z,         KC_X,         KC_C,         KC_V,       KC_B,    KC_CAPS, MO(2),  KC_N,         KC_M,       KC_COMM,      KC_DOT,       KC_SLSH,          KC_RSFT, \
                            KC_LALT,      KC_LGUI,      KC_DEL,     KC_SPC,               KC_ENT,       KC_BSPC,    KC_RGUI,      KC_RALT
),
/* SYM
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | spL  | spR  |  up  | home | end  | pgUp |                    |   $  |   {  |   }  |   =  |   +  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | left | down | rght |      | pgDn |-------.    ,-------|   (  |      |   )  |   -  |   _  |   `  |
 * |------+------+------+------+------+------|       |    |    ]  |------+------+------+------+------+------|
 * |      | mwDn | mwLf | mwRt | mwUp |      |-------|    |-------|      |   [  |   ]  |   \  |   |  |   ~  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */

[_SYM] = LAYOUT( \
  _______,       KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  LCAG(KC_LEFT), LCAG(KC_RGHT), KC_UP,   KC_HOME, KC_END,  KC_PGUP,                   KC_DLR,  KC_LCBR, KC_RCBR, KC_EQL,  KC_PLUS, KC_F12, \
  _______,       KC_LEFT,       KC_DOWN, KC_RGHT, _______, KC_PGDN,                   KC_LPRN, _______, KC_RPRN, KC_MINS, KC_UNDS, KC_GRV, \
  _______,       KC_WH_D,       KC_WH_L, KC_WH_R, KC_WH_U, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______
),

/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | vlUp  |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | vlDn |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      | mute |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */
[_MEDIA] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _SYM, _RAISE, _ADJUST);
// }

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
