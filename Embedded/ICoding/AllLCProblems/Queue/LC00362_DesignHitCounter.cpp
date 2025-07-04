/*
362. Design Hit Counter
Solved
Medium
Topics
conpanies icon
Companies
Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:

HitCounter() Initializes the object of the hit counter system.
void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).
 

Example 1:

Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

Explanation
HitCounter hitCounter = new HitCounter();
hitCounter.hit(1);       // hit at timestamp 1.
hitCounter.hit(2);       // hit at timestamp 2.
hitCounter.hit(3);       // hit at timestamp 3.
hitCounter.getHits(4);   // get hits at timestamp 4, return 3.
hitCounter.hit(300);     // hit at timestamp 300.
hitCounter.getHits(300); // get hits at timestamp 300, return 4.
hitCounter.getHits(301); // get hits at timestamp 301, return 3.
 

Constraints:

1 <= timestamp <= 2 * 109
All the calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing).
At most 300 calls will be made to hit and getHits.
 

Follow up: What if the number of hits per second could be huge? Does your design scale?
*/
/*
Need a queue for elements within current time-300
*/

class HitCounter {
public:
    queue<int> myQ;
    int current;
    HitCounter() {
        current=0;
    }
    
    void hit(int timestamp) {
        myQ.push(timestamp);current++;
        while(myQ.size()>0 && (timestamp-myQ.front())>=300)  {myQ.pop();current--;}
    }
    
    int getHits(int timestamp) {
        while(myQ.size()>0 && (timestamp-myQ.front())>=300)  {myQ.pop();current--;}
        //cout<<"front:"<<myQ.front()<<",time:"<<timestamp<<endl;
        return current;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */

 /*
 Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
10.74
MB
Beats
19.93%*/