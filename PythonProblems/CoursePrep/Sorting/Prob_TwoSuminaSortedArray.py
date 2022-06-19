'''
2 Sum In A Sorted Array
Given an array sorted in non-decreasing order and a target number, find the indices of the two values from the array that sum up to the given target number.

Example
{
"numbers": [1, 2, 3, 5, 10],
"target": 7
}
Output:

[1, 3]
Sum of the elements at index 1 and 3 is 7.

Notes
In case when no answer exists, return an array of size two with both values equal to -1, i.e., [-1, -1].
In case when multiple answers exist, you may return any of them.
The order of the indices returned does not matter.
A single index cannot be used twice.
Constraints:

2 <= Array Size <= 105.
-105 <= Array Elements <= 105.
-105 <= Target Number <= 105.
Array can contain duplicate elements.
'''
debug = 0

from typing import List

def pair_sum_sorted_array(numbers: List[int], target:int):
    """
    Args:
     numbers(list_int32)
     target(int32)
    Returns:
     list_int32
    """
    # Write your code here.
    final=[]
    left=0
    right=len(numbers)-1
    print(f"{left,right}")
    while(left<right):
        if(debug==1):
            print(f"{numbers[left],numbers[right],target}")
        if((numbers[left]+numbers[right])==target):
            final.append(left)
            final.append(right)
            return final
        elif((numbers[left]+numbers[right])>target):
            right=right-1
        else:
            left=left+1
    return [-1,-1]


numbers = [1, 2, 3, 5, 10]
target = 7
sol=pair_sum_sorted_array(numbers,target)
print(f"numbers={numbers},target={target},sol={sol}")
