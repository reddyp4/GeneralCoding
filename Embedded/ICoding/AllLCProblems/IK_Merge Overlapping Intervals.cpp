/*
Merge Overlapping Intervals
Given time intervals, merge all pairs of overlapping ones until no intervals overlap. Output should contain only mutually exclusive intervals.

All the intervals are closed intervals, i.e. the lower and upper limits are inclusive.

Example One
{
"intervals": [
[1, 3],
[5, 7],
[2, 4],
[6, 8]
}
Output:

[
[1, 4],
[5, 8]
]
[1, 3] and [2, 4] were overlapping, so they have been merged and became [1, 4].
[5, 7] and [6, 8] have been merged and became [5, 8].

Example Two
{
"intervals": [
[100, 154],
[13, 47],
[1, 5],
[2, 9],
[7, 11],
[51, 51],
[47, 50]
]
}
Output:

[
[1, 11],
[13, 50],
[51, 51],
[100, 154]
]
[1, 5] and [2, 9] have been merged and became [1, 9].
[1, 9] and [7, 11] have been merged and became [1, 11].
[13, 47] and [47, 50] have been merged and became [13, 50].
[51, 51] and [100, 154] did not overlap with any others, so they were kept unchanged.

Notes
Intervals in the input come in no particular order.
Order of intervals in the output does not matter.
Constraints:

1 <= number of input intervals <= 105
-109 <= lower limit of an interval <= upper limit of an interval <= 109
*/


vector<vector<int>> get_merged_intervals(vector<vector<int>> &intervals) {
    // Write your code here.
    if(intervals.size()<=1) return intervals;
    int i=0,len1=0;
    sort(intervals.begin(),intervals.begin()+intervals.size());
    len1=intervals.size();
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
