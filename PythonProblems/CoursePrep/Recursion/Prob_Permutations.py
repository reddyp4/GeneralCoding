''''
Letter Case Permutation

Given a string, return all strings that can be generated by changing case of one or more letters in it.

Example One
{
"s": "a1z"
}
Output:

["A1Z", "A1z", "a1Z", "a1z"]
Example Two
{
"s": "123"
}
Output:

["123"]
Notes
Return strings in any order.

Constraints:

Input string may contain only: 'a'..'z', 'A'..'Z', '0'..'9'
1 <= length of the string <= 12
'''
from curses.ascii import islower, isupper
from typing import List

def subProblem(input: str, partial: str,final: List[str], index: int):
    if(len(input)==0):
        return
    #Base Case: end of string, take partial and add it as a list element
    if(index==len(input)):
        final.append(partial)
        #print(f"partial={partial}")
        return
    if((islower(input[index])) | (isupper(input[index]))):  #character
        #print(f"char:{input[index]}")
        partial = partial + (input[index]).upper()
        #partial.join((input[index]))
        #print(f"new partial:{partial}")
        subProblem(input,partial,final,index+1)     #upper
        partial = partial[:-1]
        #how to pop last element of string?
        
        partial = partial + (input[index]).lower()
        #partial.join((input[index]))
        #print(f"new partial:{partial}")
        subProblem(input,partial,final,index+1)
        partial = partial[:-1]
        #pop last element of string?
    else:   #do nothing
        #print(f"num:{input[index]}")
        partial = partial + input[index]
        subProblem(input,partial,final,index+1)

    #detect character, case1: lower, case2: upper
    #detect anything else: do nothing

def letter_case_permutations(s):
    """
    Args:
     s(str)
    Returns:
     list_str
    """
    # Write your code here.
    final=[]
    subProblem(s,"",final,0)
    return final

s="a1z"
print(f"Input:{s}")
final=[]
final=letter_case_permutations(s)
print(f"Final List:{final}")