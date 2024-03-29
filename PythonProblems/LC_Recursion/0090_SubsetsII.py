'''
90. Subsets II
Solved
Medium
Topics
Companies
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10

'''

class Solution:
    def recursive(self, current, index, nums, final):
        if(index==len(nums)):
            newcurrent=sorted(current)
            if(newcurrent not in final):
                final.append(newcurrent)
            return
        self.recursive(current, index+1, nums, final)
        current.append(nums[index])
        self.recursive(current, index+1, nums, final)
        current.pop()
    
    #recursion with hash or just check
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        final=[]
        self.recursive([],0,nums,final)
        return final
'''
recursion
have to sort a copy and not original array

'''