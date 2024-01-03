'''
24. Swap Nodes in Pairs
Medium
11.5K
420
company
Amazon
company
Bloomberg
company
Apple
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:


Input: head = [1,2,3,4]
Output: [2,1,4,3]
Example 2:

Input: head = []
Output: []
Example 3:

Input: head = [1]
Output: [1]
 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head is None or head.next is None):
            return head
        dummy1,dummy2=ListNode(0),ListNode(0)
        node,node1,node2=head,dummy1,dummy2
        flag=False
        while(node):
            if(flag):
                node1.next=node
                node1=node1.next
            else:
                node2.next=node
                node2=node2.next
            flag=not flag
            node=node.next
        #terminate node1 and node2
        node1.next,node2.next=None,None
        dummy=ListNode(0)
        node,flag=dummy,False
        node1,node2=dummy1.next,dummy2.next
        while(node1 and node2):
            if(flag):
                node.next=node2
                node2=node2.next
            else:
                node.next=node1
                node1=node1.next
            flag=not flag
            node=node.next
        if(node1):
            node.next=node1
        elif(node2):
            node.next=node2
        return dummy.next

'''
Use two dummies and form even/odd lists
trick: true = not false
trick: terminate odd/even lists to None
trick: at the end, one node may be remaining, so check and add

'''