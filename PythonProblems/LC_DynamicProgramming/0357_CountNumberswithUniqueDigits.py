'''
357. Count Numbers with Unique Digits
Solved
Medium
Topics
Companies
Hint
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
Example 2:

Input: n = 0
Output: 1
 

Constraints:

0 <= n <= 8
'''
import math

class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        #dp
        dp=[1,10]
        if(n<=1):
            return dp[n]
        for i in range(2,n+1):
            dp.append((10-i+1)*dp[i-1]+sum(dp[:i-2+1]))
            #print("dp:",dp)
        return dp[-1]

'''
dp[i]=(10-i+1)*dp[i-1]+sum(dp[:i-2+1])
ex: for 3, dp3 = 8*dp2+dp1+dp0

'''