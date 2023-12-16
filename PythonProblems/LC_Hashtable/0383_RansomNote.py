'''
383. Ransom Note
Easy
4.7K
476
company
Amazon
company
Facebook
company
Adobe
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 

Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.

'''

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        d1, d2 = {},{}
        for c in magazine:
            if c in d1:
                d1[c]=d1[c]+1
            else:
                d1[c]=1
        for c in ransomNote:
            if c in d1 and d1[c]!=0:
                d1[c] = d1[c]-1
            else:
                return False
        return True

'''
Hash: Space-O(n),Time:O(n) of magazine

string: not possible
'''