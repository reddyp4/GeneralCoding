'''
1721. Swapping Nodes in a Linked List
Medium
5.2K
166
company
Adobe
company
Amazon
company
Facebook
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if(head.next is None):
            return head
        #Get length of linked list
        length,node,dummy = 0,head,ListNode(0)
        dummy.next=head
        parentk,childk,parentnk,childnk,nodek,nodenk=dummy,None,dummy,None,None,None
        while(node):
            length,node=length+1,node.next
        if(k>length):
            return head
        node,index=dummy,0
        while(node):
            if(index==k-1):
                parentk=node
            if(index==k):
                nodek=node
            if(index==(k+1)):
                childk=node
            if(index==(length-k)):
                parentnk=node
            if(index==(length-k+1)):
                nodenk=node
            if(index==(length-k+2)):
                childnk=node
            index=index+1
            node=node.next
        #swap
        parentk.next=nodenk
        nodenk.next=childk
        parentnk.next=nodek
        nodek.next=childnk
        return head

'''

'''