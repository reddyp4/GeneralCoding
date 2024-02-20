'''
487. Max Consecutive Ones II
Solved
Medium
Topics
Companies
Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

 

Example 1:

Input: nums = [1,0,1,1,0]
Output: 4
Explanation: 
- If we flip the first zero, nums becomes [1,1,1,1,0] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1] and we have 3 consecutive ones.
The max number of consecutive ones is 4.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 4
Explanation: 
- If we flip the first zero, nums becomes [1,1,1,1,0,1] and we have 4 consecutive ones.
- If we flip the second zero, nums becomes [1,0,1,1,1,1] and we have 4 consecutive ones.
The max number of consecutive ones is 4.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
 

Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?
'''

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        if(len(nums)==1):
            return 1
        count,countMax,len1=0,0,len(nums)
        if(sum(nums)==len1):
            return len1
        for i in range(len1):
            if(nums[i]==0):
                count=0
                left=i-1 if (i>=1) else -1
                right=i+1 if (i<(len1-1)) else len1
                while(left>-1 and nums[left]):
                    left-=1
                while(right<len1 and nums[right]):
                    right+=1
                if(left==-1 and right==len1):
                    count=len1
                elif(left!=-1 and right!=len1):
                    count=right-left-1  #both left and right stopped at 0's
                elif(left==-1):
                    count=right         #left at index0 and right stopped at 0
                elif(right==len1):
                    count=right-left-1    #left at 0 and right at end of array
                #print("i:",i,"count:",count,"left:",left,"right:",right)
                countMax=countMax if (countMax>count) else count
        return countMax

'''
Sliding Window at every 0
'''