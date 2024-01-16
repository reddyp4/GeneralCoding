'''
54. Spiral Matrix
Solved
Medium
Topics
Companies
Hint
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
'''
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ROWS=len(matrix)
        COLS=len(matrix[0])
        final=[]
        rowStart,rowEnd,colStart,colEnd=0,ROWS-1,0,COLS-1
        count=ROWS*COLS
        while(rowEnd>=rowStart and colEnd>=colStart):
            #print("rowStart:",rowStart,"rowEnd:",rowEnd,"colStart:",colStart,"colEnd:",colEnd)
            #first row
            if(count>0):
                #print("1")
                for index in range(colStart,colEnd+1):
                    i,j=rowStart,index
                    final.append(matrix[i][j])
                    count-=1
            rowStart+=1
            if(count>0):
                #print("2")
                for index in range(rowStart,rowEnd+1):
                    i,j=index,colEnd
                    final.append(matrix[i][j])
                    count-=1
            colEnd-=1
            if(count>0):
                #print("3")
                for index in range(colEnd,colStart-1,-1):
                    i,j=rowEnd,index
                    final.append(matrix[i][j])
                    count-=1
            rowEnd-=1
            if(count>0):
                #print("4")
                for index in range(rowEnd,rowStart-1,-1):
                    i,j=index,colStart
                    final.append(matrix[i][j])
                    count-=1
            #update
            colStart+=1
        return final

'''
Use traversal
trick: Use a count=mxn and decrement
'''