'''
501. Find Mode in Binary Search Tree
Easy
3.8K
766
company
Bloomberg
company
Google
company
Amazon
Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

If the tree has more than one mode, return them in any order.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [1,null,2,2]
Output: [2]
Example 2:

Input: root = [0]
Output: [0]
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-105 <= Node.val <= 105
 

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def helper(self, root, d):
        if(root.left is None and root.right is None):
            if(root.val in d):
                d[root.val]=d[root.val]+1
            else:
                d[root.val]=1
            return
        if(root.val in d):
            d[root.val]=d[root.val]+1
        else:
            d[root.val]=1
        if(root.left):
            self.helper(root.left,d)
        if(root.right):
            self.helper(root.right,d)
        return
    
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        if(root.left is None and root.right is None):
            return [root.val]
        #fill the dictionary
        d={}
        self.helper(root,d)
        #sort dictionary based on values
        newd=dict(sorted(d.items(),key=lambda x:-x[1]))
        #Find val
        newkeys=list(newd.keys())
        index=0
        modekey=newkeys[index]
        modeval=newd[modekey]
        result=[]
        while(index<len(newkeys) and d[newkeys[index]]==modeval):
            result.append(newkeys[index])
            index=index+1
        return result

'''
Recursion using DFS, add keys with value to dictionary
Sort dictionary and check all the max occurences

Doesnt use the property of BST!

'''