''''
Given an integer array nums of unique elements, return all possible subsets (the power set).

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

#Questions:
#Does order matter?
#Does order of elements matter?
#Are numbers unique? Duplicates?

#Method:
#N positions
#Every position, include or exclude
#Remember order doesnt matter

from typing import List

class Solution:
    def subProblem(self, inputS: str, final: List[int], index: int):
        if(index==len(inputS)):
            print(partialS)
            return
        #increment partial solution
        #decrease the size of subproblem
        #sub-problem
        #exclude
        self.subProblem(inputS,partialS,index+1)
        #include
        partialS.join(str(inputS[index]))
        self.subProblem(inputS,partialS,index+1)
        return

    def subsets(self, nums: List[int]) -> List[List[int]]:
        final=[]
        self.subProblem(nums, final, 0)
        return

nums=[1,2,3]
sol=Solution()
sol.subsets(nums)

