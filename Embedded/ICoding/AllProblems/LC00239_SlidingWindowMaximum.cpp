/*
239. Sliding Window Maximum
Solved
Hard
Topics
Companies
Hint

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    1 <= k <= nums.length


*/

/*
Method1: @every index, find max-bruteforce, as expected time exceeded for longer ones
Method2: deque
    deque with good elements: good if > all elements within window to right
        result is formed within window
        next element==good also means top/first>new, add to deque
        else clear deque, add new element (new element) and to result
        continue...
*/

class Solution {
public:
    void printD(deque<int> d)
    {
        cout<<"Dq:";
        for(int i=0;i<d.size();i++) cout<<d[i]<<",";
        cout<<endl;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> myHeap;
        vector<int> result;
        int len1=nums.size(),i=0;
        bool print=false;
        myHeap.push_back(k-1);
        if(print)   printD(myHeap);
        /*
        for(i=k-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])   myHeap.push_front(i);   //good
            //else do nothing
        }*/
        for(i=0;i<k;i++)
        {
            while(!myHeap.empty() && nums[myHeap.back()]<=nums[i])   myHeap.pop_back();
            myHeap.push_back(i);
        }
        if(print)   printD(myHeap);
        if(print)   cout<<"Finished initial window"<<endl;
        //first element is into result
        result.push_back(nums[myHeap[0]]);
        //Now continue to move the window
        i=k;
        //if(print)   printD(myHeap);
        while(i<len1)
        {
            //remove old elements of prev window
            while(!myHeap.empty() && myHeap.front()<=(i-k))  myHeap.pop_front();
            //remove all smaller elements
            while(!myHeap.empty() && nums[myHeap.back()]<nums[i])   myHeap.pop_back();
            //this element is bigger than nothing, so push
            myHeap.push_back(i);
            //update result
            result.push_back(nums[myHeap[0]]);
            if(print)   printD(myHeap);
            i++;
        }
        return result;
    }
};

/*
Runtime 21ms Beats69.62%
Analyze Complexity
Memory 139.04MB Beats83.44%
*/