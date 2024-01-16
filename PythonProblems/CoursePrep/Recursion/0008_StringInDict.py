'''
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.
Note that you are allowed to reuse a dictionary word.

Input: s = "leetcode", wordDict = ["leet","code"]       Output: true
"l"->"le"->"lee"
"e"->"ee"..

"l"-"le". "leet" -> "c"
                 -> "leetc"
Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple","pen"]  Output: true
Return true because "applepenapple" can be segmented as "apple pen apple".

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]    Output: false

Input: s = "catsanddog", wordDict = ["cats","dog","and","cat"]    Output: true

Input: s = "catsanddog", wordDict = ["cats","catsand","catsandog"]    Output: true

'''

def helper(s,wordDict):
    flag=False
    '''
    Form string(slate), if string in Dict, start new slate, and form new slate and call recursive
    Approach is to reduce string, until we are left with empty string, then we are parsed the complete string
    '''
    if(len(s)==0 or s in wordDict):
        return True
    # if current in wordDict, move to next string
    lens = len(s)
    start,i = 0,0
    while(i<len(s)):
        #search each string, if present, kick off a recursion, else continue
        newstr = s[start:i]
        if(newstr in wordDict):
            start=i+1
            flag=helper(s[start:],wordDict)
        i+=1
    if(len(s)==0):
        #reached full string
        return flag
    return flag

def sequence(s,wordDict):
    current=""
    return helper(s,wordDict)

s="leetbabc"
wordDict=["leet","leetabc"]
flag=sequence(s,wordDict)
if(flag):
    print("Found")
else:
    print("Did not find")