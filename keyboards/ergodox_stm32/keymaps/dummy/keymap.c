#include QMK_KEYBOARD_H
#include <keymap_template.h>

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
