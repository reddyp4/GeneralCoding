'''
Positive Negative Pair
Find all the pairs having the positive and negative value of a number in a given list of distinct numbers.

Example One
{
"nums": [3, 6, -3, -2, 2, 5, -6]
}
Output:

[
[-3, 3],
[-2, 2],
[-6, 6]
]
Example Two
{
"nums": [1, 2, 3, -4, -5]
}
Output:

[]
Notes
Return a list of pairs in any order (with respect to pairs). The negative integer should appear before the positive integer within each pair. If no such pair exists, return an empty list.

Constraints:

2 <= size of the input list <= 105
-105 <= any element of the input list <= 105
'''


def find_positive_negative_pairs(nums):
    """
    Args:
     nums(list_int32)
    Returns:
     list_list_int32
    """
    # Write your code here.
    d={}
    for index,elem in enumerate(nums):
        if elem not in d:
            d[elem]=1
    result=[]
    for index,elem in enumerate(nums):
        if elem>0 and elem in d and -elem in d:
            result.append([elem,-elem])
    return result
