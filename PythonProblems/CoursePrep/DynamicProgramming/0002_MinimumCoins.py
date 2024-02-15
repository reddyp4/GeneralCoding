'''
Minimum Coins
Given a variety of coin types defining a currency system, find the minimum number of coins 
required to express a given amount of money. Assume infinite supply of coins of every type.

Example
{
"coins": [1, 3, 5],
"value": 9
}
Output:

3
Here are all the unique ways to express 9 as a sum of coins 1, 3 and 5:

1, 1, 1, 1, 1, 1, 1, 1, 1
1, 1, 1, 1, 1, 1, 3
1, 1, 1, 1, 5
1, 1, 1, 3, 3
1, 3, 5
3, 3, 3
Last two ways use the minimal number of coins, 3.

Notes
There will be no duplicate coin types in the input.

Constraints:

1 <= number of coin types <= 102
1 <= coin value <= 102
1 <= amount of money to express <= 104
'''

def minimum_coins(coins, value):
    """
    Args:
     coins(list_int32)
     value(int32)
    Returns:
     int32
    """
    # Write your code here.
    coins.sort()
    print(coins)
    if(value<coins[0]):
        return 0
    dp={}
    lenCoins=len(coins)
    for i in range(lenCoins):
        if(coins[i]==value):
            return 1
        dp[coins[i]]=1
    print("Initial dp:",dp)
    for i in range(value+1):
        #if(coins[i] in dp):
        #    continue
        dp[i]=0
        minVal=10**10
        for k in range(lenCoins):
            if(i==coins[k]):
                dp[i]=1
                minVal=1
                continue
            #print("i:",i,"i-coins[k]:",i-coins[k])
            if(i-coins[k] in dp and dp[i-coins[k]]!=0):
                minVal=minVal if (minVal<dp[i-coins[k]]+1) else dp[i-coins[k]]+1
        dp[i]=minVal
    print("dp:",dp)
    return dp[value]

#print("result:",minimum_coins([1,3,5],9))
#print("result:",minimum_coins([1, 8, 9, 2, 5],15))
#print("result:",minimum_coins([19, 42, 81, 76, 51, 96, 4, 57, 1, 48],3))
#print("result:",minimum_coins([100, 21, 98, 76, 77, 7, 88, 30, 50, 93, 43, 99, 1], 97))
print("result:",minimum_coins([83, 57, 52, 64, 65, 97, 53, 22, 74, 54, 43, 75, 8, 6, 15, 58, 12, 27, 68, 38, 2, 14, 42, 19, 26, 29, 78, 85, 93, 80, 87, 79, 92, 51, 39, 94, 34, 73, 11, 81, 69, 36, 99, 32, 66, 88, 17, 82, 55, 30, 72, 18, 3, 9, 20, 76, 46, 13, 100, 25, 59, 91, 28, 84, 21, 33, 45, 44, 89, 40, 56, 49, 95, 24, 62, 48, 90, 41, 50, 16, 61, 1, 86, 35, 77, 96, 70, 4, 10, 71, 47, 23, 5, 7, 67, 31, 37, 98, 60],9900))

'''
Use dp
coins(n)=coins(n-ck)+1 if ck in dp
else no combination at n

{
"coins": [1, 8, 9, 2, 5],
"value": 15
}
exp:3

{
"coins": [19, 42, 81, 76, 51, 96, 4, 57, 1, 48],
"value": 3
}
exp: 3

{
"coins": [100, 21, 98, 76, 77, 7, 88, 30, 50, 93, 43, 99, 1],
"value": 97
}
exp:2

{
"coins": [81, 89, 25, 80, 98, 40, 87, 77, 92, 7, 12, 96, 51, 86, 14, 67, 72, 31, 94, 37, 24, 48, 74, 29, 66, 27, 73, 78, 4, 61, 9, 57, 6, 13, 23, 26, 82, 44, 50, 55, 70, 91, 18, 75, 30, 42, 1, 65, 100, 56, 85, 3, 69, 93, 33, 16, 71, 88, 11, 36, 59, 95, 76, 90, 97, 64, 10, 43, 28, 84, 17, 2, 45, 79, 15, 22, 8, 83, 39, 19, 58, 41, 34, 62, 35, 46, 68, 63, 21, 32, 60, 99, 5, 47, 54, 49, 20],
"value": 52
}
exp:2

{
"coins": [69, 81, 37, 55, 35, 74, 5, 19, 20, 53, 85, 38, 42, 14, 3, 72, 100, 76, 13, 4, 77, 18, 78, 90, 32, 65, 22, 60, 94, 92, 51, 84, 12, 98, 25, 73, 11, 9, 63, 52, 15, 80, 56, 86, 87, 27, 75, 82, 59, 54, 89, 33, 40, 1, 6, 49, 39, 97, 28, 16, 62, 47, 23, 96, 31, 93, 7, 68, 61, 36, 8, 70, 10, 26, 17, 66, 24, 71, 79, 41, 99, 29, 30, 43, 83, 34, 46, 58, 50, 48, 95, 2, 45, 57, 44],
"value": 24
}
exp:1

{
"coins": [83, 57, 52, 64, 65, 97, 53, 22, 74, 54, 43, 75, 8, 6, 15, 58, 12, 27, 68, 38, 2, 14, 42, 19, 26, 29, 78, 85, 93, 80, 87, 79, 92, 51, 39, 94, 34, 73, 11, 81, 69, 36, 99, 32, 66, 88, 17, 82, 55, 30, 72, 18, 3, 9, 20, 76, 46, 13, 100, 25, 59, 91, 28, 84, 21, 33, 45, 44, 89, 40, 56, 49, 95, 24, 62, 48, 90, 41, 50, 16, 61, 1, 86, 35, 77, 96, 70, 4, 10, 71, 47, 23, 5, 7, 67, 31, 37, 98, 60],
"value": 9900
}
exp:99
got runtime error
'''