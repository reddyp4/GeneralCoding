'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
'''

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        #Method1: Bruteforce, find every profit, and get the maximum. O(n2)
        #Method2: Two pointer approach? left get the increasing order, works except case 200
        '''
        # right, checks the max, and left moves to next increasing
        left, right, length, maxval =0, 0, len(prices)-1, 0
        while (left<=length-1):
            currentval = prices[left]
            # Check max of rest of list-currentval, if max > 0, then stock increase possible
            tempmax = max(prices[left+1:])-currentval
            if tempmax > maxval:
                maxval = tempmax
            left = left + 1
        return(maxval)
        '''
        #Single Pass Solution, to go global min on left and search for global max on right
        newMin, newMax, maxval = 100000,0,0
        index, length =0, len(prices)-1
        while(index<=length):
            #globalMin found, reset globalMax
            if(prices[index]<newMin):
                newMin = prices[index]
            #Not globalMin, check value and update maxval if needed
            if(prices[index]-newMin>maxval):
                maxval = prices[index] - newMin
            #in between globalMin and globalMax, do not do anything
            index = index + 1
        return maxval

        newMin, newMax, maxGain = 10**5, 0, 0
        for index,stock in enumerate(prices):
            if(stock<newMin):
                newMin=stock
                newMax=0
            if(stock>newMax):
                newMax=stock-newMin
                if(newMax>maxGain):
                    maxGain=newMax
        return maxGain
'''
Method1: Brute-force, O(n2)

Method2: Single pass, check global min, T:O(n),S:0(1)

Revised version with global, local
'''