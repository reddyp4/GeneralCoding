'''
143. Reorder List


Medium
10K
342
company
Amazon
company
Adobe
company
Google
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        #M1: Use stack and add every other element
        #Second pass to insert new elements
        if(head.next is None):
            return head
        ll = []
        node=head
        preleft,left,right=head,head,head
        while(right and right.next):
            preleft=left
            left=left.next
            right = right.next.next
        preleft.next=None
        while(left):
            node=left
            left=left.next
            node.next=None
            ll.append(node)
        node=head
        while(ll and node):
            temp=node.next
            node.next = ll.pop()
            node.next.next = temp
            if(node.next and node.next.next):
                node = node.next.next
            elif(node.next.next is None):
                node = node.next
        return head