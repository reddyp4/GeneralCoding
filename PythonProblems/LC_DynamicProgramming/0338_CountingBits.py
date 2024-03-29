'''
338. Counting Bits
Easy
8.6K
411
company
Goldman Sachs
company
Microsoft
company
Google
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
 

Follow up:

It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?
Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
'''
class Solution:
    def countBits(self, n: int) -> List[int]:
        #Method-1: One number at a time
        #Time: every element x hamming = n x log(n)
        #Space: two elements, O(1)
        '''
        ans1=list()
        for index in range(0,n+1):
            digits=0
            n=index
            while(n is not 0):
                digits+=1
                n=n&(n-1)
            ans1.append(digits)
        return ans1 '''

        #Method-2: DP+Most Significant Bit
        #Say 3->7, by adding 4 or 2^2 or one bit
        #Equation for x: P(x+b) = P(x)+1, b=2^m>x
        x=2
        b=1
        ans=[0]*(n+1)
        if(n==0):
            return ans
        ans[1]=1
        while(x<=n):
            #run loop for 2^b, 1 to 2^b-1
            m=0
            while(x<=n and m<=(pow(2,b)-1)):
                ans[x]=ans[x-pow(2,b)]+1
                x+=1
                m+=1
            b+=1
        return ans

        #Method-3: DP+Last Set Bit

        #Method-4: DP+Least Significant Bit