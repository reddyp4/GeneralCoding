'''
83. Remove Duplicates from Sorted List
Easy
8.3K
279
company
Amazon
company
Uber
company
Google
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head is None):
            return head
        dummy = ListNode(head.val-1)
        dummy.next = head
        left,right = dummy.next, dummy.next
        while(left and right and left.next):
            checkval = left.val
            right = left.next
            while(right and checkval==right.val):
                right = right.next
            left.next = right
            left = left.next
        return dummy.next

'''
For every node, check and move
node.next = right
'''