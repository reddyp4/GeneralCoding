'''
116. Populating Next Right Pointers in Each Node
Medium
9.4K
287
company
Bloomberg
company
Google
company
Facebook
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,6,7]
Output: [1,#,2,3,#,4,5,6,7,#]
Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 212 - 1].
-1000 <= Node.val <= 1000
 

Follow-up:

You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

'''
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        #Method1: Use Queue and BFS
        '''
        #M1:
        if(root is None):
            return None
        queue = []
        queue.append(root)
        index,levelCount,n=0,0,1
        while(queue):
            levelCount = 0
            #Iterate through all nodes in BFS
            for index in range(n):
                #Iterate through children in breadth
                node = queue.pop(0)
                #if not end, i=n
                if(index==n-1):
                    node.next = None
                else:
                    node.next = queue[0]
                if(node.left is not None):
                    queue.append(node.left)
                    levelCount = levelCount + 1
                if(node.right is not None):
                    queue.append(node.right)
                    levelCount = levelCount + 1
            n = levelCount
        return root
        '''
        #Method2: Use previously established pointers
        #left->right is easy
        #left.right->right->left etc... assumed that that level is already completed
        #this reduces the need for queue!!! O(1) for space due to previous level completion
        startNode = root
        if(root is None or root.left is None):
            return root
        root.left.next = root.right
        while (startNode.left is not None):
            node = startNode
            while(node.next is not None):
                node.left.next = node.right
                node.right.next = node.next.left
                node = node.next
            node.left.next = node.right
            startNode = startNode.left
        return root

'''
M1: BFS
Space: O(n), using queue for each node
Time: O(n), visiting each node

M2: Recursive - implicit stack does not count
Space: O(1)
Time: O(n)

'''