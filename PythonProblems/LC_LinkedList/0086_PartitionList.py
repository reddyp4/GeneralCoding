'''
86. Partition List


Medium
7.1K
807
company
Adobe
company
Microsoft
company
Apple
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
 

Constraints:

The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        #Maintain less and more pointers and keep adding nodes
        if(head is None):
            return head
        less,more,node = ListNode(x-1),ListNode(x+1),head
        lesshead,morehead=less,more
        while(node):
            if(node.val<x):
                less.next=node
                less=less.next
            else:
                more.next=node
                more=more.next
            node=node.next
        less.next = morehead.next
        more.next = None
        return lesshead.next