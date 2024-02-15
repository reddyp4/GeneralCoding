'''
Jump Game
Given a list of maximum jump lengths from different houses, determine if you can reach the last house in one or more jumps starting from the first one.

Maximum jump length of 2 from a house, for example, means that you can either jump to the next house or to the one after next.

Example One
{
"maximum_jump_lengths": [2, 3, 1, 0, 4, 7]
}
Output:

1
You can reach the last house in the following way:

Example one

Example Two
{
"maximum_jump_lengths": [3, 1, 1, 0, 2, 4]
}
Output:

0
You cannot make it past house at index 3. Maximum jump length of 0 from that house means that you cannot jump further from it.

Notes
Constraints:

0 <= jump length <= 105
1 <= number of houses <= 105
'''


def can_reach_last_house(maximum_jump_lengths):
    """
    Args:
     maximum_jump_lengths(list_int32)
    Returns:
     bool
    """
    # Write your code here.
    #Idea, create a dp matrix, turn on all numbers from index, if dp[index]==1,
    #of course, dp[0]=1
    len1=len(maximum_jump_lengths)
    dp=[0]*len1
    dp[0]=1
    for i in range(len1):
        if(dp[i]==1):
            for j in range(1,maximum_jump_lengths[i]+1):
                if((i+j)<len1):
                    dp[i+j]=1
    return (dp[len1-1]==1)

#array = [2, 3, 1, 0, 4, 7]
array = [3, 1, 1, 0, 2, 4]

if(can_reach_last_house(array)):
    print("Can reach!")
else:
    print("Cannot reach!")

'''
Timie limit excceded:
'''