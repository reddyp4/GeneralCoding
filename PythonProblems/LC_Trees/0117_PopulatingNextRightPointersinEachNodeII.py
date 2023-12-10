'''
117. Populating Next Right Pointers in Each Node II
Medium
5.7K
309
company
Bloomberg
company
Amazon
company
Facebook
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Example 1:


Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
Example 2:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100
 

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
    def connect(self, root: 'Node') -> 'Node':
        #M1: Use a queue, Space: O(n), Time:O(1)
        if(root is None or (root.left is None and root.right is None)):
            return root
        queue = []
        queue.append(root)
        levelCount, n = 0, 1
        while(queue):
            levelCount = 0
            for index in range(n):
                node = queue.pop(0)
                #n-1
                if(index==n-1):
                    if(node.left and node.right):
                        node.left.next = node.right
                        queue.append(node.left)
                        queue.append(node.right)
                        levelCount = levelCount + 2
                    elif(node.left):
                        queue.append(node.left)
                        levelCount = levelCount + 1
                    elif(node.right):
                        queue.append(node.right)
                        levelCount = levelCount + 1
                else:
                    #Next for left
                    if(node.left):
                        if(node.right):
                            node.left.next = node.right
                        else:
                            j=0
                            while(queue and j<(n-index-1) and queue[j].left is None and queue[j].right is None):
                                j = j+1
                            if(queue and j is not (n-index-1)):
                                if(queue[j].left):
                                    node.left.next = queue[j].left
                                elif(queue[j].right):
                                    node.left.next = queue[j].right
                        queue.append(node.left)
                        levelCount = levelCount + 1
                    #Next for right
                    if(node.right):
                        j=0
                        while(queue and j<(n-index-1) and queue[j].left is None and queue[j].right is None):
                            j = j+1
                        if(queue and j is not (n-index-1)):
                            if(queue[j].left):
                                node.right.next = queue[j].left
                            elif(queue[j].right):
                                node.right.next = queue[j].right
                        queue.append(node.right)
                        levelCount = levelCount + 1
            n = levelCount
        return(root)

