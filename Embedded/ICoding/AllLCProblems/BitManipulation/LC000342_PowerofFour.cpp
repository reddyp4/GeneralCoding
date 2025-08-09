/*
342. Power of Four
Solved
Easy
Topics
conpanies icon
Companies
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?
*/
/*
Power of 4, log(4)!=0
Keep dividing by 4, i.e. right shift by two bits
1, 100, 10000 ... 
and not 10, 1000
*/
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        //cout<<"ChecK:"<<n<<",n-1:"<<n-1<<",&:"<<((n&(n-1))==0)<<endl;
        if(!((n&(n-1))==0))   return false;
        //cout<<"Second ChecK"<<endl;
        while(n>1) {
            //cout<<","<<n;
            n>>=2;
        }
        return(n&0x1);
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
7.64
MB
Beats
98.35%
*/