/* Simple Circular Buffer file 

1) Initialize
    Return circular buffer handle, given a buffer pointer and size
    Notice size is variable
    cbuf_handle_t circular_buffer_init(uint8_t *buffer, size_t size);
2) Free
    Free the buffer for circular buffer
3) Put
    Version1: Put data into the circular buffer, old data is overwritten
4) Put2
    Variation2: Put data into circular buffer, returns if full
5) Get
    Returns 0 on success, -1 if empty
6) IsEmpty
    Return true if buffer is empty
7) IsFull
    Return true if buffer is full
8) Capacity
    Returns the maximum capacity
9) CurrentSize
    Returns current size of the buffer

Source: https://embeddedartistry.com/blog/2017/05/17/creating-a-circular-buffer-in-c-and-c/
*/

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdlib.h>

/* Structure of the circular buffer */
typedef struct circular_buffer_t
{
    uint8_t *buffer;
    int head;
    int tail;
    int size;
    int max;
} circular_buffer_t;

/* Initialize the circular buffer with an existing buffer */
circular_buffer_t* circular_buffer_init(size_t size)
{
    if(size==0) return NULL;
    circular_buffer_t *CBUFFER = (circular_buffer_t*)malloc(sizeof(circular_buffer_t));
    CBUFFER->buffer = (uint8_t *)malloc(sizeof(uint8_t)*size);
    CBUFFER->head = 0;
    CBUFFER->tail = 0;
    CBUFFER->size = 0;
    CBUFFER->max = size;
    return CBUFFER;
}

/* Initialize the circular buffer with an empty buffer */
circular_buffer_t* circular_buffer_init2(size_t size)
{
    if(size==0) return NULL;
    circular_buffer_t *CBUFFER = (circular_buffer_t*)malloc(sizeof(circular_buffer_t));
    CBUFFER->buffer = (uint8_t *)malloc(sizeof(uint8_t)*size);
    CBUFFER->head = 0;
    CBUFFER->tail = 0;
    CBUFFER->size = 0;
    CBUFFER->max = size;
    for(int i=0;i<CBUFFER->max;i++)
        CBUFFER->buffer[i]=0;
    return CBUFFER;
}

/* Free the circular buffer */
void circular_buffer_free(circular_buffer_t* cbuf)
{
    free(cbuf->buffer);
    free(cbuf);
}

/* Put an element, return 0 if successful and 1 if not, overwrite */
int circular_buffer_put1(circular_buffer_t* cbuf, int value)
{
    /* Buffer is full, dont overwrite */
    if(cbuf->size==cbuf->max)   return 1;
    cbuf->buffer[cbuf->head] = value;
    cbuf->head = (cbuf->head+1)%(cbuf->max);
    cbuf->size++;
    return 0;
}

/* Get an element */
int circular_buffer_get(circular_buffer_t* cbuf)
{
    if(cbuf->size==0)   return -1;
    int value = cbuf->buffer[cbuf->tail];
    cbuf->buffer[cbuf->tail]=0;
    cbuf->tail = (cbuf->tail+1)%cbuf->max;
    cbuf->size--;
    return value;
}

/* Print contents of circular buffer */
void circular_buffer_print(circular_buffer_t* cbuf)
{
    for(int i=0;i<cbuf->max;i++)
        printf("%d ",cbuf->buffer[i]);
    printf("\n");
}

int main(void)
{
    /* declare the circular buffer */
    circular_buffer_t* CBUF;
    /* Initialize the circular buffer */
    CBUF = circular_buffer_init(10);
    /* Fill some items */
    for(int i=0;i<7;i++)
        circular_buffer_put1(CBUF,i);
    for(int i=0;i<5;i++)
        printf("Value popped: %d \n",circular_buffer_get(CBUF));
    /* print the buffer */
    circular_buffer_print(CBUF);
    /* Remove 5 elements */
    /* Insert again */
    for(int i=0;i<8;i++)
        circular_buffer_put1(CBUF,i+10);
    circular_buffer_print(CBUF);
    for(int i=0;i<7;i++)
        printf("Value popped: %d \n",circular_buffer_get(CBUF));
    /* print the buffer */
    circular_buffer_print(CBUF);
}