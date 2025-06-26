/*
316. Remove Duplicate Letters
Solved
Medium
Topics
conpanies icon
Companies
Hint
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.
 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
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
5
ms
Beats
4.10%
Analyze Complexity
Memory
16.74
MB
Beats
9.36%
*/