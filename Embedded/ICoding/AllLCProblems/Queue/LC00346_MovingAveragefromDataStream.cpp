/*
346. Moving Average from Data Stream
Solved
Easy
Topics
conpanies icon
Companies
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
 

Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
 

Constraints:

1 <= size <= 1000
-105 <= val <= 105
At most 104 calls will be made to next.
*/

/*
maintain the count until n, and once reached, drop the previous value
to know the previous value, keep in a queue
*/

class MovingAverage {
public:
    queue<int> myQ;
    double SIZE;
    double average;
    MovingAverage(int size) {
        SIZE=size;
        average=0;
    }
    
    double next(int val) {
        if(myQ.size()<SIZE)
        {
            //cout<<"average:"<<average<<",val:"<<((double)val)<<",size:"<<(double)(myQ.size())<<endl;
            average = (average*((double)myQ.size())+val)/((double)myQ.size()+1);
        }
        else 
        {
            average=(average*SIZE-myQ.front()+val)/((double)SIZE);
            myQ.pop();
        }
        myQ.push(val);
        return average;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

/*
 Runtime
3
ms
Beats
47.82%
Analyze Complexity
Memory
20.80
MB
Beats
77.54%
*/