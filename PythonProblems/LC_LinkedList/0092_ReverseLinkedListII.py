'''
92. Reverse Linked List II
Medium
11.1K
535
company
Adobe
company
Amazon
company
Facebook
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

Follow up: Could you do it in one pass?
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        #M1: Use a stack
        if(head.next is None):
            return head
        dummy = ListNode()
        dummy.next = head
        count = 1
        preleftNode, afterrightNode = dummy, dummy
        while(count<left):
            preleftNode = preleftNode.next
            count = count + 1
        count = 1
        while(count<=right+1):
            afterrightNode = afterrightNode.next
            count = count + 1
        stack = []
        node = preleftNode.next
        while(node!=afterrightNode):
            stack.append(node)
            node=node.next
        node = preleftNode
        while(stack):
            node.next = stack.pop()
            node = node.next
        node.next = afterrightNode
        return dummy.next

'''
M1: Stack, single pass
Time:O(n), Space:O(n)

M2: Iterative recursion

M3: Recursion

'''