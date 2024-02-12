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
        #Approach1: Dict with multi-values and iteration
        #Recursion? For every character, check between indices?
        #if two indices next to each other are palindromes, maintain the start,end indices
        if(len(s)==1):
            return s
        #O(n2) pushed to recursion?
        '''
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
        #Approach2: assume dp table of n*n, 
        #substr of 3 is pal if s[i+1]==s[i-1] and dp[i][i]
        #next substr or center+i is pal, if s[c-i]==s[c+i] and dp[c+(i-1)] is true
        #this is considred dp, since we are "building" on top of previous value
        n=len(s)
        result=[0,0]
        dp=[[False] * n for _ in range(n)]
        for i in range(n):
            dp[i][i]=True
        #Now for every index, start checking the increasing growing strings, until end
        substr=s[0]
        for i in range(n-1):
            if(s[i]==s[i+1]):
                dp[i][i+1]=True
                result=[i,i+1]
        #print("dp:",dp)
        for diff in range(2,n):
            for i in range(n-diff):
                j = i + diff
                print("checking[",i,":",j,"]")
                if(s[i]==s[j] and dp[i+1][j-1]):
                    dp[i][j]=True
                    print("oldstring:",substr)
                    if(len(substr)>(2*j)):
                        substr=s[i-j:i+j+1]
                    print("newstring:",substr)
                    result=[i,j]
        #print("dp:",dp)
        return s[result[0]:result[1]+1]
'''
Maintain a dict of key-multiple indices
Check palindrom for each pairs
corner case: all counts are 1, i.e. single value
This solution is not recursive. 
'''
