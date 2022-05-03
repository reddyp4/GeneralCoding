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
    def __init__(self) -> None:
        pass
    
    def push(self, s:str, c:str) -> str:
        s1 = s+c
        #print(f"In push: s1={s1}")
        return s1
    
    def pop(self, s:str) -> str:
        s1 = s[0:len(s)-1:1]
        #print(f"In pop: s={s}, len={len(s)},s1={s1}")
        return s1
    
    def backspaceString(self, s: str) -> str:
        len1=len(s)
        s1 = ""
        for i in range(0,len1):
            if(s[i]=="#"):
                s1=self.pop(s1)
            else:
                s1=self.push(s1,s[i])
        #print(f"Final String={s1}")
        return s1

    def backspaceCompare(self, s: str, t: str) -> bool:
        s1=self.backspaceString(s)
        t1=self.backspaceString(t)
        print(f"s={s1},t={t1}")
        if(s1==t1):
            return True
        else:
            return False
        return False

''''
#Test case1
s="ab#c"
t="ad#c"
'''

#Test case2
s="ab##"
t="c#d#"

sol=Solution()
val=sol.backspaceCompare(s,t)
if(val):
    print(f"s:{s},t={t} are same!")
else:
    print(f"s:{s},t={t} are not the same!")

