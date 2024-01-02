'''
113. Path Sum II
Medium
7.7K
148
company
TikTok
company
Amazon
company
Facebook
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000

'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recur(self, root, current, path, result) -> List[List[int]]:
        if(root.left is None and root.right is None):
            current=current-root.val
            if(current==0):
                path.append(root.val)
                newlist=path.copy()
                result.append(newlist)
                path.pop()
        current=current-root.val
        path.append(root.val)
        if(root.left):
            result=self.recur(root.left,current,path,result)
        if(root.right):
            result=self.recur(root.right,current,path,result)
        path.pop()
        return result

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if(root is None):
            return []
        #Similar to Pathsum(112), create a list and append (note need to make copy of list)
        result=list()
        result=self.recur(root,targetSum,[],result)
        return result

'''
DFS, add path, check end result of zero
Tricky: always pop from path in current node, as well as at end-end only if leaf was ending with zero

'''
