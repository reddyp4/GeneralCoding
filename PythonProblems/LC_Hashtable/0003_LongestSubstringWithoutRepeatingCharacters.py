'''
3. Longest Substring Without Repeating Characters
Medium
38.1K
1.7K
company
Amazon
company
Bloomberg
company
Apple
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        maxlen = 0
        if(len(s)==0):
            return 0
        if(len(s)==1):
            return 1
        sub = {}
        newStr = ""
        for c in s:
            if c in sub:
                if(len(newStr)>maxlen):
                    maxlen = len(newStr)
                #if first character drop, no change to sub
                #if last character, then reinitialize
                if(newStr[-1]==c):
                    newStr=c
                    sub={}
                    sub[c]=1
                    continue
                index = newStr.index(c)
                for i in range(0,index+1):
                    sub.pop(newStr[i])
                newStr=newStr[index+1:]+c
                sub[c]=1
            else:
                newStr=newStr+c
                sub[c]=1
        if(len(newStr)>maxlen):
            maxlen = len(newStr)
        return maxlen 

'''
Hashmap:
Maintain new string, hashset (dict)
Trick: If c is last in string, whole string drops
If c occurs elsewhere, drop everything until c and update newstr and hashset

'''