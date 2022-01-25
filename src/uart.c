#include "sys.h"
#include "uart.h"

void uart_init() {
    // enable reading:
    *(uint32_t*)(UART_BASE + UART_RXCTRL) = 1;
    // set baud divisor (the SiFive FE310-G002 manual lists a table of possible
    // values in Section 18.9, determined this particular choice
    // experimentally. Furthermore, it's the default on HiFive1-revB board):
    *(uint32_t*)(UART_BASE + UART_BAUD_RATE_DIVISOR) = 138;
}

char uart_readchar() {
    volatile int32_t* rx = (int32_t*)(UART_BASE + UART_RXDATA);
    int32_t word;
    do {
        word = *rx;
    } while (word < 0);
    return word & 0xff;
}

void uart_writechar(char ch) {
    volatile int32_t* tx = (int32_t*)(UART_BASE + UART_TXDATA);
    while ((int32_t)(*tx) < 0);
    *tx = ch;
}