'''
369. Plus One Linked List
Medium
922
42
company
Google
Given a non-negative integer represented as a linked list of digits, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list.

 

Example 1:

Input: head = [1,2,3]
Output: [1,2,4]
Example 2:

Input: head = [0]
Output: [1]
 

Constraints:

The number of nodes in the linked list is in the range [1, 100].
0 <= Node.val <= 9
The number represented by the linked list does not contain leading zeros except for the zero itself. 
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addRecursive(self, head):
        if(head.next is None):
            sum1=head.val+1
            head.val=sum1%10
            carry=int(sum1/10)
            return carry
        carry = self.addRecursive(head.next)
        sum1=head.val+carry
        head.val=sum1%10
        carry=int(sum1/10)
        return carry
        
    def plusOne(self, head: ListNode) -> ListNode:
        carry = self.addRecursive(head)
        if(carry):
            newnode=ListNode(carry)
            newnode.next=head
            return newnode
        else:
            return head

'''
Recursive add, using stack
'''