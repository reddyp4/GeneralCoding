/* Malloc with fixed size blocks */

/* BUFFER_SIZE */
#define BUFFER_SIZE 100

/* Structure with head/data */
typedef struct 
{
    void *addr;
    size_t size;
} block;

/* Need a stack pointer to keep track of top */
char* stackTop;

/* Need a memory pool to keep track of first element of memory*/
char MemoryPool[BLOCK_SIZE];

/* */
void *malloc1()
{
    /* check if size is feasible */
    if(size > sizeof(block) )
}