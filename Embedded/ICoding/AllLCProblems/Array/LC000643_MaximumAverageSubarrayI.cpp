/*
643. Maximum Average Subarray I
Solved
Easy
Topics
conpanies icon
Companies
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxsum=0,sum=0;
        int i=0,len1=nums.size();
        for(i=0;i<k;i++)  sum+=nums[i];
        maxsum=sum;
        while(i<len1)   {
            sum=(sum+nums[i]-nums[i-k]);
            maxsum=(maxsum>sum)?maxsum:sum;
            i++;
        }
        return (maxsum/k);
    }
};

/*
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
113.77
MB
Beats
44.39%
*/