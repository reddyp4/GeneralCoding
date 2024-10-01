/* 0xAxxxBxxx -> 0bBxxxAxxx*/
#include<stdio.h>
#include<stdint.h>

uint8_t swapBits(uint8_t b)
{
    uint8_t answer=(b&0x77);
    answer |= (((b&0x80)>>7)<<3);
    answer |= (((b&0x8)>>3)<<7);
    return answer;
}

int main(void)
{
    uint8_t b=0xA4;
    printf("Original:%x, Swapped:%x\n",b,swapBits(b));
    return 1;
}