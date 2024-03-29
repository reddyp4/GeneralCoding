'''
118. Pascal's Triangle
Solved
Easy
Topics
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30
'''
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result=[]
        current=[1]
        result.append(current[:])
        if(numRows==1):
            return result
        current=[1,1]
        result.append(current[:])
        if(numRows==2):
            return result
        for i in range(3,numRows+1):
            newcurrent=[1]
            for j in range(1,len(current)):
                newcurrent.append(current[j]+current[j-1])
            newcurrent.append(1)
            result.append(newcurrent[:])
            current=newcurrent
        return result