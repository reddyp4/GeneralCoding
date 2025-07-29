/*
2554. Maximum Number of Integers to Choose From a Range I
Solved
Medium
Topics
conpanies icon
Companies
Hint
You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.

 

Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
 

Constraints:

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109
*/
/*
Bruteforce
    Start counting, if in bonned, dont use, else use
    update sum
    exit once sum>maxSum
Improvement
    hash of banned
    or sort and maintain pointer
Trip-up: 
    repeated elements in banned
*/
class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        /* Sort solution */
        sort(banned.begin(),banned.end());
        int count=0,i=1,ibanned=0,sum=0;
        //for(i=0;i<banned.size();i++)    cout<<","<<banned[i];
        i=1;
        while(i<=n) {
            if(ibanned!=banned.size() && banned[ibanned]==i)  {
                while(ibanned!=banned.size() && banned[ibanned]==i)   ibanned++;
                i++;
            }
            else    {
                if((sum+i)>maxSum)  break;
                //cout<<"i:"<<i<<",banned[ibanned]:"<<banned[ibanned]<<endl;
                sum+=i;
                count++;
                i++;
            }
        }
        return count;
    }
};

/*
Runtime
63
ms
Beats
83.80%
Analyze Complexity
Memory
117.44
MB
Beats
98.43%

*/