'''
82. Remove Duplicates from Sorted List II
Medium
8.5K
218
company
Amazon
company
Apple
company
Bloomberg
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

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
        #M1: no hash map
        if(head is None):
            return head
        dummy = ListNode(head.val-1)
        dummy.next = head
        left,right = dummy, dummy.next
        while(left and right and left.next):
            checkval = left.next.val
            count = 0
            while(right and checkval==right.val):
                right=right.next
                count=count+1
            if(count>1):
                left.next = right
            else:
                left = left.next
                if(right and right.next):
                    right = left.next
        return dummy.next

'''
No hash, manual moving - can be slow

If lot of duplicates, use a hash and reconstruct the linked list

'''
