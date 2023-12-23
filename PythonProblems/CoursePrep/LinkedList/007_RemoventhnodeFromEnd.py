'''
Remove nth node from end
'''
class Node:
    def __init__(self,value):
        self.value=value
        self.next=None

def printLL(head):
    node=head
    while(node):
        print(node.value,"->",end="")
        node=node.next

def removenthLL(head,n):
    if(head is None):
        return head
    node,prenode,count=head,head,1
    while(count<n-1 and node):
        node=node.next
        count=count+1
    if(node is None):
        return head
    prenode=head
    while(node.next):
        node=node.next
        prenode=prenode.next
    if(prenode.next):
        prenode.next=prenode.next.next
    return head 

def createLL(list):
    if(len(list)==0):
        return None
    head=Node(list.pop(0))
    node=head
    while(len(list)>0):
        node.next=Node(list.pop(0))
        node=node.next
    return head

head=createLL([1,2,3,4,5])
#printLL(head)
head=removenthLL(head,2)
printLL(head)
