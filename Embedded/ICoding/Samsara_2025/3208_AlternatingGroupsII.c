/*
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

Example 1:

Input: colors = [0,1,0,1,0], k = 3

Output: 3

Explanation:



Alternating groups:



Example 2:

Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2

Explanation:



Alternating groups:



Example 3:

Input: colors = [1,1,0,1], k = 4

Output: 0

Explanation:



 

Constraints:

3 <= colors.length <= 105
0 <= colors[i] <= 1
3 <= k <= colors.length
*/

/* 
parking spot=427

Idea is to calculate the k'number xor 
and move the array one step a time
lets say array is from n to n+k-1
store alternates in array alternate=[]

xor sequence array
correct sequence has all elements as one
incorrect sequence has atleast one element is not one
*/

int numberOfAlternatingGroups(int* colors, int colorsSize, int k) {
    /* make alternate array first time */
    int alternate=0,count=0;
    int first, last;
    for(int i=0;i<k-1;i++)
    {
        alternate+=(colors[i]^colors[(i+1)%colorsSize]);
        //printf("%d,%d\n",i,alternate);
    }
    if(alternate==(k-1))  count++;
    /* now move the xor array by each element, check the first two elements, and next element only */
    for(int i=0;i<colorsSize-1;i++)
    {
        /* current array is from 0+i to k-1+i */
        first=i;last=k-1+i;
        /* check first and last elements only */
        if(colors[first]^colors[(first+1)%colorsSize])   alternate--;
        if(colors[last%colorsSize]^colors[(last+1)%colorsSize])   alternate++;
        if(alternate==(k-1))    count++;
        //printf("%d,%d,%d,%d\n",first,last,alternate,count);
    }
    return count;
}
