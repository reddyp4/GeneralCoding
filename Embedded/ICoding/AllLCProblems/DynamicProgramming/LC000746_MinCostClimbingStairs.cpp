/*
746. Min Cost Climbing Stairs
Solved
Easy
Topics
conpanies iconCompanies
Hint

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

 

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999


*/
/*
M1: Start from 0, or 1
        Costn = min(Cost(n-1),cost(n-2))
    
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /* Use map to store previous */
        /*
        map<int,int> myMap;
        myMap[0]=cost[0];
        myMap[1]=cost[1];
        for(int i=2;i<cost.size();i++)  myMap[i]=min(myMap[i-1],myMap[i-2])+cost[i];
        myMap[cost.size()]=min(myMap[cost.size()-1],myMap[cost.size()-2]);
        return myMap[cost.size()];*/
        int stepm1,stepm2,i=2;
        stepm2=cost[0];
        stepm1=cost[1];
        while(i<cost.size())  {
            if(i%2==0)  stepm2=min(stepm2,stepm1)+cost[i];
            else  stepm1=min(stepm2,stepm1)+cost[i];
            i++;
        }
        return min(stepm1,stepm2);
    }
};
/*
Runtime
7ms
Beats4.16%
Analyze Complexity
Memory
19.48MB
Beats5.00%

Runtime
0ms
Beats100.00%
Analyze Complexity
Memory
17.62MB
Beats52.90%

*/