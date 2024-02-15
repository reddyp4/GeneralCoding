'''
Robbery
There are n houses built in a line, each of which contains some value in it. A thief is going to steal the maximal value in these houses, but he cannot steal in two adjacent houses because the owner of a stolen house will tell his two neighbours on the left and right side. What is the maximal stolen value?

For example, if there are four houses with values [6, 1, 2, 7], the maximal stolen value is 13, when the first and fourth houses are stolen.

Example
{
"values": [6, 1, 2, 7]
}
Output:

13
Steal from the first and the last house.

Notes
Constraints:
'''



def maximum_stolen_value(values):
    """
    Args:
     values(list_int32)
    Returns:
     int32
    """
    # Write your code here.
    #Traditional dp
    if(len(values)==1):
        return values[0]
    dp={}
    dp[0]=values[0]
    dp[1]=max(values[0],values[1])
    for i in range(2,len(values)):
        dp[i]=max(dp[i-2]+values[i],dp[i-1])
    return dp[len(values)-1]

