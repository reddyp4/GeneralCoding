'''
1952. Three Divisors
Easy
405
20
company
Microsoft
Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

 

Example 1:

Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.
Example 2:

Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.
 

Constraints:

1 <= n <= 104
'''

class Solution:
    def isThree(self, n: int) -> bool:
        #M1: Brute-force, check from 1 to n/2
        #M2: N is square of a prime number, check square root and check if square root is a prime
        #M3: Store prime list, check if sqrt(n) is in list
        primes = [2,3,4,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97]
        if((sqrt(n)) in primes):
            return True
        return False