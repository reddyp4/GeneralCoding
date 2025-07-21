/*
1679. Max Number of K-Sum Pairs
Solved
Medium
Topics
conpanies icon
Companies
Hint
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

*/

/*
Bruteforce: For i, check j, and go on recursively, if result==0, add to list
Method1:
    Setup the hashmap of value, count
    Iterate through key, if k-key exists, increment, and continue
*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res=0,i,j,len1=nums.size();
        unordered_map<int,int> myMap;
        for(i=0;i<len1;i++) {
            if(myMap.count(nums[i])>0)  myMap[nums[i]]++;
            else myMap[nums[i]]=1;
        }
        for(auto &key:myMap)    {
            if(k==2*key.first)  {
                res+=(key.second/2);
                key.second=0;
            }
            else if(myMap.count(k-key.first)>0)   {
                res+=min(key.second,myMap[k-key.first]);
                myMap[k-key.first]=0;
                key.second=0;
            }
        }
        return res;
    }
};
/*
Runtime
104
ms
Beats
40.22%
Analyze Complexity
Memory
71.49
MB
Beats
36.79%
*/