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
    if(index==len(s)):
        #reached end of string
        final.append(str(partial))
        if(debug==1):
            print(f"Base: s={s},partial={partial},final={final},index={index}")
        return
    #Exclude, dont push anything into partial, just increment index 
    # and call subproblem
    if(debug==1):
        print(f"Exclude Start: s={s},partial={partial},final={final},index={index}")
    subProblem(s,partial,final,index+1)
    #partial=partial[:-1] << no need to do , since nothing added
    if(debug==1):
        print(f"Exclude End: s={s},partial={partial},final={final},index={index}")

    #Include, push the string character into partial 
    # increment index and call subProblem
    partial=partial+str(s[index])
    #partial=partial.join(s[index])
    if(debug==1):
        print(f"Include Update: s={s},s[index]={s[index]},partial={partial},final={final},index={index}")
    subProblem(s,partial,final,index+1)
    #partial=partial[:-1]
    if(debug==1):
        print(f"Include End: s={s},partial={partial},final={final},index={index}")

def generate_all_subsets(s) -> List[str]:
    """
    Args:
     s(str)
    Returns:
     list_str
    """
    # Write your code here.
    partial=""
    final=[]
    subProblem(s,partial,final,0)
    return final

s="xy"
final=generate_all_subsets(s)
print(f"Final:{final}")