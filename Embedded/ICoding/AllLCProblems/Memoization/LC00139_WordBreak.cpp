/*
139. Word Break
Medium
Topics
conpanies icon
Companies
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
 

Constraints:

1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

/*
Store dict in hashmap, check left-right ptrs
*/
/* DOES NOT WORK
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int> myMap;
        for(int i=0;i<wordDict.size();i++)  myMap[wordDict[i]]=1;
        int left=0,subslen=1;
        bool found=false;
        if(s.size()==1)
        {
            if(myMap[s]==1) return true;
            else return false;
        }
        while(left<s.size())
        {
            found=false;
            cout<<"Start:left:"<<left<<",subslen:"<<subslen<<",found:"<<found<<endl;
            while((left+subslen)<s.size() && myMap.count(s.substr(left,subslen))!=1)    {subslen++;found=true;}
            cout<<"String checked:"<<s.substr(left,subslen)<<endl;
            if(found==false)    break;
            cout<<"End:left:"<<left<<",subslen:"<<subslen<<",found:"<<found<<endl;
            left+=subslen;
            subslen=1;
        }
        return found;
    }
};*/

/* 
Method1: Just search, fails. 
Method2: Variation of Method1. Instead of two pointers, do it for each element of left
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*  Step1: Build set
            Step2: Queue of seen spots
        */
        //Step1: Build set
        unordered_set<string> mySet(wordDict.begin(),wordDict.end());
        //Step2: Queue
        queue<int> queue;queue.push(0); //index0
        //Step3: Vector of all false as start
        vector<bool> seen(s.length(),false);

        while(!queue.empty())
        {
            int start = queue.front();queue.pop();
            //cout<<"start:"<<start<<endl;

            if(start==s.length())   return true;    //reached end

            for(int end=start+1;end<=s.length();end++)
            {
                //cout<<"end:"<<end;
                if(seen[end])   continue;   //this index already seen move on
                
                //cout<<",substr:"<<s.substr(start,end-start)<<";"<<endl;
                if(mySet.find(s.substr(start,end-start)) != mySet.end() )
                {
                    //cout<<"pushing:"<<end<<endl;
                    queue.push(end);
                    seen[end]=true;
                }
            }
        }
        return false;
    }
};