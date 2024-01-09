'''
266. Palindrome Permutation
Easy
1K
68
company
Facebook
company
Google
company
Uber
Given a string s, return true if a permutation of the string could form a 
palindrome
 and false otherwise.

 

Example 1:

Input: s = "code"
Output: false
Example 2:

Input: s = "aab"
Output: true
Example 3:

Input: s = "carerac"
Output: true
 

Constraints:

1 <= s.length <= 5000
s consists of only lowercase English letters.
'''

class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        #one odd, rest even
        d={}
        for c in s:
            if(c in d):
                d[c]=d[c]+1
            else:
                d[c]=1
        #check all keys, should be single odd?
        odd=0
        allkeys=list(d.keys())
        for key in allkeys:
            if(d[key]%2==1):
                if(odd==1):
                    return False
                else:
                    odd=1
        return True
    
'''
Only one odd key count, rest should be even in a dict
'''

