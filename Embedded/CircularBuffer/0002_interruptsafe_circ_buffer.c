/* Interrupt safe circular buffer */
/* To be interrupt safe, the index is modified after writing/reading from buffer */
/* Additionally, the index is modified inside the put/get */

/* How does this make it interrupt safe? 
If interrupt comes after reading memory, and put is completed, then after coming back
memory isnt corrupted
or vice versa
if interrupt comes after writing memory, and get is completed, it gets the new value
No lock is used! 
Additionally the buffer, head, tail have to be volatile
Source: https://www.downtowndougbrown.com/2013/01/microcontrollers-interrupt-safe-ring-buffers/
*/

/* Use 2^n for size 
When hitting end, head=(head+1)&63 is faster than modulo
*/
#define RING_SIZE   64

/* volatile to account for interrupts */
volatile uint8_t ring_pos_t
volatile ring_pos_t ring_head;
volatile ring_pos_t ring_tail;
volatile char ring[RING_SIZE];
volatile char size;

int add(char c)
{
    ring_pos_t next_head = (ring_head+1)&63;
    if(size!=64)
    {
        ring_data[ring_head]=c;
        ring_head=next_head;
        return 0;
    }
    return -1;
}

int remove(char c)
{
    if(size!=0)
    {
        int value=ring_data[ring_tail];
        ring_tail = (ring_tail+1)&63;
        return value;
    }
    return -1;
}