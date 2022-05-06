''''
371. Sum of Two Integers
Given two integers a and b, return the sum of the two integers without using the operators + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000
'''

from ctypes import sizeof


class Solution:
    def printBit(self,num:int):
        s=f"Num={num}="
        for i in range(31,-1,-1):
            bit = (num&(0b1<<i))>>i
            s=s+str(bit)
        print(s)

    def twoComplement(self,num:int) -> int:
        num = pow(2,32)-num
        return num

    def getSum(self, a: int, b: int) -> int:
        #Get binary representations
        #already a,b
        #Get xor to see non-same bits
        #d = a^b
        #Get carryon
        #c = ((a&b)<<1)
        sum=0
        carryon=0
        newbit=0
        for i in range(1,33):
            bita = (a&(0x01)<<(i-1))>>(i-1)
            bitb = (b&(0x01)<<(i-1))>>(i-1)
            if(bita&bitb):
                #if-carryon=1, set new bit=1, carry-on=1
                #if-carryon=0, set new bit=0, carry-on=1
                if(carryon==0):
                    newbit=0
                else:
                    newbit=1
                carryon=1
            elif(bita|bitb):
                #only one bit is 1
                #if carryon=0,assign newbit to 1, carryon=0
                #if carryon=1,assign newbit to 0, carryon=1
                if(carryon==0):
                    newbit=1
                    carryon=0
                else:
                    newbit=0
                    carryon=1
            else:
                #if carryon=0, assign newbit to 0, carryon=0
                #if carryon=1, assign newbit to 1, carryon=0
                #no-carryon
                if(carryon==0):
                    newbit=0
                else:
                    newbit=1
                carryon = 0
            #assign newbit to sum
            #print(f"i={i},bita={bita},bitb={bitb},newbit={newbit},carryon={carryon}")
            sum = (sum|(newbit<<(i-1)))
        #Check 2's complement, if MSB==1, return 2's complement
        #if(sum&(0b01<<32)==1):
        if(((sum&(0b01<<31))>>31)==1):
            print("True")
            sum = -self.twoComplement(sum)
        print(sum)
        return sum

    def getSum2(self,x, y):
        #check complementary numbers
        # Iterate till there is no carry
        if((x+y)!=0):
            while (y != 0):
                # carry now contains common
                # set bits of x and y
                carry = x & y 
                # Sum of bits of x and y where at
                # least one of the bits is not set
                x = x ^ y
                # Carry is shifted by one so that  
                # adding it to x gives the required sum
                y = carry << 1
                print(y)
            return x
        else:
            return 0

#testcase1
#a=1
#b=3
#testcase2
a=-12
b=-8

a=-1
b=1

sol=Solution()
#Sum=sol.getSum(a,b)

Sum = sol.getSum2(a,b)

#sol.printBit(a)
#sol.printBit(b)
#sol.printBit(Sum)
print(f"a={a},b={b},sum={Sum},actualsum={a+b}")
#print(f"a={bin(a)},b={bin(b)},sum={bin(Sum)},actualsum={bin(a+b)}")
