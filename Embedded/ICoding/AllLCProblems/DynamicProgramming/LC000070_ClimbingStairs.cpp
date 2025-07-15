/*
70. Climbing Stairs
Solved
Easy
Topics
conpanies iconCompanies
Hint

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45


 */
/*
M1: At every step, have two ways
    Recursively check, until reaching sum of n or more, if reached add to count
*/
class Solution {
public:
    int sum;
    /* Recursive approach exceeds time limit for n=45*/
    void recur(int currentSum,int finalSum) {
        if(currentSum==finalSum)   {sum++;return;}
        if(currentSum>finalSum)    return;
        recur(currentSum+1,finalSum);
        recur(currentSum+2,finalSum);
    }
    int climbStairs(int n) {
        /* Recursive Approach */
        //recur(0,n);
        //return sum;
        /* Dynamic Approach, break problem into, n and n-1 and n-2 
            result(n)=result(n-1)+result(n-2), maintains an array, or map */
        map<int,int> myMap;
        myMap[1]=1;
        myMap[2]=2;
        for(int i=3;i<=n;i++)   myMap[i]=myMap[i-1]+myMap[i-2];
        return myMap[n];
    }
};

/*
Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
7.87MB
Beats72.91%

*/