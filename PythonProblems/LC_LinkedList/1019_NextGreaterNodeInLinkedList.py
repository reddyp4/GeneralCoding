'''
1019. Next Greater Node In Linked List
Medium
3.2K
116
company
Amazon
company
Apple
company
Microsoft
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 104
1 <= Node.val <= 109
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        if(head.next is None):
            return [0]
        #Bruteforce: Check for each node
        #M2: If reversed, then max stack?
        values=[]
        node=head
        while(node):
            values.append(node.val)
            node=node.next
        #print("act values:",values)
        #Use stack, add to stack if smaller than top of stack 
        #else pop, assign result of this value as new value
        #until all smaller values
        result=[0]*len(values)
        stack=[]
        for i in range(len(values)):
            if(len(stack)==0):
                stack.append(i)
                continue
            if(values[stack[-1]]<values[i]):
                while(len(stack)!=0 and values[stack[-1]]<values[i]):
                    result[stack[-1]]=values[i]
                    stack.pop()
                #result=result+tempresult
                stack.append(i)
                #print("result:",result)
            else:
                stack.append(i)
            #print("result:",result,"value:",values[i],"stack:",stack)
        return result
    
'''
Create a monotonic stack
Trick: save the index instead of value
'''