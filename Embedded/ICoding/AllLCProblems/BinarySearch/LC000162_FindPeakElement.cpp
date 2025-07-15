/*
162. Find Peak Element
Solved
Medium
Topics
conpanies iconCompanies

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

 

Constraints:

    1 <= nums.length <= 1000
    -231 <= nums[i] <= 231 - 1
    nums[i] != nums[i + 1] for all valid i.


*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len1=nums.size();
        /* O(n) solution */
        /*
        for(int i=1;i<len1-1;i++)
        {
            if((nums[i]>nums[i-1]) && (nums[i]>nums[i+1]))  return i;
        }*/
        /* log(n) - binary search */
        /* sort, criteria being greater than elements - order: Nlogn
            and doesnt satisfy log(n) */
        /* log(n) = binary search? */
        /* Go to mid, if peak, output 
            if not, either left or right - which one to pick? 
            Go to one, which is bigger? */
        /*  Idea: Lets say l=mid, r=midp1 (mid+1)
                if mid>midp1, go left
                if mid<midp1, go right
                do until l==r
        */
        return search(nums,0,len1-1);
    }
private:
    int search(vector<int>&nums,int l,int r)    {
        if(l==r)    return l;
        int mid=(l+r)/2;
        if(nums[mid]>nums[mid+1])   return search(nums,l,mid);
        else return search(nums,mid+1,r);
    }
};

/*
Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
12.57MB
Beats31.81%
*/