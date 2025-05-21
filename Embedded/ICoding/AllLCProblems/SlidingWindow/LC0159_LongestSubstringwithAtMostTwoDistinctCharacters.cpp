/*
159. Longest Substring with At Most Two Distinct Characters
Solved
Medium
Topics
Companies

Given a string s, return the length of the longest

that contains at most two distinct characters.

 

Example 1:

Input: s = "eceba"
Output: 3
Explanation: The substring is "ece" which its length is 3.

Example 2:

Input: s = "ccaabbb"
Output: 5
Explanation: The substring is "aabbb" which its length is 5.

 

Constraints:

    1 <= s.length <= 105
    s consists of English letters.

*/

/*
@every left=index:
    right=left+1
    char1=left, move right until char2!=char1, char2=[right]
    now move right until char3 comes

*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int left=0,right=0,len1=s.length(),maxlength=0;
        if(len1<=1) return len1;
        char char1,char2;
        right=left+1;
        maxlength=right-left;
        while(right<len1)
        {
            char1=s[left];char2=s[right];
            while(right<len1 && s[right]==s[left])    right++;
            if(right==len1) 
            {
                maxlength=max(maxlength,right-left);
                break;
            }
            char2=s[right++];
            while(right<len1 && (s[right]==char1 || s[right]==char2))   right++;
            maxlength=max(maxlength,right-left);
            left++;
            right=left+1;
        }
        return maxlength;
    }
};

/*
Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
11.92MB
Beats93.85%
*/