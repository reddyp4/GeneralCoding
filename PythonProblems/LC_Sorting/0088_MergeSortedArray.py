''''
88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
'''

#Approach1: Add one array into second and sort
#Approach2: Merge starting with end, and take the larger of the elements
#First approach-O(n-logn)
#Second approach-O(n)

from typing import List

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        left=m-1
        right=n-1
        k=len(nums1)-1
        #print(f"left:{left},right:{right},k:{k}")
        while((left>=0) & (right>=0)):
            #compare
            if(nums1[left]>nums2[right]):
                nums1[k]=nums1[left]
                left=left-1
            else:
                nums1[k]=nums2[right]
                right=right-1
            #print(f"nums1:{nums1},left:{left},right:{right},k:{k}")
            k=k-1
        #Gather phase
        while(left>=0):
            nums1[k]=nums1[left]
            left=left-1
            k=k-1
        while(right>=0):
            nums1[k]=nums2[right]
            right=right-1
            k=k-1

        

nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
print(f"Before merging: nums1:{nums1}, nums2:{nums2}")
sol=Solution()
sol.merge(nums1,3,nums2,3)
print(f"After merging: nums1:{nums1}, nums2:{nums2}")
