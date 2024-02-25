'''
42. Trapping Rain Water
Hard
Topics
Companies
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
'''
class Solution:
    def trap(self, height: List[int]) -> int:
        len1=len(height)
        #make a stack and fill from left and then right
        stk=[-1]*len1
        stk[0]=height[0]
        #get max element
        maxVal = max(height)
        maxIndex = height.index(maxVal)
        print("max:",maxVal,",maxIndex:",maxIndex)
        #make stk as heights, as per past element from left
        for i in range(1,maxIndex+1):
            stk[i] = height[i] if (height[i]>stk[i-1]) else stk[i-1]
        print("From left stk:",stk)
        for i in range(len1-1,maxIndex,-1):
            stk[i] = height[i] if (height[i]>stk[i-1]) else stk[i-1]
        print("From right stk:",stk)
        #compute volume
        vol=0
        for i in range(1,maxIndex):
            newHeight=stk[i]-height[i]
            vol+=newHeight
        for i in range(len1-1,maxIndex,-1):
            newHeight=stk[i]-height[i]
            vol+=newHeight
        return vol

'''
Basic Idea1: Use a monotonic Stack, where height of water at that is max so far
Do from left and right until the max element
Now add up volumes
'''