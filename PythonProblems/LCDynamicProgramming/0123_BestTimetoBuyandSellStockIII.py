'''
123. Best Time to Buy and Sell Stock III
Hard
Topics
Companies
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
'''
class Solution:
    def recursive(self, prices, maxCount):
        #print("Entry prices:",prices,"maxCount:",maxCount)
        if(len(prices)==1 or len(prices)==0 or maxCount==2):
            #print("Reached end:",prices,":",maxCount)
            return 0    #this array does not have a gain anymore
        len1,maxGain=len(prices),0
        #now check for first element only
        for index,stock in enumerate(prices):
            #check for each element until count of two
            for k in range(index+1,len1):
                gain=0
                if(maxCount<2 and prices[k]>prices[index]):
                    gain+=prices[k]-prices[index]
                    #call recursive for next
                    gain+=self.recursive(prices[(k+1):],maxCount+1)
                    #print("prices:",prices,"prices[index]:",prices[index],"prices[k]:",prices[k],"gain:",gain)
                maxGain = maxGain if (maxGain>gain) else gain
        return maxGain~

    def maxProfit(self, prices: List[int]) -> int:
        #Use recursion baseline, every recursion checks next greater, and continues until count
        maxGain = self.recursive(prices,0)
        return maxGain

'''
Recursion works for 200/214 test sets
'''