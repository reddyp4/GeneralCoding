'''
First Repeating Element
Find the first repeating element in a given list of numbers.

Example One
{
"nums": [10, 8, 3, 3, 8]
}
Output:

8
Example Two
{
"nums": [10, 5, 4, 9, 120]
}
Output:

-1
Notes
If there are multiple repeating elements, return the one whose index of the first occurrence is the smallest.
Return -1 if there is no repeating element in the input list.
Constraints:

1 <= size of the input list <= 105
0 <= any element of the input list <= 105
'''


#!/usr/bin/env python
import json
import math
import os
import random
import re
import sys
import traceback
from collections import deque

sys.setrecursionlimit(2000009)

def find_first_repeating_element(nums):
    """
    Args:
     nums(list_int32)
    Returns:
     int32
    """
    # Write your code here.
    d = {}
    for index,elem in enumerate(nums):
        if(elem in d):
            d[elem]=d[elem]+1
        else:
            d[elem]=1
    for index, elem in enumerate(nums):
        if(d[elem]>1):
            return elem
    return -1

def output_int32(argument):
    if argument is None:
        sys.stderr.write("Return value contains None where integer is expected")
        exit()
    if type(argument) is not int:
        sys.stderr.write(f"Return value contains {type(argument).__name__} '{argument}' where integer is expected")
        exit()
    sys.stdout.write(f'{argument}')


def input_int32(data):
    argument = int(data)
    return argument


def input_list_int32(data):
    argument = []
    for json_array_item in data:
        argument.append(input_int32(json_array_item))
    return argument


if __name__ == '__main__':
    try:
        data = json.load(sys.stdin)
        nums = input_list_int32(data['nums'])
    except Exception as ex:
        sys.stderr.write('reading-input-failed-json\n')
        traceback.print_exc()
        raise ex

    original_out = sys.stdout
    sys.stdout = sys.stderr
    result = find_first_repeating_element(nums)
    sys.stdout = original_out
    output_int32(result)
    sys.stdout.write('\n')

'''
Hashtable lookup: O(n)

Cracking the coding interview
1) Speak more
2) Clarify with more questions
3) Get fmiliar more with code
4) Test cases
5) Take hints 

'''

