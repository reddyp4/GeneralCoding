int count_continue_ones(uint64_t x) {
    int maxval = 0, current=0;
    for (int i=0;i<64;i++)
    {
        if (x&(0x1ULL<<i))
        {            
            current++;
            //printf("%d mask:0x%08X current%d\n", i, 0x1 <<i, current);
        }
        else
        {
                maxval = (current>maxval)? current : maxval;
                current=0;
        }
    }
    maxval = (current>maxval)? current : maxval;
    return maxval;
}

int main(void)
{
    //uint64_t x = 0xF0FF040FFFULL;
   // uint64_t arr[] = {0xF0F0F80ULL, 0xFFF080BLL, 0xF, 0x4, 0xC, 0xF0FF040FFF};
    uint64_t arr[] = { 0xF0FF040FFF,  0xFFFFFFFFFFFFFF00ULL};
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
        printf("Max length: %d\n",count_continue_ones(arr[i]));
    
    return 0;
}
