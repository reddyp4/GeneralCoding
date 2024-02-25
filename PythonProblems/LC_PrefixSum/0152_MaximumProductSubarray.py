'''
152. Maximum Product Subarray
Medium
Topics
Companies
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
'''
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        #Which Datastructure? PrefixProduct
        '''
        len1=len(nums)
        if(len1==1):
            return nums[0]
        leftPrefix,rightPrefix=[0]*len1,[0]*len1
        i=0
        leftPrefix[0]=nums[0]
        rightPrefix[-1]=nums[-1]
        while(i<len1):
            if(nums[i]==0):
                leftPrefix[i]=0
            else:
                if(i!=0 and leftPrefix[i-1]!=0):
                    leftPrefix[i]=leftPrefix[i-1]*nums[i]
                else:
                    leftPrefix[i]=nums[i]
            i+=1
        i=len1-1
        while(i>=0):
            if(nums[i]==0):
                rightPrefix[i]=0
            else:
                if(i!=(len1-1) and rightPrefix[i+1]!=0):
                    rightPrefix[i]=rightPrefix[i+1]*nums[i]
                else:
                    rightPrefix[i]=nums[i]
            i-=1
        print("leftPrefix:",leftPrefix)
        print("rightPrefix:",rightPrefix)
        return max(max(leftPrefix),max(rightPrefix))
        '''
        #Modification of Prefix Product and removing the array need
        len1=len(nums)
        if(len1==1):
            return nums[0]
        leftMax,rightMax,leftCurrent,rightCurrent=nums[0],nums[-1],nums[0],nums[-1]
        for i in range(1,len1):
            if(nums[i]==0):
                leftCurrent=0
            else:
                if(leftCurrent!=0):
                    leftCurrent=leftCurrent*nums[i]
                else:
                    leftCurrent=nums[i]
            leftMax=leftMax if (leftMax>leftCurrent) else leftCurrent
            #print("i:",i,"leftCurrent:",leftCurrent,"leftMax:",leftMax)
        for i in range(len1-2,-1,-1):
            if(nums[i]==0):
                rightCurrent=0
            else:
                if(rightCurrent!=0):
                    rightCurrent=rightCurrent*nums[i]
                else:
                    rightCurrent=nums[i]
            rightMax=rightMax if (rightMax>rightCurrent) else rightCurrent
            #print("i:",i,"rightCurrent:",rightCurrent,"rightMax:",rightMax)
        return max(leftMax,rightMax)

'''
Estimate prefix product! Doesnt work if first number is negative or zero!
Change: if zero, restart product. 
Get left and right prefix and check the maximum value

'''