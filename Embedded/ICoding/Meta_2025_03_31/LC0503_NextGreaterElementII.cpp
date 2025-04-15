/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109
Seen this question in a real intervi
*/

class Solution {
    public:
        void printStack(stack<int> mystk, int printFlag) {
            if(printFlag==0)    return;
            cout<<"Stack:";
            while(!mystk.empty())
            {
                cout<<mystk.top()<<",";
                mystk.pop();
            }
            cout<<":"<<endl;
        }
    
        vector<int> nextGreaterElements(vector<int>& nums) {
            int printFlag=0;
            int len1 = nums.size();
            stack<int> mystk,myindexstk;
            vector<int> result(len1,-1);
            if(len1==1) 
            {
                result[0]=-1;
                return(result);
            }
            if(printFlag)   cout<<"len:"<<len1;
            for(int i=0;i<2*len1;i++)
            {
                printStack(mystk,printFlag);
                if(mystk.empty())
                {
                    //push element into stack
                    mystk.push(nums[i%len1]);myindexstk.push(i%len1);
                    continue;
                }
                if(!mystk.empty() && mystk.top()>=nums[i%len1])
                {
                    //smaller elements get pushed into stack
                    mystk.push(nums[i%len1]);myindexstk.push(i%len1);
                }
                else
                {
                    while(!mystk.empty() && mystk.top()<nums[i%len1])
                    {
                        //found nge for mystk.top() at nums[i]
                        if(printFlag)
                            cout<<"found nge="<<nums[i%len1]<<" for "<<nums[myindexstk.top()]<<endl;
                        result[myindexstk.top()]=nums[i%len1];
                        mystk.pop();myindexstk.pop();
                    }
                    mystk.push(nums[i%len1]);myindexstk.push(i%len1);
                }
            }
            if(printFlag)
                cout<<"Finished:Stack:";
            printStack(mystk,printFlag);
            if(printFlag)
                cout<<"Index stack:";
            printStack(myindexstk,printFlag);
            return result;
        }
    };

/*
Runtime
451
ms
Beats
5.01%

Memory
415.96
MB
Beats
5.21%
*/