/* Given 8-bit pattern find pattern and return offset */
/* Note: can be unaligned */
#include<stdio.h>
#include<stdint.h>

/* Approach1: Take 8-bit& align & compare byte */

/* Approach2: Left-shift, compare last byte */
uint64_t pattern(char* input, int size_bytes, char pattern)
{
    char *current_byte,*next_byte;
    /* Initialize */
    current_byte=input;
    next_byte=(input+1);
    for(int i=0;i<size_bytes;i++)
    {
        for(int j=1;j<=8;j++)
        {
            /* Check each 8-bit pattern */
            if(*current_byte==pattern)   return (i*8+j);
            *current_byte = ((*current_byte)<<j)|((*next_byte)>>(8-j));
        }
        current_byte++;
        next_byte++;
    }
    return -1;
}

int main()
{
    return 1;
}