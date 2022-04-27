''''
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]
Output: 8
Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.
'''

from ctypes import sizeof

def missingNumber(nums):
    value = len(nums)
    missing = value
    for i, num in enumerate(nums):
        missing ^= i^num
    return missing

array = {0,27,40,43,47,22,42,34,33,31,49,10,24,28,1,46,20,37,41,11,29,4,30,13,19,3,12,23,39,44,17,25,26,5,38,2,18,48,14,16,32,21,8,6,35,7,15,36,9};
missing = missingNumber(array)

print(f"Missing number={missing}")
