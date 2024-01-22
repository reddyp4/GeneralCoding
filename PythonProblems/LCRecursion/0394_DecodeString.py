'''
394. Decode String
Solved
Medium
Topics
Companies
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

 

Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
 

Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
'''
class Solution:
    def getPattern(self,s):
        index,lens,count=1,len(s),1
        while(index<lens and count!=0):
            if(s[index]=='['):
                count+=1
            elif(s[index]==']'):
                count-=1
            index+=1
        #print("Pattern:",s[1:index-1],"index:",index,"s:",s)
        return s[1:index-1]

    #chars until first numeric are added to final
    #go to first numeric, get pattern, between [ and ]. no nums in pattern, make sequence
    #if nums in pattern, call for iteration and get new sequence
    #attach sequence to final from right
    #continue till end
    def decodeString(self, s: str) -> str:
        #Corner case
        if(s.isalpha()):
            #all alphabets
            return s
        index,lens,final,count=0,len(s),"",0
        while(index<lens):
            if(index<lens):
                print("index1:",index,"s[index]:",s[index],"final:",final)
            if(s[index].isnumeric() and s[index+1]!='['):
                count=count*10+int(s[index])
            elif(s[index].isnumeric()):
                count=count*10+int(s[index])
                #get string between brackets
                pattern=self.getPattern(s[index+1:])
                index+=(len(pattern)+2)
                if(not pattern.isalpha()):
                    #call recursively
                    pattern=self.decodeString(pattern)
                substr=""
                for k in range(count):
                    substr=substr+pattern
                final=final+substr
                count=0
            elif(s[index]!='[' and s[index]!=']'):
                final=final+s[index]
                count=0
            #if(index<lens and pattern):
            #    print("index2:",index,"s[index]:",s[index],"final:",final,"len-patt:",len(pattern),"patt:",pattern)
            index+=1
        return final
'''
For every number, check pattern between brackets
If pattern is all alphabets, then call recursively
Calls: isnumeric() has numbers, isalpha() has alphabets
Tricky: update index to pattern+2, before calling recursively
'''