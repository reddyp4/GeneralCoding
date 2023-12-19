'''
1836. Remove Duplicates From an Unsorted Linked List
Medium
360
11
company
Goldman Sachs
company
Microsoft
Given the head of a linked list, find all the values that appear more than once in the list and delete the nodes that have any of those values.

Return the linked list after the deletions.

 

Example 1:


Input: head = [1,2,3,2]
Output: [1,3]
Explanation: 2 appears twice in the linked list, so all 2's should be deleted. After deleting all 2's, we are left with [1,3].
Example 2:


Input: head = [2,1,1,2]
Output: []
Explanation: 2 and 1 both appear twice. All the elements should be deleted.
Example 3:


Input: head = [3,2,2,1,3,2,4]
Output: [1,4]
Explanation: 3 appears twice and 2 appears three times. After deleting all 3's and 2's, we are left with [1,4].
 

Constraints:

The number of nodes in the list is in the range [1, 105]
1 <= Node.val <= 105
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        #Use hash, maintain unique values only
        d={}
        dummy = ListNode(head.val-1)
        dummy.next = head
        node = head
        while(node):
            if(node.val in d):
                d[node.val]=d[node.val]+1
            else:
                d[node.val]=1
            node = node.next
        #pop non-unique
        for key in list(d.keys()):
            if(d[key]>1):
                d.pop(key)
        if(not d):
            return None
        #traverse ll
        node=dummy
        while(node.next):
            if(node.next.val not in d):
                node.next = node.next.next
            elif(node.next):
                node = node.next
        return dummy.next

'''
Maintan a hash (dict), and remove keys with value more than 1
trick: while popping use list(d.keys())
'''