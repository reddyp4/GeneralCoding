/* 
Bounded Buffer

This is needed when there is a buffer to write to, and there are 
one producer and multiple consumers

Need a condition variable to awaken to consume.
Single mutex not enough, since multiple readers, and other readers need to sleep,
    until they get the signal to read

*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<uninstd.h>
#include<string.h>

/* Define the buffer in question */
#define SIZE 10
static int buffer[SIZE];
static int first_empty_slot;    /* We can write from here */
static int last_filled_slot;    /* We can consume till here */
static int count;   /* Count of consumers */

static pthread_mutex_t peek;
static pthread_cond_t not_full;     /* cv to signal producer to write */
static pthread_cond_t not_empty;    /* cv to signal consumer to read */

int consume(void)
{
    pthread_mutex_lock(&peek);      /* First grab the mutex */
    while(count == 0)       /* check if buffer is empty and wait to be filled */
        pthread_cond_wait(&not_empty,&peek);    /* sleep until mutex, not_empty is got */
    value = buffer[last_filled_slot];
    last_filled_slot = (last_filled_slot+1)%SIZE;
    count--;        /* This consumer is done */
    pthread_cond_signal(&not_full);     /* signal to writer in case of writing */
    pthread_mutex_unlock(&peek);    /* release the mutex */
    return value;
}

int produce(void)
{
    pthread_mutex_lock(&peek);
    while(count==SIZE)     /* check if buffer is full */
        pthread_cond_wait(&not_full,&peek);    /* wait for not_full and mutex */
    buffer[first_empty_slot] = value;
    count++;    /* update the count? */
    pthread_cond_signal(&not_empty);    /* wrote, so send not_compty cond signal */
    pthread_mutex_unlock(&peek);        /* release the mutex */
    return value;
}

int main()
{
    first_empty_slot = last_filled_slot = 0;

    pthread_mutex_init(&peek, NULL);    /* init the mutex */

    pthread_cond_init(&not_empty,NULL); /* init for consumer cv */
    pthread_cond_init(&not_full,NULL);  /* init for producer cv */
}