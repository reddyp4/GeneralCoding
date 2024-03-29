'''
6. Zigzag Conversion
Medium
7.1K
13.9K
company
Amazon
carwale
company
PayPal
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
 

Constraints:

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

'''
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        #symmetry from 0 to 2*(n-2)+1+1: n=3,2n-2=3:0,4,8,12..,; n=4,2n-2=6:0,6,12,.
        #numRows = 3, len(s)=14, step=4, zigzags = 4
        #Row1: 0,2n-2,
        if(numRows==1):
            return s
        slist=list(s)
        final=[""]*numRows
        step=2*numRows-2
        zigzags = int(len(s)/step+1)
        for j in range(zigzags-1):
            index=0
            if(step*j+index<len(s)):
                final[index]=final[index]+slist[step*j+index]
            for index in range(1,numRows-1):
                if(step*(j+1)-index<len(s)):
                    final[index]=final[index]+slist[step*j+index]+slist[step*(j+1)-index]
                elif(step*j+index<len(s)):
                    final[index]=final[index]+slist[step*j+index]
            index=numRows-1
            if(step*j+index<len(s)):
                final[index]=final[index]+slist[step*j+index]
        #last zigzags
        j=zigzags-1
        index=0
        if(step*j+index<len(s)):
            final[index]=final[index]+slist[step*j+index]
        for index in range(1,numRows-1):
            if((step*(j+1)-index)<len(s)):
                final[index]=final[index]+slist[step*j+index]+slist[step*(j+1)-index]
            elif(step*j+index<len(s)):
                final[index]=final[index]+slist[step*j+index]
        index=numRows-1
        if(step*j+index<len(s)):
            final[index]=final[index]+slist[step*j+index]
        finals=""
        for index in range(numRows):
            finals=finals+final[index]
        return finals

'''
Split into list and work each zigzag seperately
'''
