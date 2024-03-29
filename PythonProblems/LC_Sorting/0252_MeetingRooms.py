''''
252. Meeting Rooms

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
'''
#Method1: Sort by first element
#Loop i, check if i,1 > i+1,0, if yes return False
#Yuval: yscharf@gmail.com

from typing import List

class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
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
sol=Solution()
print(f"Intervals:{intervals}")
result = sol.canAttendMeetings(intervals)
if(result==True):
    print("Can attend!")
else:
    print("Cant attend!")
