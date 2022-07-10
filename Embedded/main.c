/* Main for functions */
#include <gpio_driver.h>

bool btn_state;
uint32_t sensorValue;

int main()
{
    p1_button_init();
    pa1_analog_init();
    uint32_t tempval[1]={0};

    linkedlist_create(tempval,1);       //linkedlist

    while(get_pc13_button_state())     //Wait forever until button is pressed
    {
        linkedlist_insert(head,0,read_chip_tempeature());
        linkedlist_insert(head,1,read_chip_tempeature());
        linkedlist_insert(head,2,read_chip_tempeature());
    }
    while(1)
    {
        btn_state = get_p13_button_state();
        sensorValue = analog_read();
    }
}
