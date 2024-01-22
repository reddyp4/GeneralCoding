'''
1087. Brace Expansion
Solved
Medium
Topics
Companies
Hint
You are given a string s representing a list of words. Each letter in the word has one or more options.

If there is one option, the letter is represented as is.
If there is more than one option, then curly braces delimit the options. For example, "{a,b,c}" represents options ["a", "b", "c"].
For example, if s = "a{b,c}", the first character is always 'a', but the second character can be 'b' or 'c'. The original list is ["ab", "ac"].

Return all words that can be formed in this manner, sorted in lexicographical order.

 

Example 1:

Input: s = "{a,b}c{d,e}f"
Output: ["acdf","acef","bcdf","bcef"]
Example 2:

Input: s = "abcd"
Output: ["abcd"]
 

Constraints:

1 <= s.length <= 50
s consists of curly brackets '{}', commas ',', and lowercase English letters.
s is guaranteed to be a valid input.
There are no nested curly brackets.
All characters inside a pair of consecutive opening and ending curly brackets are different.

'''

class Solution:
    def recursive(self, current, index, s, count, final):
        #Make recursive call for every element within bracket, else just continue
        #current=string being made, index is in s, s original, count=needed length
        if(len(current)==count):
            final.append(current)
            return
        while(index<len(s)):
            if(s[index]!='{'):
                current=current+s[index]
            else:
                clist=""
                while(s[index]!='}'):
                    if(s[index].isalpha()):
                        clist=clist+s[index]
                    index+=1
                for c in clist:
                    self.recursive(current+c,index+1,s,count,final)
            index+=1
        if(len(current)==count):
            final.append(current)
            return

    #at every {, call recursion on elements in {}, finish with length without brackets
    def expand(self, s: str) -> List[str]:
        final=[]
        index,lens,count=0,len(s),0
        #final length of string
        while(index<lens):
            if(s[index]!='{'):
                count+=1
            else:
                count+=1
                while(s[index]!='}'):
                    index+=1
            index+=1
        #print("count:",count)
        if(count==lens):
            final.append(s) #no brackets
        else:
            self.recursive("", 0, s,count,final)
        final.sort()
        return final
'''
Similiar to 394 - decode string
first get actual length we are going to make - call it count
now setup a recursive call to make a string, append once we reach above count
tricky: may finish string, for tail end - so need to check at both ends
'''