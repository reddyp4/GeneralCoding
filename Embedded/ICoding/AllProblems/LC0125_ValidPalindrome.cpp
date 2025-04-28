/*
125. Valid Palindrome
Solved
Easy
Topics
Companies
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
*/

class Solution {
    public:
        bool isPalindrome(string s) {
            int len1=s.length(),left=0,right,i=0;
            int flagPrint = 0;
            if(len1<=1) return true;
            if(flagPrint)   cout<<"Original string:"<<s<<endl;
            /* 1. Convert to lower */
            for(int i=0;i<len1;i++) s[i]=tolower(s[i]);
            if(flagPrint)   cout<<"Converted string:"<<s<<endl;
            /* 2. Remove non-chars */
            while(i<len1)
            {
                if((s[i]>='a' && s[i]<='z')  || (s[i]>='0' && s[i]<='9')) i++;
                else
                {
                    if(flagPrint)   cout<<"i:"<<i<<"s[i]:"<<s[i]<<endl;
                    s.erase(i,1);
                    len1--;
                }
            }
            if(flagPrint)   cout<<"Converted string:"<<s<<endl;
            len1=s.length();
            if(len1<=1)    return true;
            right=len1-1;
            /* 3. two pointer, from either ends */
            while(left<right && (s[left]==s[right]))
            {
                left++;right--;
            }
            if(flagPrint)   cout<<"left:"<<left<<"right:"<<right<<endl;
            if(s[left]!=s[right]) return false;
            return true;
        }
    };

/*
Runtime
50
ms
Beats
7.45%
Analyze Complexity
Memory
9.93
MB
Beats
58.47%
*/