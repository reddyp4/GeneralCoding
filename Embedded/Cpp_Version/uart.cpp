#include "stm32f4xx.h"  /* File having the structures for register access */
#include "uart.h"

int n;
char str[80];

/*  1) Initiate driver 
    2) Enable clock access
    3) Enable pins */

/* Reference Manual STM32F411xC*/

void uart_init(void)
{
    /* Assume a structure for register access already present */
    str_register hALLREG = &ALL_REG;
    str_register hUART = &UART;

    /* Enable UART, set UART bit in APB1ENR */
    hALLREG->ENABLE_REG |= UART_BIT;  /* UART_BIT is assigned as per register: say 0xA000 */

    /* Enable clock access for UART, set UART bit in APB1ENR */
    hALLREG->CLOCK_REG = 0x001;

    /* Configure alternate access for this pin, if needed */
    hALLREG->MODE_REG &= 0xFF;

    /* Configure type of alternate function */
    hALLREG->ALTERNATE_REG[0] &= ~0xFF00;

    /* Configure uart */
    /* baud-rate, data-size, stop bit etc., flow-control */
    hUART->BAUD_REG = 0x0683;
    hUART->CONTROL_REG = 0x000C;    /* Enabled tx/rx */
    hUART->FLOW_REG = 0x0000;       /* Flow control */
    hUART->ENABLE_REG = 0x2000;     /* Enable the UART */
}

void uart_write(int ch)
{
    while(UART->STATUS_REG & NOT_EMPTY);    /* Wait until ready */
    UART->DATA_REG = (ch & 0xFF);
    return 1;
}

void uart_read()
{
    while(UART->STATUS_REG & EMPTY);    /* Wait for data present */
    return UART->DATA_REG;
}