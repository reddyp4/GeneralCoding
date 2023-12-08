'''
122. Best Time to Buy and Sell Stock II
Medium
12.8K
2.6K
company
Microsoft
company
Amazon
company
Apple
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
'''
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #Method1: Bruteforce, buy at min/dip, sell at peaks until reversal
        index, currMin, nextPrice, currProfit, totalProfit,length = 0, prices[0], 0, 0, 0, len(prices)-1
        while(index<=length):
            #if length, assume the end of array at zero and do appropriately
            if(index==length):
                nextPrice = 0
            else:
                nextPrice = prices[index+1]
            #Check for rise
            if(prices[index]-currMin>currProfit):
                currProfit = prices[index]-currMin  #keep, update currProfit
            #check for drop, until length-1
            if(nextPrice<prices[index]):
                totalProfit = totalProfit + currProfit
                currMin = nextPrice
                currProfit = 0
            #check for peak and reversal
            index = index + 1
        return totalProfit

'''
Method1: Bruteforce

Method2: LC121 (Best time to buy stock) + check for reversals
'''