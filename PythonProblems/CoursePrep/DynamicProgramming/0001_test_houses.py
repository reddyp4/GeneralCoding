'''

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses  were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 Example 1:
 Input: nums = [1,2,3,1]
 Output: 4
 

[1 2 3 1]
1+3=4
2+1=3

[1,2,3,4,5]
1+3+5=9

Brute:
for every index, make combinations: skip the next element, 
for index in array:
   if(array is empty): return 0
   if(array is one element): return this element
   result+=value at index
   result+=call recursively for array(index+2)

[1,2,3,4,5,6...] = f(n)
f(n) = 1 + f(3...)
     = 2 + f(4...)
     = 3 + f(5...)
     ...
     pick the max of these combinations
f(n) = 5 + f(7,...) => once end of reached, store into an array, value=total at that index

dp[last element] = last element
dp[prev-last element] = prev-last element
.. start working from end to store the values


dp[index] = val at index + dp[index+2]
            dp[index+1]

[1,2,3,1]

[0 0 0 1]
[0 0 3 1]
[0 3 3 1]
[4 3 3 1]


[1,2,10,1]
[0 0 0  1]
[0 0 10 1]
[0 10 10 1]
[11 10 10 1]


start 2, index=1, max (2+dp[3], 3)
at 1 (index=0), max of two numbers
        number1: 1+dp[2]
        number2: dp[1]






'''
dp={}

def helper(array,currIndex):
    maxVal=0
    if(len(array)==0):
        return 0
    if(len(array)==1):
        return array[0]
    if(len(array)==2):
        return max(array[0],array[1])
    dp[len(array)-1]=array[-1]
    dp[len(array)-2]=max(array[-1],array[-2])
    for i in range(len(array)-2,-1,-1):
        number1 = array[i]+dp[i+2]
        number2 = dp[i+1]
        dp[i] = max(number1, number2)
    #maxVal = max(array[-1],array[-2])
    '''
    for index in range(len(array)-1-2,-1,-1):
        current=array[index]
        if((index+currIndex+2) in dp):
            current+=dp[index+currIndex+2]
        else:
            current+=helper(array[index+2:],currIndex+index+2)
        maxVal = maxVal if (maxVal>current) else current
    '''
    return dp[0]

def maxRob(array):
    if(len(array)==0):
        return 0
    if(len(array)==1):
        return array[0]
    if(len(array)==2):
        return max(array[0],array[1])
    lenArr=len(array)
    dp[lenArr-1]=array[lenArr-1]
    dp[lenArr-2]=max(array[lenArr-1],array[lenArr-2])
    return helper(array,0)
    #call for memoization
    #return helper(array,0)

#array=[1,2,3,1]
#array=[0,2,3,4,5]
#array=[5,4,3,2,1]
#array=[8,5,1,5,3,8]
#array=[1,1,1,1,1,1]
#array=[]
#array=[1]
#array=[2,3]
#array=[2,2]
print("Max value:",maxRob(array))




