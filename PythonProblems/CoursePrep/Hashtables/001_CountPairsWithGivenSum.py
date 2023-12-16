'''
Count Pairs With Given Sum
Count the number of pairs whose sum equals the given required sum.

Example One
{
"nums": [1, 2, 3, 4],
"required_sum": 5
}
Output:

2
nums[0] + nums[3] = 1 + 4 = 5
nums[1] + nums[2] = 2 + 3 = 5

Example Two
{
"nums": [2, 2, 2, 2, 2],
"required_sum": 4
}
Output:

10
Each 2 will produce a sum of 4 with any 2.

Notes
Constraints:

1 <= size of the input list <= 105
1 <= any element of the input list <= 106
1 <= required sum <= 107
'''


def count_pairs_with_given_sum(nums, required_sum):
    """
    Args:
     nums(list_int32)
     required_sum(int32)
    Returns:
     int64
    """
    # Write your code here.
    d={}
    for index,elem in enumerate(nums):
        if elem in d:
            d[elem]=d[elem]+1
        else:
            d[elem]=1
    pair = 0
    for index,elem in enumerate(nums):
        val = required_sum - elem
        if val == elem and val in d:
            pair = pair + d[val] - 1
            continue
        if val in d:
            pair = pair + d[val]
    return int(pair/2)   #counted twice
