'''
53. Maximum Subarray
Solved
Medium
Topics
Companies
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
'''
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        #Use prefix with check at element
        len1=len(nums)
        if(len1==1):
            return nums[0]
        maxSum,currentSum=-10**5,0
        for i in range(len1):
            currentSum+=nums[i]
            if(nums[i]>currentSum):
                currentSum=nums[i]
            maxSum=max(maxSum,nums[i],currentSum)
        currentSum=0
        for i in range(len1-1,-1,-1):
            currentSum+=nums[i]
            if(nums[i]>currentSum):
                currentSum=nums[i]
            maxSum=max(maxSum,nums[i],currentSum)
        return maxSum

'''
prefix Sum solution:
if current prefixsum<currentnum, update prefixsum to current
<Why add a negative number to current num! >
'''