/* Memcpy copies 1 byte at a time, like a char or uint8_t */
/* C implementation here */
#include <string.h>
#include <stdio.h>
#include <stdint.h>
// Measuring time
#include <time.h>

#define SIZE_MAX1    1000000
/* void* for both source and destination 
   This allows for copy of any input */
/* Simplest memcpy function */
void myMemCpy(void *dest, void *src, size_t n)
{
    char *csrc = (char *) src;
    char *cdest = (char *) dest;
    for(int i=0;i<n;i++)
    {
        *(cdest+i) = *(csrc+i);
    }
}

/* Copy by 32 bits instead of 8 bits */
void myMemCpy32(void *dest, void const *src, size_t n)
{
    long * plDst = (long *) dest;
    long const * plSrc = (long const *) src;

    //if (!(src & 0xFFFFFFFC) && !(dest & 0xFFFFFFFC))
    //{
    while (n >= 4)
    {
            *plDst++ = *plSrc++;
            n -= 4;
    }

    char * pcDst = (char *) plDst;
    char const * pcSrc = (char const *) plSrc;

    while (n--)
    {
        *pcDst++ = *pcSrc++;
    }
#if 0
    long *pDest32 = (long *) dest;
    long *pSrc32 = (long *) src;
    /* First copy 4 bytes at a time */
    for(int i=0;i<(int)(n/4);i++)
    {
        *(pDest32+i) = *(pSrc32+i);
    }
    /* Last copy remaining bytes at a time */
    char *csrc = (char *) pSrc32;
    char *cdest = (char *) pDest32;
    for(int i=0;i<(int)(n%4);i++)
    {
        *(cdest+i) = *(csrc+i);
    }
#endif
}

int main()
{
    char src[] = "This is memcpy!";
    char dest[100];
    myMemCpy(dest, src, strlen(src)+1);
    printf("Destination: %s\n",dest);

    // Copying int variables
    uint16_t isrc[SIZE_MAX1];
    for(int i=0;i<SIZE_MAX1;i++) isrc[i]=i;
    // Get size
    unsigned long
     size_isrc = sizeof(isrc)/sizeof(isrc[0]);
    uint16_t idest[size_isrc],i;
    //Run memcpy
    clock_t begin = clock();
    //myMemCpy(idest, isrc, size_isrc);
    myMemCpy32(idest, isrc, size_isrc);
    clock_t end = clock();
    double time_spent = (double)(end-begin)/CLOCKS_PER_SEC*1e6;
    // Time spent
    printf("Time taken: %f, size = %lu\n", time_spent,size_isrc);
    //print out
    //for(int i=0;i<size_isrc;i++)
    //    printf("val[%d]=%d\n",i,idest[i]);

    return 0;
}