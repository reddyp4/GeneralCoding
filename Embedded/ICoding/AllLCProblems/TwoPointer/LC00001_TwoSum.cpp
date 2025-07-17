/*
1. Two Sum
Solved
Easy
Topics
conpanies iconCompanies
Hint

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
/*
M1: for i, check if i+j=nums, order of n^2
M2: Sort, left+right ptr, store one index in a map
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* M1 *//*
        int i,j,len1=nums.size();
        vector<int> result;
        for(i=0;i<len1;i++)
            for(j=i+1;j<len1;j++)
                if(nums[i]+nums[j]==target) {
                    result.push_back(i);result.push_back(j);
                    return(result);
                }
        return result;*/
        /* M2 */
        int i,j;
        vector<int> result;
        map<int,vector<int>> myMap;
        for(i=0;i<nums.size();i++)  myMap[nums[i]].push_back(i);
        sort(nums.begin(),nums.end());
        i=0;j=nums.size()-1;
        while(i!=j) {
            if(nums[i]+nums[j]==target) {
                if(nums[i]==nums[j])    {
                    result.push_back(myMap[nums[i]][0]);result.push_back(myMap[nums[i]][1]);
                }
                else    {
                    result.push_back(myMap[nums[i]][0]);result.push_back(myMap[nums[j]][0]);
                }                
                return result;
            }
            if(nums[i]+nums[j]<target)  i++;
            else    j--;
        }
        return result;
    }
};

/*
M1
Runtime
59ms
Beats18.07%
Analyze Complexity
Memory
14.10MB
Beats64.06%


M2
Runtime
14ms
Beats41.19%
Analyze Complexity
Memory
18.36MB
Beats6.84%
*/