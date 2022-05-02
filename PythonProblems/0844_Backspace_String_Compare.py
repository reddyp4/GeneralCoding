''''
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
'''

#class Solution:
#    def backspaceCompare(self, s: str, t: str) -> bool:

#Method-1: Brute Force - evaluate strings, string compare
class Solution:
    def backspaceString(self, s: str) -> str:
        len1=len(s)
        s1 = ""
        for i in range(0,len1-2):
            if(s[i+1]=="#"):
                i+=1
            else:
                s1=s1+s[i]
        if(s[len1-1]!="#"):
            s1=s1+s[len1-1]
        return s1

    def backspaceCompare(self, s: str, t: str) -> bool:
        s1=self.backspaceString(s)
        t1=self.backspaceString(t)
        if(s1==t1):
            return True
        else:
            return False
        return False

s="ab#c"
t="ad#c"
val=Solution.backspaceCompare(s,t)
if(val):
    print(f"s:{s},t={t} are same!")
else:
    print(f"s:{s},t={t} are not the same!")

