'''
1171. Remove Zero Sum Consecutive Nodes from Linked List
Medium
2.1K
94
josh technology
company
Amazon
company
Google
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head.next is None and head.val!=0):
            return head
        if(head.next is None):
            return None
        #Bruteforce: Go through each time, and add, O(n2), since removal of two nodes may bring back two other nodes
        #add prefix sum, whenever the same sum is seen, remove all elements
        #in between
        dummy=ListNode(1001)
        dummy.next=head
        node=dummy
        prefix={}
        prefixsum=0
        while(node):
            prefixsum=prefixsum+node.val
            if(prefixsum in prefix):
                #remove all elements in between
                prefix[prefixsum].next=node.next
                #pop this key and all previous keys
                keyslist = list(prefix.keys())
                while(keyslist[-1]!=prefixsum):
                    key=keyslist[-1]
                    prefix.pop(key)
                    keyslist.pop()
            else:
                prefix[prefixsum]=node
            node=node.next
        return dummy.next

'''
keep prefix sum in hash, hash[prefixsum]=node, when repeats, remove all elements and keys

'''