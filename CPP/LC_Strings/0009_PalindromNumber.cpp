/*
9. Palindrome Number
Easy
9.8K
2.5K
company
Amazon
company
Adobe
company
Facebook
Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1
 

Follow up: Could you solve it without converting the integer to a string?
Accepted
3.3M
Submissions
6.1M
Acceptance Rate

*/

class Solution {
public:
    bool isPalindrome(int x) {
        std::string initial,finaln;
        initial = to_string(x);
        finaln = initial;
        reverse(finaln.begin(),finaln.end());
        return(initial==finaln);
    }
};