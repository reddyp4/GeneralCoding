#IFNDEF GPIO_H
#DEFINE GPIO_H

typedef struct 
{
    uint32_t pin;
    uint32_t mode;
    uint32_t pull;
    uint32_t speed;
    uint32_t alternate;
} GPIO_InitTypeDef;


typedef enum
{
    OFF=0,
    ON
} GPIO_PinState;

class Gpio
{
    private:
        GPIO_TypeDef GPIO_regStr;   /* comes for ST */
        GPIO_InitTypeDef GPIO_initStruct;
    public:
        Gpio(PORT_NameType GPIO_PortName);
        void gpio_init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *gpio_init);
        void gpio_write(GPIO_TypeDef *GPIOx, uint16_t pin, GPIO_PinState state);
        void gpio_toggle(GPIO_TypeDef *GPIOx, uint16_t pin);
}

#ENDIF