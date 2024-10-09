/* Fixed size malloc implementation here */
// Sources
// https://github.com/subhashjadvani/algorithms/blob/main/c-language/pool_allocator/fast_efficient_fixed_size_memory_pool.cpp
// https://embeddedartistry.com/blog/2017/02/15/implementing-malloc-first-fit-free-list/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* block structure */
typedef struct block {
    uint32_t len;
    struct block *next;
    uint32_t data[];
} block;

#define HEAP_SIZE 100   /* Number of blocks */
static uint8_t *free_list = NULL;   /* Maintain the free list*/

/* Initialization function */
void my_init(void)
{
    /* Assign free list */
    free_list = (block*)heap;
    free_list->len = 0;
    free_list->next = NULL;
}

void* my_malloc(size_t size)

{
    block *current = free_list;
    block *prev = NULL;
    /* Check if null Freelist, if not attach at end */
    if(current!=NULL)
    {
        /* Non-empty free-list */
        /* check if size fits */
        if(curr->len>=size)
        {
            /*size fits */
            int32_t remainder = curr->len - size - sizeof(block);
            /* allocate current entry */
            if(prev == NULL)
            {
                free_list = curr->next;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
            }
            /* Split the list */
            if(remainder>0)
            {
                /* assign space */
                block *new = (block*)((uintptr_t)curr->data + size);
                new->len = remainder;
                new->next = free_list;
                free_list = new;
                curr->len = size;
            }
            break;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    /* Memory already allocated, return pointer to data */
    if(curr!=NULL)
        return curr->data;
    else
        return NULL;
}

/* Free memory, simply add to free_list */
void my_free(void *ptr)
{
    block *b = (block*)((uintptr_t)ptr - sizeof(block));

    /* Check if free ptr is witin range */
    if( !ptr || (uintptr_t)ptr > (uintptr_t)heap || (uintptr_t)ptr < (uintptr_t)heap)
        return;
    b->next = free_list;
    free_list = b;
}

int main()
{
    my_init();
    uint8_t *ptr;
    size_t size;

    size = 100;
    ptr = my_malloc(size);
    printf("malloc(%zu): ptr %p heap %p sizeof(block) 0x%lx\n",size,ptr,heap,sizeof(block));
}

// Others
// https://gist.github.com/DmitrySoshnikov/e51ebc51a0a27b87cf466a33ce97458c
// http://dmitrysoshnikov.com/compilers/writing-a-pool-allocator/
