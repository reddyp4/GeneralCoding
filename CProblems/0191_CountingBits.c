/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

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

int countBits(int n){
    // Use Brian Kernighan Algorithm
    uint32_t bits=0;
    while(n>0)
    {
        bits+=1;
        n = (n&(n-1));
    }
    return bits;
}

void main(void) {
    printf("Hello World!\n");
    uint32_t n = 15;
    printf("Number of bits of %d is %d\n",n,countBits(n));
}