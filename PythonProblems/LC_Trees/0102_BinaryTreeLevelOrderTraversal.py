'''
102. Binary Tree Level Order Traversal
Solved
Medium
Topics
Companies
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        #BFS
        if(root is None):
            return []
        q,result,level=[],[],[]
        q.append(root)
        level.append(root.val)
        result.append(level[:])
        while(len(q)!=0):
            level=[]
            for index in range(len(q)):
                node=q[0]
                q.pop(0)
                if(node.left):
                    q.append(node.left)
                    level.append(node.left.val)
                if(node.right):
                    q.append(node.right)
                    level.append(node.right.val)
            print(level)
            if(level!=[]):
                result.append(level[:])
        return result

'''
BFS
Trick: use level=[] to reset. to append result.append(result[:])
'''