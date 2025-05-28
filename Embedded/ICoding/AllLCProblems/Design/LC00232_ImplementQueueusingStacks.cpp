/*
232. Implement Queue using Stacks
Solved
Easy
Topics
conpanies icon
Companies
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
Notes:

You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

Constraints:

1 <= x <= 9
At most 100 calls will be made to push, pop, peek, and empty.
All the calls to pop and peek are valid.
 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

/*
Method1: Fill everything in stack1, stack2 is empty
push: push to stack
pop: move from stack1 to stack2
peek: keep track, if pop happends, update peek value
empty: same as size of stack
*/
#include<stack>
class MyQueue {
public:
    stack<int> myStk1,myStk2;
    int peekVal;
    MyQueue() {
        peekVal=0;
    }
    
    void push(int x) {
        if(myStk1.empty())   peekVal=x;
        myStk1.push(x);
    }
    
    int pop() {
        int val=-1;
        if(myStk1.empty())  return(-1);
        while(myStk1.size()!=1)  {myStk2.push(myStk1.top());myStk1.pop();}
        if(!myStk1.empty()) {val=myStk1.top();myStk1.pop();}
        if(!myStk2.empty())  peekVal=myStk2.top();
        else    peekVal=-1;
        while(!myStk2.empty())  {myStk1.push(myStk2.top());myStk2.pop();}
        return val;
    }
    
    int peek() {
        return peekVal;
    }
    
    bool empty() {
        return myStk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

 /*
Runtime 
0 ms Beats 100.00%
Analyze Complexity
Memory 9.76 MB Beats 26.39%
 */