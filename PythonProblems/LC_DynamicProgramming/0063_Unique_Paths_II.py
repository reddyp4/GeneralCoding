'''
63. Unique Paths II
Solved
Medium
Topics
Companies
Hint
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
'''

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        #Similar to unique paths, [i][j]=[i-1][j]+[i][j-1], if both elements are not obstacles
        rows,cols=len(obstacleGrid),len(obstacleGrid[0])
        if(rows==1 and cols==1):
            return 1-obstacleGrid[0][0]
        if(obstacleGrid[0][0]==1):
            return 0
        dp=[[0]*cols for i in range(rows)]
        dp[0][0]=1
        #set the known values
        for i in range(1,cols):
            dp[0][i] = 1 if (dp[0][i-1]==1 and obstacleGrid[0][i]==0) else 0
        for i in range(1,rows):
            dp[i][0] = 1 if (dp[i-1][0]==1 and obstacleGrid[i][0]==0) else 0
        #now populate the dp matrix
        for i in range(1,rows):
            for j in range(1,cols):
                dp[i][j] = dp[i-1][j]+dp[i][j-1] if (obstacleGrid[i][j]==0) else 0
        return dp[rows-1][cols-1]

'''
Simpler DP: difference equation+check obstacle
Corner case: if first is obstacle or last is, then answer is 0
'''