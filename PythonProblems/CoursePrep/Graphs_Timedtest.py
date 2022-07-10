"""
Problem
Find Order Of Characters In Alien Dictionary
Given a sorted dictionary of an alien language, find the order of characters in the alphabet.

Example One
{
"words": ["baa", "abcd", "abca", "cab", "cad"]
}
Output:

"bdac"
Example Two
{
"words": ["caa", "aaa", "aab"]
}
Output:

"cab"
Notes
Given dictionary is sorted in the lexicographical order of the alien language.
Output is a string consisting of all the characters of the alien alphabet, in order.
Constraints:

1 <= total length of all the words in the dictionary <= 105
Input will consist of lowercase latin characters only
Input will be such that it is possible to determine the alphabet order uniquely
The dictionary may contain duplicate words
"""

def find_order(words):
    """
    Args:
     words(list_str)
    Returns:
     str
    """
    # Write your code here.
    final=""
    count=0
    #Build the adjacency list
    #traverse each count and build the string
    size1=len(words)
    for i in range(0,size1):
        c=""
        if(c!=words[count][0]):
            final.append(c)
    return final
