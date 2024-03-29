'''
64. Minimum Path Sum
Solved
Medium
Topics
Companies
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
'''

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        rows,cols=len(grid),len(grid[0])
        if(rows==1 and cols==1):
            return grid[0][0]
        dp=[[0]*cols for i in range(rows)]
        dp[0][0]=grid[0][0]
        for i in range(1,cols):
            dp[0][i]=dp[0][i-1]+grid[0][i]
        for i in range(1,rows):
            dp[i][0]=dp[i-1][0]+grid[i][0]
        for i in range(1,rows):
            for j in range(1,cols):
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]
        return dp[rows-1][cols-1]

'''
Classical DP: 
Diff equation: 
'''