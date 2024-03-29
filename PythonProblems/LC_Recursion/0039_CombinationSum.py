'''
39. Combination Sum
Solved
Medium
Topics
Companies
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
'''
class Solution:
    def recur(self,current,candidates,final):
        currsum,lencurrent=sum(current),len(current)
        #print("current:",current,"currsum:",currsum,"candidates:",candidates)
        if(currsum==0):
            if(current[1:] not in final):
                #print("current1 found:",current[1:])
                final.append(current[1:])
            return
        if(currsum>0):
            return
        for index in range(len(candidates)):
            val=candidates[index]
            numofval=int((-currsum)/val)
            if((-currsum)%val==0):
                current=current+( [val]*numofval )
                if(current[1:] not in final):
                    final.append(current[1:])
                current=current[:lencurrent]
            #check for each addition of this val, numofval times
            for k in range(numofval,0,-1):
                current=current+( [val] * k)
                self.recur(current,candidates[index+1:],final)
                current=current[:lencurrent]
    
        
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        final=[]
        self.recur([-target],candidates,final)
        return final

'''
Simple recursion with backtracking is to run 1 to k times and check
'''