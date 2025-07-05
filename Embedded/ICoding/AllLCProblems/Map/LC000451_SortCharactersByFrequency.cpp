/*
451. Sort Characters By Frequency
Solved
Medium
Topics
conpanies icon
Companies
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
*/
/*
M1: Count, put in map, sort map by value, make new string
M2: 
*/

class Solution {
public:
    string frequencySort(string s) {
        if(s.length()==1)   return s;
        map<char,int> myMap;
        for(int i=0;i<s.length();i++)   {
            myMap[s[i]]++;
            //cout<<"myMap[key]:"<<myMap[s[i]]<<endl;
        }
        vector<pair<char,int>> vec;
        for(auto &key:myMap) vec.push_back(key);
        //cout<<"vec[0]:"<<vec[0]<<endl;
        sort(vec.begin(),vec.end(),[](pair<char,int>&a,pair<char,int>&b){return a.second>b.second;});
        string result;
        for(int i=0;i<vec.size();i++)   {
            for(int j=0;j<vec[i].second;j++)
                result+=vec[i].first;
        }
        return result;
    }
};
/*
Runtime
7
ms
Beats
21.85%
Analyze Complexity
Memory
10.89
MB
Beats
80.77%
*/