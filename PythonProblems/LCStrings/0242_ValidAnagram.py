'''
242. Valid Anagram
Easy
11.3K
357
company
Bloomberg
company
Amazon
company
Apple
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
'''

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #M1: Bruteforce: For each character, add to a hashmap with count, check count at end
        #default case
        if(len(s)!=len(t)):
            return False
        alph = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        countS, countT = [0]*26,[0]*26
        for c in s:
            index = alph.index(c)
            countS[index] = countS[index] + 1
        for c in t:
            index = alph.index(c)
            countT[index] = countT[index] + 1
        if(countS==countT):
            return True
        return False

'''
M1: Hashtable approach with list, O(n) for space, and O(n) with single pass
M2: Sort: O(nlogn) if merge sort

'''