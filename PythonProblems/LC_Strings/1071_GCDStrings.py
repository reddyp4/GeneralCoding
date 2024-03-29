'''
1071. Greatest Common Divisor of Strings
Easy
3.3K
507
company
Arista Networks
company
Visa
company
Amazon
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

 

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
'''
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if(str1==str2):
            return str1
        len1=len(str1)
        len2=len(str2)
        minlen = len1 if len1<len2 else len2
        j=minlen
        substr = str()
        while(j>0):
            substr=str1[0:j]
            #create the equivalent str1 and str2 and compare, if len doesnt divide move on
            if(len(str1)%len(substr)==0 and len(str2)%len(substr)==0):
                str1build=str()
                str2build=str()
                #for i in range(0,int(len(str1)/len(substr))):
                #    str1build=str1build+substr
                #better code
                str1build=substr*(len(str1)//len(substr))
                str2build=substr*(len(str2)//len(substr))
                #for i in range(0,int(len(str2)/len(substr))):
                #    str2build=str2build+substr
                if(str1build==str1 and str2build==str2):
                    return substr
            j=j-1
        return ""    