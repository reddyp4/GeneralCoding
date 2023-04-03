'''
204. Count Primes
Medium
6.6K
1.3K
company
Capital One
company
Amazon
company
TikTok
Given an integer n, return the number of prime numbers that are strictly less than n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106

'''

class Solution:
    def countPrimes(self, n: int) -> int:
        #sieve of Eratosthenes
        #array for composites, from 0 to n
        #instead of int array, use enum
        #ans = [0]*(n+1)
        ans = [False, False] + [True] * (n-2)
        #initialize primes
        #primes = 0
        # go for each number
        for index in range(2,int(sqrt(n))+1):
            ''' Do sum instead
            if(ans[index]==0):
                primes+=1
            '''
            #assign all multiples to 0
            m=2
            # while loop is slow, replace by for loop
            '''
            while(index*m<=n):
                ans[index*m]=1
                m+=1
            '''
            for multiple in range(index*index, n, index):
                ans[multiple] = False
        return sum(ans)