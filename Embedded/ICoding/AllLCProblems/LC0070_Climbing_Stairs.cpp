/*
70. Climbing Stairs
Solved
Easy
Topics
conpanies icon
Companies
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
Traditional approach of recursion takes long
/*
start with 1, call recursively until the sum is >=n, if equal return

class Solution {
public:
    //hash-map
    map<int,int> myMap;
    int check_step(int current, int n, int total)   //total=current methods, current=current sum, n=number to be reached
    {
        //if(myMap.count(current)>0)  return myMap[current];
        //cout<<"current:"<<current<<",total:"<<total<<endl;
        if(current==n)  {return (total+1);}
        if(current>n)   return total;
        total=check_step(current+1,n,total);
        total=check_step(current+2,n,total);
        return total;
    }

    int climbStairs(int n) {
        int total=check_step(0,n,0);
        return total;
    }
};

*/

/*
Memoization, start doing from 1 to n, if exists just pick up value
*/

class Solution {
public:
    map<int,int> myMap;
    int climbStairs(int n) {
        myMap[1]=1;
        myMap[2]=2;
        for(int i=3;i<=n;i++)
        {
            myMap[i]=myMap[i-1]+myMap[i-2];
        }
        return myMap[n];
    }
};

/*
Runtime
2
ms
Beats
5.17%
Analyze Complexity
Memory
8.08
MB
Beats
55.64%
*/