/* GPIO Driver */
/* Connect hardware to data structure */
#include "gpio_driver.h"
#include "stm32f4xx.h"
#include <stdio.h>

void p1_button_init(void)
{
    RCC->AHB1ENR |= (1U<<2);    // Enable clock access to PORTC

    //Set P13 as input
    GPIOC->MODER &= (0U<<26);
    GPIOC->MODER &= (0U<27);
}

bool get_p13_button_state(void)
{
    //Read the status of GPIO read buffer
    GPIOC-> IDR &= (1U<<13);
}

int main()
{
    // Initialization
    // printf("Hello from main function");
    while(1)
    {

    }
}

