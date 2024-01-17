'''
50. Pow(x, n)
Medium
Topics
Companies
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
n is an integer.
Either x is not zero or n > 0.
-104 <= xn <= 104
'''
class Solution:
    def recursive(self,x,n):
        if(n==0):
            return 1
        if(n==1):
            return x
        val=self.recursive(x,int(n/2))
        if(n%2==0):
            return val*val
        else:
            return val*val*x

    def myPow(self, x: float, n: int) -> float:
        #Use recursion, by going to n/2 etc, until reaching 1
        if(n>0):
            result=self.recursive(x,n)
        else:
            result=self.recursive(1/x,-n)
        return result

'''
Use a binary tree approach, x^n=(x^(n/2))*(x^(n/2))

'''