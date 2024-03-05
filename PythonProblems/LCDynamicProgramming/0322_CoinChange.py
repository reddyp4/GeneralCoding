'''
322. Coin Change
Solved
Medium
Topics
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
'''
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        #DP min path to target
        #Use dict to reduce space
        if(amount==0):
            return 0
        minCoin = min(coins)
        if(minCoin>amount):
            return -1
        dp={}
        len1=len(coins)
        for i in range(len1):
            if(amount==coins[i]):
                return 1
            dp[coins[i]]=1
        #now construct bottoms up
        for i in range(minCoin,1+amount):
            if(i not in dp):
                #excluded already counted singles
                minNumber=10**10
                #iterate through all coins
                for c in range(len1):
                    if((i-coins[c]) in dp):
                        minNumber = minNumber if (minNumber<(dp[i-coins[c]]+1)) else (dp[i-coins[c]]+1)
                if(minNumber!=10**10):
                    dp[i]=minNumber
        #print("dp:",dp)
        if(amount in dp):
            return dp[amount]
        return -1

'''
Use dp counting up
Use a dict to reduce space and only keep values made
corner cases, <minCoin, =coins[i]
'''