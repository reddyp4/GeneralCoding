/*
// Write a function that swaps the highest bits in each nibble of the byte
// pointed to by the pointer b. (i.e. 0bAxxxBxxx -> 0bBxxxAxxx)
void swapBits(uint8_t* b)
{
}
0bAxxxBxxx -> 0bBxxxAxxx)
0bF0000000
0b0000F000
num = (num&0b0FFF0FFF) | ((num&0bF0000000)>>16) | ((num&0b0000F000)<<16)
*/
