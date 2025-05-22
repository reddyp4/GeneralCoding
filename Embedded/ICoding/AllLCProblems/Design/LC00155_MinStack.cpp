/*
155. Min Stack
Solved
Medium
Topics
Companies
Hint
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/

/*
Two stack solution:

Stack1  MinStack
5       1
1       1
7       2
5       2
2       2
8       8

push: check element and minstack top
pop: if element not same as top of minstack, easy
    if not, need to keep popping minstack, until top>element and rebuild
top: return top of stack
getMin: return top of minstack

*/

#include<stack>

class MinStack {
public:
    stack<int>  myStk;
    stack<int>  myMinStk;
    MinStack() {
        //nothing here
    }
    
    void push(int val) {
        myStk.push(val);
        if(myMinStk.empty())    myMinStk.push(val);
        else    myMinStk.push(min(myMinStk.top(),val));
    }
    
    void pop() {
        if(!myStk.empty())
        {
            myStk.pop();
            myMinStk.pop();
        }
    }
    
    int top() {
        if(!myStk.empty())  return myStk.top();
        return -1;
    }
    
    int getMin() {
        if(!myStk.empty())  return myMinStk.top();
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */