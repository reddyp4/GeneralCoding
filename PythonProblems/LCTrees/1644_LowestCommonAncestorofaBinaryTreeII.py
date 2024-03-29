'''
1644. Lowest Common Ancestor of a Binary Tree II
Given the root of a binary tree, return the lowest common ancestor (LCA) of two given nodes, p and q. If either node p or q does not exist in the tree, return null. All values of the nodes in the tree are unique.

According to the definition of LCA on Wikipedia: "The lowest common ancestor of two nodes p and q in a binary tree T is the lowest node that has both p and q as descendants (where we allow a node to be a descendant of itself)". A descendant of a node x is a node y that is on the path from node x to some leaf node.

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:



Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5. A node can be a descendant of itself according to the definition of LCA.
Example 3:



Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 10
Output: null
Explanation: Node 10 does not exist in the tree, so return null.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
 

Follow up: Can you find the LCA traversing the tree, without checking nodes existence?
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    LCA = TreeNode(10**10)

    def foundLCA(self,root,p,q):
        found,left,right=0,0,0
        if(root==p or root==q):
            found=1
        if(root.left):
            left=self.foundLCA(root.left,p,q)
        if(root.right):
            right=self.foundLCA(root.right,p,q)
        if(found+left+right>1):
            self.LCA=root
        return (found or left or right)

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.foundLCA(root,p,q)
        if(self.LCA.val==10**10):
            return None
        else:
            return self.LCA

'''
Similar to LCA
'''