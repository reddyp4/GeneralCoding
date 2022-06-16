''''
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
 

Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
'''

# Brute-force Method1: Recursive, each worker picks element at i, pops it in reduceList 
# and adds to partial list
# Call recursive subproblem for each i from i+1 to end
# Base problem1: length(nums)==1, since we are popping 
# Can we back-track once len(nums)==1

from typing import List

class Solution:
    debug = 0

    def subProblem(self, nums: List[int], partial: List[int], final: List[int]):
        #Run base case
        if(len(nums)==1):
            a = nums.pop()
            partial.append(a)
            final.append(list(partial))
            if(self.debug==1):
                print(f"Base: partial:{partial},nums:{nums},final={final}")
            a = partial.pop()
            nums.append(a)
            if(self.debug==1):
                print(f"Base Return:partial:{partial},nums:{nums},final={final}")
            return
        #Include element i, push index to Hash table, pop from remaining
        # Call worker for each i, pop first element in nums, add to partial, 
        # call subProblem on nums
        # once returned pop the element to move to next ith element
        for index in range(0,len(nums)):
            #pop element out of nums
            a = nums.pop(index)
            #push element into partial
            partial.append(a)
            if(self.debug==1):
                print(f"index:{index},partial:{partial},nums:{nums},final={final}")
            #call next level
            self.subProblem(nums,partial,final)
            #do I need to pop from partial and enter back into nums at index
            if(self.debug==1):
                print(f"returned index:{index},partial:{partial},nums:{nums},final={final}")
            a=partial.pop()
            nums.insert(index,a)
            if(self.debug==1):
                print(f"finished index:{index},partial:{partial},nums:{nums},final={final}")

    def permute(self, nums: List[int]) -> List[List[int]]:
        final = []
        newList = nums
        partial = []
        self.subProblem(newList, partial, final)
        return final

nums = [1,2,3]
print(f"Initial list:{nums}")
sol = Solution()
permut = sol.permute(nums)
print(f"Final list:{permut}")
