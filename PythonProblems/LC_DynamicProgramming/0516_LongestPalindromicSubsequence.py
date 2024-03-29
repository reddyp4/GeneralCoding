'''
516. Longest Palindromic Subsequence
Medium
Topics
Companies
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
'''

class Solution:
    def makeSubStr(self,current,leftStr,rightStr,bestSub):
        print("current:",current,"left:",leftStr,"right:",rightStr,"best:",bestSub)
        if(len(leftStr)==0 or len(rightStr)==0):
            print("len(current):",len(current),",len(bestSub):",len(bestSub))
            if(len(current)>len(bestSub)):
                bestSub=current[:]
                print("Improved1!best:",bestSub)
            #check if adding left or right also results in palindrome
            if(len(leftStr)==0):
                newS=current+rightStr
                if(newS==newS[::-1] and len(newS)>len(bestSub)):
                    bestSub=newS[:]
                    print("Improved2!best:",bestSub)
            else:
                newS=leftStr+current
                if(newS==newS[::-1] and len(newS)>len(bestSub)):
                    bestSub=newS[:]
                    print("Improved3!best:",bestSub)
            return bestSub
        m=len(leftStr)
        for i in range(m):
            c=leftStr[i]
            rightIndex = rightStr.find(c)
            if(rightIndex!=-1):
                print("Found c:",c,"left:",leftStr,"right:",rightStr,"righti:",rightIndex,"current:",current)
                bestSub=self.makeSubStr(c+current+c,leftStr[:i],rightStr[rightIndex+1:],bestSub)
                print("Returned best:",bestSub,"current:",current)
                lenCurrent=len(current)
                print("reset current:",current,"left:",leftStr,"right:",rightStr,"righti:",rightIndex)
        print("Finished1 bestSub:",bestSub)
        return bestSub
        
    def longestPalindromeSubseq(self, s: str) -> int:
        #starting case, is elimination of n-1 chars (in dp table that is 1,n-1, 2-n-2 etc), i to j are eliminated
        #this is the other diagnal
        #after dropping, if both i,j are same and prev case was good, then it is possible, to make a new string
        #first all characters are dropped except the ith index
        n=len(s)
        if(n==1):
            return s
        bestSub=""
        for i in range(n):
            current=s[i]
            leftStr=s[:i]
            rightStr=s[i+1:]
            bestSub=self.makeSubStr(current,leftStr,rightStr,bestSub)
            print("index:",i,"bestSub:",bestSub)
        return len(bestSub)

'''
Start with simple string, do different strings from left and right

'''