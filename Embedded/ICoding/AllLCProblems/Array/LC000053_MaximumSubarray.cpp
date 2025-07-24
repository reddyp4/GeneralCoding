/*
53. Maximum Subarray
Solved
Medium
Topics
conpanies iconCompanies

Given an integer array nums, find the

with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
/*
Bruteforce:
    For every i, keep checking all subarrays, and store the maxsum-On2
    Breaks for 204 out of 211 cases
Optimize with cumulative sum:
    compute cum-sum, 
    if cum-sum<nums[i], we can start with nums[i] as new cumsum
    pick max of (cum-sum, nums[i],maxsum)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /* Bruteforce - fails for 204 case out of 211 cases */
        /*int i,j,len1=nums.size(),maxsum=INT_MIN,sum=0;
        for(i=0;i<len1;i++) {
            sum=0;
            for(j=i;j<len1;j++) {
                sum+=nums[j];
                maxsum=(maxsum>sum)?maxsum:sum;
            }
        }
        return maxsum;*/
        /* Is max cum sum, the pivot and just check there? */
        int i,j,len1=nums.size(),maxsum=INT_MIN,maxi=-1,sum=0;
        for(i=0;i<len1;i++) {
            sum+=nums[i];
            if(nums[i]>=sum)    sum=nums[i];
            maxsum=max(maxsum,max(sum,nums[i]));
            //cout<<"i:"<<i<<",nums[i]:"<<nums[i]<<",sum:"<<sum<<",maxsum:"<<maxsum<<endl;
        }
        sum=0;
        for(i=len1-1;i>=0;i--) {
            sum+=nums[i];
            if(nums[i]>=sum)    sum=nums[i];
            maxsum=max(maxsum,max(sum,nums[i]));
            //cout<<"i:"<<i<<",nums[i]:"<<nums[i]<<",sum:"<<sum<<",maxsum:"<<maxsum<<endl;
        }
        return maxsum;
    }
};
/*
Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
71.88MB
Beats16.75%
*/