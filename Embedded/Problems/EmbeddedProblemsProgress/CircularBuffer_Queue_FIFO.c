/* Design a circular buffer to be used a processor */
typedef struct circularBuffer
{
    uint8_t *data;
    uint8_t head,tail;
} circularBuffer;

void push(circularBuffer* CB, uint8_t value)
{
    if(CB->head==-1)
    {
        /* Empty Queue */
        CB->data[++CB->head] = data;
        CB->tail = 0;
        CB->head++;
    }
    else if(CB->head==CB->tail)
    {
        /* FULL, DO NOTHING */
    }
    else
    {
        CB->data[CB->head++] = data;
    }
}

uint8_t pop(circularBuffer *CB, uint8_t *val)
{
    if(CB->head==-1)
    {
        /*Empty Buffer */
        return 0;
    }
    *val = CB->data[CB->tail++];
    if(CB->head==CB->tail)
    {
        /*Empty*/
        CB->head=CB->tail==-1;
    }
    return 1;
}