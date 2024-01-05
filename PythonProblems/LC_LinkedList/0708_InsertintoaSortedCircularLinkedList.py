'''
708. Insert into a Sorted Circular Linked List
Medium
1.1K
742
company
Facebook
company
Microsoft
company
Google
Given a Circular Linked List node, which is sorted in non-descending order, write a function to insert a value insertVal into the list such that it remains a sorted circular list. The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node. Otherwise, you should return the originally given node.

 

Example 1:


 
Input: head = [3,4,1], insertVal = 2
Output: [3,4,1,2]
Explanation: In the figure above, there is a sorted circular list of three elements. You are given a reference to the node with value 3, and we need to insert 2 into the list. The new node should be inserted between node 1 and node 3. After the insertion, the list should look like this, and we should still return node 3.



Example 2:

Input: head = [], insertVal = 1
Output: [1]
Explanation: The list is empty (given head is null). We create a new single circular list and return the reference to that single node.
Example 3:

Input: head = [1], insertVal = 0
Output: [1,0]
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-106 <= Node.val, insertVal <= 106
'''

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    def insert(self, head: 'Optional[Node]', insertVal: int) -> 'Node':
        if(head is None):   #no elements
            head=Node(insertVal)
            head.next=head
            return head
        if(head.next is head):  #single element
            newnode=ListNode(insertVal)
            head.next=newnode
            newnode.next=head
            return head
        #Find node.next that is greater, corner case is greatest or smallest number
        #creation of new head is special case, we dont need?
        #number greater than all elements is special case
        #number smaller than all elements is special case
        #all other case, find where node1<newnode<node2(node2=node1.next)
        node=head
        newnode=ListNode(insertVal)
        #find the greatest val
        while(node.next.val>=node.val):  #move node until greatest number
            #print(node.val)
            node=node.next
            if(node==head):
                break
        #check equal values, else continue searching for greatest
        if(node!=head): #not circled, means no greatest value i.e. all values are equal
            while(node.next.val>=node.val and node!=head):  #move node until greatest number
                #print(node.val)
                node=node.next
        #check if insertval is greatest or smallest, then add after node, else search
        #print(node.val)
        if(node.val<=insertVal or insertVal<node.next.val):
            #do nothing
            node=node
        else:
            #start looking from here
            while not (node.val<=insertVal and insertVal<node.next.val):
                node=node.next
                #print(node.val)
        #node points to where newnode is added
        newnode.next=node.next
        node.next=newnode
        return head

'''
Find the greatest node first, and then search
Tricky: all values are equal
Tricky: non-unique numbers, so check <= and < 
'''