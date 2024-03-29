'''
111. Minimum Depth of Binary Tree
Solved
Easy
Topics
Companies
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5
 

Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def depthTree(self, root):
        if(root.left is None and root.right is None):
            return 1
        leftdepth,rightdepth=1e6,1e6
        if(root.left):
            leftdepth=self.depthTree(root.left)
        if(root.right):
            rightdepth=self.depthTree(root.right)
        #print("root.val:",root.val,"lefthdepth:",leftdepth,"rightdepth:",rightdepth)
        if(leftdepth<rightdepth):
            return leftdepth+1
        else:
            return rightdepth+1
        
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if(root is None):
            return 0
        depth=self.depthTree(root)
        return depth

'''
compare leftdepth and rightdepth
trick, initiate leftd,rightd=1e6,1e6
'''