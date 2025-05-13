/*
73. Set Matrix Zeroes
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
Method: Check each element and set map to zero, iterate later
    Needs maps, and searching maps
Constant space approach: If zero, set it to 2, and later iterate the matrix and turn all 2's to zeroes
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i=0,j=0,print=0;
        int cols=matrix[0].size(),rows=matrix.size();
        map<int,int> myMapRow,myMapCol;
        if(print)   cout<<"rows:"<<rows<<",cols:"<<cols<<endl;
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                if(matrix[i][j]==0)
                {
                    //Brute force
                    if(myMapRow.find(i)==myMapRow.end())    myMapRow[i]=0;
                    if(myMapCol.find(j)==myMapCol.end())    myMapCol[j]=0;
                }
            }
        }
        //zero out now
        if(!myMapRow.empty())
            for(auto key:myMapRow)
            {
                for(j=0;j<cols;j++) matrix[key.first][j]=0;
            }
        if(!myMapCol.empty())
            for(auto key:myMapCol)
            {
                for(i=0;i<rows;i++) matrix[i][key.first]=0;
            }
        return;        
    }
};

/*
Method1
Runtime 0ms
Beats 100.00%
Analyze Complexity
Memory 19.01MB
Beats 6.62%
*/