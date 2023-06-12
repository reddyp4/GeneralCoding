'''
150. Evaluate Reverse Polish Notation
Medium
5.7K
871
company
Amazon
company
Google
company
LinkedIn
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
 

Constraints:

1 <= tokens.length <= 104
tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
'''
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        #M1: if number push to stack. If not pop twice and evaluate and push result to stack.
        #Beats T(22%),S(9%)
        totalStack=[]
        for val in tokens:
            #hit an operator, pop operator1 and pop operator2 and push result
            if(val not in {"/","+","*","-"}):
                #hit operatand
                totalStack.append(val)
                continue
            num1=totalStack.pop()
            num2=totalStack.pop()
            if(val=='+'):
                totalStack.append(int(num1)+int(num2))
            elif(val=='*'):
                totalStack.append(int(num1)*int(num2))
            elif(val=='/'):
                result=int(int(num2)/int(num1))
                totalStack.append(result)
            elif(val=='-'):
                totalStack.append(int(num2)-int(num1))
        return(int(totalStack.pop()))