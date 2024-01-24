'''
Possible To Achieve Target Sum
Given a set of integers and a target value k, find whether there is a non-empty subset that sums up to k.

Example One
{
"arr": [2, 4, 8],
"k": 6
}
Output:

1
Because 2 + 4 = 6.

Example Two
{
"arr": [2, 4, 6],
"k": 5
}
Output:

0
Because no subset of numbers from the input sums up to 5.

Notes
Constraints:

1 <= size of the input array <= 18
-1012 <= elements of the array, k <= 1012
'''
from typing import List

def check_if_sum_possible(arr, k):
    """
    Args:
     arr(list_int64)
     k(int64)
    Returns:
     bool
    """
    # Write your code here.
    return []