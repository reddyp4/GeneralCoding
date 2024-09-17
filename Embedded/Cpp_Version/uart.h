#IFNDEF UART_H
#DEFINE UART_H

typedef enum {
    RED = 0,
    GREEN,
    BLUE
} led_colours;

void uart_init();
void uart_write();
void uart_read();

#ENDIF