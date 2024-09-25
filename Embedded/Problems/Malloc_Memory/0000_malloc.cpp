/*
Question: Design a malloc without any system calls from scratch
(discuss different search algo, first-fit, best fit etc)
*/

//Define the basic block as per Embedded_0001_Malloc.c
using word_t = intptr_t;

struct block {
    size_t size;
    bool used;
    block *next;
    word_t data[1];
}

/* Heap start, of all the headers */
static block *heapStart = nullptr;

/* top */
static auto top = heapStart;
