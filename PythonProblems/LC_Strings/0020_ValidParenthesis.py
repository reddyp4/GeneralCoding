'''
20. Valid Parentheses
Easy
19.6K
1.1K
company
Amazon
company

Google
company
Bloomberg
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
'''
class Solution:
    def isValid(self, s: str) -> bool:
        #M1: stack solution, if left bracket, push to stack, if right pop and compare.Beats:T(6%),S(17%)
        '''
        stack=[]
        s=list(s)
        for c in s:
            if(c=='(' or c=='{' or c=='['):
                stack.append(c)
            else:
                if(len(stack)==0):
                    return False
                cpop = stack.pop()
                if(cpop=='(' and c==')') or (cpop=='{' and c=='}') or (cpop=='[' and c==']'):
                    cpop=''
                else:
                    return False
        if(len(stack)==0):
            return True
        return False
        '''
        #M2: Dont use a list. Cycle through string as is.Beats:T(16%),S(17%)
        '''
        stack=[]
        for c in s:
            if(c=='(' or c=='{' or c=='['):
                stack.append(c)
            else:
                if(len(stack)==0):
                    return False
                cpop = stack.pop()
                if(cpop=='(' and c==')') or (cpop=='{' and c=='}') or (cpop=='[' and c==']'):
                    cpop=''
                else:
                    return False
        if(len(stack)==0):
            return True
        return False
        '''
        #M3: Optimization: instead of ==, use set, since faster lookup
        stack=[]
        left={")":"(","}":"{","]":"["}
        for c in s:
            if(c not in left):
                stack.append(c)
            else:
                if (len(stack)==0) or (stack.pop()!=left[c]):
                    return False
        if(not stack and len(s)!=1):
            return True
        return False