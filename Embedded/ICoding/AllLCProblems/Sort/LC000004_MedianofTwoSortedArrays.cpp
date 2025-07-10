/*
4. Median of Two Sorted Arrays
Solved
Hard
Topics
conpanies icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int i,j;
        double median;
        for(i=0;i<nums1.size();i++)
            vec.push_back(nums1[i]);
        for(i=0;i<nums2.size();i++)
            vec.push_back(nums2[i]);
        sort(vec.begin(),vec.end());
        int len1=vec.size();
        //cout<<len1<<","<<vec[len1/2-1]<<","<<vec[len1/2]<<endl;
        if(len1%2==0)   median=(vec[len1/2-1]+vec[len1/2])/2.0;
        else    median=vec[len1/2];
        return median;
    }
};
/*
Runtime
4
ms
Beats
21.32%
Analyze Complexity
Memory
95.83
MB
Beats
25.04%
*/