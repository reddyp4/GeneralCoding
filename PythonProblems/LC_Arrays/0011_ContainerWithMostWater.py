'''
11. Container With Most Water
Medium
27.5K
1.5K
company
Amazon
company
Microsoft
company
Apple
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
'''

from functools import reduce
import numpy as np

class Solution:
    def maxArea(self, height: List[int]) -> int:
        #M0: Bruteforce
        '''
        len1,newmax = len(height), 0
        npheight = np.array(height)
        for i in range(len1):
            arr = np.array(range(0,len1-i))
            height1 = np.array(range(0,len1-i))
            for j in range(len1-i):
                height1[j] = min(npheight[i],npheight[j+i])
            newmatrix = np.multiply(arr,height1)
            volume = max(newmatrix)
            if(volume>newmax):
                newmax = volume
        return newmax
        '''
        #M1: Two pointer, left tracks. right tracks, volume count unti left<right
        left, right = 0, len(height)-1
        leftmax, rightmax, volume = height[left],height[right],0
        volume = right*min(height[right],height[left])
        while(left<right):
            if(leftmax>rightmax):
                #get better right
                if(height[right]>rightmax):
                    #new right high. check volume
                    newvol = min(height[right],leftmax)*(right-left)
                    if(newvol>volume):
                        #new max, assign volume, right is stationary now
                        volume = newvol
                    rightmax = height[right]
                    continue
                #move right
                right = right - 1
            else:
                #get better left
                if(height[left]>leftmax):
                    #new left high. Check volume
                    newvol = min(height[left],rightmax)*(right-left)
                    if(newvol>volume):
                        #new max, assign volume, left is stationary now
                        volume=newvol
                    leftmax = height[left]
                    continue
                #not a new left, so keep moving
                left = left + 1
        return volume

'''
Bruteforce: O(n2)
Elegant: O(n), left, right pointers
Only move, when next bigger element is found. 
It makes sense to "stick to highest element from left or right - while keeping track of volume"
'''