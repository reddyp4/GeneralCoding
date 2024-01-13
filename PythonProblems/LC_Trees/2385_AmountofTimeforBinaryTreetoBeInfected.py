'''
2385. Amount of Time for Binary Tree to Be Infected
Medium
Topics
Companies
Hint
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
Example 2:


Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    foundShare = 0
    shareDepth = 0
    
    def depthTree(self, root, share):
        if(root is None):
            return 1
        leftdepth,rightdepth=0,0
        self.shareDepth=self.shareDepth+1
        if(root.left):
            leftdepth=self.depthTree(root.left,share)+1
        if(root.right):
            rightdepth=self.depthTree(root.right,share)+1
        if(root.val==share):
            self.shareDepth = max(leftdepth,rightdepth)
            self.foundShare = 1
        else:
            self.shareDepth=self.shareDepth-1
        if(leftdepth>rightdepth):
            return leftdepth
        else:
            return rightdepth

    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        if(root is None):
            return 0
        if(root.left is None and root.right is None):
            return 0
        #Scenario1: if share is head, just return depth of tree
        if(root.val==start):
            return self.depthTree(root,start)
        depth=0
        #Scenario2: Find left or right subtree location of share, get new depth
        #also find depth of share in mean while
        leftdepth,rightdepth=0,0
        if(root.left):
            leftdepth = self.depthTree(root.left,start)
        if(self.foundShare==1):
            self.foundShare = 2
        if(root.right):
            rightdepth = self.depthTree(root.right,start)
        if(self.foundShare==1):
            #share on right side
            result = max(leftdepth+1+self.shareDepth,self.shareDepth)
        else:
            #share on left side
            result = max(rightdepth+1+self.shareDepth,self.shareDepth)
        print("leftdepth:",leftdepth,"rightdepth:",rightdepth,"shareDepth:",self.shareDepth,"foundShare",self.foundShare)
        return result

'''
1) understand the problem, clarification, get constraints, throw ball to interviewer, take your time
2) approach discussion, if nothing comes try bruteforce, ask interviewer
3) ask interviewer if code should work, not fully optimized even if implemented - always close on approach
   technique - thought process - call out data structure - if handyman tool is correct?
   dsa: tools - hashmap, lists etc. ask interviewer for correct dsa 
4) implementation - should be clean implementation - do not throw ball to interviewer - run a couple of scenarios
5) throw ball to interviewer for discussion, test cases, complexity, may be phase-1, phase-2, 40 mins-2medium

do practice, apply logical skills - stay calm - ask hints
keep doing - retrospective of interviewer - what you were missing on every problem 
resources - online - leetcode is best - focus on approach, understand basics - logical skills 
can look at variations - 

1 or 2 problems - background area - focus in basics 

lot of patience - market is not good

'''
