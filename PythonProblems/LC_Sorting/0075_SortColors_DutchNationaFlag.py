''''
75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.
 

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
'''
from typing import List

#0,1,2
class Solution:
    def sortColors(nums: List[int]):
        #int l = 0, r = nums.length - 1, i = 0;
        #l=-1, r=-1. i=0
        l=-1
        r=-1
        i=0
        while (i <= len(nums)):
            if (nums[i] == 0):
                self.swap(nums, l, i)
                l=l+1
                i=i+1
            elif (nums[i] == 2):
                self.swap(nums, i, r)
                #swap
                r=r-1
            else:
                i=i+1

    def swap(A: List[int], i, j):
        tmp = A[i]
        A[i] = A[j]
        A[j] = tmp

nums = [2,0,2,1,1,0]
print(f"Before sorting:{nums}")
sol=Solution()
print(f"After sorting:{sol.sortColors(nums)}")

#