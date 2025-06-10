/*i2c - device

i2c_init()  - initializing the i2c driver - 
    STM32 - Assigning GPIO - 2 primary pins - GPIO 
    Hardware config - pull-up/down, clock, pins (non-gpio) 
i2c_write(uint8_t reg, uint8_t data)
    writing data to a register - byte level, 4-byte, multiple
    (start, length, source) - more than 1 byte 
    ACK-logic
    retries-
uint32_t i2c_read(uint32_t reg)
    read register value
    read a stread for a given length

EEPROM: Memory is 256 bytes total, r/w, use on stm32/other devices */

void i2c_init();    //init was done in main

int nvram_write(uint8_t *src, uint32_t length, uint8_t dest)
{
    int value=0;
    for(uint32_t i=0;i<length;i++)
    {
        //value=(int)i2c_write(*dest++,*src++);    //dest, byte to be written, ACK bit
        value=(int)i2c_write(dest+i,*(src+i));    //dest, byte to be written, ACK bit
        if(value==1)
            break;  //    return -1;      //fail
        //while(i2c_write(*dest++,*src);    //dest, byte to be written, ACK bit
    }
    //return 0;
    return value;
}

//MISRA - conventions