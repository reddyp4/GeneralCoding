'''
61. Rotate List
Medium
9.1K
1.4K
company
Amazon
company
Adobe
company
Apple
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        #Use list to keep values, it is easy to rotate list
        #take mod, to remove rotations leading to same ll
        if(head is None or head.next is None):
            return head
        ll = []
        node = head
        count = 0
        while(node):
            ll.append(node.val)
            node=node.next
            count = count+1
        k = k%count
        ll1 = ll[count-k:]
        ll1.extend(ll[:count-k+1])
        node=head
        i=0
        while(node):
            node.val = ll1[i]
            node=node.next
            i=i+1
        return head

'''
Use a list and its rotation and reassign the node values
'''
