/* Design aligned_malloc and aligned_free functions.

    32-bit system
    12 bytes
    4-4-4-

    4-byte aligbed
    0X1232 - NOT ALIGNED
    1230-1234-1238 - ALIGNED

    first time
    10-bytes - 1230-1234-1238-1242-
    second time
    4bytes - 1242

*/

uint8_t* aligned_malloc(int size)
{
    uint8_t *ptr;
    if(size%4==0)
        ptr=(uint8_t*)malloc(size);
    else
        ptr=(uint8_t*)malloc(4*(int)(size/4)+4);    //4*(10/4)=4*2=8, 8+4=12, 2bytes is buffer, ask was 10bytes
    return ptr;
}

uint8_t* aligned_free(uint8_t *ptr)
{
    free(ptr);
}
