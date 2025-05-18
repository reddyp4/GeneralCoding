/*
253. Meeting Rooms II
Attempted
Medium
Topics
Companies
Hint
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
*/
class Solution {
    public:
        int minMeetingRooms(vector<vector<int>>& intervals) {
            int i=0,len1=intervals.size(),rooms=1;
            if(len1==0) return 0;
            if(len1==1) return 1;
            sort(intervals.begin(),intervals.begin()+len1);
            while(i<len1)
            {
                while(i<len1-1 && (intervals[i+1][0]<intervals[i][1]))
                {
                    //overlap, need room
                    rooms++;i++;
                }
                i++;
            }
            return rooms;
        }
    };

/*

*/