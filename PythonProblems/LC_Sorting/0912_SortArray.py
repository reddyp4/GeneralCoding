''''
912. Sort an Array
Given an array of integers nums, sort the array in ascending order.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
'''
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if(len(nums)<=1):
            return nums
        #Get midpoint
        mid = int(len(nums)/2)
        #Recursive sort left, sort right
        leftarr = self.sortArray(nums[:mid])
        rightarr = self.sortArray(nums[mid:])
        #combine
        i,j,k = 0,0,0
        while(i<len(leftarr) and j<len(rightarr)):
            if(leftarr[i]<rightarr[j]):
                nums[k]=leftarr[i]
                i=i+1
            elif(leftarr[i]>rightarr[j]):
                nums[k]=rightarr[j]
                j=j+1
            elif(leftarr[i]==rightarr[j]):
                nums[k]=leftarr[i]
                k=k+1
                nums[k]=rightarr[j]
                i,j = i+1, j+1
            k = k+1
        while(i<len(leftarr)):
            nums[k]=leftarr[i]
            i=i+1
            k=k+1
        while(j<len(rightarr)):
            nums[k]=rightarr[j]
            j=j+1
            k=k+1
        return nums