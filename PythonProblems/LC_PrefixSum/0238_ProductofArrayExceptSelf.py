'''
238. Product of Array Except Self
Medium
20.9K
1.2K
company
Amazon
Asana
company
Apple
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
'''
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #Bruteforce
        '''
        prodnums=[]
        for index in range(len(nums)):
            prod=1
            for prodindex,elem in enumerate(nums):
                if(prodindex!=index):
                    prod=prod*elem
            prodnums.append(prod)
        return prodnums
        '''
        #Optimal-can we use complete product - will not work elements are zero
        len1=len(nums)-1
        left,right,prod=[1]*(len1+1),[1]*(len1+1),[1]*(len1+1)
        for i in range(1,len1+1):
            left[i]=left[i-1]*nums[i-1]
        for i in range(1,len1+1):
            right[len1-i]=right[len1-i+1]*nums[len1-i+1]
        for index in range(0,len1+1):
            prod[index]=left[index]*right[index]
        return prod
'''
Prefix sum:
left[i]=left[i-1]*nums[i-1]: from left
right[i]=right[i+1]*nums[i+1]: from right
prod[i]=left[i]*right[i]
'''