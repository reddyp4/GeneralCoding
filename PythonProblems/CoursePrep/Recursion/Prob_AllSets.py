''''
Generate All Subsets Of A Set
Generate ALL possible subsets of a given set. The set is given in the form of a string s containing distinct lowercase characters 'a' - 'z'.

Example
{
"s": "xy"
}
Output:

["", "x", "y", "xy"]
Notes
Any set is a subset of itself.
Empty set is a subset of any set.
Output contains ALL possible subsets of given string.
Order of strings in the output does not matter. E.g. s = "a", arrays ["", "a"] and ["a", ""] both will be accepted.
Order of characters in any subset must be same as in the input string. For s = "xy", array ["", "x", "y", "xy"] will be accepted, but ["", "x", "y", "yx"] will not be accepted.
Constraints:

0 <= length of s <= 19
s only contains distinct lowercase English letters.
'''
from typing import List

debug=1

def subProblem(s:str, partial:str, final: List[str], index: int):
    #Base Problem, reached end of string
    if(len(partial)==len(s)):
        #reached end of string
        final.append(partial)
    #Exclude, dont push anything into partial, just increment index 
    # and call subproblem
    #Include, push the string character into partial 
    # increment index and call subProblem

def generate_all_subsets(s):
    """
    Args:
     s(str)
    Returns:
     list_str
    """
    # Write your code here.
    return []
