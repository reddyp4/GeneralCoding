/* API for MyMalloc*/
#ifndef MY_MALLOC_H

#include <stdbool.h>
#define MY_MALLOC_H

// Max size is 1GB, 1000MB
#define MAX_MALLOC_SIZE     (1024*1024*16)

typedef struct malloc_str
{
    struct malloc_str* prev;                /*! Previous points to previous header */
    struct malloc_str* next;                /*! Previous points to next header */
    int size;                               /*! Stores the data section size */
    bool inUse;                             /*! Pointer to start of data */
    struct malloc_str* nextFree;
    struct malloc_str* prevFree;
} str_malloc;

void initMyMalloc();
str_malloc* newMalloc(int size);
void free(void *buffer);

// For debugging alone
void printMyMallocFreeList();

#endif
