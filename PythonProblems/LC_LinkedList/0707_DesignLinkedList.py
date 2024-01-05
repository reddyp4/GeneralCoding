'''
707. Design Linked List
Medium
2.5K
1.6K
company
Google
company
Amazon
company
Microsoft
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
'''

class ListNode:
    def __init__(self,val):
        self.val=val
        self.next = None

class MyLinkedList:
    def __init__(self):
        self.head = ListNode(0)
    
    def get(self, index: int) -> int:
        count,node=-1,self.head
        while(node and count<index):
            node=node.next
            count=count+1
        if(node is None):
            return -1
        return node.val

    def addAtHead(self, val: int) -> None:
        newnode = ListNode(val)
        if(self.head.next is None):
            self.head.next = newnode
            return
        temp = self.head.next
        self.head.next = newnode
        newnode.next = temp

    def addAtTail(self, val: int) -> None:
        node=self.head
        while(node.next):
            node=node.next
        node.next = ListNode(val)

    def addAtIndex(self, index: int, val: int) -> None:
        count,node=-1,self.head
        while(node.next and count<index-1):
            count,node=count+1,node.next
        if(node.next is None):
            if(count==index-1):
                node.next=ListNode(val)
                return
            else:
                #dont add
                return
        temp=node.next
        node.next=ListNode(val)
        if(temp):
            node.next.next = temp

    def deleteAtIndex(self, index: int) -> None:
        count,node=-1,self.head
        while(node.next and count<index-1):
            count,node=count+1,node.next
        if(node.next is None):
            return
        node.next=node.next.next
        return


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)

'''
Use class ListNode for easier node creation
Trick: In addIndex, need to check if reached end, if not DO NOT ADD!!! 

'''