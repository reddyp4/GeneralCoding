'''
716. Max Stack
Hard
1.9K
503
company
LinkedIn
Walmart Labs
company
Amazon
Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.

 

Example 1:

Input
["MaxStack", "push", "push", "push", "top", "popMax", "top", "peekMax", "pop", "top"]
[[], [5], [1], [5], [], [], [], [], [], []]
Output
[null, null, null, null, 5, 5, 1, 5, 1, 5]

Explanation
MaxStack stk = new MaxStack();
stk.push(5);   // [5] the top of the stack and the maximum number is 5.
stk.push(1);   // [5, 1] the top of the stack is 1, but the maximum is 5.
stk.push(5);   // [5, 1, 5] the top of the stack is 5, which is also the maximum, because it is the top most one.
stk.top();     // return 5, [5, 1, 5] the stack did not change.
stk.popMax();  // return 5, [5, 1] the stack is changed now, and the top is different from the max.
stk.top();     // return 1, [5, 1] the stack did not change.
stk.peekMax(); // return 5, [5, 1] the stack did not change.
stk.pop();     // return 1, [5] the top of the stack and the max element is now 5.
stk.top();     // return 5, [5] the stack did not change.
 

Constraints:

-107 <= x <= 107
At most 105 calls will be made to push, pop, top, peekMax, and popMax.
There will be at least one element in the stack when pop, top, peekMax, or popMax is called.
'''

class MaxStack:

    #Idea: Use same idea as minStack, maintain a maxStack
    def __init__(self):
        self.stk = []
        self.maxstk = []

    def push(self, x: int) -> None:
        self.stk.append(x)
        if(self.peekMax()<x):
            self.maxstk.append(x)
        else:
            self.maxstk.append(self.maxstk[-1])

    def pop(self) -> int:
        val = self.stk[-1]
        self.stk.pop()
        self.maxstk.pop()
        return val

    def top(self) -> int:
        if(len(self.stk)==0):
            return 0
        else:
            return self.stk[-1]

    def peekMax(self) -> int:
        if(len(self.maxstk)==0):
            return -1e8
        else:
            return self.maxstk[-1]

    def popMax(self) -> int:
        #For popping need find the index of the maximum stack and pop
        #However note that may change the maxStack as well
        if(self.peekMax()==self.top()):
            val=self.top()
            self.stk.pop()
            self.maxstk.pop()
            return val
        else:
            newstk=[]
            #print(newstk,self.stk,self.maxstk)
            while(len(self.stk)!=0 and self.top()!=self.peekMax()):
                newstk.append(self.pop())
            #print(newstk,self.stk,self.maxstk)
            #pop the max
            result=self.stk[-1]
            self.stk.pop()
            self.maxstk.pop()
            #refill the stack
            val=newstk[-1]
            self.stk.append(val)
            if(len(self.maxstk)==0 or val>self.maxstk[-1]):
                self.maxstk.append(val)
            else:
                self.maxstk.append(val)
            newstk.pop()
            while(len(newstk)!=0):
                val=newstk[-1]
                maxval=self.maxstk[-1]
                self.stk.append(val)
                self.maxstk.append(val) if (val>maxval) else self.maxstk.append(maxval)
                newstk.pop()
        return result

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()

'''
Method1: Keep maxstack works - works except for case 165/167 - exceeds time limit
Method2: Python use SortedList(), keeps the list sorted for you!!!
Method3: heapq
'''