'''
101. Symmetric Tree
Easy
14.7K
351
company
Yandex
company
Amazon
company
Apple
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
 

Follow up: Could you solve it both recursively and iteratively?
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        #M1: Use a BFS, queue, check each level and see if the resulting queue is "symmetrical"
        #M2: Treat left, right as seperate trees. Use any recursive approach to check each value
        #M1: Use queue
        if(root is None):
            return True
        if(root.left is None and root.right is None):
            return True
        queue, valqueue = [],[]
        levelCount, n = 0, 1
        queue.append(root)
        while(queue):
            levelCount = 0
            for index in range(n):
                node = queue.pop(0)
                if(node.left):
                    queue.append(node.left),valqueue.append(node.left.val)
                    levelCount = levelCount + 1
                else:
                    valqueue.append(101)
                if(node.right):
                    queue.append(node.right),valqueue.append(node.right.val)
                    levelCount = levelCount + 1
                else:
                    valqueue.append(101)
            n = levelCount
            if( (len(valqueue)%2 != 0) or (valqueue!=valqueue[::-1]) ):
                return False
            valqueue = []
        return True