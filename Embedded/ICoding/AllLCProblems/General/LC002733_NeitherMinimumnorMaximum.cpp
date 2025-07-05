/*
2733. Neither Minimum nor Maximum
Easy
Topics
Hint
Given an integer array nums containing distinct positive integers, find and return any number from the array that is neither the minimum nor the maximum value in the array, or -1 if there is no such number.

Return the selected integer.

 

Example 1:

Input: nums = [3,2,1,4]
Output: 2
Explanation: In this example, the minimum value is 1 and the maximum value is 4. Therefore, either 2 or 3 can be valid answers.
Example 2:

Input: nums = [1,2]
Output: -1
Explanation: Since there is no number in nums that is neither the maximum nor the minimum, we cannot select a number that satisfies the given condition. Therefore, there is no answer.
Example 3:

Input: nums = [2,1,3]
Output: 2
Explanation: Since 2 is neither the maximum nor the minimum value in nums, it is the only valid answer. 
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
All values in nums are distinct
*/

/*
Find Min, Max
Scan again to find a non-min, non-max
*/

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size()<=2)  return -1;
        int minval,maxval,i,result;
        minval=nums[0];maxval=nums[0];
        for(i=1;i<nums.size();i++)
        {
            if(maxval<nums[i])  maxval=nums[i];
            if(minval>nums[i])  minval=nums[i];
        }
        if(minval==maxval)  return -1;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=minval && nums[i]!=maxval)  {   
                result=nums[i];
                break;
            }
        }
        //cout<<"minval:"<<minval<<",maxval:"<<maxval<<endl;
        return result;
    }
};

/*
Runtime
99
ms
Beats
5.31%
Analyze Complexity
Memory
97.11
MB
Beats
56.21%

*/