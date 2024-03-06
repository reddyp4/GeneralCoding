'''
1130. Minimum Cost Tree From Leaf Values
Medium
Topics
Companies
Hint
Given an array arr of positive integers, consider all binary trees such that:

Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.

 

Example 1:


Input: arr = [6,2,4]
Output: 32
Explanation: There are two possible trees shown.
The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.
Example 2:


Input: arr = [4,11]
Output: 44
 

Constraints:

2 <= arr.length <= 40
1 <= arr[i] <= 15
It is guaranteed that the answer fits into a 32-bit signed integer (i.e., it is less than 231).
'''
import sys

class Solution:
    totalSum = 0

    def recursive(self, arr, start, end, sum1):
        if(end-start==1):
            print("start:",start,"end:",end,"minProduct:",arr[start]*arr[end])
            return [arr[start]*arr[end],max(arr[start],arr[end])]
        if(start==end):
            print("start:",start,"end:",end,"minProduct:",0)
            return [0,arr[start]]
        maxVal=-sys.maxsize
        minProduct=sys.maxsize
        for i in range(start,end):
            #leftarr between start and i
            leftProduct,leftValue=self.recursive(arr,start,i,sum1)
            #rightarr between i+1 and end
            rightProduct,rightValue=self.recursive(arr,i+1,end,sum1)
            #now estimate the value at this partition
            minProduct = min(leftValue*rightValue,minProduct)
        self.totalSum+= minProduct
        print("start:",start,"end:",end,"minProduct:",minProduct)
        return minProduct,maxVal

    def mctFromLeafValues(self, arr: List[int]) -> int:
        #call recursive function
        minproduct,maxval = self.recursive(arr,0,len(arr)-1,0)
        return self.totalSum