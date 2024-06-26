/*
1670. Design Front Middle Back Queue
Medium
Topics
Companies
Hint
Design a queue that supports push and pop operations in the front, middle, and back.

Implement the FrontMiddleBack class:

FrontMiddleBack() Initializes the queue.
void pushFront(int val) Adds val to the front of the queue.
void pushMiddle(int val) Adds val to the middle of the queue.
void pushBack(int val) Adds val to the back of the queue.
int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:

Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 

Example 1:

Input:
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
Output:
[null, null, null, null, null, 1, 3, 4, 2, -1]

Explanation:
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // return 1 -> [4, 3, 2]
q.popMiddle();    // return 3 -> [4, 2]
q.popMiddle();    // return 4 -> [2]
q.popBack();      // return 2 -> []
q.popFront();     // return -1 -> [] (The queue is empty)
 

Constraints:

1 <= val <= 109
At most 1000 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.
*/
class FrontMiddleBackQueue {
public:
    std::deque<int> front1, back1;
    /* Use two double ended queues */
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        /* push into front */
        front1.push_front(val);
    }
    
    void pushMiddle(int val) {
        if(front1.size()<back1.size())    front1.push_back(val);
        else                            back1.push_front(val);
    }
    
    void pushBack(int val) {
        /* push to back */
        back1.push_back(val);
    }
    
    int popFront() 
    {
        int value;
        if(front1.size()>0)
        {
            value = front1.front();
            front1.pop_front();
        }
        else if(back1.size()>0)
        {
            value = back1.back();
            back1.pop_back();
        }
        else
            value=-1;
        return value;
    }
    
    int popMiddle() 
    {
        int value;
        if(back1.size()==0 && front1.size()==0) return -1;
        if(back1.size()==0)
        {
            if(front1.size()==0)    return -1;
            value=front1.back();
            front1.pop_back();
        }
        else if(front1.size()==0)
        {
            if(back1.size()==0)    return -1;
            value=back1.front();
            back1.pop_front();
        }
        else
        {
            if(front1.size()<back1.size())
            {
                value=back1.front();
                back1.pop_front();
            }
            else
            {
                value=front1.back();
                front1.pop_back();
            }
        }
        return value;
    }
    
    int popBack() {
        int value;
        if(back1.size()>0)
        {
            value=back1.back();
            back1.pop_back();
        }
        else if (front1.size()>0)
        {
            value=front1.back();
            front1.pop_back();
        }
        else
            value=-1;
        return value;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */