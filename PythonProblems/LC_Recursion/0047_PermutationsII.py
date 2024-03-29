'''
47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10

'''
class Solution:
    d={}

    def recur(self,current,nums,final):
        if(len(nums)==0):
            val=''.join(str(x) for x in current)
            #print(val)
            if(val not in self.d):
                self.d[val]=1
                final.append(current[:])
            return
        for index in range(len(nums)):
            val=nums[index]
            current.append(val)
            nums.pop(index)
            self.recur(current,nums,final)
            current.pop()
            nums.insert(index,val)
        
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        final=[]
        self.recur([],nums,final)
        return final