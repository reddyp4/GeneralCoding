/* Adding the thread safety to circular buffer */
/* Thready safety: Producer modifies head, consumer modifies tail */
/* Lock needed on head and tail */
/* https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/ */

/* Single producer and singe consumer: look-ahead method 
Multiple p/c need a lock, from pthread, especially when writing/reading */

/* Write in ISR, read in main */
/* Shift to volatile for buffer, head and tail in global variables */
volatile char circ_buf[n] = {0};
volatile size_t head_index = 0;
volatile size_t tail_index = 0;

void buffer_input(const char c)
{
    if((head_index+ 1) % n != tail_index) {
        //Only if buffer is not full
        circ_buf[head_index] = c;
        head_index = (head_index + 1) % n;
    }
}

char buffer_read(void)
{
    if (tail_index != head_index)
    {
        char c = circ_buf[tail_index];
        tail_index = (tail_index + 1) % n;
        return c;
    }
    //Lets assume 0 will never be content of the buffer for this example
    return 0;
}
