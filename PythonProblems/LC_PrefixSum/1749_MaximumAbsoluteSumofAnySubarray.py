'''
1749. Maximum Absolute Sum of Any Subarray
Medium
Topics
Companies
Hint
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
'''

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        len1=len(nums)
        if(len1==1):
            return nums[0]
        currentSum,maxSum=0,0
        for i in range(len1):
            currentSum+=nums[i]
            print("nums[i]:",nums[i],"current:",currentSum,"max:",maxSum)
            if(abs(currentSum)<abs(nums[i])):
                currentSum=nums[i]
            maxSum=max(maxSum,abs(currentSum),abs(nums[i]))
        return maxSum