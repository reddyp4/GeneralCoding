'''
784. Letter Case Permutation
Solved
Medium
Topics
Companies
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
class Solution:
    def recursive(self,i,s,final):
        if(not s[i:].isalpha()):
            #print("i:",i,"s:",s,"final:",final)
            if(s not in final):
                #reached the end of string
                final.append(s[:])
        while(i<len(s)):
            if(s[i].isalpha()):
                #recursive for all characters only
                newstr=s[:i]+s[i].lower()+s[i+1:]
                #print("newstr1:",newstr)
                self.recursive(i+1,newstr,final)
                newstr=s[:i]+s[i].upper()+s[i+1:]
                #print("newstr1:",newstr)
                self.recursive(i+1,newstr,final)
            i+=1

    def letterCasePermutation(self, s: str) -> List[str]:
        #Thought: every letter has its recursive thread, itself and all children with consequent letters
        #no need to go back
        final=[]
        self.recursive(0,s,final)
        return final

'''
Can be faster with hash
'''