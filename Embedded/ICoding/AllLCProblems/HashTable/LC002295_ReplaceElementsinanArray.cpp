/*
2295. Replace Elements in an Array
Solved
Medium
Topics
conpanies icon
Companies
Hint
You are given a 0-indexed array nums that consists of n distinct positive integers. Apply m operations to this array, where in the ith operation you replace the number operations[i][0] with operations[i][1].

It is guaranteed that in the ith operation:

operations[i][0] exists in nums.
operations[i][1] does not exist in nums.
Return the array obtained after applying all the operations.

 

Example 1:

Input: nums = [1,2,4,6], operations = [[1,3],[4,7],[6,1]]
Output: [3,2,7,1]
Explanation: We perform the following operations on nums:
- Replace the number 1 with 3. nums becomes [3,2,4,6].
- Replace the number 4 with 7. nums becomes [3,2,7,6].
- Replace the number 6 with 1. nums becomes [3,2,7,1].
We return the final array [3,2,7,1].
Example 2:

Input: nums = [1,2], operations = [[1,3],[2,1],[3,2]]
Output: [2,1]
Explanation: We perform the following operations to nums:
- Replace the number 1 with 3. nums becomes [3,2].
- Replace the number 2 with 1. nums becomes [3,1].
- Replace the number 3 with 2. nums becomes [2,1].
We return the array [2,1].
 

Constraints:

n == nums.length
m == operations.length
1 <= n, m <= 105
All the values of nums are distinct.
operations[i].length == 2
1 <= nums[i], operations[i][0], operations[i][1] <= 106
operations[i][0] will exist in nums when applying the ith operation.
operations[i][1] will not exist in nums when applying the ith operation.
*/
/*
Bruteforce
    Every nums[i], keep replacing while in operations?
    How to know if in operations? Hashmap
    Trip: operations[i][1] must not exist in nums already! 
        Need hashmap of nums
*/
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> myOperMap;
        unordered_map<int,int> myNumsMap;
        int i=0,m=1,len1=nums.size(),index;
        for(i=0;i<operations.size();i++)    myOperMap[operations[i][0]]=operations[i][1];
        for(i=0;i<nums.size();i++)  myNumsMap[nums[i]]=i;
        i=0;
        while(i<operations.size())  {
            if(myNumsMap.count(operations[i][0])>0) {
                index=myNumsMap[operations[i][0]];
                //cout<<"nums[i]:"<<nums[i]<<"->"<<myOperMap[nums[i]]<<endl;
                myNumsMap.erase(operations[i][0]);
                nums[index]=operations[i][1];
                myNumsMap[nums[index]]=index;
            }
            i++;
        }
        return nums;
    }
};
/*
Runtime
161
ms
Beats
18.06%
Analyze Complexity
Memory
146.81
MB
Beats
14.45%
*/