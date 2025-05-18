/*
252. Meeting Rooms
Solved
Easy
Topics
Companies
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106

*/

class Solution {
    public:
        bool canAttendMeetings(vector<vector<int>>& intervals) {
            int len1=intervals.size(),i=0;
            if(len1<=1) return true;
            sort(intervals.begin(),intervals.begin()+intervals.size());
            while(i<len1-1)
            {
                //found overlapping, return false
                if(intervals[i+1][0]<intervals[i][1])
                    return false;
                i++;
            }
            return true;
        }
    };

/*
Runtime 0ms
Beats 100.00%
Memory 16.01MB
Beats 23.43%
*/