/*
3643. Flip Square Submatrix Vertically
Solved
Easy
Topics
Hint
You are given an m x n integer matrix grid, and three integers x, y, and k.

The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

Your task is to flip the submatrix by reversing the order of its rows vertically.

Return the updated matrix.

 

Example 1:


Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3

Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]

Explanation:

The diagram above shows the grid before and after the transformation.

Example 2:

​​​​​​​
Input: grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2

Output: [[3,4,4,2],[2,3,2,3]]

Explanation:

The diagram above shows the grid before and after the transformation.

 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 100
0 <= x < m
0 <= y < n
1 <= k <= min(m - x, n - y)
*/
/*
row: from x to x+k-1
    v1 = i
    v2 = i+k-1
col: from y to y+k-1
*/
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int i,j,temp,Y=grid[0].size(),X=grid.size();
        int v1,v2;
        bool print=false;
        if(print)   cout<<"X:"<<X<<",Y:"<<Y<<endl;
        //i=row, j=col
        for(j=y;j<y+k;j++) {
            for(i=0;i<k/2;i++)  {
            //for(i=x;i<x+k/2;i++)    {
                v1=x+i;
                v2=(x+k-1)-i;
                if(print) cout<<"v1:"<<v1<<",v2:"<<v2<<",j:"<<j<<endl;
                if(print) cout<<"value1:"<<grid[v1][j]<<",value2:"<<grid[v2][j]<<endl;
                temp=grid[v1][j];
                grid[v1][j]=grid[v2][j];
                grid[v2][j]=temp;
            }
        }
        return grid;
    }
};

/*
Runtime
4
ms
Beats
17.80%
Analyze Complexity
Memory
33.90
MB
Beats
35.57%
*/