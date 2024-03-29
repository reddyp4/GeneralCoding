'''
277. Find the Celebrity
Medium
Topics
Companies
Hint
Suppose you are at a party with n people labeled from 0 to n - 1 and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know the celebrity, but the celebrity does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. You are only allowed to ask questions like: "Hi, A. Do you know B?" to get information about whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) that tells you whether a knows b. Implement a function int findCelebrity(n). There will be exactly one celebrity if they are at the party.

Return the celebrity's label if there is a celebrity at the party. If there is no celebrity, return -1.

 

Example 1:


Input: graph = [[1,1,0],[0,1,0],[1,1,1]]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
Example 2:


Input: graph = [[1,0,1],[1,1,0],[0,1,1]]
Output: -1
Explanation: There is no celebrity.
 

Constraints:

n == graph.length == graph[i].length
2 <= n <= 100
graph[i][j] is 0 or 1.
graph[i][i] == 1
 

Follow up: If the maximum number of allowed calls to the API knows is 3 * n, could you find a solution without exceeding the maximum number of calls?
'''

# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

class Solution:
    def findCelebrity(self, n: int) -> int:
        '''
        #Bruteforce: traverse entire array
        #maintain a connToIndex, connFromIndex. Once connFromIndex>2, skip this index and move on
        connToIndex,connFromIndex=[0]*n,[0]*n
        index,k=0,0
        while(index<n):
            k=0
            while(k<n):
                if(knows(index,k)):
                    #print("knows:","index:",index,"k:",k)
                    connToIndex[k]+=1
                    connFromIndex[index]+=1
                k+=1
            index+=1
        #celebrity should where both arrays are equal to 1
        #print("connFromIndex:",connFromIndex,"connToIndex:",connToIndex)
        for index in range(n):
            if(connToIndex[index]==n and connFromIndex[index]==1):
                return index
        return -1
        '''
        #Optimal method: Traverse first row only. n calls. Traverse first column only. 
        # if 0 knows 1, 0 is not a celebrity. If not, 1 is not a celebrity. Work to reduce the list
        left,right,chosen=0,n-1,-1
        while(left<right):
            if(knows(left,right)):
                left+=1
            else:
                right-=1
        #Now check for left/right
        for index in range(n):
            if(knows(left,index) and index!=left) or (not knows(index,left) and index!=left):
                return -1
        return left
'''
Bruteforce: make all calls
connToIndex=n-1 and connFromIndex=1
Failing on time limit, Case 168/180

Elegant is based on following premise:
if left knows right, left is not a celebrity; else right is not a celebrity
In the end, still need to check for left doesnt know everyone and everyone knows left

'''