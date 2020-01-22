#include QMK_KEYBOARD_H
#include "quantum_keycodes.h"
#include "action_layer.h"
#include "version.h"
#include "config.h"

#define VERSION_STRING QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION
#define _______ KC_TRNS
#define X_____X KC_TRNS
#define KC_ATM LGUI(LSFT(KC_P))
#define KC_ATP LGUI(LCTL(KC_P))
#define TG_FS TG(FN_SHORTCUT)
#define TG_WK TG(WORK)
#define TG_FN TG(FUNCTION)
#define TG_MT TG(META)
#define LT_FN(X) LT(FUNCTION, X)
#define LT_MT(X) LT(META, X)
#define TAPPING_TOGGLE 2
#define TT_FN TT(FUNCTION)
#define TT_MT TT(META)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* BASE
  *
  * ,--------------------------------------------------.           ,--------------------------------------------------.
  * | NORMAL |   1  |   2  |   3  |   4  |   5  | ⇧⌘P  |           | PROJ |   6  |   7  |   8  |   9  |   0  |   -    |
  * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
  * |   ESC  |   Q  |   W  |   E  |   R  |   T  |  `   |           |   [  |   Y  |   U  |   I  |   O  |   P  |   ]    |
  * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
  * |   DEL  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
  * |--------+------+------+------+------+------|   =  |           |   \  |------+------+------+------+------+--------|
  * |   L⇧   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   R⇧   |
  * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
  *   |   ⌃  |   ⌥  |  (   |  [   |   {  |                                       |  }   |  ]   |   )  |   ⌥  |   ⌃  |
  *   `----------------------------------'                                       `----------------------------------'
  *                                        ,-------------.       ,-------------.
  *                                        | HOME | END  |       | PGDN | PGUP |
  *                                 ,------|------|------|       |------+------+------.
  *                                 |SPACE |      | SYMB |       | SYMB |      | ENTER|
  *                                 |      |  ESC |------|       |------| BKSP |      |
  *                                 |      |      | NORM |       | MUSE |      |      |
  *                                 `--------------------'       `--------------------'
  */
  [BASE] = LAYOUT_ergodox(
    // Left Hand
    KC_LOCK,KC_1,   KC_2,   KC_3,    KC_4,   KC_5, KC_ATM,
    KC_DEL ,KC_Q,   KC_W,   KC_E,    KC_R,   KC_T, KC_EQL,
    KC_TAB ,KC_A,   KC_S,   KC_D,	 KC_F,   KC_G,
    KC_LSFT,KC_Z,   KC_X,   KC_C,    KC_V,   KC_B, KC_GRV,
    KC_LCTL,KC_LALT,KC_LPRN,KC_LBRC, KC_LCBR,

                                            KC_HOME,KC_END ,
                                            TG_WK,
                                            KC_SPC,KC_ESC ,TG_FS,


    // Right Hand
                              KC_ATP , KC_6, KC_7,   KC_8,    KC_9,   KC_0,   KC_MINS,
                              KC_LBRC, KC_Y, KC_U,   KC_I,    KC_O,   KC_P,   KC_RBRC,
                                       KC_H, KC_J,   KC_K,    KC_L,   KC_SCLN,KC_QUOT,
                              KC_BSLS, KC_N, KC_M,   KC_COMM, KC_DOT, KC_SLSH,KC_RSFT,
                                             KC_RCBR,KC_RBRC, KC_RPRN,KC_RALT,KC_RCTL,

    KC_PGUP,  KC_PGDN,
    TT_FN,
    TT_MT , KC_BSPC, KC_ENT
  ),

  [WORK] = LAYOUT_ergodox(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                                _______,_______,
                                                                        _______,
                                                        GUI_T(KC_SPC),_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                      _______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,GUI_T(KC_ENT)
  ),

  [FN_SHORTCUT] = LAYOUT_ergodox(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,LT_MT(KC_F),LT_FN(KC_G),
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                      _______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),

  [META] = LAYOUT_ergodox(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

    // Right Hand
                              _______,_______,KC_ACL0,KC_ACL1,KC_ACL2,_______,_______,
                              _______,_______,KC_BTN1,KC_BTN3,KC_BTN2,_______,KC_MUTE,
                                      KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,_______,KC_VOLU,
                              _______,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,_______,KC_VOLD,
                                              KC_MRWD,KC_MSTP,KC_MPLY,KC_MFFD,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),
};

/*
  [BLANK] = LAYOUT_ergodox(
    // Left Hand
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,_______,_______,
    _______,_______,_______,_______,_______,

                                                                _______,_______,
                                                                        _______,
                                                        _______,_______,_______,

    // Right Hand
                              _______,_______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                      _______,_______,_______,_______,_______,_______,
                              _______,_______,_______,_______,_______,_______,_______,
                                              _______,_______,_______,_______,_______,

    _______,_______,
    _______,
    _______,_______,_______
  ),

 */

const uint16_t PROGMEM fn_actions[] = {
  /* [1] = ACTION_LAYER_TAP_TOGGLE(1) */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* bool SHIFTED = (keyboard_report->mods & MOD_BIT(KC_LSFT)) | */
  /*                (keyboard_report->mods & MOD_BIT(KC_RSFT)); */

  /* switch (keycode) { */
  /*   default: */
  /*     break; */
  /* } */

  // End by clearing the queue unless keycode is a
  // if ((record->event.pressed) &&
  //     (keycode != VIM_I ||
  //     keycode != VIM_C ||
  //     keycode != VIM_D ||
  //     keycode != VIM_V)) {
  //   VIM_LEADER(KC_NO);
  // }

  return true;
};

layer_state_t default_layer_state_set_user(layer_state_t state) {
  // do initial state setup
  return state;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);

    ergodox_led_all_off();
    ergodox_board_led_1_off();
    ergodox_board_led_2_off();
    ergodox_board_led_3_off();
    switch (layer) {
      case 1:
        ergodox_board_led_1_on();
        break;
      case 2:
        ergodox_board_led_2_on();
        break;
      case 3:
        ergodox_board_led_2_on();
        break;
      case 4:
        ergodox_board_led_1_on();
        ergodox_board_led_2_on();
        break;
      case 5:
        ergodox_board_led_1_on();
        ergodox_board_led_3_on();
        break;
      case 6:
        ergodox_board_led_2_on();
        ergodox_board_led_3_on();
        break;
      case 7:
        ergodox_board_led_1_on();
        ergodox_board_led_2_on();
        ergodox_board_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
