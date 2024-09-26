/* Design a circular buffer to be used a processor */
typedef struct circularBuffer
{
    uint8_t *data;
    uint8_t head,tail,size;
} circularBuffer;

void push(circularBuffer* CB, uint8_t value)
{
    if(CB->head==-1)
    {
        /* Empty Queue */
        CB->head = (CB->head+1)%(CB->size);
        CB->data[] = data;
        CB->tail = 0;
        CB->head++;
    }
    else if(CB->head==CB->tail)
    {
        /* FULL, DO NOTHING */
    }
    else
    {
        CB->data[CB->head] = value;
        CB->head = (CB->head+1)%(CB->size);
    }
}

uint8_t pop(circularBuffer *CB, uint8_t *val)
{
    if(CB->head==-1)
    {
        /*Empty Buffer */
        return 0;
    }
    *val = CB->data[CB->tail];
    CB->tail = (CB->tail+1)%(CB->size);
    if(CB->head==CB->tail)
    {
        /*Empty*/
        CB->head=CB->tail==-1;
    }
    return 1;
}