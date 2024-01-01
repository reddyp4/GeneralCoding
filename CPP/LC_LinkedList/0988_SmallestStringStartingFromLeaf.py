'''
988. Smallest String Starting From Leaf
Medium
1.6K
227
company
Google
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

For example, "ab" is lexicographically smaller than "aba".
A leaf of a node is a node that has no children.

 

Example 1:


Input: root = [0,1,2,3,4,3,4]
Output: "dba"
Example 2:


Input: root = [25,1,3,1,3,0,2]
Output: "adz"
Example 3:


Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"
 

Constraints:

The number of nodes in the tree is in the range [1, 8500].
0 <= Node.val <= 25

'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, current, result):
        if(root.left is None and root.right is None):
            current=chr(root.val+ord("a"))+current
            if(result==""):
                result=current
            elif(current<result):
                result=current
            return result
        current=chr(root.val+ord("a"))+current
        if(root.left is not None):
            result=self.helper(root.left,current,result)
        #current=current[1:]
        if(root.right is not None):
            result=self.helper(root.right,current,result)
        return result

    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        current,result="",""
        result=self.helper(root,current,result)
        return result

'''
DFS and make string
use ord() to get ascii value
use chr(node.val+ord('a')) to get new string
'''