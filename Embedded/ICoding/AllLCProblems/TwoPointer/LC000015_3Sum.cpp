/*
15. 3Sum
Attempted
Medium
Topics
conpanies iconCompanies
Hint

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

 

Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105


*/

/*
M1: Bruteforce - Similar to 2sum, for i,j,k, for every i,j
        Sort and push into set
        Unravel set into vector
        WOrks for 307 cases out of 314, 308 time limit exceeded
M2: Map of indices (to allow for duplicates) like 0,0,0, or -1,-1,2
    For i,j, check if -(i+j) exists in map
    for i,j, target sum is -(i+j) 
M3: Sorting
        Map vector
        Sort vector
        Pick i,j, search -(i+j) using binary search
How to ensure no duplicates of vector? Set
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i,j,k,index,ij,len1=nums.size();
        set<vector<int>> mySet;
        map<int,vector<int>> myMap; //Map of all values to indices
        map<int,int> found; //Map of just nums[i],nums[j] (i<=j), eliminate searching in set
        bool print=false,zeroes=false;
        for(i=0;i<len1;i++)  myMap[nums[i]].push_back(i);
        for(i=0;i<len1;i++)
            for(j=i+1;j<len1;j++)
            {
                ij = -nums[i]-nums[j];
                /* Corner case of all zeroes */
                if(nums[i]==nums[j] && nums[i]==0 && !zeroes && myMap.count(ij)>0 && myMap[ij].size()>=3)    {
                    if(print)   cout<<"zeroes!"<<endl;
                    vector<int> vec;
                    vec.push_back(0);vec.push_back(0);vec.push_back(0);
                    mySet.insert(vec);
                    zeroes=true;
                }
                if(nums[i]!=nums[j] && myMap.count(ij)>0) {
                    //Check if already in set
                    vector<int> vec;
                    vec.push_back(nums[i]);vec.push_back(nums[j]);vec.push_back(ij);
                    sort(vec.begin(),vec.end());
                    if(mySet.find(vec)!=mySet.end());   //already in set
                    else    {
                        //in map and check if not already counted
                        k=myMap[ij].size();index=0;
                        while(index<k && (myMap[ij][index]==i || myMap[ij][index]==j)) index++;
                        if(index!=k)
                        {
                            if(print)   cout<<"i:"<<i<<",j:"<<j;
                            if(print)   cout<<",[i]:"<<nums[i]<<",[j]:"<<nums[j]<<",ij:"<<ij<<endl;
                            vector<int> triplet;
                            triplet.push_back(nums[i]);
                            triplet.push_back(nums[j]);
                            triplet.push_back(ij);
                            sort(triplet.begin(),triplet.end());
                            mySet.insert(triplet);
                        }
                    }
                }
            }
        /* Convert set into vector */
        vector<vector<int>> result;
        vector<int> vec1;
        for(const auto &vec1:mySet) result.push_back(vec1);
        return result;
    }
};
/*
Runtime
2867ms
Beats5.00%
Analyze Complexity
Memory
507.78MB
Beats5.04%
*/