'''
559. Maximum Depth of N-ary Tree
Easy
Topics
Companies
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:



Input: root = [1,null,3,2,4,null,5,6]
Output: 3
Example 2:



Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: 5
 

Constraints:

The total number of nodes is in the range [0, 104].
The depth of the n-ary tree is less than or equal to 1000.
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def depthTree(self,root):
        if(root is None):
            return 0
        children=list(root.children)
        len1=len(children)
        if(len1==0):
            return 1
        depth=[0]*len1
        for index in range(len1):
            depth[index]=self.depthTree(children[index])+1
        maxdepth = max(depth)
        return maxdepth

    def maxDepth(self, root: 'Node') -> int:
        #Similar to BST, except keep the length[number of children]
        if(root is None):
            return 0
        depth = self.depthTree(root)
        return depth