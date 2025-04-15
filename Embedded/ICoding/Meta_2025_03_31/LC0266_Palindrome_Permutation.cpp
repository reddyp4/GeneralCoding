/*
266. Palindrome Permutation
Solved
Easy
Topics
Companies
Hint
Given a string s, return true if a permutation of the string could form a palindrome and false otherwise.

 

Example 1:

Input: s = "code"
Output: false
Example 2:

Input: s = "aab"
Output: true
Example 3:

Input: s = "carerac"
Output: true
 

Constraints:

1 <= s.length <= 5000
s consists of only lowercase English letters.
*/

class Solution {
    public:
        bool canPermutePalindrome(string s) {
            map<char,int> p;
            int cnt=0;
            for(char c:s)
            {
                p[c]++;
            }
            for(auto iter=p.begin();iter!=p.end();iter++)
            {
                if(((iter->second)%2)!=0)   cnt++;
            }
            if(cnt>=2)   return false;
            return true;
        }
    };

/*
Runtime
0
ms
Beats
100.00%

Memory
8.46
MB
Beats
31.55%
*/