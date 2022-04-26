/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

Constraints:

0 <= n <= 105
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdint.h>

int returnBits(int val)
{
    int bits=0;
    while(val>0)
    {
        bits+=1;
        val = val&(val-1);
    }
    return bits;
}

void countBits(int n, int* returnSize){
    int count;
    for(count=1;count<=n;count++)
    {
        *returnSize = returnBits(count);
        returnSize++;
        //printf("Number = %d, Bits = %d\n",count,*(returnSize-1));
    }
}

int main(void) 
{
    printf("Hello World!\n");
    int n = 5;
    int m=0,k=0;
    int* returnSize;
    returnSize = &m;
    //printf("Number of bits of %d is %d\n",n,*returnSize);
    countBits(n,returnSize);
    printf("[");
    for(k=0;k<5-1;k++)
    {
        //printf("Number of bits of %d is %d\n",n,*(returnSize+k));
        printf("%d, ",*(returnSize+k));
    }
    printf("%d ]\n",*(returnSize+k));
    return 0;
}
