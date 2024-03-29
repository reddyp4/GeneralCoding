'''
372. Super Pow
Attempted
Medium
Topics
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

 

Example 1:

Input: a = 2, b = [3]
Output: 8
Example 2:

Input: a = 2, b = [1,0]
Output: 1024
Example 3:

Input: a = 1, b = [4,3,3,8,5,2]
Output: 1
 

Constraints:

1 <= a <= 231 - 1
1 <= b.length <= 2000
0 <= b[i] <= 9
b does not contain leading zeros.
'''
class Solution:
    def powNum(self,a,b):
        #print("a1:",a,"b1:",b)
        #b is number
        if(b==0):
            return 1
        if(b==1):
            return a
        result=self.powNum(a,int(b/2))%1337
        if(b%2==0):
            result=(result*result)%1337
        else:
            result=(result*result*a)%1337
        #print("a1:",a,"b1:",b,"result:",result)
        return result

    def pow(self,a,b):
        #Call recursively for a^(b/10)*a check mod and multiply
        #print("a:",a,"b:",b)
        result=1
        if(len(b)==1):
            result=self.powNum(a%1337,b[0])
        else:
            blen=len(b)
            newa=self.pow(a,b[:blen-1])%1337
            result=self.powNum(newa,10)
            result=(result*self.powNum(a,b[-1]))%1337
        return result
        
    def superPow(self, a: int, b: List[int]) -> int:
        #if a=(1337*k), then answer is k^b mod 1337
        if(a==1):
            return a
        a=a%1337
        result=self.pow(a,b)
        return result
'''
Doing recursion is a bit space/time complexity: (123^456)%1337 = (((123^45)%1337)^10)%1337 * (123^6)%1337
'''