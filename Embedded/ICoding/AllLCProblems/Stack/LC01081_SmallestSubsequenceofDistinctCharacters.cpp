/*
1081. Smallest Subsequence of Distinct Characters
Attempted
Medium
Topics
conpanies icon
Companies
Hint
Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
 

Note: This question is the same as 316: https://leetcode.com/problems/remove-duplicate-letters/
*/
/* 
Stack with monotonic rising for repeated characters, others just add
> build, vector of lists to add positions of each char: ex: a->1,2; b->0,3 ...
> For every character: keep track of elem in stk, and full list
 > if stk is empty, add char, update seen, reduce list
 > else if already in stack (seen) already, move
 > else if newchar>stk.top, add, reduce list
 > else if newchar<stk.top, pop if this top is in rest of string (or list>0)
   > add char, update see, reduce list

*/

/* 
Stack with monotonic rising for repeated characters, others just add
> build, vector of lists to add positions of each char: ex: a->1,2; b->0,3 ...
> For every character: keep track of elem in stk, and full list
 > if stk is empty, add char, update seen, reduce list
 > else if already in stack (seen) already, move
 > else if newchar>stk.top, add, reduce list
 > else if newchar<stk.top, pop if this top is in rest of string (or list>0)
   > add char, update see, reduce list

*/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<deque<int>> myOccur{26};
        for(int i=0;i<s.size();i++) myOccur[s[i]-'a'].push_back(i);
        stack<char> myStk;      //stack for result
        vector<int> myStkSeen(26,0);    //keep track of chars in stack
        bool print=false;
        for(int i=0;i<s.size();i++)
        {
            if(print)   cout<<"Char:"<<s[i]<<",inStack?"<<myStkSeen[s[i]-'a']<<",Size:"<<myOccur[s[i]-'a'].size();
            //if stack is empty add
            if(myStk.empty()) // || myOccur[s[i]-'a'].size()==1)    
            {
                myStk.push(s[i]);
                if(print)   cout<<",1Push:"<<s[i];
                myOccur[s[i]-'a'].pop_front();  //update count
                myStkSeen[s[i]-'a']=1;
            }
            //if element in stack, move on
            else if(myStkSeen[s[i]-'a']==1) 
            {
                if(print)  cout<<",seen:"<<s[i];
                myOccur[s[i]-'a'].pop_front();
            }
            //if char>top and occurs again move, and update the list
            else if(s[i]>myStk.top())
            {
                myStk.push(s[i]);
                if(print)   cout<<",2Push:"<<s[i];
                myOccur[s[i]-'a'].pop_front();  //update count
                myStkSeen[s[i]-'a']=1;
            }
            //if char<=top, pop until 1) char<=top and unique char OR 2) and top occurs again, pop until this cond is not true, pop for list to push to count of 1
            else
            {
                if(print)   cout<<",higher";
                while(!myStk.empty() && s[i]<myStk.top() && !myOccur[myStk.top()-'a'].empty())
                {
                    if(print)   cout<<",pop:"<<myStk.top()<<",Empty?"<<myOccur[myStk.top()-'a'].empty();
                    //myOccur[myStk.top()-'a'].pop_front();  //remove old occurence
                    myStkSeen[myStk.top()-'a']=0;
                    myStk.pop();
                }
                //if element already in stack, move else push
                if(print)   cout<<",3Push:"<<s[i];
                //update size
                myOccur[s[i]-'a'].pop_front();
                //cout<<",newsize:"<<myOccur[s[i]-'a'].size()<<endl;
                myStk.push(s[i]);
                myStkSeen[s[i]-'a']=1;
            }
            if(print)   cout<<",newsize:"<<myOccur[s[i]-'a'].size()<<endl;
            //if char>top and no more occurence of char, add char
        }
        //pop stack and build the string
        string result;
        while(!myStk.empty())   
        {
            result=myStk.top()+result;
            myStk.pop();
        }
        return result;
    }
};

/*
Runtime
1
ms
Beats
25.03%
Analyze Complexity
Memory
10.41
MB
Beats
8.06%
*/