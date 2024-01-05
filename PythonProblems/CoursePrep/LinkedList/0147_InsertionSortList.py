'''
147. Insertion Sort List
Medium
3K
855
company
Microsoft
company
Google
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def printnode(self,head):
        node=head
        while(node):
            print(node.val,"->",end="")
            node=node.next
        print("")
        
    def insert(self, head, newnode):
        node=head
        #print("newnode:",newnode.val,end=",")
        while(node.next and node.next.val<newnode.val):
            node=node.next
            #print("node:",node.val)
        if(node.next is None):
            node.next=newnode
        else:
            newnode.next=node.next
            node.next=newnode
        
    def insertionSortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head.next is None):
            return head
        dummy=ListNode(-5001)
        node=head
        while(node):
            temp=node.next
            node.next=None
            self.insert(dummy,node)
            #self.printnode(dummy)
            node=temp
        return dummy.next

'''
Insert with a dummy.
Tricky: ensure to make temp = node.next, otherwise will get a circular list
'''