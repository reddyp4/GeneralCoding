#include "stdio.h"

int main()
{
    uart_init();
    while(1)
    {
        uart_write(val);
        printf("received=%d\n", uart_read());
    }
}