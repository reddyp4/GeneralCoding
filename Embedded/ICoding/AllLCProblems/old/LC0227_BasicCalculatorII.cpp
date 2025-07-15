/*
227. Basic Calculator II

Medium
Topics
Companies
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

*/
/*
getNumber: get all continuous digits to make a number

no stack solution?
for every character
    space: ignore
    + or -: wait until next + or - and calculate intermediate number
        space:ignore
        get number
        * or -
            get second operand
    calculate result, multiply by + or - as per sign
    update answer
*/

class Solution {
public:
    int calculate(string s) {
        char operation;
        int current=0,result=0;
        stack<int> myStk;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ');
            else if(isdigit(s[i]))
            {
                current=current*10+(s[i]-'0');
            }
            else if(s[i]=='*' || s[i]=='/')
            {
                if(operation=='-') myStk.push(-current);
                else  myStk.push(current);
                operation=s[i];
                current=0;
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                operation=s[i];
                myStk.push(current);
                current=0;
            }
        }
        if(operation=='*')
        {
            int val=myStk.top()*current;
            myStk.pop();
            myStk.push(val);
        }
        else if(operation=='/')
        {
            int val=myStk.top()/current;
            myStk.pop();
            myStk.push(val);
        }
        else
            myStk.push(current);
        while(!myStk.empty())
        {
            //cout<<"stk.top:"<<myStk.top()<<endl;
            result+=myStk.top();
            myStk.pop();
        }
        return result;
    }
};