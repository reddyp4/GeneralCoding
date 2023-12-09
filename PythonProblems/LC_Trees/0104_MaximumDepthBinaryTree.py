'''
104. Maximum Depth of Binary Tree
Easy
12.2K
203
company
Adobe
company
Apple
company
Google
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        #Method1: BFS and count the number until queue is empty
        #Can use from collections import deque for faster access
        count,n=0,1
        queue = []  #unofficial queue
        queue.append(root)  #number of elements in first level
        node = root
        if(root is None):
            return 0
        while(queue):
            levelCount = 0
            #Loop to add all children in the level
            for i in range(n):
                #Run for all nodes in a level
                node = queue.pop(0)
                if(node.left is not None):
                    queue.append(node.left)
                    levelCount = levelCount+1
                if(node.right is not None):
                    queue.append(node.right)
                    levelCount = levelCount+1
            n = levelCount
            count = count + 1
        return count

'''
M1: BFS (Beats 29% on time, 86% on space)
Space: O(n) -> Stored elements in queue
Time: O(n) -> Going through all elements

'''