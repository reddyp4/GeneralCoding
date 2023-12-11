'''
100. Same Tree
Easy
10.7K
214
company
Amazon
company
Google
company
Adobe
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        #Do BFS and compare values
        if(p is None and q is None):
            return True
        if(p is None or q is None):
            return False
        queue1,queue2 = [],[]
        levelCount1, levelCount2, n = 0, 0, 1
        queue1.append(p),queue2.append(q)
        while(queue1 and queue2):
            levelCount1, levelCount2 = 0, 0
            for index in range(n):
                if(len(queue1)==0 or len(queue2)==0):
                    return False
                node1, node2 = queue1.pop(0),queue2.pop(0)
                if(node1.val!=node2.val):
                    return False
                if(node1.left and node2.left):
                    queue1.append(node1.left),queue2.append(node2.left)
                    levelCount1,levelCount2 = levelCount1 + 1,levelCount2 + 1
                if(node1.right and node2.right):
                    queue1.append(node1.right),queue2.append(node2.right)
                    levelCount1,levelCount2 = levelCount1 + 1,levelCount2 + 1
                if(node1.left is None and node2.left is not None) or (node1.left is not None and node2.left is None) or (node1.right is None and node2.right is not None) or (node1.right is not None and node2.right is None):
                    return False
            n = levelCount1
        if(queue1 or queue2):
            return False
        return True

'''
M1: BFS Space-O(n), Time-O(n)
'''