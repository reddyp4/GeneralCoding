/*
347. Top K Frequent Elements
Attempted
Medium
Topics
conpanies icon
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
/*
M1: Count occurences, add to vector?
But Top-k, sort by occurences in vec
*/

class Solution {
public:
    vector<int> sortMap(map<int,int> &myMap, int k)    {
        vector<pair<int,int>> vec;
        vector<int> result;
        for(auto &key:myMap) vec.push_back(key);
        //sort vector as per value
        sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){return a.second>b.second;});
        //update map
        for(int i=0;i<k;i++)
        {
            //sorted vector of pairs
            //cout<<"key:"<<vec[i].first<<",value:"<<vec[i].second<<endl;
            result.push_back(vec[i].first);
        }
        return result;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> vec;
        stack<int> myStk;
        map<int,int> myMap;
        map<int,bool> seen;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(myMap.count(nums[i])>0)  myMap[nums[i]]++;
            else    myMap[nums[i]]=1;
        }
        /* sort map based on value */
        result = sortMap(myMap,k);
        /* Are maps sorted by key? Yes! However inverse may have multiple keys with same value! */
        return result;
    }
};