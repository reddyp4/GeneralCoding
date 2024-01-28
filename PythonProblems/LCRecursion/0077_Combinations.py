'''
77. Combinations
Solved
Medium
Topics
Companies
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:

1 <= n <= 20
1 <= k <= n
'''
class Solution:
    def recur(self, current, arr, k, final):
        if(len(current)==k):
            final.append(current[:])
            return
        for index in range(len(arr)):
            val=arr[index]
            current.append(val)
            #arr.pop(index)
            self.recur(current,arr[index+1:],k,final)
            current.pop()
            #arr.insert(index,val)
    
    def combine(self, n: int, k: int) -> List[List[int]]:
        final=[]
        arr=list(range(1,n+1))
        self.recur([],arr,k,final)
        return final

'''
Recursion:
No need of hashmap, since array is sorted
'''