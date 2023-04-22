'''
206. Reverse Linked List
Easy
17.5K
319
company
Apple
company
Amazon
company
Bloomberg
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    #Use of globals not recommended
    # newhead = ListNode()
    
    def revList(self, head: ListNode)-> ListNode:
        if(head.next==None):
            return head
        temp = self.revList(head.next)
        head.next.next = head
        head.next=None
        return temp

    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head==None):
            return head
        #M1:iterative solution, with stack. Beats:T(24%),S(87%)
        '''
        stack = []
        temp=head
        while(temp is not None):
            stack.append(temp)
            temp=temp.next
        temp=stack.pop()
        head=temp
        while(temp is not None and len(stack)!=0):
            temp1=stack.pop()
            temp.next=temp1
            temp=temp.next
        temp.next=None
        return head
        '''
        #recursive: Assume k+1 to end is reversed. reverse k., Beats: T(68%),S(12%)
        '''
        if not(head) or not(head.next):
            return head
        temp = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return temp
        '''
        #My recursive with addn function: B:T(39),S(5%)
        temp = self.revList(head)
        head.next=None
        return temp