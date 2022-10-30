/*
Assume no existing malloc/free implementations on the platform
intended for an embedded processor
Unspecified allocation pattern and sizes
*/

//(void*)malloc(k*sizeof(data_type));
//free(void*)

/*
Implementation issues:
1) data_type 
2) alignment issues 
3) finding the free space 
4) maintaing the queue - extra space 
5) fixed vs non-fixed size blocks 
*/

/*
Issues:
Book-keeping: 
    sizes of what is in use and free 
    Linked-list, array, bitmap, structure 
how to choose free block? 
    first fit or best fit 
    fragmentation - internal or external 
    alignment 
malloc vs free 
    coaceing/merging of free blocks 
    constant or top speed which is fastest? 
where does the memory come from? 
    sbrk 
    linker script 
    global variable 

*/


//Lets implement a linked list for the header
typedef struct block {
    uint32_t len;
    struct block *next;
    uint32_t data[];
} block_size;

static uint8_t 

// Linkedlist of free blocks
void* malloc(size_t cnt)
{
    block* iter = free_list, *prev=NULL;
    if(0==cnt)
        return NULL;
    while(NULL!=iter)
    {
        if(iter->len)
    }
}
