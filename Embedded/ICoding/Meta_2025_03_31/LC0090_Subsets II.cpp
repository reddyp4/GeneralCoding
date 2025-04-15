/*
90. Subsets II
Solved
Medium
Topics
Companies
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

#include<unordered_set>
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result;
        vector<vector<int>> result1;
        int len1=nums.size();
        for(int i=0;i<pow(2,len1);i++)
        {
            vector<int> temp;
            for(int k=0;k<len1;k++)
            {
                if((1<<k)&(i))  temp.push_back(nums[k]);
            }
            std::sort(temp.begin(),temp.end());
            result.insert(temp);
        }
        for(vector v:result)    result1.push_back(v);
        return result1;
    }
};

/*
Runtime
3
ms
Beats
40.30%

Memory
11.08
MB
Beats
31.45%
*/