/*
287. Find the Duplicate Number
Solved
Medium
Topics
Companies
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/

class Solution {
    public:
        void printBits(vector<int>&nums) {
            cout<<"array:";
            for(int i=0;i<nums.size();i++)  cout<<nums[i]<<",";
            cout<<endl;
        }
    
        int findDuplicate(vector<int>& nums) {
            //Bit Manipulation
            vector<int> onesNums(32),onesRegular(32),result(32);
            for(int i=0;i<nums.size();i++)
            {
                for(int j=0;j<30;j++)
                {
                    onesNums[j]+=((nums[i]&(1<<j))!=0);
                    onesRegular[j]+=((i&(1<<j))!=0);
                }
            }
            //cout<<"given"<<endl;
            //printBits(onesNums);
            //cout<<"regular"<<endl;
            //printBits(onesRegular);
            for(int j=0;j<32;j++)   result[j]=(onesNums[j]-onesRegular[j]);
            //cout<<"result:"<<endl;
            //printBits(result);
            int number=0,pow2=1;
            for(int i=0;i<30;i++)
            {
                number+=(pow2*(result[i]>0));
                pow2<<=1;
            }
            return number;
        }
    };

/*
Runtime
38
ms
Beats
23.83%

Memory
65.01
MB
Beats
68.98%

*/