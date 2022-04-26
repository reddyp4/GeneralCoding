/*
Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.
 

Constraints:

The input must be a binary string of length 32
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BIT(n) (1<<n)

struct 
{
    unsigned char bit1:1;
    unsigned char bit2:2;
    unsigned char bit3:3;
    unsigned char bit4:4;
    unsigned char bit5:5;
    unsigned char bit6:6;
    unsigned char bit7:7;
    unsigned char bit8:8;
} bitmap;

union bitfield
{
    uint32_t number;
    //bitmap map[4];
};
    //reverse 0,31 and so on
    //new.map[0] = n&0xFF;
    //new.map[1] = (n>>8)&0xFF;
    //.map[2] = (n>>16)&0xFF;
    //new.map[3] = (n>>24)&0xFF;
    //return final.number;

// Brute Force
uint32_t reverseBits(uint32_t n) {
    uint32_t final=0;
    uint32_t bitn=0;
    for(uint32_t i=0;i<32;i++)
    {
        bitn = (uint32_t)(1) <<i;
        final |= ((n&bitn)>>i)<<(31-i);
    }
    return final;
}

// Elegant - Mask & Shift
//The idea can be considered as a strategy of divide and conquer, where we divide the original 32-bits into blocks with fewer bits via bit masking, then we reverse each block via bit shifting, and at the end we merge the result of each block to obtain the final result.
uint32_t reverseBits2(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xFF00FF00)>>8) | (( n & 0x00FF00FF)<<8);
    n = ((n & 0xF0F0F0F0)>>4) | (( n & 0x0F0F0F0F)<<4);
    n = ((n & 0xCCCCCCCC)>>2) | (( n & 0x33333333)<<2);
    n = ((n & 0xAAAAAAAA)>>1) | (( n & 0x55555555)<<1);
    return n;
}


int main(void) 
{
    uint32_t n = 43261596;
    uint32_t new = reverseBits(n);
    printf("Original Number= %u, Reversed Number is %u\n",n,new);
    uint32_t new2 = reverseBits2(n);
    printf("Original Number= %u, Reversed Number is %u\n",n,new2);

    return 0;
}
