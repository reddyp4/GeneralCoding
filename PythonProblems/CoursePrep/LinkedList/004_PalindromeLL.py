class Node:
    def __init__(self,val):
        self.val = val
        self.next = None 

def printLL(head):
    node=head
    while(node):
        print("->",node.val)

def insertNode(head,val):
    if(head is None):
        node = Node(val)
        return node
    node=head
    while(node.next):
        node=node.next
    newnode = Node(val)
    node.next = newnode

def checkPalindrome(head):
    if(head is None):
        return True
    if(head.next is None):
        return True
    node=head
    ll=[]
    while(node):
        ll.append(node.val)
        node=node.next
    node=head
    while(node):
        if(node.val==ll[-1]):
            ll.pop()
        else:
            return False
        node=node.next
    return True 

head=Node(2)
insertNode(head,5)
insertNode(head,10)
insertNode(head,10)
insertNode(head,5)
insertNode(head,2)

if(checkPalindrome(head)):
    print("Palindrome!")
else:
    print("Not a Palindrome")
