/*
1323. Maximum 69 Number
Solved
Easy
Topics
conpanies icon
Companies
Hint
You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

 

Example 1:

Input: num = 9669
Output: 9969
Explanation: 
Changing the first digit results in 6669.
Changing the second digit results in 9969.
Changing the third digit results in 9699.
Changing the fourth digit results in 9666.
The maximum number is 9969.
Example 2:

Input: num = 9996
Output: 9999
Explanation: Changing the last digit 6 to 9 results in the maximum number.
Example 3:

Input: num = 9999
Output: 9999
Explanation: It is better not to apply any change.
 

Constraints:

1 <= num <= 104
num consists of only 6 and 9 digits.
*/
/*
Idea: Start with MSB, change first 6 
*/
class Solution {
public:
    int maximum69Number (int num) {
        int i=num,value_to_add=0,j=1;
        if((i%10)==6)   value_to_add=j;
        i/=10;
        while(i!=0) {
            j*=10;
            if((i%10)==6)   value_to_add=j;
            i/=10;
        }
        num+=3*value_to_add;
        return num;
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
7.79
MB
Beats
99.58%
*/