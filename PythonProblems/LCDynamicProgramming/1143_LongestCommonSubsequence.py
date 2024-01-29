'''
1143. Longest Common Subsequence
Attempted
Medium
Topics
Companies
Hint
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

 

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
'''
class Solution:
    def getCount(self,text1,text2,count):
        len1,len2=len(text1),len(text2)
        #print("text1:",text1,"text2:",text2,"len1:",len1,"len2:",len2,"count:",count)
        if(len1==0):
            return count
        newseq=0
        #for every char of 1, check the sequence in 2?
        countmax=prevcount=count
        for index in range(len1):
            if(text1[index] in text2):
                index2=text2.find(text1[index])
                count=self.getCount(text1[index+1:],text2[index2+1:],prevcount+1)
                countmax = countmax if (countmax>count) else count
                #print("text1[index]:",text1[index],"match:count",countmax)
        #print(count)
        return countmax

    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        val=self.getCount(text1,text2,0)
        return val

'''
getcount works until case 15, where it exceeds time limit

'''