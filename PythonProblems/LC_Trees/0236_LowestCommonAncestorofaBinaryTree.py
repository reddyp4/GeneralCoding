'''
236. Lowest Common Ancestor of a Binary Tree
Solved
Medium
Topics
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    LCA=TreeNode()

    def getStackPath(self, current, target, path):
        if(current==None):
            return 0
        if(current==target):
            path.append(current)
            return 1
        path.append(current)
        if(current.left):
            result=self.getStackPath(current.left,target,path)
            if(result):
                return 1
            else:
                path.pop()
        if(current.right):
            result=self.getStackPath(current.right,target,path)
            if(result):
                return 1
            else:
                path.pop()

    def stackLCA(self, root, p, q):
        lca=TreeNode(0)
        node=root
        pathp,pathq=[],[]
        self.getStackPath(root, p, pathp)
        self.getStackPath(root, q, pathq)
        index,lenp,lenq=0,len(pathp),len(pathq)
        while(index<lenp and index<lenq):
            if(pathp[index]==pathq[index]):
                index+=1
            else:
                break
        return pathp[index-1]

    def foundPQ(self,root,p,q):
        #Single pass without path storage, indirect stack
        leftcount,rightcount,count=0,0,0
        if(root==p):
            count=1
        if(root==q):
            count=1
        if(root.left):
            leftcount=self.foundPQ(root.left,p,q)
        if(root.right):
            rightcount=self.foundPQ(root.right,p,q)
        if(leftcount+rightcount+count>1):
            #either p/q parent of other (comes by count)
            #or common parent, when both leftcount=rightcount=1
            self.LCA=root
        return leftcount or rightcount or count

    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #M1: stack approach, push nodes to two stacks and compare, similiar to LL intersection
        #node=self.stackLCA(root, p, q)
        #return node
        #M2:
        self.foundPQ(root,p,q)
        return self.LCA

'''
Stack appraoch: space: O(n), time: O(n)
Novel: Keep selfcount, leftcount, rightcount, LCA when sum(count,leftcount,rightcount)>1
Pattern here is depth first algorithm, with slight addition of leftcount, rightcount on top
'''