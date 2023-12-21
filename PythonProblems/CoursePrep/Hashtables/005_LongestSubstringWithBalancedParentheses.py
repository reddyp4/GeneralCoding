'''
Longest Substring With Balanced Parentheses
Given a string brackets that only contains characters '(' and ')', find the length of the longest substring that has "balanced parentheses".

Example One
{
"brackets": "((((())(((()"
}
Output:

4
Because "(())" is the longest substring with balanced parentheses.

Example Two
{
"balanced": "()()()"
}
Output:

6
The entire string "()()()" has parentheses balanced.

Notes
A string is defined as having balanced parentheses if and only if it has an equal number of '(' and ')' and its every prefix has at least as many '('s as ')'s.
Constraints:

1 <= length of brackets <= 105
'''

def find_max_length_of_matching_parentheses(brackets):
    """
    Args:
     brackets(str)
    Returns:
     int32
    """
    # Write your code here.
    maxcount,count,left=0,0,0
    ll=[]
    for c in brackets:
        if(c==')'):
            if(ll[-1]=='('):
                count=count+1
                ll.pop()
                if(maxcount>count):
                    maxcount=count
                left=left-1
            else:
            if(left<0):
        elif(c=='('):
            ll.append(c)
            left=left+1
    return maxcount

balanced = "((((())()((()"
#balanced = "()()()"
print(find_max_length_of_matching_parentheses(balanced))

Xiaofan Tong 
