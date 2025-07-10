/*
2387. Median of a Row Wise Sorted Matrix
Solved
Medium
Topics
conpanies icon
Companies
Hint
Given an m x n matrix grid containing an odd number of integers where each row is sorted in non-decreasing order, return the median of the matrix.

You must solve the problem in less than O(m * n) time complexity.

 

Example 1:

Input: grid = [[1,1,2],[2,3,3],[1,3,4]]
Output: 2
Explanation: The elements of the matrix in sorted order are 1,1,1,2,2,3,3,3,4. The median is 2.
Example 2:

Input: grid = [[1,1,3,3,4]]
Output: 3
Explanation: The elements of the matrix in sorted order are 1,1,3,3,4. The median is 3.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
m and n are both odd.
1 <= grid[i][j] <= 106
grid[i] is sorted in non-decreasing order.
*/
/*
Median: Mid-point of all values
M1: Maintain a vector of elements, add
    Sort
    Get mid-point
    doesnt use the sortness of each row!
*/
class Solution {
public:
    int matrixMedian(vector<vector<int>>& grid) {
        vector<int> vec;
        int i,j,median;
        for(i=0;i<grid.size();i++)
            for(j=0;j<grid[0].size();j++)
                vec.push_back(grid[i][j]);
        sort(vec.begin(),vec.end());
        int len1=vec.size();
        if(len1%2==0)   median=(vec[len1/2]+vec[len1/2+1])/2;
        else    median=vec[len1/2];
        return median;
    }
};