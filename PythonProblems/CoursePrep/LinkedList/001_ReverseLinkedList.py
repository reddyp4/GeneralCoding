'''
Reverse a linked list

'''
class ListNode:
    def __init__(self,val):
        self.val = val 
        self.next = None

def printLL(head):
    node=head
    while(node):
        print(node.val,"->")
        node=node.next

#Recursion
def reverseLLRecur(head,newhead): # -> [head,newhead]:
    if(head.next is None):
        return [head,head]
    [node,newhead] = reverseLLRecur(head.next,newhead)
    node.next = head
    return [head,newhead]

#Using stack
def reverseLL(head):
    if(head is None or head.next is None):
        return head
    ll=[]
    node=head
    while(node):
        ll.append(node)
        node=node.next
    dummy=ListNode(0)
    node=dummy
    while(len(ll)>0):
        node.next = ll.pop()
        node=node.next
    node.next=None
    return dummy.next

def addNode(head,val):
    if(head is None):
        node=ListNode(val)
        return node
    node=head
    while(node.next is not None):
        node=node.next
    newnode = ListNode(val)
    node.next = newnode
    return head

head=ListNode(2)
head=addNode(head,5)
head=addNode(head,15)
head=addNode(head,3)
head=addNode(head,8)
head=addNode(head,1)
printLL(head)
print("Reversed LL")
#newhead = reverseLL(head)
newhead=ListNode(0)
[head,newhead] = reverseLLRecur(head,newhead)
head.next = None
printLL(newhead)
