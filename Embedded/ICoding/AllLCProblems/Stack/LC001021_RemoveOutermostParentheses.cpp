/*
1021. Remove Outermost Parentheses
Solved
Easy
Topics
conpanies icon
Companies
Hint
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

 

Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".
Example 2:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
Example 3:

Input: s = "()()"
Output: ""
Explanation: 
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".
 

Constraints:

1 <= s.length <= 105
s[i] is either '(' or ')'.
s is a valid parentheses string.
*/

/*
What is this problem? Strip outer paranthesis, keep the inner ones only? No
    For the inner ones, only strip the outermost brackets
M1: 
    When closing -> set a flag, and look for outermost to strip out
        Need count of ( to determine the outermost
        Put all brackets in stack and keep count of (


*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result,newstr;
        int i=0,count=0;
        bool found=false,print=false;
        stack<char> myStk;
        while(i<s.size())
        {
            myStk.push(s[i]);
            //Move i till found
            if(s[i]=='(')   count++;
            else if(s[i]==')')  {found=true;count--;}
            //Now wait until count==1
            if(found && count==0)   //one bracket open, to pop stack to make result
            {
                myStk.pop();    //remove outer )
                while(myStk.size()>1)    {
                    newstr=myStk.top()+newstr;
                    myStk.pop();
                }
                result+=newstr;
                if(print)   cout<<"newstr:"<<newstr<<",result:"<<result<<endl;
                newstr="";
                myStk.pop();    //remove outer (
                found=false;
            }
            i++;
        }
        return result;
    }
};

/*
Runtime
4
ms
Beats
12.73%
Analyze Complexity
Memory
9.02
MB
Beats
24.85%
*/