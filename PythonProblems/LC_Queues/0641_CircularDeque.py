'''
641. Design Circular Deque
Medium
989
69
company
Goldman Sachs
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.
'''
class MyCircularDeque(object):

    def __init__(self, k):
        """
        :type k: int
        """
        self.array = [-1]*k
        self.head=self.tail=-1

    def insertFront(self, value):
        """
        :type value: int
        :rtype: bool
        """
        #Insert at head. Check if full. Other reduce head (with wrap) and insert. Also add to empty array.
        if(self.isEmpty()):
            self.head=self.tail=0
            self.array[self.head]=value
            return True
        if(self.isFull()):
            return False
        # Decrement head with wrap and insert
        self.head = (self.head-1)%len(self.array)
        self.array[self.head] = value
        return True
        

    def insertLast(self, value):
        """
        :type value: int
        :rtype: bool
        """
        #Insert at tail, similar to Queue. Check empty, check full, else increment tail and add.
        if(self.isEmpty()):
            self.head=self.tail=0
            self.array[self.tail] = value
            return True
        if(self.isFull()):
            return False
        #Increment tail with wrap and insert
        self.tail = (self.tail+1)%len(self.array)
        self.array[self.tail] = value
        return True
        

    def deleteFront(self):
        """
        :rtype: bool
        """
        #Delete at head. If empty, return false. If single element, delete and init head&tail. Else delete like queue.
        if(self.isEmpty()):
            return False
        if(self.head==self.tail):
            self.array[self.head]=-1
            self.head=self.tail=-1
            return True
        #Increment head with wrap.
        self.array[self.head] = -1
        self.head = (self.head+1)%len(self.array)
        return True
        

    def deleteLast(self):
        """
        :rtype: bool
        """
        #Delete at tail. If empty, return false. If single element, reset. Otherwise decrement tail with wrap.
        if(self.isEmpty()):
            return False
        if(self.head==self.tail):
            #single element
            self.array[self.tail]=-1
            self.head=self.tail=-1
            return True
        #Decrement tail with wrap.
        self.array[self.tail] = -1
        self.tail = (self.tail-1)%len(self.array)
        return True

        

    def getFront(self):
        """
        :rtype: int
        """
        #return value at head, if not empty
        if(self.isEmpty()):
            return -1
        return self.array[self.head]
        

    def getRear(self):
        """
        :rtype: int
        """
        #return value at tail, if not empty
        if(self.isEmpty()):
            return -1
        return self.array[self.tail]
        

    def isEmpty(self):
        """
        :rtype: bool
        """
        #Check head value -1
        return (self.head==-1)
        

    def isFull(self):
        """
        :rtype: bool
        """
        #Check head=tail+1
        return (self.head==(self.tail+1)%len(self.array))
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()