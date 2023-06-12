'''
1047. Remove All Adjacent Duplicates In String
Easy
5.7K
221
company
Amazon
company
Facebook
company
Adobe
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
'''

class Solution:
    def removeDuplicates(self, s: str) -> str:
        #M1: Make list of all duplicates, remove from string.
        #replace is O(n), exceeding time
        '''
        duplicates = {'aa','bb','cc','dd','ee','ff','gg','hh','ii','jj','kk','ll','mm','nn','oo','pp','qq','rr','ss','tt','uu','vv','ww','xx','yy','zz'}
        prevLength=0
        while(len(s)!=prevLength):
            prevLength=len(s)
            for dupl in duplicates:
              s=s.replace(dupl,'')
        return s
        '''
        #M2: Stack. Push on each character to stack. Compare next to top, if yes, pop otherwise append
        #Time:O(n), Space:O(n):BeatsT(36%),S(12%)
        '''
        st=[]
        for c in s:
            if(st and (st[-1]==c)):
                st.pop()
            else:
                st.append(c)
        return "".join(st)
        '''
        #M3: More efficient way without stack. Two pointer approach.
        #left=0,right=left+1