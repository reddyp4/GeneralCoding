'''
MSB comes first
'''
class Node:
    def __init__(self,value):
        self.value=value
        self.next=None 

def printLL(head):
    node=head
    while(node):
        print(node.value,"->",end=" ")
        node=node.next

def createLL(lists):
    if(len(lists)==0):
        return None
    head=Node(lists[0])
    node=head
    if(len(lists)==1):
        return head
    for index,elem in enumerate(lists[1:]):
        node.next = Node(elem)
        node=node.next
    return head

def sumLL(head1,head2):
    if(head1 is None and head2 is None):
        return None 
    if(head1 is None):
        return head2
    if(head2 is None):
        return head1
    list1,list2=[],[]
    node1,node2=head1,head2
    while(node1):
        list1.append(node1.value)
        node1=node1.next
    while(node2):
        list2.append(node2.value)
        node2=node2.next
    node1,node2,carry,finallist=head1,head2,0,[]
    if(len(list1)>len(list2)):
        finalhead=head1
    else:
        finalhead=head2
    while(len(list2)>0 and len(list1)>0):
        newsum=carry+list1.pop()+list2.pop()
        finallist.append(newsum%10)
        carry=int(newsum/10)
        node1=node1.next
    if(len(list1)>0):
        while(len(list1)>0):
            newsum=carry+list1.pop()
            finallist.append(newsum%10)
            carry=int(newsum/10)
    if(len(list2)>0):
        while(len(list2)>0):
            newsum=carry+list2.pop()
            finallist.append(newsum%10)
            carry=int(newsum/10)
    if(carry):
        finallist.append(carry)
    print("finallist:",finallist)
    node=finalhead
    while(len(finallist)>0 and node.next):
        node.value=finallist.pop()
        node=node.next
    node.value=finallist.pop()
    while(len(finallist)>0):
        node.next=Node(finallist.pop())
        node=node.next
    return finalhead

head1=createLL([9])
head2=createLL([9])
finalhead=sumLL(head1,head2)
printLL(finalhead)