''''
Find All Well-formed Brackets
Given a positive integer n, return ALL strings of length 2 * n with well-formed round brackets.

Example
{
"n": 3
}
Output:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
Any array containing these five strings in any order is a correct output.

Notes
Order of strings in the returned array is insignificant, e.g. for n = 2 both ["(())", "()()"] and ["()()", "(())"] will be accepted.
Constraints:

1 <= n <= 12
Only use round brackets. '(' and ')'
'''
#Method: Final List = (, (, (, ), ), )
#like 111000 -> number of numbers that can be formed = 6C3 = 6X5X4 = 120?
#Ideally, 111111 options? 
#Maintain an open count, 

from typing import List

def subProblem(final: List[str],partial: str, count: int, len1: int, bracket: int):
    #base case: reached end of string length & bracket count = 0
    if(count==len1):
        if(bracket==0):
            final.append(str(partial))
        return
    #check count and decide accordingly
    #if bracket>=0, can add ( decrement bracket, increment count 
    # other option is to add ), increment bracket
    #else: cannot add (, instead add )
    if(bracket>=0):
        print(partial)
        partial=partial+"("
        #partial.join("(")
        print(partial)
        bracket=bracket-1
        count=count+1
        print(f"(: final={final},partial={partial},count1={count+1}, bracket={bracket}")
        subProblem(final,partial,count+1, len1, bracket)
        #pop for next option
        partial=partial[:-1]
        count=count-1
        print(f"(: final={final},partial={partial},count1={count+1}, bracket={bracket}")

        #partial.join(")")
        partial=partial+")"
        bracket=bracket+1
        count=count+1
        print(f"(: final={final},partial={partial},count1={count+1}, bracket={bracket}")
        subProblem(final,partial,count, len1, bracket)
        partial=partial[:-1]
        print(f"): final={final},partial={partial},count1={count}, bracket={bracket}")
        

def find_all_well_formed_brackets(n):
    """
    Args:
     n(int32)
    Returns:
     list_str
    """
    # Write your code here.
    final=[]
    partial=""
    subProblem(final,partial,0,2*n,0)
    return final

n=3
final=find_all_well_formed_brackets(n)
print(final)
