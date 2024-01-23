'''
779. K-th Symbol in Grammar
Medium
Topics
Companies
Hint
We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
   0
  01
 0110
01101001 ... 
01101001+(10)+0110=0110 1001 1001 0110
01101001 10010110 10010110 01101001

f(n)=f(n-1)+(f(n-1)-complement)

0 to 01
1 to 10
01 to 0110
10 to 1001
0110 to 0110+1001
check sequence: 0110, replace, now 1001? 


Example 1:

Input: n = 1, k = 1
Output: 0
Explanation: row 1: 0
Example 2:

Input: n = 2, k = 1
Output: 0
Explanation: 
row 1: 0
row 2: 01
Example 3:

Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
 

Constraints:

1 <= n <= 30
1 <= k <= 2n - 1
'''

class Solution:
    d = {}
    def recursion(self, n, s):
        #print("n:",n,"s:",s)
        if(n==1):
            return s
        lens2,newstr,newstr2=int(len(s)/2),"",""
        if(s[:lens2] in self.d):
            newstr+=self.d[s[:lens2]]
        else:
            for c in s[:lens2]:
                if(c=="0"):
                    newstr+="01"
                else:
                    newstr+="10"
        self.d[s[:lens2]]=newstr
        #print("s1:",s[:lens2],"newstr:",newstr)
        if(s[lens2:] in self.d):
            newstr2+=self.d[s[lens2:]]
        else:
            for c in s[lens2:]:
                if(c=="0"):
                    newstr2+="01"
                else:
                    newstr2+="10"
        self.d[s[lens2:]]=newstr2
        #("s2:",s[lens2:],"newstr2:",newstr2)
        return self.recursion(n-1,newstr+newstr2)

    def kthGrammar(self, n: int, k: int) -> int:
        #need recursion? there is repeating elements
        self.d["0"]="01"
        self.d["1"]="10"
        s=self.recursion(n,"0")
        #print("s:",s)
        return int(s[k-1])
    
'''
    d = {}
    def complement(self,s):
        #complementary novel algorithm: do ~num&(ans), where ans=num&(num-1), until ans&(ans-1)!=0 or keep last known 1 bit
        #print("com s:",bin(s))
        if(s==0):
            return 1
        if(s==1):
            return 0
        ans=~s
        while(s&(s-1)!=0):
            s=s&(s-1)
        #print("ans:",bin(ans),"s-1:",bin(s-1),"com s2:",bin(ans&(s-1)))
        return ans&(s-1)

    def recursion(self, n):
        #print("n:",n)
        result=""
        if(n==1):
            return "0"
        #fn = fn-1 + fn-1-complement
        if(n in self.d):
            return self.d[n]
        else:
            result = self.recursion(n-1)
            self.d[n] = result
        compl = bin(self.complement(int(result,2)))
        compl = compl[2:]
        #print("compl:",compl)
        if(len(compl)<len(result)):
            while(len(compl)!=(len(result)-1)):
                compl="0"+compl
            compl="1"+compl
        #print("n:",n,"result:",result,"compl:",compl,"ret:",result+compl)
        return result+compl

    def kthGrammar(self, n: int, k: int) -> int:
        #need recursion? there is repeating elements
        self.d[1]="0"
        if(n in self.d):
            return int((self.d[n])[k-1])
        s=self.recursion(n)
        #("s:",s)
        return int(s[k-1])
'''
