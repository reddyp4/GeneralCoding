/*
14. Longest Common Prefix
Solved
Easy
Topics
conpanies icon
Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.
*/

/*
Idea: take first string, iterate every char?
Iterate i from 0 to first char length or least length, loop a second time
This is O(n^2), n count 0 to length, and on top, iterate all strings
better?
Find the min: O(n)

*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minlen=strs[0].size(),len1=strs.size(),i,j;
        bool print=false;
        if(len1==1) return strs[0];
        bool good=true;
        string result;
        //loop all strings
        for(i=0;i<len1;i++) minlen=minlen<strs[i].size()?minlen:strs[i].size();
        if(print)   cout<<"min length:"<<minlen<<endl;
        i=0;
        while(good && i<minlen)   {
            if(good)    {
                j=1;
                while(good && j<len1)   {
                    good=(strs[j].at(i)==strs[0].at(i));
                    j++;
                }
            }
            if(good)    result+=strs[0].at(i);
            i++;
        }
        return result;
    }
};

/*
Runtime
0
ms
Beats
100.00%
Analyze Complexity
Memory
11.78
MB
Beats
84.31%

*/