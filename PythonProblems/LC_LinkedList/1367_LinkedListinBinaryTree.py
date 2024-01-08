'''
1367. Linked List in Binary Tree
Medium
2.2K
65
company
Amazon
company
Adobe
SoundHound
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:



Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
Example 2:



Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 

Constraints:

The number of nodes in the tree will be in the range [1, 2500].
The number of nodes in the list will be in the range [1, 100].
1 <= Node.val <= 100 for each node in the linked list and binary tree.
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recur(self, head, node, flag):
        if(node and head):
            print("Base: head.val:",head.val,"node:",node.val,"flag:",flag)
        #End-case
        if(node is None):
            print("Found!")
            return True
        if(head is None):
            print("Reached end of tree!")
            return False
        #Case of match, already started comparing
        if(flag):
            oldflag=flag
            if(head.val!=node.val):
                return False
            #Proceed if match
            if(head.left):
                if(node.next):
                    print("Going left: head:",head.val,"node.next:",node.next.val,"flag:",flag)
                flag=self.recur(head.left,node.next,flag)
                if(flag):
                    return flag
            if(head.right):
                flag=oldflag
                if(node.next):
                    print("Going left: head:",head.val,"node.next:",node.next.val,"flag:",flag)
                flag=self.recur(head.right,node.next,flag)
                if(flag):
                    return flag
            if(head.left is None and head.right is None and node.next):
                return False
        #else
        else:
            if(head.val==node.val):
                flag=True
            oldflag=flag
            if(head.left):
                flag=oldflag
                if(flag):
                    if(node.next):
                        print("Going left: head:",head.val,"node.next:",node.next.val,"flag:",flag)
                    flag=self.recur(head.left,node.next,flag)
                else:
                    print("Going left: head:",head.val,"node:",node.val,"flag:",flag)
                    flag=self.recur(head.left,node,flag)
                if(flag):
                    return flag
            if(head.right):
                flag=oldflag
                if(flag):
                    if(node.next):
                        print("Going right: head:",head.val,"node.next:",node.next.val,"flag:",flag)
                    flag=self.recur(head.right,node.next,flag)
                else:
                    print("Going right: head:",head.val,"node:",node.val,"flag:",flag)
                    flag=self.recur(head.right,node,flag)
                if(flag):
                    return flag
            if(head.left is None and head.right is None and node.next):
                return False
        return flag

    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        #Bruteforce: Each dfs, check element to head, and start verifying flag, once flag is true, return
        #dfs will use recursion
        flag = self.recur(root,head,False)
        return flag