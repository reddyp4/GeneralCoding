'''
1207. Unique Number of Occurrences
Easy
4.4K
104
company
Apple
company
Amazon
company
Google
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
Example 2:

Input: arr = [1,2]
Output: false
Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
 

Constraints:

1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
'''

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        #M1: Put occurence in dict:[key=element]:value=occurence
        #Start with each value, put in dict if already exists, then not unique
        if(len(arr)==1):
            return True
        d={}
        for index,elem in enumerate(arr):
            if(elem in d):
                d[elem]=d[elem]+1
            else:
                d[elem]=1
        occ={}
        for key in d:
            if(d[key] in occ):
                return False
            else:
                occ[d[key]]=1
        return True

'''
Two hashmaps/dicts

'''