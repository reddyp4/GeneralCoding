''''
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

 

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]
 

Constraints:

1 <= s.length <= 12
s consists of lowercase English letters, uppercase English letters, and digits.
'''

#Question to ask: order of strings
#Question to ask: length of string
#Question to ask: special chacterers
#Question to ask on numbers

#Method-1: Lazy manager approach
#Takes previous strings, does work on her location and calls subsequent calls
#Manager work: Check digit/lowercase-alpha/uppercase-alpha
#Recursive call, one lower, one upper
#Base case: Reached end of string

from curses.ascii import isdigit, islower, isupper
from typing import List

class Solution:
    #input string, partial solution, index for sub-problem
    def subProblem(self, s:str, partialS:str, index:int, final:List):
        if(index==len(s)):    #Reached end of string
            #print(partialS)
            final.append(partialS)
            return
        
        else:   #partial problem (slate)
            if(islower(s[index]) | isupper(s[index])):    #got uppercase or lowercase
                self.subProblem(s,partialS+(str(s[index])).lower(),index+1, final)   #lowercase
                self.subProblem(s,partialS+(str(s[index])).upper(),index+1, final)   #lowercase
            elif(isdigit(s[index])):   #got a number
                self.subProblem(s,partialS+str(s[index]),index+1, final)
        pass

    def letterCasePermutation(self, s: str) -> List[str]:
        final=[]
        self.subProblem(s,"",0,final)
        return final


s = "a1b2"
sol=Solution()
#Print all solutions
final=[]
final = sol.letterCasePermutation(s)
print(final)
