/* Operating System Fundamentals for Embedded Systems */
/* https://sites.cs.ucsb.edu/~rich/class/cs170/ */
/* My malloc */
/* Dynamic Memory Allocator */

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "MyMalloc.h"

int globalMemory[MAX_MALLOC_SIZE];
str_malloc globalStr={0};

/* initMyMalloc*/
/* Initialize the structure*/
void initMyMalloc(void)
{
    /* Create malloced list */
    /* Already done in global structure? */
    globalStr.prev = &(globalMemory[0]);
    globalStr.next = &(globalMemory[0]);
    globalStr.size = globalMemory[0];
    printf("Sizeof(str_malloc)=%d\n",(int)(sizeof(str_malloc)));
    //globalStr->buffer = 0;
}

str_malloc* newMalloc(int size)
{
    str_malloc* new = NULL;
    /* Check if size can fit*/
    if(size>(MAX_MALLOC_SIZE-globalStr.size))
    {
        printf("Malloc failed! Size limit!\n");
    }
    else
    {
        //Go to end of current data and start header there
        //Get next pointer, and put header there

        //Update the globalMemoryStructure
        //New Previous
        globalMemory[globalStr.next] = globalMemory[globalStr.next]
        //New Next
        //New size
        //New buffer

        //Four Steps for updating the header.
        //Update new prev should point to end of last data
        //Update prev
        globalStr.prev = &globalMemory[*globalStr.next+sizeof(str_malloc)+size];
        //Update data
        //Update next
        globalMemory[*globalStr.next+sizeof(str_malloc)+size] = (*globalStr.next+sizeof(str_malloc)+size);
        globalStr.next = &globalMemory[*globalStr.next+sizeof(str_malloc)+size];

        //globalMemory[globalStr.next]
        //Update next
        //Update size
        //Update data
        //globalMemory[globalStr.next]+= sizeof(str_malloc);
        //Add data
        //for(int i=0;i<size;i++)
        //{
        //    globalMemory[i+globalStr.next] = i+globalStr.next;
        //}
        //Update header
        //globalMemory[globalStr.next]+= sizeof(str_malloc);

        //globalStr
    }
    /* Assume continguous and assign towards memory towards the end */
    /* Need list of final malloced structure */ 
    /* (Optional) Sort the memory in decreasing size*/
    return new;
}

void printMyMallocFreeList()
{
    //Print the list of headers
    printf("Main Structure, prev = %d\n",*(globalStr.prev));
    printf("Main Structure, next = %d\n",*(globalStr.next));
    printf("Main Structure, size = %d\n",globalStr.size);
}


/* Simple test for malloc */
int main(int argc, char *argv[])
{
    char *array;
    int i;
    str_malloc* first;

    /*Initialize malloc*/
    initMyMalloc();

    /*Call Malloc*/
    first = newMalloc(128);
    /*Free Malloc*/

    /*Print Malloced Structure*/
    printMyMallocFreeList();

    return 0;
}