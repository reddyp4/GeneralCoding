/*
641. Design Circular Deque
Solved
Medium
Topics
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
*/
class MyCircularDeque {
    int head, tail, size, capacity;
    int *myQ;
public:
    MyCircularDeque(int k) {
        /* Initialize */
        head=0;     //head=front
        tail=0;     //tail=rear
        size=0;
        capacity=k;
        myQ=new int[capacity];
        //printf("Init head:%d,tail:%d,size:%d\n",head,tail,size);
    }
    
    bool insertFront(int value) {
        if(isFull())    return false;
        if(isEmpty())
            tail=head;
        else
            head=(head+1)%capacity;
        myQ[head]=value;
        size++;
        //printf("insertFront head:%d,tail:%d,size:%d,value:%d\n",head,tail,size,value);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())    return false;
        if(isEmpty())
            head=tail;
        else
            tail = (tail==0)? capacity-1 : tail-1;
        myQ[tail]=value;
        size++;
        //printf("insertLast head:%d,tail:%d,size:%d,value:%d\n",head,tail,size,value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())   return false;
        head--;
        head = (head<0)? capacity-1 : head;
        size--;
        if(isEmpty())   tail=head;
        //printf("deleteFront head:%d,tail:%d,size:%d\n",head,tail,size);
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())   return false;
        tail=(tail+1)%capacity;
        size--;
        if(isEmpty())   head=tail;
        //printf("deleteLast head:%d,tail:%d,size:%d\n",head,tail,size);
        return true;
    }
    
    int getFront() {
        if(isEmpty())   return -1;
        int value;
        /*if(head==0)
        {
            value=myQ[capacity-1];
            printf("getFront head:%d,tail:%d,size:%d,value:%d\n",head,tail,size,value);
            return value;
        }*/
        value=myQ[head];
        //printf("getFront head:%d,tail:%d,size:%d,value:%d\n",head,tail,size,value);
        return value;
    }
    
    int getRear() {
        if(isEmpty())   return -1;
        int value=myQ[tail];
        //printf("getRear head:%d,tail:%d,size:%d,value:%d\n",head,tail,size,value);
        return value;
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==capacity);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */