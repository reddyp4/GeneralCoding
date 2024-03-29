'''
222. Count Complete Tree Nodes
Easy
8.3K
470
company
Amazon
company
Google
company
TikTok
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:


Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [0, 5 * 104].
0 <= Node.val <= 5 * 104
The tree is guaranteed to be complete.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recur(self, root, total,level,flag):
        if(flag):
            return total,flag
        if(root.left is None and root.right is None):
            return (total-2),False
        if(root.right is None and root.left):
            #end, stop counting
            return (total-1),True
        if(root.left and root.right and (level==2)):
            #another end, stop counting
            return total,True
        if(root.right):
            total,flag=self.recur(root.right,total,level-1,flag)
            if(flag):
                return total,flag
        if(root.left):
            total,flag=self.recur(root.left,total,level-1,flag)
            if(flag):
                return total,flag
        return total,flag

    def countNodes(self, root: Optional[TreeNode]) -> int:
        #Use BFS and count the number of nodes - works for any tree
        #Complete tree - only last level is not full populated
        #Option2: Get number of levels, by just going left
        #Now, start to right first, check the missing elements
        levelleft,node,total=0,root,0
        #check if complete binary tree
        while(node):
            total=total+2**levelleft
            levelleft=levelleft+1
            node=node.left
        levelright,node=0,root
        while(node):
            levelright=levelright+1
            node=node.right
        if(levelleft==levelright):
            return total
        #else some nodes are missing, start with total and start removing unknown
        newtotal,flag=self.recur(root,total,levelleft,False)
        return newtotal

'''
Use DFS, but start on right. 
Get depth, to start initial count as 1+2+4... 
Anytime no right, or on level=2, no children, stop reducing count

'''