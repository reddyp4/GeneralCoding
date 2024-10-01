/* Given 8-bit pattern find pattern and return offset */
/* Note: can be unaligned */
#include<stdio.h>
#include<stdint.h>

/* Approach1: Take 8-bit& align & compare byte */

/* Approach2: Left-shift, compare last byte */
uint64_t pattern(uint8_t* input, int size_bytes, uint8_t pattern)
{
    uint8_t *current_byte,*next_byte;
    uint8_t byte;
    /* Initialize */
    current_byte=input;
    next_byte=(input+1);
    //printf("size of char:%d\n",sizeof(char));
    printf("input:%x, pattern:%x\n",*input,pattern);
    for(int i=0;i<size_bytes;i++)
    {
        printf("current:%x, next:%x\n",*current_byte,*next_byte);
        byte=*current_byte;
        for(int j=1;j<=8;j++)
        {
            printf("byte:%x, pattern:%x\n",byte,pattern);
            /* Check each 8-bit pattern */
            if(byte==pattern)   return (i*8+j);
            byte = ((*current_byte)<<j)|((*next_byte)>>(8-j));
        }
        current_byte++;
        next_byte++;
    }
    return -1;
}

int main()
{
    uint8_t bitstream[] = {0xAB,0xBC,0xCD,0xDE,0xEF,0xFF};
    uint8_t byte=0xCC;
    //printf("Bit stream: %x, byte:%x\n",bitstream,byte);
    //printf("%d\n",sizeof(bitstream));
    printf("Position:%llu\n",pattern(bitstream,sizeof(bitstream),byte));
    return 1;
}