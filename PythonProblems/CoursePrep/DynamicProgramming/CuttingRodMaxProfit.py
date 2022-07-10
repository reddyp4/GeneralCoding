"""
Cutting rod to maximize profit
Given a rod of length N inches and an array of prices with all pieces of size <=N, determine the 
maximum value obtainable by cutting up the rod and selling the pieces

Example input
rod_length = 4
prices = [0,2,5,7,8]
lenghts = [0,1,2,3,4]
Explanation: 1-inch piece sell for $2, a piece of 2 inch size will sell of $5

Is this - an optimization problem? counting problem? 
It is optimization = "maximum value"
How many ways to cut rod?

https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/
Given a rod of length N inches and an array of prices, price[] that contains prices of all pieces of size smaller than N. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example 1:

Input:
N = 8
Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
Output:
22
Explanation:
The maximum obtainable value is 22 by
cutting in two pieces of lengths 2 and 
6, i.e., 5+17=22.
Example 2:

Input:
N=8
Price[] = {3, 5, 8, 9, 10, 17, 17, 20}
Output: 24
Explanation: 
The maximum obtainable value is 
24 by cutting the rod into 8 pieces 
of length 1, i.e, 8*3=24. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function cutRod() which takes the array A[] and its size N as inputs and returns the maximum price obtainable.


Expected Time Complexity: O(N2)
Expected Auxiliary Space: O(N)


Constraints:
1 ≤ N ≤ 1000
1 ≤ Ai ≤ 105
"""

#User function Template for python3

class Solution:
    def cutRod(self, price, n):
        #Array initialization
        finalArr = [0]*n
        #Base case condition
        finalArr[0] = 0
        len_price = len(price)
        #Loops
        for rod_size in range(1,n+1):    #run for all values, python limits at n
            #initializing to zero, or price but if n>price_list
            finalArr[rod_size]=0
            for cut_size in range(0,rod_size+1):    #run for all price lists
                #other way for j in range(0,i):
                #no need to check if j>i
                #basic dp logic
                finalArr[rod_size] = max(finalArr[rod_size],price[cut_size]+finalArr[rod_size-cut_size])
            #Timecomplexity: n*n
            #Spacecomplexity: n
        return finalArr[n]


#{ 
#  Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.cutRod(a, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends

