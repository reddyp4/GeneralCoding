'''
43. Multiply Strings
Medium
6.8K
3.2K
Two Sigma
company
Facebook
company
Amazon
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

 

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
 

Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
'''

class Solution:
    def addString(self,total,prod):
        if(total==""):
            return prod
        len1,len2=len(total),len(prod)
        sum1,carry,newtotal=0,0,""
        #print("total:",total,"prod:",prod)
        for i in range(min(len1,len2)):
            sum1=int(total[i])+int(prod[i])+carry
            newtotal=newtotal+str(sum1%10)
            carry=int(sum1/10)
        if(len1<len2):
            for i in range(len1,len2):
                sum1=int(prod[i])+carry
                newtotal=newtotal+str(sum1%10)
                carry=int(sum1/10)
        else:
            for i in range(len2,len1):
                sum1=int(total[i])+carry
                newtotal=newtotal+str(sum1%10)
                carry=int(sum1/10)
        if(carry):
            newtotal=newtotal+str(carry)
        return newtotal
    
    def multiply(self, num1: str, num2: str) -> str:
        if(num1=="0" or num2=="0"):
            return "0"
        num1=num1[::-1]
        num2=num2[::-1]
        prod=""
        carry,total,zero=0,"",""
        len1,len2=len(num1),len(num2)
        minlen=min(len1,len2)
        maxnum=num1 if (len1>len2) else num2
        for c1 in num1:
            prod=""
            carry=0
            n1=int(c1)
            for c2 in num2:
                n2=int(c2)
                prodnum=n1*n2+carry
                prod=prod+str(prodnum%10)
                carry=int(prodnum/10)
                #print("n1:",n1,"n2:",n2,"prodnum:",prodnum,"carry:",carry,"prod:",prod)
            if(carry):
                prod=prod+str(carry)
            carry=0
            if(index!=1):
                zero=zero+"0"
            prod=zero+prod
            #print("total:",total,"prod:",prod)
            total=self.addString(total,prod)
            #print("After addition: total:",total,"prod:",prod)
        if(carry):
            total=total+"1"
        #print("total:",total,"prod:",prod)
        total=total[1:]
        return total[::-1]

'''
Write a function to add strings
Tricky: "0"
'''
