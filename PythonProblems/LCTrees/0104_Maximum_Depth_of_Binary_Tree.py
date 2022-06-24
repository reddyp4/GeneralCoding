'''
104. Maximum Depth of Binary Tree
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

"""
Idea1: 
Recursive
Works - accepted in LC
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
from typing import List

class Solution:
    def depthHelper(self, root:TreeNode, depth:int):
        if(root is None):
            return 0
        #base reached the leaf node
        if((root.left is None) and (root.right is None)):
            return 1
        left = self.depthHelper(root.left,depth)+1
        right = self.depthHelper(root.right,depth)+1
        max1 = left if left>right else right
        depth = max1 if max1>depth else depth
        #check height against the count and choose
        return depth
    
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth = 0
        #call the helper and return height
        if(root is not None):
            depth=self.depthHelper(root,depth)
        #return value
        return depth