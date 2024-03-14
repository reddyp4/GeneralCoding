/* This is a general purpose gpio driver file */
/* @file    gpio.h */
/* @author  Patel B. Reddy */
/* @brief   GPIO HW Layer */

#include<stdint.h>
#include<gpio_hw.h>
#include<gpio.h>
#include<device.h>

#define PIN(X)  (1UL<<(X))  //shifting pinmask

/* Define each gpio data */
typedef struct gpio_handle_t
{
    /* data */
    uint32_t pin;               //pin
    gpio_State_t default_State; //default state
    GPIO_Direction direction;   //direction of gpio, in/out
};

/* make gpio table */
gpio_handle_t gpio_handle_table[GPIO_COUNT] = 
{
    //Index 0
    {
        .pin = 133,
        .default_state = HIGH,
        .direction = GPIO_DIR_MODE_OUT,
    }
    //Index 1
    {
        .pin = 93,
        .default_state = LOW,
        .direction = GPIO_DIR_MODE_OUT,
    }
    //Index 2
    {
        .pin = 86,
        .default_state = HIGH,
        .direction = GPIO_DIR_MODE_IN,
    }
};

/* INIT - called after entering main */
void gpio_init(void)
{
    GPIO_unlockPortConfig(GPIO_PORT_A, 0xFFFFFFFF);

    for(int ch=0;ch<GPIO_COUNT;ch++)
    {
        /* Set direction */
        GPIO_setDirectionMode(gpio_handle_table[ch].pin,gpio_handle_table[ch].direction);
        /* set/reset default state */
        if(gpio_handle_table[ch].default_State==HIGH)
        {
            gpio_set((gpio_Channel_t)ch);
        }
        else
        {
            gpio_reset((gpio_Channel_t)ch);
        }
        /* set pad configuration */
        if(ch==GPIO_ON_OFF_DSP_IN)
            GPIO_setPadConfig(gpio_handle_table[ch].pin,GPIO_PIN_TYPE_PULLUP);
    }
    /* any unbounded pull-ups */
    Device_enableUnboundedGPIOPullups();
    /* If XBAR, special GPIOs */
    XBAR_setInputPin(XBAR_INPUT1, 82);
}

/* do gpio_set */
void gpio_set(gpio_Channel_t channel)
{
    GPIO_writePin(gpio_handle_table[channel].pin, 1);
}

/* gpio reset */
void gpio_reset(gpio_Channel_t channel)
{
    GPIO_writePin(gpio_handle_table[channel].pin, 0);
}
