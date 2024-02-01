'''
240. Search a 2D Matrix II
Solved
Medium
Topics
Companies
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true
Example 2:


Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= n, m <= 300
-109 <= matrix[i][j] <= 109
All the integers in each row are sorted in ascending order.
All the integers in each column are sorted in ascending order.
-109 <= target <= 109
'''
class Solution:
    def recur(self, matrix, target, rowstart,rowend,colstart,colend):
        flag=False
        #print("rowstart:",rowstart,"rowend:",rowend,"colstart:",colstart,"colend:",colend)
        if(matrix[rowstart][colstart]==target) or (matrix[rowend][colstart]==target) or (matrix[rowend][colend]==target) or (matrix[rowstart][colend]==target):
            #print("Found:",target)
            return True
        if(rowstart==rowend and colstart==colend):
            return False
        if(target<matrix[rowstart][colend]):
            if(colstart<colend):
                return self.recur(matrix,target,rowstart,rowend,colstart,colend-1)
            else:
                return False
        else:
            if(rowstart<rowend):
                return self.recur(matrix,target,rowstart+1,rowend,colstart,colend)
            else:
                return False
    
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #M1: Bruteforce, seach every row and column
        #M2: Divide and conquer: in a matrix [2,2], all elements<maxtrix[2,2]. Find two submatrices between which target lies.
        # Then do a linear search in that row and column. Diagnam [m,n]->[m-1,n-1].. 
        '''
        ROW=len(matrix)
        COL=len(matrix[0])
        foundrow=-1
        foundcol=-1
        if(target>matrix[ROW-1][COL-1]) or (target<matrix[0][0]):
            return False
        if(ROW==1) and (COL==1):
            if(matrix[ROW-1][COL-1]==target):
                return True
            else:
                return False
        #Exhaust single row and single column options
        if(ROW==1) or (COL==1):
            if(ROW==1):
                index=0
                while(index<COL):
                    if(matrix[0][index]==target):
                        return True
                    index=index+1
            elif(COL==1):
                index=0
                while(index<ROW):
                    if(matrix[index][0]==target):
                        return True
                    index=index+1
            return False
        #search from 0,0; 1,1; until n,n; n==ROW-1 or n==COL-1
        m=0
        found=0
        while (m<ROW) and (m<COL):
            if(matrix[m][m]==target) or (matrix[0][m]==target) or (matrix[m][0]==target):
                return True
            if (matrix[m][0]<target) and (matrix[m][m]>target):
                #search in that row
                index=0
                while(index<m):
                    if(matrix[m][index]==target):
                        return True
                    elif (matrix[m][index]>target):
                        break
                    index=index+1
            if ((matrix[0][m]<target) and (matrix[m][m]>target)):
                #search in that column
                index=0
                while(index<m):
                    if(matrix[index][m]==target):
                        return True
                    elif (matrix[index][m]>target):
                        break
                    index=index+1
            if ((matrix[0][m]>target) and (matrix[m][0]>target)):
                #reached matrix where corners>target, target cannot be found
                return False
            #do this for m, until hitting row/column end
            m=m+1
        # if row is hit, continue transition column, m=ROW-1, transition n=ROW-1 ++
        n=ROW-1
        while (n<COL):
            if(matrix[0][n]==target) or (matrix[ROW-1][n]==target):
                return True
            if (matrix[0][n]<target) and (matrix[ROW-1][n]>target):
                #search in that column
                index=0
                while(index<ROW-1):
                    if(matrix[index][n]==target):
                        return True
                    elif(matrix[index][n]>target):
                        break
                    index=index+1
            if ((matrix[0][n]>target) and (matrix[ROW-1][0]>target)):
                return False
            n=n+1
        # do the same if column is hit, n=COL-1, transition m=COL-1 ++
        m=COL-1
        while (m<ROW):
            if(matrix[m][0]==target) or (matrix[m][COL-1]==target):
                return True
            if (matrix[m][0]<target) and (matrix[m][COL-1]>target):
                index=0
                while(index<(COL-1)):
                    if(matrix[m][index]==target):
                        return True
                    elif(matrix[m][index]>target):
                        break
                    index=index+1
            if (matrix[m][0]>target) and (matrix[m][COL-1]>target):
                return False
            m=m+1
        #if you are here, you havent found target
        return False'''
        #M4: target<matrix[0][COL-1], eliminate last column 
        #else: eliminate first row
        #Should end up with a row or 
        #corner case
        if(target< matrix[0][0] or target>matrix[len(matrix)-1][len(matrix[0])-1]):
            return False
        flag = self.recur(matrix, target,0,len(matrix)-1,0,len(matrix[0])-1 )
        return flag

'''
Use cyclesort:
if target>last elemment in first row, eliminate first row else first colum
do recusively until corners match
O(n)

'''