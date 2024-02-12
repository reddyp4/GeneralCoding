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
        '''
        for index in range(len(s)):
            if(d[s[index]]==1):
                return index
        return -1'''
        #Approach2: make the count dict, and sort the dict itself
        result=sorted(d.items(), key=lambda x:x[1])
        if(result[0][1]!=1):
            return -1
        return s.find(result[0][0])
        #Approach3: convert dict to list and sort list1 by list2    
'''
make count, and check first character for count of 1
Space: O(1) and time: O(n)

Same but sort (log(n))
'''