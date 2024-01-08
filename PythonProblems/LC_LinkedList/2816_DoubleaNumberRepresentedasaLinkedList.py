'''
2816. Double a Number Represented as a Linked List
Medium
426
6
company
Nvidia
company
Amazon
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

Constraints:

The number of nodes in the list is in the range [1, 104]
0 <= Node.val <= 9
The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def recur(self, head, carry):
        if(head.next is None):
            new= 2*head.val
            head.val = new%10
            carry = int(new/10)
            return carry
        carry = self.recur(head.next,carry)
        new = 2*head.val+carry
        head.val = new%10
        carry=int(new/10)
        return carry

    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        carry = self.recur(head,0)
        if(carry):
            newhead = ListNode(carry)
            newhead.next=head
            return newhead
        return head

'''
Recursion
'''