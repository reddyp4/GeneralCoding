/*
448. Find All Numbers Disappeared in an Array
Solved
Easy
Topics
conpanies icon
Companies
Hint
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
 

Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/
/*
Bruteforce: Maintain hash and check
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,bool> myMap;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
            if(!(myMap.count(nums[i])>0))
                myMap[nums[i]]=true;
        for(int i=1;i<=nums.size();i++)
            if(!(myMap.count(i)>0))
                res.push_back(i);
        return res;
    }
};

/*
Runtime
44
ms
Beats
24.84%
Analyze Complexity
Memory
64.37
MB
Beats
17.06%
*/