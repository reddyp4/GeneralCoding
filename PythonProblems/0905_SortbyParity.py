''''
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

 

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 5000
0 <= nums[i] <= 5000

'''

#Method1: Follow suit of quicksort, left/right pointers, check parity
#Important: Edgecases, all even/all odd numbers, empty arrays

from typing import List

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        size1=len(nums)
        left=0
        right=size1-1
        if(left==right):    #single element
            return nums
        while(left<=right):
            while(((nums[left]%2)==0) & (left<size1-2)):   #move until even
                #print(f"{left},")
                left=left+1
            if(left==size1):   #reached end right away
                return nums
            while(((nums[right]%2==1)) & (right>=0)):  #move until odd
                right=right-1
            if(right==-1):      #reached end
                return nums
            if(((nums[left]%2)==1) & ((nums[right]%2)==0) & (left<right)):   #swap
                c=nums[right]
                nums[right]=nums[left]
                nums[left]=c
            left=left+1
            right=right-1
            #print(f"left:{left},right:{right}")
        return nums
        

nums = [3,1,2,4]
sol=Solution()
print(f"After sort:{sol.sortArrayByParity(nums)}")
