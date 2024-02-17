'''
45. Jump Game II
Solved
Medium
Topics
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
'''

class Solution:
    def jump(self, nums: List[int]) -> int:
        if(len(nums)==1):
            return 0
        n=len(nums)
        #last reachable index, and current index, first index has to picked
        dpend,currIndex,jump=nums[0],0,0
        #current index being worked on in a loop unti dpend
        while(currIndex<=(n-1) and dpend<(n-1)):
            #now check from next range and pick the max element extending our search
            print("currIndex:",currIndex,"dpend:",dpend)
            maxVal,maxIndex=nums[currIndex+1],currIndex+1
            for k in range(currIndex+1,dpend+1):
                #check if we will update dpend, and check max
                if(nums[k]+k>dpend):
                    #got a new dpend
                    dpend = nums[k]+k
                    #check max
                    if(nums[k]>maxVal):
                        maxVal=nums[k]
                        maxIndex=k
                        print("New index:",maxIndex,",value:",maxVal)
            print("Picked index:",maxIndex,",value:",maxVal,"dpend:",dpend,"currIndex:",currIndex)
            #Now pick the new start as maxIndex and update jump
            currIndex=maxIndex
            jump+=1
        #guaranteed we will reach the end
        return jump+1

'''
Similiar to jumpgame, but now pick the max value of jumps
'''