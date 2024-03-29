'''
1922. Count Good Numbers
Solved
Medium
Topics
Companies
Hint
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015
'''

class Solution:
    prime = {"2","3","5","7"}
    size_prime = len(prime)
    even = {"0","2","4","6","8"}
    size_even = len(even)
    size_even_odd = size_prime*size_even
    mod1 = 10**9+7
    def pow(self,a,b):
        #f(4) = f_4 * f_3 * f_2 * f_1 = (f_even)^2 * (f_prime)^2
        #f_n = (f_even)^k1 * (f_prime)^k2, k1=k2=n/2, if n is even, else k1=k2+1 if n is odd
        #f_n = (f_even_odd)^k1 * f_even*(k1-k2)
        #this is a^b mod problem
        if(b==1):
            return a
        if(b==0):
            return 1
        result=(self.pow(a,int(b/2)))%self.mod1
        result=(result*result)%self.mod1
        if(b%2==0):
            return result
        else:
            return ((result*a)%self.mod1)

    def countGoodNumbers(self, n: int) -> int:
        k1=k2=int(n/2)
        if(n%2!=0):
            k1=k1+1
        ans1=(self.pow(self.size_even,k1))%self.mod1
        ans2=(self.pow(self.size_prime,k2))%self.mod1
        return int((ans1*ans2)%self.mod1)
        