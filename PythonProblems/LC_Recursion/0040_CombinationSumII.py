'''
40. Combination Sum II
Solved
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
'''

class Solution:
    def recur(self,current,candidates,final):
        currsum,currlen,index=sum(current),len(candidates),0
        if(currsum==0):
            final.append(current[1:])
            return
        if(currsum>0):
            return
        while(index<currlen):
            val=candidates[index]
            if(val+currsum>0):
                #Backtrack
                break
            current.append(val)
            self.recur(current,candidates[index+1:],final)
            current.pop()
            while(index<currlen-1 and val==candidates[index+1]):
                #this ensures no repetition
                index+=1
            index+=1
        
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        final=[]
        self.recur([-target],candidates,final)
        return final

'''
recursion with backtracking
trick is to add target as first element and aim for zero
another trick, while loop to prevent multiple answers
'''