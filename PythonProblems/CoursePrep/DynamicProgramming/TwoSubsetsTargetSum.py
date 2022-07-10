"""
Given an array, does it have two subsets which has two equal sums?

"""



def can_partition(nums:int[]):
    N = len(nums)
    sum_all = sum(nums)

    if(sum_all.is_odd()):
        return False
    
    T = int(sum_all/2)

    dp = bool[N][T+1]

    num_cols = T+1
    num_rows = N

    #Base case
    for j in range(0,num_cols+1):
        dp[0][j] = True if nums[j]==T else False
    for i in range(0,num_rows):
        dp[i][0] = True
    #dp loop
    for i in range(1,N):
        cur_nums = nums[i]
        for j in range(1,T):
            exclude = dp[i-1][j]
            #include = dp[i-1][j-nums[i]]
            include = dp[i-1][j-cur_nums] if j-cur_nums >=0 else False
            dp[i][j] = exclude | include
    
    return dp[N-1][T]

#Time Complexity
#Number of iterations = N*T
#Space Complexity
#dp matrix = 2D array of N*T
