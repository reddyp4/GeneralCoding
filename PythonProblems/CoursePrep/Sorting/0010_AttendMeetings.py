''''
Attend Meetings
Given a list of meeting intervals where each interval consists of a start and an end time, check if a person can attend all the given meetings such that only one meeting can be attended at a time.

Example One
{
"intervals": [[1, 5], [5, 8], [10, 15]]
}
Output:

1
As the above intervals are non-overlapping intervals, it means a person can attend all these meetings.

Example Two
{
"intervals": [[1, 5], [4, 8]]
}
Output:

0
Time 4 - 5 is overlapping in the first and second intervals.

Notes
A new meeting can start at the same time the previous one ended.
Constraints:

1 <= number of intervals <= 105
0 <= start time < end time <= 109
'''

from typing import List


def can_attend_all_meetings(intervals):
    """
    Args:
     intervals(list_list_int32)
    Returns:
     int32
    """
    # Write your code here.
    size1=len(intervals)
    newlist = sorted(intervals,key=lambda x: int(x[0]))
    print(f"newlist:{newlist}")
    #Check if each element is less than next
    i=0
    while(i < size1-1):
        if(newlist[i][1]>newlist[i+1][0]):
            return False
        i=i+1
    return True

#intervals = [[7,10],[2,4]]
intervals = [[5,8],[6,8]]
print(f"Intervals:{intervals}")
result = can_attend_all_meetings(intervals)
if(result==True):
    print("Can attend!")
else:
    print("Cant attend!")
