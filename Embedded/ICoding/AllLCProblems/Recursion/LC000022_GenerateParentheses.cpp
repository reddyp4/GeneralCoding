/*
22. Generate Parentheses
Solved
Medium
Topics
conpanies icon
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/
/*
Numbers from 0 to 2^n-1
equal number of 1 and 0, 
Recursive: Count=0,max=n, 
    if(count<0) return
    update count if add ( call recursive
    decrement count if add ) call recursive
    If length==n, count==0, add to list
*/
class Solution {
public:
    void recur(vector<string> *vec,string s, int current, int max) {
        //cout<<"string:"<<s<<",current:"<<current<<endl;
        if(s.size()>2*max)  return;
        if(current<0)   return;
        if(s.size()==2*max)     {
            if(current==0)  {
                vec->push_back(s);
                return;
            }
            return;
        }
        recur(vec,s+'(',current+1,max);
        if(current>0)  recur(vec,s+')',current-1,max);
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        recur(&result,"",0,n);
        return result;
    }
};