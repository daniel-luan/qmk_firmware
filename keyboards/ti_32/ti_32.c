
#include "quantum.h"
#include "uart.h"

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);

    if (res) {
        uint8_t command[] = {0x02, led_state.raw};
        uart_transmit(command, 2);
    }

    return res;
}

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = layer_state_set_user(state);

    uint8_t command[] = {0x03, state};
    uart_transmit(command, 2);

    return state;
}