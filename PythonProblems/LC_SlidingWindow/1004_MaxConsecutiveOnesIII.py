'''
1004. Max Consecutive Ones III
Solved
Medium
Topics
Companies
Hint
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length
'''

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        #Form array of 0's
        len1=len(nums)
        print("len1:",len1)
        if(len1==1):
            if(nums[0]==1):
                return 1
            else:
                return k
        arrayZeroes = []
        for i in range(len1):
            if(nums[i]==0):
                arrayZeroes.append(i)
        print("Zeroes:",arrayZeroes)
        if(len(arrayZeroes)<=k):
            return len1
        #Sliding Window of k
        maxLength=0
        for i in range(len(arrayZeroes)-k+1):
            if(i==0):
                start=0
            else:
                start=arrayZeroes[i-1]+1
            if(i==(len(arrayZeroes)-1)-k+1):
                end = len1-1
            else:
                end = arrayZeroes[i+k]-1
            newlen = end-start+1
            print("start:",start,"end:",end,"newlen:",newlen,"maxLength:",maxLength)
            maxLength = maxLength if (maxLength>newlen) else newlen
        return maxLength

'''
Make array of zeroes
Then apply sliding window
'''