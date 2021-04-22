#include QMK_KEYBOARD_H
#include <stdio.h>
// #include "lily58/rev1/rev1.h"

// Left-hand home row mods
#define A_HOME LSFT_T(KC_A)
#define S_HOME LCTL_T(KC_S)
#define D_HOME LALT_T(KC_D)
#define F_HOME LGUI_T(KC_F)

// Right-hand home row mods
#define J_HOME RGUI_T(KC_J)
#define K_HOME RALT_T(KC_K)
#define L_HOME LCTL_T(KC_L)
#define SEMI_HOME RSFT_T(KC_SCLN)

#define L_SPC LCAG(KC_LEFT)
#define R_SPC LCAG(KC_RGHT)
#define L_WORD LALT(KC_LEFT)
#define R_WORD LALT(KC_RGHT)

enum layer_number {
    _QWERTY = 0,
    _SYM = 1,
    _MEDIA = 2,
};

#define KEYMAP_GEN

#ifdef KEYMAP_GEN
    #include "./keymap_gen.c"
#else
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |  5   |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |  Q   |  W   |  E   |  R   |  T   |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  A⇧  |  S ^ |  D ⌥ |  F * |  G   |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  del  |    | bksp  |------+------+------+------+------+------|
 * |LShift|  Z   |  X   |  C   |  V   |  B   |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | caps |  del | sym  | /Enter  /       \Space \  |  sym | bksp | media|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
//LT(_SYM,???)
[_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,   KC_5,                 KC_6,    KC_7,   KC_8,    KC_9,   KC_0,     KC_MINS, \
  KC_GRAVE, KC_Q,   KC_W,    KC_E,    KC_R,   KC_T,                 KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,     KC_BSLS, \
  KC_TAB,   A_HOME, S_HOME,  D_HOME,  F_HOME, KC_G,                 KC_H,    J_HOME, K_HOME,  L_HOME, SEMI_HOME,KC_QUOTE,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,   KC_B, KC_DEL,KC_BSPC, KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT, \
                      KC_CAPS, KC_DEL, TT(_SYM),KC_ENT,          KC_SPC, TT(_SYM), KC_BSPC, MO(_MEDIA)
),
/* SYM
 * spc = space
 * wrd = word
 *
 * mouse keys?
 * (requires enabling MOUSEKEY_ENABLE in rules.mk)
 * mw = mouse wheel: KC_WH_D, KC_WH_L, KC_WH_R, KC_WH_U
 * mouse left click for click and drag?
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | spcL | wrdL |  up  | wrdR |      | pgUp |                    |   #  |   {  |   }  |   =  |   +  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | spcR | left | down | rght |      | pgDn |-------.    ,-------|   $  |   (  |   )  |   -  |   _  |   `  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   &  |   [  |   ]  |   \  |   |  |   ~  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 */

[_SYM] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
  L_SPC,   L_WORD,  KC_UP,   R_WORD,  KC_HOME, KC_PGUP,                   KC_HASH, KC_LCBR, KC_RCBR, KC_EQL,  KC_PLUS, KC_F12, \
  R_SPC,   KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN,                   KC_DLR,  KC_LPRN, KC_RPRN, KC_MINS, KC_UNDS, KC_GRV, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_AMPR, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, KC_TILD, \
  _______, _______, _______, _______, _______, _______, _______, _______
),

/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | vlUp |      |      |      |                    |      |      |      |      |      |      |
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
#endif // KEYMAP_GEN

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_HOME:
        case S_HOME:
        case D_HOME:
        case F_HOME:
        case J_HOME:
        case K_HOME:
        case L_HOME:
        case SEMI_HOME:
            return true;
        default:
            return false;
    }
}

// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case A_HOME:
//     case S_HOME:
//     case D_HOME:
//     case F_HOME:
//     case J_HOME:
//     case K_HOME:
//     case L_HOME:
//     case SEMI_HOME:
//       return 500;
//     default:
//       return TAPPING_TERM;
//   }
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _SYM, _RAISE, _ADJUST);
// }

// copied from layer_state_reader.c
#define L_BASE 0
#define L_SYM (1 << 1)
#define L_MEDIA (1 << 2)

char layer_state_str[24];

const char *read_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            // return "Default";
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
            break;
        case L_SYM:
            // return "Sym/Nav";
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Sym/Nav");
            break;
        case L_MEDIA:
            // return "Media";
            snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Media");
            break;
        default:
            // return "Other";
              snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
    }

    return layer_state_str;
}

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
// const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// void set_timelog(void);
// const char *read_timelog(void);

char wpm_str[24];

const char *read_wpm(void) {
    snprintf(wpm_str, sizeof(wpm_str), "WPM: %i", get_current_wpm());
    return wpm_str;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        oled_write_ln(read_wpm(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
}
#endif  // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}
