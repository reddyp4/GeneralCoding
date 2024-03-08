/* Circular buffer concept */
#include<stdio.h>
#include<stdint.h>

#define BUFFER_SIZE 10

uint16_t BUFFER[BUFFER_SIZE];
uint16_t head=0;
uint16_t tail=0;
uint16_t filled=0;

void enque(uint16_t element)
{
    if(filled!=BUFFER_SIZE)
    {
        BUFFER[tail]=element;
        tail=((tail+1)%BUFFER_SIZE);
        filled+=1;
    }
    else
    {
        printf("Buffer full!\n");
    }
}

uint16_t deque(void)
{
    if(filled!=0)
    {
        uint16_t element = BUFFER[head];
        head=(head+1)%BUFFER_SIZE;
        filled-=1;
        return element;
    }
    else
    {
        printf("Buffer empty!\n");
        return -1;
    }
}

int main(void)
{
    printf("Returned element: %d\n",deque());
    for(int i =0;i<12;i++)
    {
        enque(i);
        printf("Enqueued %d\n",i);
    }
    for(int i=0;i<12;i++)
        printf("Returned element: %d\n",deque());
    return 1;
}