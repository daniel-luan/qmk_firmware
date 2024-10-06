#include "matrix.h"

#include "uart.h"
#include "print.h"

#define UART_MATRIX_RESPONSE_TIMEOUT 1000000

void matrix_init_custom(void) {
    uart_init(115200);
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool has_changed = false;

    // uint8_t command[] = {0x01, 0x00}; // Command to request matrix state

    // uart_transmit(command, 2);

    const size_t packed_matrix_size                                      = (MATRIX_ROWS * sizeof(matrix_row_t)) + 1;
    uint8_t      packed_matrix[(MATRIX_ROWS * sizeof(matrix_row_t)) + 1] = {0};

    uint8_t key_event[2] = {0};

    if (!uart_available()) {
        return false;
    }

    uint8_t start = uart_read();

    if (start == 0x11) {
        int timeout = 0;
        for (uint8_t i = 0; i < packed_matrix_size; i++) {
            while (!uart_available()) {
                timeout++;
                if (timeout > UART_MATRIX_RESPONSE_TIMEOUT) {
                    uprintf("full scan timeout\n");
                    return false;
                }
            }

            if (timeout < UART_MATRIX_RESPONSE_TIMEOUT) {
                packed_matrix[i] = uart_read();
            } else {
                packed_matrix[i] = 0x00;
            }
        }

        size_t index = 0;

        for (size_t row = 0; row < MATRIX_ROWS; ++row) {
            matrix_row_t current_row = current_matrix[row];

            matrix_row_t unpacked_row = 0;

            // Unpack the row from the byte array
            for (size_t i = 0; i < sizeof(matrix_row_t); ++i) {
                unpacked_row |= ((matrix_row_t)packed_matrix[index++] << (i * 8));
            }
            if (unpacked_row != current_row) {
                current_matrix[row] = unpacked_row;
                has_changed         = true;
            }
        }

    } else if (start == 0x12) {
        int timeout = 0;
        for (uint8_t i = 0; i < 2; i++) {
            while (!uart_available()) {
                timeout++;
                if (timeout > UART_MATRIX_RESPONSE_TIMEOUT) {
                    uprintf("key event scan timeout\n");
                    return false;
                }
            }

            if (timeout < UART_MATRIX_RESPONSE_TIMEOUT) {
                key_event[i] = uart_read();
            } else {
                key_event[i] = 0x00;
            }
        }

        uint8_t col   = key_event[0];
        uint8_t row   = key_event[1] >> 1;
        bool    state = key_event[1] & 0x01;

        if (state) {
            current_matrix[row] |= (1 << col); // Set the bit at position 'col' in row
        } else {
            current_matrix[row] &= ~(1 << col); // Clear the bit at position 'col' in row
        }

        has_changed = true;
    }

    return has_changed;
}