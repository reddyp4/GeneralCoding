/* This is a header for a general purpose gpio driver */

/* Double inclusion guard */
#ifndef GPIO_HW_H
#define GPIO_HW_H

#include <stdint.h>

/* Define states of GPIO */
typedef enum{
    LOW=0,
    HIGH
} gpio_State_t;

/* define all the gpios */
typedef enum{
    GPIO_0=0,
    GPIO_1,
    GPIO_2,
    GPIO_COUNT
} gpio_Channel_t;

/* define gpio inputs */
typedef enum{
    GPIO_INPUT_1 = GPIO_1,
    GPIO_INPUT_COUNT=1
} gpio_input_t;


/* gpio functions init, set, reset */
void gpio_init(void);
void gpio_set(gpio_Channel_t channel);
void gpio_reset(gpio_Channel_t channel);
void gpio_toggle(gpio_Channel_t channel);
void gpio_read(gpio_Channel_t channel);

#endif
