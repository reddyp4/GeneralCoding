/*
215. Kth Largest Element in an Array
Attempted
Medium
Topics
conpanies icon
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
*/

/*
Method1: With sorting
    Update map
    Sort map
    Keep adding until k
Method2: Without sorting
Can we do two stacks of size of k, and seen[key]
*/
/*
Method1: With sorting
    Update map
    Sort map
    Keep adding until k
Method2: Without sorting
Can we do two stacks of size of k, and seen[key]
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* Method1: Make map, make vector, sort vector */
        map<int,int,greater<int>> myMap;
        int i=0,j=0;
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++)
        {
            if(myMap.count(nums[i])>0)  myMap[nums[i]]++;
            else myMap[nums[i]]=1;
        }
        for(auto &key:myMap)    vec.push_back(key);
        //sort(vec.begin(),vec.end(),[](pair<int,int>&a,pair<int,int>&b){return(a.second<b.second);});
        //for(i=0;i<vec.size();i++)   cout<<"Key:"<<vec[i].first<<",value:"<<vec[i].second<<endl;
        i=0;
        //cout<<"i:"<<i<<",k:"<<k<<endl;
        while(i<k)  {
            i+=vec[j++].second;
            //cout<<"i:"<<i<<endl;
            }
        //if(i>nums.size())  return vec[j-1].first;
        return vec[j-1].first;
    }
};

/*
Runtime
114
ms
Beats
6.00%
Analyze Complexity
Memory
74.16
MB
Beats
8.98%
*/