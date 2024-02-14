'''
Count Ways To Reach The Nth Step
There is a staircase with n steps. A person standing at the 0-th step wants to reach the n-th one. They are capable of jumping up by certain numbers of steps at a time.

Given how the person can jump, count the number of ways they can reach the top.

Example One
{
"steps": [1, 2],
"n": 1
}
Output:

1
The person can jump up by either 1 or 2 steps at a time. The only way to reach step 1 from step 0 is to jump up one step once.

Example Two
{
"steps": [1, 2],
"n": 2
}
Output:

2
There are two distinct ways to reach step 2: {1, 1}, {2}.

Example Three
{
"steps": [2, 3],
"n": 7
}
Output:

3
There are three distinct ways to reach step 7 from step 0: {2, 2, 3}, {2, 3, 2}, {3, 2, 2}.

Notes
Constraints:

1 <= n <= 10000
1 <= length of the given list steps <= 100
1 <= element of the given list steps <= 10000
Answer will fit in a 64-bit integer
'''

dp={}


#This is recursion by checking each element
def makeSteps(current,steps,n,final):
    #print("current:",current,"n:",n,"final:",final)
    if(n==0):
        #final.append(current[:])
        #print("found!current:",current)
        return (final+1)
    if(n<0):
        return final
    for i in range(len(steps)):
        current.append(steps[i])
        #print("current2:",current,"n-i:",n-steps[i])
        final=makeSteps(current,steps,n-steps[i],final)
        #print("updated final:",final)
        current.pop()
    return final

def count_ways_to_climb(steps, n):
    """
    Args:
     steps(list_int32)
     n(int32)
    Returns:
     int64
    """
    # Write your code here.
    #populate starting dp
    final=0
    #for index in range(len(steps)):
    #    dp[steps[index]]=[]
    #    dp[steps[index]].append(steps[index])
    #print("dp:",dp)
    current=[]
    #Recursion works for 70% cases
    #final = makeSteps(current,steps,n,final)
    #print(final)
    #return final
    #DP: dp(n)+=dp(n-s_k)+1
    lenSteps=len(steps)
    dp = {}
    dp[0]=0
    dp[steps[0]]=1
    if(n==1):
        if(steps[0]!=1):
            return 0
        else:
            return 1
    for i in range(n+1):
        dp[i]=0
        for k in range(lenSteps):
            if(i==steps[k]):
                dp[i]+=1
            if((i>steps[k]) and (dp[i-steps[k]]>=1)):
                dp[i]+=dp[i-steps[k]]
    print("dp:",dp)
    return dp[n]


#count_ways_to_climb([2,3],7)
#count_ways_to_climb([1],7)
count_ways_to_climb([1,2,3,4,5],5)

'''
{
"steps": [1, 2],
"n": 2
}

{
"steps": [2, 3],
"n": 7
}
exp: 3

{
"steps": [1],
"n": 10
}
exp:1

{
"steps": [1, 2, 3, 4, 5],
"n": 5
}
exp:16
'''