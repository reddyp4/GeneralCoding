'''
2046. Sort Linked List Already Sorted Using Absolute Values
Medium
158
3
company
Bloomberg
Given the head of a singly linked list that is sorted in non-decreasing order using the absolute values of its nodes, return the list sorted in non-decreasing order using the actual values of its nodes.
 

Example 1:


Input: head = [0,2,-5,5,10,-10]
Output: [-10,-5,0,2,5,10]
Explanation:
The list sorted in non-descending order using the absolute values of the nodes is [0,2,-5,5,10,-10].
The list sorted in non-descending order using the actual values is [-10,-5,0,2,5,10].
Example 2:


Input: head = [0,1,2]
Output: [0,1,2]
Explanation:
The linked list is already sorted in non-decreasing order.
Example 3:

Input: head = [1]
Output: [1]
Explanation:
The linked list is already sorted in non-decreasing order.
 

Constraints:

The number of nodes in the list is the range [1, 105].
-5000 <= Node.val <= 5000
head is sorted in non-decreasing order using the absolute value of its nodes.
 

Follow up:
Can you think of a solution with O(n) time complexity?
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortLinkedList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        #Push all negative into a stack and pop and attach to positive
        if(head is None or head.next is None):
            return head
        dummy=ListNode(-100000)
        node=head
        st=[]
        posnodehead=ListNode(0)
        prevposnode=posnodehead
        while(node):
            if(node.val<0):
                temp=node.next
                node.next=None
                st.append(node)
                #print("neg node:",node.val)
                node=temp
            else:
                temp=node.next
                node.next=None
                #print("prevposnode node:",prevposnode.val)
                prevposnode.next=node
                prevposnode=node
                #print("new prevposnode node:",prevposnode.val)
                node=temp
        #pop from stack in reverse
        #print("stack:",st)
        node=dummy
        while(len(st)!=0):
            node.next=st[-1]
            st.pop()
            node=node.next
        #attach
        node.next=posnodehead.next
        return dummy.next

'''
Two dummy pointer approach
small change is use of stack for negative numbers.

'''