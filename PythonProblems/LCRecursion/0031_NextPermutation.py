'''
31. Next Permutation
Solved
Medium
Topics
Companies
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

'''

class Solution:
    def nextNumber(self, nums, start):
        lenNums,nextIndex=len(nums),start+1
        nextGreater=nums[nextIndex]
        for index in range(start+1,lenNums):
            if(nums[index]>nums[start] and nums[index]<nums[nextIndex]):
                nextIndex=index
        #print("start:",start,"next greater index:",nextIndex)
        #swap
        temp=nums[start]
        nums[start]=nums[nextIndex]
        nums[nextIndex]=temp
        #print("nums1:",nums[start+1:])
        #sort
        #if(nextIndex==lenNums-1):
        #    return
        nums[start+1:]=sorted(nums[start+1:])
        #print("nums2:",nums[start+1:])
        return

    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        #start from end, find decreasing sub-suquence of 2?, until increasing-pick next greater and sort rest
        #if no sequence, sort?
        #123215->123251;1231251->1231512;1231125->1231152;123-2531->123-3125;321->123
        lenNums,substart=len(nums),len(nums)-2
        while(substart>=0):
            if(nums[substart]<nums[substart+1]):
                break
            substart-=1
        #print("substart:",substart,"nums[substart]:",nums[substart])
        if(substart==-1):
            nums.sort()
        else:
            self.nextNumber(nums,substart)
        return

'''
Find decreasing sequence from end, and find next greater element
'''