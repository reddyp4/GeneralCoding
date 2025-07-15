/*
371. Sum of Two Integers
Solved
Medium
Topics
Companies
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = 2, b = 3
Output: 5
 

Constraints:

-1000 <= a, b <= 1000

*/

/*
Bit1, Bit2: add is a truth table, 0+0=0, 0+1=1+0=1, 1+1=1 and carry 1
Negative numbers just appear to add as well (2's complement=inverse+1)
Get bit1, bit2, carry
result, carry: as per truth table
assign result bit, and move to next bit
*/

class Solution {
public:
    int truth_table(int bit1,int bit2, int *carry, int print)
    {
        int result=(bit1+bit2+*carry);
        *carry=(result)>>1;
        if(print)   cout<<"Truth table: bit1:"<<bit1<<",bit2:"<<bit2<<",carry:"<<*carry<<",result:"<<result<<endl;
        return (result&0x1);
    }
    int getSum(int a, int b) {
        int carry=0,i,bit1,bit2,result=0,print=0;
        for(int i=0;i<32;i++)
        {
            bit1=(a&(0x1<<i))>>i;
            bit2=(b&(0x1<<i))>>i;
            result=((truth_table(bit1,bit2,&carry,print))<<i)|(result);
            if(print)   cout<<"bit1:"<<bit1<<",bit2:"<<bit2<<",carry:"<<carry<<",result:"<<result<<endl;
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
7.74
MB
Beats
65.23%

*/