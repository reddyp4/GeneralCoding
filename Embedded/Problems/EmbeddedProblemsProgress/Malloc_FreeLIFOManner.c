#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Fixed size buffer */
#define BUFFER_SIZE 100

/* Structure to represent allocated memory block */
typedef struct 
{
    /* data */
    void *addr; //start address of memory block
    size_t size;    //size of memory block
} AllocatedBlock;

/* Memory pool */
char MemoryPool[BUFFER_SIZE];

/* Stack pointer to keep tract of top element */
char *stackTop = MemoryPool;

/* Stack to keep track of allocated blocks */
AllocatedBlock allocatedBlocks[BUFFER_SIZE];

int blockCount=0;   //Keep track of allocated blocks

/* Function to allocate memory in a LIFO manner */
void *AllocMemory(size_t size)
{
    /* Check if size is enough */
    if(MemoryPool + BUFFER_SIZE < size + stackTop)
    {
        printf("Not enough memory available to allocate %zu bytes\n", size);
        return NULL;
    }
    /* Allocate memory by moving the stack pointer */
    void *allocAddr = stackTop;
    /* Update stackTop */
    stackTop+= size;

    /* Store allocation chunks in allocatedBlcoks */
    allocatedBlocks[blockCount].addr = allocAddr;
    allocatedBlocks[blockCount].size = size;
    blockCount++;

    printf("Allocated %zu bytes at address: %p\n",size, allocAddr);
    return allocAddr;
}

/* function to free chunk of memory in LIFO manner */
void freeChunkMemory()
{
    if(blockCount==0)
    {
        printf("No blocks to free\n");
        return;
    }
    /* Get last assigned block */
    AllocatedBlock lastChunk = allocatedBlocks[--blockCount];
    stackTop -= lastChunk.size;
    /* freed block by updating the stacktop */
    printf("Freed %zu bytes from address: %p\n",lastChunk.size,lastChunk.addr);
}

int main()
{
    void *ptr1 = AllocMemory(10);    //10 bytes
    void *ptr2 = AllocMemory(20);    //10 bytes
    void *ptr3 = AllocMemory(30);    //30 bytes

    freeChunkMemory();  //Frees ptr3
    void *ptr4 = AllocMemory(40);

    freeChunkMemory();  //Frees ptr3
    freeChunkMemory();  //Frees ptr3
    freeChunkMemory();  //Frees ptr3
    return 0;
}