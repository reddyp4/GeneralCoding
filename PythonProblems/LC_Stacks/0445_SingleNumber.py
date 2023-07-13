'''
445. Add Two Numbers II
Medium
4.5K
246
company
Bloomberg
company
Amazon
company
Capital One
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]
Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
 

Follow up: Could you solve it without reversing the input lists?
'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        #M1: Use two stacks, and add to bigger LL (with new nodes) and reverse this list=
        #Beats: Time(25%),Space(25%)
        stk1,stk2,carry=list(),list(),0
        l1Node,l2Node=l1,l2
        while(l1Node is not None):
            stk1.append(l1Node.val)
            l1Node=l1Node.next
        while(l2Node is not None):
            stk2.append(l2Node.val)
            l2Node=l2Node.next
        l1Node = l1 if (len(stk1)>len(stk2)) else l2
        l2Node = l1Node
        while(stk1 or stk2 or carry):
            n1 = stk1.pop() if stk1 else 0
            n2 = stk2.pop() if stk2 else 0
            new = n1+n2+carry
            carry=int(new/10)
            new = (new%10)
            if(l1Node.next is not None):
                l1Node.val = new
            else:
                l1Node.val = new
                if(carry is not 0):
                    newNode = ListNode()
                    l1Node.next = newNode
            l1Node = l1Node.next
        #rev l1
        l1Node=l2Node
        while(l1Node):
            stk1.append(l1Node)
            l1Node = l1Node.next
        prev=ListNode()
        node = prev
        while(stk1):
            node.next=stk1.pop()
            node=node.next
        node.next = None
        return prev.next
        #M2: Reverse both lists, using a stack, add to bigger LL with new nodes and reverse this list
        return l1