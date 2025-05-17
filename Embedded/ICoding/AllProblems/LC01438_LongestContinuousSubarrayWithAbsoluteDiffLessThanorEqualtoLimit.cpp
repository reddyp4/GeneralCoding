/*
1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
Attempted
Medium
Topics
Companies
Hint
Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:

Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.
Example 2:

Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
Example 3:

Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= limit <= 109
*/

/*
Method1: Brute Force: at every index=left, move right until number over limit = O(n*n)
Method2: sliding window keeping maximum and minimum value indices
    
*/

/*
Method1: Brute Force: at every index=left, move right until number over limit = O(n*n)
Method2: sliding window keeping maximum and minimum value indices
    
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if(nums.size()==0)  return 0;
        if(nums.size()==1)  return 1;
        int minIndex=0,maxIndex=0,left=0,right=0,longest=0,len2=0,len1=nums.size();
        bool print=true;
        //first element, get window, keep tab of minIndex, maxIndex
        while(right<len1 && abs(nums[left]-nums[right])<=limit && abs(nums[minIndex]-nums[maxIndex])<=limit)
        {
            //find minIndex and maxIndex
            minIndex=(nums[minIndex]<=nums[right])?minIndex:right;
            maxIndex=(nums[maxIndex]>=nums[right])?maxIndex:right;
            right++;
            longest=max(longest,right-left);
        }
        if(print)   cout<<"1:left:"<<left<<",right:"<<right<<",minIndex:"<<minIndex<<",maxIndex:"<<maxIndex<<endl;
        //drop left most, check if this minIndex or maxIndex, if yes, recalculate
        left+=1;
        //if not, keep moving right
        while(left<len1 && right<len1)
        {
            //reset the sliding window, recalculate minIndex & maxIndex
            minIndex=left;maxIndex=left;
            right=left+1;
            //keep moving right
            while(right<len1 && abs(nums[left]-nums[right])<=limit && abs(nums[minIndex]-nums[maxIndex])<=limit)
            {
                //find minIndex and maxIndex
                minIndex=(nums[minIndex]<=nums[right])?minIndex:right;
                maxIndex=(nums[maxIndex]>=nums[right])?maxIndex:right;
                right++;
            }
            if(print)   cout<<"End:left:"<<left<<",right:"<<right<<",minIndex:"<<minIndex<<",maxIndex:"<<maxIndex<<endl;
            //update longest
            if(right==len1) longest=max(longest,right-left);
            else if(abs(nums[left]-nums[right])>limit)  longest=max(longest,right-left);
            else    longest=max(longest,right-left-1);
            //drop left
            left++;
        }
        if(print)   cout<<"End:left:"<<left<<",right:"<<right<<",minIndex:"<<minIndex<<",maxIndex:"<<maxIndex<<endl;
        return longest;
    }
};