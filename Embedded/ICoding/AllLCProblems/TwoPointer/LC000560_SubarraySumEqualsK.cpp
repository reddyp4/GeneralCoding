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
            Check for every combination
        ? Sort? May not help, since numbers are random
HashMap Solution Using Cumulative Sum = sum = sum of all elements upto and including nums[i]
    if(sum[i]==0)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*int i,j,len1=nums.size(),sum=0,res=0;
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
        return res;*/
        /* Hashmap solution */
        unordered_map<int,int> myMap;
        int i,j,res=0,len1=nums.size(),sum=0;
        /* loop, get sum, update sum[k], check if sum-k=0, & key exists update count */
        myMap[0]=1;
        for(i=0;i<len1;i++) {
            sum+=nums[i];
            if(myMap.count(sum-k)>0)  {
                //Already exists
                res+=myMap[sum-k];
                //cout<<nums[i]<<":"<<res<<endl;
            }
            if(myMap.count(sum)>0)  myMap[sum]++;
            else    myMap[sum]=1;
        }
        return res;
    }
};

/* i,j solution
Runtime
1411ms
Beats22.65%
Analyze Complexity
Memory
34.30MB
Beats93.79%

Runtime
39ms
Beats78.18%
Analyze Complexity
Memory
45.44MB
Beats57.15%

*/