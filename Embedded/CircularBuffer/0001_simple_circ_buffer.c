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

*/

#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

/* Structure of the circular buffer */
typedef struct circular_buffer_t
{
    uint8_t *buffer;
    int head;
    int tail;
    int size;
    int max;
};

/* Initialize the circular buffer with an existing buffer */
circular_buffer_t* circular_buffer_init(uint8_t *buffer, size_t size)
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