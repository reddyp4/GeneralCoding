/* Question:  Design a system to open and close garage door opener given the HW 
- NVIC and 16-bit timer/counter:
    - Memory mapped register to setup interval of timer interrupt
    - Zero for no interrupts
- SENSOR:
    - Memory mapped register to read the distance of the door to the ground
    - 8-bit positive values in range of 0 to 255
- Motor: Use function "void set_speed(int Speed)" to set door speed and direction
    - Positive values to close the door
    - Negative values to open the door
- OPEN/CLOSE button to initiate door operations as needed
- STOP button to halt the motor immediately at any position
*/

#include <stdint.h>

// Binary semaphore
Sem_t sem;

void haltDoor()
{
    //
}

void haltButtonISR()
{
    halt = true;
    signalSemaphore(&sem);
}

bool openSwitch = false; //true: open it, false: close it

void openCloseSwitch()
{
    //
    openSwitch = readGPIO(GPIO_OPEN_CLOSE_SWITCH);
    halt = false;
    signalSemaphore(&sem);
}

// Assume it runs at 10Hz = 100ms
void timer_ISR()
{
    //
    signalSemaphore(&sem);
}

/* Get sensor value in inches */
uint8_t readSensor();

/* Set speed in inches/second */
void set_speed(int speed);

void taskDoorOperation() //Make this the highest priority task
{
    //
    while(1)
    {
        while(waitSemaphore());
        uint8_t door_opening = readSensor();
        if(halt)
        {
            set_speed(0);
        }
        if(openSwitch && door_opening < DOOR_OPEN_HEIGHT)
        {
            set_speed(0);
    }
        else if(!openSwitch && door_opening > 0)
        {
            set_speed(10);
        }
        else
        {
            // do nothing
        }
    }
}