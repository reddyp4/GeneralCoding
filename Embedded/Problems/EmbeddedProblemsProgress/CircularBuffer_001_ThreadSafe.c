/* Adding the thread safety to circular buffer */
/* Thready safety: Producer modifies head, consumer modifies tail */
/* Lock needed on head and tail */
/* https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/ */

/* Single producer and singe consumer: look-ahead method 
Multiple p/c need a lock, from pthread, especially when writing/reading */

/* Write in ISR, read in main */
/* Shift to volatile for buffer, head and tail in global variables */
#include <pthread.h>

volatile char circ_buf[n] = {0};
volatile size_t head_index = 0;
volatile size_t tail_index = 0;

volatile pthread_mutex_t LOCK;
pthread_mutexattr_t attr;
pthread_cond_t *CV;

void buffer_init()
{
    pthread_mutex_init(&LOCK, &attr);
}

void buffer_input(const char c)
{
    pthread_mutex_lock(LOCK);
    if((head_index+ 1) % n == tail_index)
    {
        //Buffer is full
        pthread_cond_wait(LOCK,CV);
        /* COND_WAIT: 1) unlock mut, 2) sleep, 3) lock mut*/
    }
    /* If you are here, mutex is on, cv is done, ready to wrte*/
    //Only if buffer is not full
    circ_buf[head_index] = c;
    head_index = (head_index + 1) % n;
    pthread_cond_signal(CV);
    pthread_mutex_unlock(&LOCK);
}

char buffer_read(void)
{
    pthread_mutex_lock(LOCK);
    if (tail_index == head_index)
    {
        /* buffer is empty, wait until available */
        pthread_cond_wait(LOCK,CV);
        /* COND_WAIT: 1) unlock mut, 2) sleep, 3) lock mut*/
    }
    char c = circ_buf[tail_index];
    tail_index = (tail_index + 1) % n;
    //Lets assume 0 will never be content of the buffer for this example
    pthread_mutex_unlock(LOCK);
    return c;
}
