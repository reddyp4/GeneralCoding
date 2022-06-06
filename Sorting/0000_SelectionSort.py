''''
Selection sort is brute-force sorting
One inner and outer loop to sort elements
First find minimum, put in beginning, and continue
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:
Return number of tries
'''
from typing import List


class Solution:
    def swap(self, nums: List[int], index1, index2) -> List[int]:
        c=nums[index1]
        nums[index1]=nums[index2]
        nums[index2]=c
        return nums
    
    def sortArray(self, nums: List[int]) -> List[int]:
        size1 = len(nums)
        print(f"Size: {size1}")
        #Find minimum for i
        for i in range(0,size1):
            min = nums[i]
            minindex1=i
            #Scan through array to get minimum
            for j in range(i+1,size1):
                if(nums[j]<min):
                    min=nums[j]
                    minindex1=j
            #Swap the minimum value with i
            self.swap(nums,i,minindex1)
        return nums


nums = [5,2,3,1]
print(f"Initial array: {nums}")
sol = Solution()
nums=sol.sortArray(nums)
print(f"Sorted array: {nums}")
