'''
201. Bitwise AND of Numbers Range
Solved
Medium
Topics
Companies
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0
 

Constraints:

0 <= left <= right <= 231 - 1
'''

class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        i,num=0,0
        while(i<32):
            if(left+2**i<=right):
                i+=1
                num=(num<<1)|1
            else:
                break
        #anding number
        print("i:",i,",num:",num)
        return (right&(~num)&left)

'''
if left+2 exists within range, then left most bit flips through 0
if left+4 exists, then 2nd bit (from left) flips...

'''