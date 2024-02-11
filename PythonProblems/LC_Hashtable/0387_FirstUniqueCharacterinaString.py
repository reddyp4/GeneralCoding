'''
387. First Unique Character in a String
Solved
Easy
Topics
Companies
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
'''

class Solution:
    def firstUniqChar(self, s: str) -> int:
        #Approach1: Space:O(1) for 36 chars, Time:O(n)
        #Now another loop to check its count
        d={}
        for c in s:
            if(c in d):
                d[c]+=1
            else:
                d[c]=1
        for index in range(len(s)):
            if(d[s[index]]==1):
                return index
        return -1
        #Approach2: sort string based on the count, and pick the first character
        #this is fixed space for characters, so O(1). Sort 
    
'''
make count, and check first character for count of 1
Space: O(1) and time: O(n)

Same but sort (log(n))
'''