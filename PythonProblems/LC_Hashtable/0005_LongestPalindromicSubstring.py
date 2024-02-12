'''
5. Longest Palindromic Substring
Solved
Medium
Topics
Companies
Hint
Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
'''

class Solution:
    def checkPalindrome(self,s,indices,result):
        if(len(s)==0):
            return 
        for index in range(len(indices)):
            start=indices[index]
            for k in range(index+1,len(indices)):
                end=indices[k]
                newstr=s[start:end+1]
                #print("[start:",start,",end:",end,"]",",newstr:",newstr)
                if(newstr==newstr[::-1]):
                    if(end-start+1>(result[1]-result[0]+1)):
                        result.append(start)
                        result.append(end)
                        result.pop(0)
                        result.pop(0)
        return

    def longestPalindrome(self, s: str) -> str:
        #Bruteforce: make dict with positions, cycle through all combinations
        #Recursion? For every character, check between indices?
        #if two indices next to each other are palindromes, maintain the start,end indices
        if(len(s)==1):
            return s
        #O(n2) pushed to recursion?
        result=[0,0]
        d={}
        for index in range(len(s)):
            c=s[index]
            if(c in d):
                d[c].append(index)
            else:
                d[c]=[index]
        print(d)
        #Now pass each list of indices to recursion to check all combinations, and update 
        for key in d:
            if(len(d[key])!=0):
                self.checkPalindrome(s,d[key],result)
        if(result[0]==-1):
            return ""
        return s[result[0]:result[1]+1]

'''
Maintain a dict of key-multiple indices
Check palindrom for each pairs
corner case: all counts are 1, i.e. single value
This solution is not recursive. 
'''
