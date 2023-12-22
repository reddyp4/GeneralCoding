class Node:
    def __init__(self,val):
        self.val = val
        self.next = next 

def printLL(head):
    node=head
    while(node):
        print("->",node.val)

