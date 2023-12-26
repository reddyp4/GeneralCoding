'''
477. Total Hamming Distance
Medium
2.2K
88
company
Facebook
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:

Input: nums = [4,14,2]
Output: 6
Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just
showing the four bits relevant in this case).
The answer will be:
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.
Example 2:

Input: nums = [4,14,4]
Output: 4
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 109
The answer for the given input will fit in a 32-bit integer.
'''

class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        sum1,len1=0,len(nums)
        #M1: Time exceeded for one case, Hamming+hashmap
        #M2: Find bit set from 1 to 32 for each number.
        count=[0]*32
        for index,elem in enumerate(nums):
            i=0
            while(elem>0):
                count[i]=count[i]+int(elem&0x01)
                elem=elem>>1
                i=i+1
        for index,elem in enumerate(count):
            sum1=sum1+elem*(len1-elem)
        return sum1
        #M1
        '''
        for i in range(256):
            count=0
            k=i
            while(k):
                count=count+1
                k=k&(k-1)
            d[i]=count
        for i in range(256,256*256):
            d[i]=d[i&0xFF]+d[(i>>8)&0xFF]
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                k=nums[i]^nums[j]
                sumnew=d[k>>16]+d[k&0xFFFF]
                sum1=sum1+sumnew
        return sum1
        '''

'''
Bruteforce method gives time limit issues.
Can save time by hash? Still not working within timelimits
'''

