'''
70. Climbing Stairs
Solved
Easy
Topics
Companies
Hint
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        #DP: Full array
        '''
        dp={1:1,2:2}
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]
        return dp[n]
        '''
        #DP:Only last two values
        dp1,dp2=2,1
        if(n==1):
            return dp2
        if(n==2):
            return dp1
        for i in range(3,n+1):
            dpi=dp1+dp2
            dp2=dp1
            dp1=dpi
        return dpi