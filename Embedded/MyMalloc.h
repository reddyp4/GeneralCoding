/* API for MyMalloc*/
#ifndef MY_MALLOC_H

#define MY_MALLOC_H

// Max size is 1GB, 1000MB
#define MAX_MALLOC_SIZE     (1024*1024*16)

void initMyMalloc();
void *MyMalloc(int size);
void free(void *buffer);

// For debugging alone
void printMyMallocFreeList();

#endif
