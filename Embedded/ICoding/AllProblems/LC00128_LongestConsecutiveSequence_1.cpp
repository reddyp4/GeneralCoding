/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

//Method1: Create index hashmap, sort, check consecutivness, return difference of indices
//Corner case: empty matrix, getting 10^9 at end 

#include<cmath>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxIndex=0,len1=nums.size()+1,print=0;
        if(len1==1) return 0;
        //insert arbitrary large number at end to avoid corner case
        nums.push_back(1e9+2);
        //create index hashmap
        map<int,int> myMap;
        for(int i=0;i<len1;i++) myMap[nums[i]]=i;
        //sort
        sort(nums.begin(),nums.end());
        if(print)
        {
            cout<<"Sorted:";
            for(int i=0;i<len1;i++) cout<<nums[i];
            cout<<endl;
        }
        //check consecutiveness
        int flag=0, i=0,index=0;
        while(i<len1)
        {
            //reset currentindex
            index=1;
            //start consecutive check
            while(i<(len1-1) && (nums[i+1]-nums[i])<2) 
            {
                if(print)   cout<<"i:"<<nums[i]<<"nums[i]:"<<nums[i]<<endl;
                if(nums[i+1]!=nums[i]) index++;
                i++;
            }
            //update maxindex
            maxIndex = (maxIndex>index)?maxIndex:index;
            if(print)   cout<<"maxIndex:"<<maxIndex<<",index:"<<index<<endl;
            i++;
        }
        //return difference of indices
        return maxIndex;
    }
};

/*
Runtime 168 ms
Beats 10.20%
Analyze Complexity
Memory
91.21 MB
Beats 11.67%
*/