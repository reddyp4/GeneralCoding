'''
78. Subsets
Solved
Medium
Topics
Companies
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
'''

class Solution:
    #recursion
    def recursive(self, current, index, nums, final):
        if(index==len(nums)):
            final.append(current[:])
            return
        self.recursive(current, index+1, nums, final)
        current.append(nums[index])
        self.recursive(current, index+1, nums, final)
        current.pop()

    def subsets(self, nums: List[int]) -> List[List[int]]:
        final=[]
        self.recursive([],0,nums,final)
        return final
        
'''
standard recursion
trap1: copy list has to be added as .append(current[:])
trap2: once appended, pop - since list is mutable through recursion
'''