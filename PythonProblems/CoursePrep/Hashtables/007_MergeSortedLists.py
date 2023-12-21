class ListNode:
    def __init__(self,val):
        self.val = val 
        self.next = None 

def printLL(head):
    node=head
    while(node):
        print("->",node.val)
        node=node.next 

def addNode(head,val):
    if(head is None):
        return head
    node=head
    while(node.next):
        node=node.next
    node.next = ListNode(val)

def mergeLists(head1,head2):
    if(head1 is None and head2 is None):
        return head1
    if(head1 is None):
        return head2
    if(head2 is None):
        return head1
    node1,node2=head1,head2
    dummy=ListNode(0)
    node=dummy
    while(node1 and node2):
        if(node1.val<=node2.val):
            node.next = node1
            node1=node1.next
            node=node.next
        else:
            node.next = node2
            node2=node2.next
            node=node.next
    if(node1):
        node.next=node1
        node,node1=node.next,node1.next
    if(node2):
        node.next=node2
        node,node2=node.next,node2.next
    return dummy.next

head1=ListNode(2)
addNode(head1,4)
addNode(head1,6)
addNode(head1,8)
addNode(head1,10)
print("head1")
printLL(head1)

head2=ListNode(1)
addNode(head2,3)
addNode(head2,4)
addNode(head2,5)
addNode(head2,15)
print("head2")
printLL(head2)

newhead = mergeLists(head1,head2)
print("newhead")
printLL(newhead)
