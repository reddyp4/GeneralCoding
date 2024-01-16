'''
59. Spiral Matrix II
Solved
Medium
Topics
Companies
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20

'''

class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        #Similar to spiral problem
        result=[ [0]*n for i in range(n) ]
        rowStart,rowEnd,colStart,colEnd=0,n-1,0,n-1
        count=n*n
        while(count>0):
            if(count>0 and colEnd>=colStart):
                for index in range(colStart,colEnd+1):
                    result[rowStart][index]=n*n-count+1
                    count-=1
            rowStart+=1
            #print("result1:",result)
            if(count>0 and rowEnd>=rowStart):
                for index in range(rowStart,rowEnd+1):
                    result[index][colEnd]=n*n-count+1
                    count-=1
            colEnd-=1
            #print("result1:",result)
            if(count>0 and colEnd>=colStart):
                for index in range(colEnd,colStart-1,-1):
                    result[rowEnd][index]=n*n-count+1
                    count-=1
            rowEnd-=1
            #print("result1:",result)
            if(count>0 and rowEnd>=rowStart):
                for index in range(rowEnd,rowStart-1,-1):
                    result[index][colStart]=n*n-count+1
                    count-=1
            colStart+=1
            #print("result1:",result)
        return result

'''
Notice the pattern and pseudocode for matrix modifications
        while(count>0):
            if(count>0 and colEnd>=colStart):
                for index in range(colStart,colEnd+1):
                    #do
                    count-=1
            rowStart+=1
            #print("result1:",result)
            if(count>0 and rowEnd>=rowStart):
                for index in range(rowStart,rowEnd+1):
                    #do
                    count-=1
            colEnd-=1
            #print("result1:",result)
            if(count>0 and colEnd>=colStart):
                for index in range(colEnd,colStart-1,-1):
                    #do
                    count-=1
            rowEnd-=1
            #print("result1:",result)
            if(count>0 and rowEnd>=rowStart):
                for index in range(rowEnd,rowStart-1,-1):
                    #do
                    count-=1
            colStart+=1
'''