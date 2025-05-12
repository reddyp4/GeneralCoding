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
private:
    stack<int> myStk;
public:
    int getNumber(string s, int* loc, bool print,int len1)
    {
        int val=0;
        while(s[*loc]==' ')    (*loc)++;
        while(((*loc)<len1) && !(s[*loc]=='+' || s[*loc]=='-' || s[*loc]=='*' || s[*loc]=='/' || s[*loc]==' '))
        {
            val=val*10+(int)(s[*loc]-'0');
            if(print)   cout<<"s[*loc]"<<s[*loc]<<",val:"<<val<<endl;
            (*loc)++;
        }
        return val;
    }

    int calculate(string s) {
        int len1=s.size(),i=0,ans=0,val=0,oper1=0,oper2=0;
        char operation;
        bool print=0;
        if(print)   cout<<"len1:"<<len1<<endl;
        while(i<len1)
        {
            if (s[i]==' ')    i++;    //space
            else if(s[i]=='+')
            {
                myStk.push(1);i++;
            }
            else if(s[i]=='-')
            {
                myStk.push(-1);i++;
            }
            else if(s[i]=='*' || s[i]=='/')
            {
                operation=s[i];
                //Operand1
                oper1=myStk.top();
                myStk.pop();
                //Operand2
                i++;
                oper2=getNumber(s,&i,print,len1);
                //higher priority operation, * or /
                if(operation=='*')  val=oper1*oper2;
                else if(operation=='/')  val=oper1/oper2;
                if(print)   cout<<"oper1:"<<oper1<<",oper2:"<<oper2<<",val:"<<val<<endl;
                myStk.push(val);
            }
            else
            {
                //number
                val=getNumber(s,&i,print,len1);
                if(!myStk.empty())  {val*=myStk.top();myStk.pop();}
                if(print)   cout<<"val:"<<val<<endl;
                myStk.push(val);
            }
        }
        //pop stack
        while(!myStk.empty())   
        {
            if(print)   cout<<"stk.top:"<<myStk.top()<<endl;
            ans+=myStk.top();
            myStk.pop();
        }
        if(print)   cout<<"ans:"<<ans<<endl;
        return ans;
    }
};