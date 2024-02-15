'''
55. Jump Game
Solved
Medium
Topics
Companies
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
'''

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if(len(nums)==1):
            return True
        dpend,len1,i = nums[0],len(nums),0
        while(i<len1 and i<=dpend):
            if(nums[i]+i) > dpend:
                dpend = nums[i]+i
            i+=1
        if(dpend>=len1-1):
            return True
        return False

'''
Traditional dp: set dp[i+index] for all elements i from index
check if we reach n-1
However, we dont need to maintain the array - just the last element
Hence check every element in array, and see if we exceed the length
'''