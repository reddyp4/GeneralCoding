'''
415. Add Strings
Easy
4.5K
661
company
Apple
company
Facebook
company
Adobe
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
 

Constraints:

1 <= num1.length, num2.length <= 104
num1 and num2 consist of only digits.
num1 and num2 don't have any leading zeros except for the zero itself.
'''
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        #M1: Compare each character and create new string. Beats space(41%), time(33%)
        ans = ""
        ai=len(num1)-1
        bi=len(num2)-1
        carry=0
        while((ai>=0) or (bi>=0) or carry):
            n1 = int(num1[ai]) if ai>=0 else 0
            n2 = int(num2[bi]) if bi>=0 else 0
            sum1=n1+n2+carry
            carry=int(sum1/10)
            sum1=sum1%10
            ans=str(sum1)+ans
            ai=ai-1
            bi=bi-1
        return(ans)
        