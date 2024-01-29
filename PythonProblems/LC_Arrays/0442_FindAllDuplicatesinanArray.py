'''
442. Find All Duplicates in an Array
Solved
Medium
Topics
Companies
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
'''
class Solution:
    def swap(self,nums,i,j):
        temp=nums[i]
        nums[i]=nums[j]
        nums[j]=temp
    
    def findDuplicates(self, nums: List[int]) -> List[int]:
        '''Lazy Approach with sort
        nums.sort()
        result,index,lenums=[],0,len(nums)
        while(index<lenums-1):
            if(nums[index]==nums[index+1]):
                result.append(nums[index])
                index+=1
            index+=1
        return result'''
        #Use the sorting technique
        for index in range(len(nums)):
            while(nums[index]!=index+1):
                d=nums[index]-1
                if(nums[d]!=nums[index]):
                    self.swap(nums,d,index)
                else:
                    break
        print(nums)
        #Now array is sorted, search and any element not present is duplicated
        result=[]
        for index in range(len(nums)):
            if(nums[index]!=index+1):
                result.append(nums[index])
        return result
'''
Not the fastest

second version: sorting array partially!!! Look at cycle sort!

'''