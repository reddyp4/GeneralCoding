
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int getBits(int a)
{
    int val=0;
    while(a>0)
    {
        val+=1;
        a = a^(a-1);
    }
    return val;
}

int* sortByBits(int* arr, int arrSize, int* returnSize){
    // Malloc the final array
    int* final = (int*)malloc(arrSize*sizeof(int));
    //Set returnSize
    *returnSize = arrSize;

    // Get Bits first
    int bits[arrSize];
    for(i=0;i<arrSize;i++)
    {
        bits[i] = getBits(*(arr+i));
    }
    // Sort array based on bits
    // 
    return final;
}

int main(void) 
{
    int* nums;

    int array[9] = {0,1,2,3,4,5,6,7,8};
    nums = &array[0];
    int* final;
    int num = 9;
    int* returnSize;
    returnSize = &num;
    final = sortByBits(nums,9,returnSize);

    //printf("Missing Number = %d\n",missing);
    return 0;
}