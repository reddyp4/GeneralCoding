'''
102. Binary Tree Level Order Traversal
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

#Method1: Add quueue
#Key points: make count of levels, 
#Time: O(n), Space: O(n)
#Method2: Recursive->FAIL, 


from asyncio.windows_events import NULL
import queue
from typing import List


class Treenode:
    def __init__(self,val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        #Initiate the result
        result=[]
        # If root==null, return result
        if(root==NULL):
            return result
        # Initiate queue
        que = queue()
        # Add root to queue
        que.add(root)
        # while node in queue is not empty
        # get count = queue size
        # initiate temp list of results

root = [3,9,20,NULL,NULL,15,7]
resultval=Solution.levelOrder(root)
print(f"Final Result:{resultval}")
