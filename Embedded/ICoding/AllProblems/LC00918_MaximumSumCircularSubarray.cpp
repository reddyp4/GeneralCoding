/*
918. Maximum Sum Circular Subarray
Solved
Medium
Topics
Companies
Hint

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.

Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

 

Constraints:

    n == nums.length
    1 <= n <= 3 * 104
    -3 * 104 <= nums[i] <= 3 * 104


*/

/*
Method1: Brute force, for every i, check all sums, O(n*n)
Method2: Find the max's, start with left & right pointers around
Method3: Kadane's Algorithm, O(n)+linear space
    At every index, from the previous max local sum, add its value is sum is positive
        Pick the best of new sum and the index , say maxSum
    Do same to get minSum
    
    Circular 
        Circular Max Sum = total Sum - minSum
        Normal Max Sum = totalSum - maxSum
        if(circular Max Sum == total Sum)   return maxSum
        otherwise-
        return(max(maxSum,CircularSum))
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxLocalSum=0, minLocalSum=0, i=0,len1=nums.size(),totalSum=0;
        int resultMax=0,resultMin=0;
        bool print=false;
        vector<int> used(len1,0);
        if(len1==0) return 0;
        minLocalSum=nums[i];maxLocalSum=nums[i];
        resultMax=nums[i];resultMin=nums[i];
        totalSum=nums[i];
        for(int i=1;i<len1;i++)
        {
            totalSum+=nums[i];
            maxLocalSum=max(maxLocalSum+nums[i],nums[i]);
            resultMax=max(maxLocalSum,resultMax);
            minLocalSum=min(minLocalSum+nums[i],nums[i]);
            resultMin=min(minLocalSum,resultMin);
        }
        if(print)   cout<<"resultMax:"<<resultMax<<"resultMin:"<<resultMin<<endl;
        if(print)   cout<<"maxLocalSum:"<<maxLocalSum<<"minLocalSum:"<<minLocalSum<<endl;

        int circularSumMax = totalSum-resultMin;

        if(resultMin==totalSum) return resultMax;

        return max(resultMax,circularSumMax);
    }
};