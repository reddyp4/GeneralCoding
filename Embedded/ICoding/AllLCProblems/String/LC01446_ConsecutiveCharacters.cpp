/*
1446. Consecutive Characters
Solved
Easy
Topics
conpanies icon
Companies
Hint
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.

 

Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

class Solution {
public:
    int maxPower(string s) {
        int newmax=1,maxval=1;
        char prev=s[0];
        for(int i=1;i<s.size();i++)
        {
            if(s[i]==prev)
            {
                newmax++;
            }
            else
            {
                maxval=maxval>newmax?maxval:newmax;
                newmax=1;
                prev=s[i];
            }
        }
        maxval=maxval>newmax?maxval:newmax;
        return maxval;
    }
};

/*
Runtime
1
ms
Beats
15.96%
Analyze Complexity
Memory
9.67
MB
Beats
12.72%
*/