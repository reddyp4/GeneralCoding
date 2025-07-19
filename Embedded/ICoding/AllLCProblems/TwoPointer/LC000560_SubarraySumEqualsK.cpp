/*
560. Subarray Sum Equals K
Solved
Medium
Topics
conpanies iconCompanies
Hint

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

 

Constraints:

    1 <= nums.length <= 2 * 104
    -1000 <= nums[i] <= 1000
    -107 <= k <= 107


*/
/*
Bruteforce: for every i, move j until sum is achieved
    Optimize? 
        ? Maintain sum upto index i? sumj-sumi = sum of all elements between i and j
            At index, check [sum-to-end]-index is equal to k, if yes we have an array
        ? Sort? May not help, since numbers are random
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i,j,len1=nums.size(),sum=0,res=0;
        for(i=0;i<len1;i++) {
            sum=nums[i];
            if(sum==k)  res++;
            for(j=i+1;j<len1;j++)   {
                sum+=nums[j];
                if(sum==k)  {
                    res++;
                }
            }
        }
        return res;
    }
};

/*
Runtime
1411ms
Beats22.65%
Analyze Complexity
Memory
34.30MB
Beats93.79%
*/