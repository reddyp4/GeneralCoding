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

#Key things to remember
#Exclude, no action
#include, append, call, and pop
#pop removes last element in partial solution
#Why do we pop for partial list?
#Going up a tree, while finishing a leg and going back, we need to pop the last element

from typing import List

class Solution:
    def subProblem(self, inputS: List[int], final: List[int], partialSet: List[int], index: int):
        if(index==len(inputS)):
            print(f"inputS={inputS},index={index}")
            print(f"Final partialSet=:{partialSet}")
            final.append(list(partialSet))
            print(f"Final Set=:{final}")
            partialSet=[]
            return 
        #increment partial solution
        #decrease the size of subproblem
        #sub-problem
        #exclude
        print(f"Exclude PartialSet:{partialSet},index:{index}")
        self.subProblem(inputS,final, partialSet,index+1)
        #include
        partialSet.append(inputS[index])
        print(f"Include PartialSet:{partialSet},index:{index}")
        self.subProblem(inputS,final,partialSet,index+1)
        partialSet.pop()
        return

    def subsets(self, nums: List[int]) -> List[List[int]]:
        final=[]
        partialSet = []
        self.subProblem(nums, final, partialSet, 0)
        return final

nums=[1,2,3]
sol=Solution()
final = sol.subsets(nums)
print(f"Printing final:{final}")
