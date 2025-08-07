/*
219. Contains Duplicate II
Solved
Easy
Topics
conpanies icon
Companies
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/
/*
Bruteforce
    For i, search i-k to i+k and see if numbers are same
Better
    Push all indices to map, if duplicate comes check index, 
        if more, keep new, discard old on
    if less, return true
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> myMap; //value-index
        int i=0,len1=nums.size();
        while(i<len1)   {
            if(myMap.count(nums[i]))    {
                //check index
                if((i-myMap[nums[i]])<=k)   return true;
                myMap[nums[i]]=i;
            }
            else    myMap[nums[i]]=i;
            i++;
        }
        return false;
    }
};

/*
Runtime
167
ms
Beats
12.84%
Analyze Complexity
Memory
102.43
MB
Beats
5.61%
*/