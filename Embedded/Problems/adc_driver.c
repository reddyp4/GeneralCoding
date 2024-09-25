#include "adc_driver.h"
#include "stm32f4xx.h"

void pa1_analog_init(void)
{
    //Enable clock access to gpioa
    RCC->AHB1ENR |= (1U<<0);

    //Set PA1 as analog pin
    GPIOA->MODER |= (1U<<2);
    GPIOA->MODER |= (1U<<3);

    //Set ADC1
    RCC->APB2ENR |= (1U<<8);    //Enables clock access to ADC1
    ADC1->CR2 = 0;     // SW Trigger, writing zero to it, gives SW trigger, disables adc
    ADC1->SQR3 = 1;     // Conversion sequence starts at CH1
    ADC1->SQR1 = 0;     // Conversion sequence length is 1
    ADC1->CR2 = (1U<<0);    // Enable ADC1
}


//Function to get adc result
uint32_t pa1_analog_read(void)
{
    ADC1->CR2 |= (1U<<30);      // Start a conversion
    while(! (ADC1->SR & (1U<<1)));  // Wait until the status register and conversion complete
    return ADC1->DR;    //Return value of data register
}

// Configure TIMER2 to generate 1Hz output
// to trigger on_chip_tempeture sensor adc conversion 
// sysclock = TIM2 clock source, 16 MHz
// 16 000 000 / 1 600 = 10 000
// 10 000 / 10 000 = 1
void temp_sensor_init(void)
{
    //Setup TIM2
    RCC->APB1ENR |= (1U<<0);    //Enable clock to Timer2
    TIM2->PSC = 1600 -1;    //Clock divided by 1600
    TIM2->ARR = 10000-1;   //Auto reload register, divide by 10000, sample at 1 Hz
    TIM2->CNT = 0;
    TIM2->CCMR1 = 0x00006800;   //pwm1 mode, preload enable
    TIM2->CCER = 0x10;        //enable channel2 (1U<<4), capture/compare enable register
    TIM2->CCR2 = 50-1;          //Capture/compare register, high value compare 2
    TIM2->CR1 = 1;              //Enable TIM2

    //Setup ADC
    RCC->APB2ENR |= (1U<<8);    //Clock to adc
    ADC->CCR |= (0x8000);       //Turn on tempsensor, disable vbat
    ADC->CCR &= (0x4000);       //Set Bit22 to zero
    ADC1->SMPR1 = 0x4000000;        //Set min sampling time to 10 us
    ADC1->SQR3 = 18;    //Connected to adc18
    ADC1->CR2 = 0x13000000;     //Trigger is external, rising edge, extsel3 = time2, channel2
    ADC1->CR2 |= 1; //Enable adc1, same as 1u<<0, by default hex 0001
}

double read_chip_temperature(void)
{
    uint32_t data;
    double volt, temp;
    while(!(ADC1->SR)&(1U<<1))
    {
        //
    }
    data = ADC1->DR;    //Get adc value into data
    volt = (double)(data/4095*3.3f);    //convert adc output to voltage
    temp = (volt-0.76)/0.0025 + 25;     //formula to convert volt into degC
    return temp;
}