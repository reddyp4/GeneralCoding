'''
Subsets With Duplicate Characters

Given a string that might contain duplicate characters, find all the possible distinct subsets of that string.

Example One
{
"s": "aab"
}
Output:

["", "a", "aa", "aab", "ab", "b"]
Example Two
{
"s": "dc"
}
Output:

["", "c", "cd", "d"]
Notes
All the subset strings should be individually sorted.
The order of the output strings does not matter.
Constraints:

1 <= length of the string <= 15
String consists of lowercase English letters
'''
seen = {}

def recursive(current,count,s,final):
    if(count==len(s)):
        newcurrent="".join(sorted(current))
        if(newcurrent not in seen):
            final.append(newcurrent)
            seen[newcurrent]=1
        return
    #print("current:",current,"count:",count,"s:",s,"final:",final)
    recursive(current,count+1,s,final)
    recursive(current+s[count],count+1,s,final)

def get_distinct_subsets(s):
    """
    Args:
     s(str)
    Returns:
     list_str
    """
    # Write your code here.
    final=[]
    recursive("",0,s,final)
    return final
