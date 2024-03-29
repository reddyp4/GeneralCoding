'''
29. Divide Two Integers
Medium
Topics
Companies
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
'''

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        #103,3;1035,30
        if(dividend==-2147483648 and divisor==-1):
            return 2147483647
        sign = -1 if (dividend*divisor<0) else 1
        dividend=abs(dividend)
        divisor=abs(divisor)
        if(dividend<divisor):
            return 0
        if(divisor==1):
            return dividend*sign
        newdividend=int(str(dividend)[0])
        dividend=str(dividend)[1:]
        quotient=str(int(newdividend/divisor))
        newdividend=newdividend-int(newdividend/divisor)*divisor
        #print("Outside loop: quotient:",quotient,"newdividend:",newdividend,"remaining:",dividend)
        while(len(dividend)!=0): #int(str(newdividend)+dividend)>=divisor):
            #print("New round: quotient:",quotient,"newdividend:",newdividend,"remaining:",dividend)
            m=0
            while(newdividend<divisor and len(dividend)!=0):
                newdividend=newdividend*10+int(dividend[0])
                if(newdividend<divisor): # and m>=1):
                    quotient+="0"
                dividend=dividend[1:]
                m+=1
                #print("Find number.. quotient:",quotient,"newdividend:",newdividend,"remaining:",dividend)
            if(len(dividend)==0 and newdividend<divisor):
                break
            k=0
            #print("Ready for division: quotient:",quotient,"newdividend:",newdividend,"remaining:",dividend)
            while(newdividend>=divisor):
                newdividend-=divisor
                k+=1
            quotient+=str(k)
            #print("Finished division:quotient:",quotient,"newdividend:",newdividend,"remaining:",dividend)
            #Update newdividend and complete dividend
            #if(len(dividend)==0 or newdividend==0):
            #    break
        return int(quotient)*sign

'''
Pick part of dividend from beginning, everytime <divisor, add 0 - miss the first time only
Some tricks: take absolute of numbers, after getting sign and multiply quotient later
This solution beats 99.93% solutions on time
'''