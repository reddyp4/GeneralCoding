/*
56. Merge Intervals
Solved
Medium
Topics
Companies
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int len1=intervals.size(),i=0;
            if(len1<=1) return intervals;
            sort(intervals.begin(),intervals.begin()+intervals.size());
            while(i<len1)
            {
                //merge all intervals that match current interval
                while(i<(len1-1) && intervals[i][1]>=intervals[i+1][0])
                {
                    intervals[i][1]=max(intervals[i][1],intervals[i+1][1]);
                    intervals.erase(intervals.begin()+i+1);
                    len1--;
                }
                i++;
                len1=intervals.size();
            }
            return intervals;
        }
    };

/*
Runtime 339ms
Beats 5.08%
Analyze Complexity
Memory 23.45MB
Beats 96.89%
*/