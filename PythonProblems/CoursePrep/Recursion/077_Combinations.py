''''
Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
'''

#Questions to ask:
#duplicates?

#Method
#number of values: n*(n-1)/2? 4numberof2combinationes=6, 4*3/2=6
#Recursive call with back-tracking (limited by k)
#Similar to previous case with subsets, but now with constraints (size of k)
#Q1: How do we know we reached solution
#Q2: How do we know we are done processing with input
#base solution: return once size is k
#internal nodes: add an element, pass to fill next blank


#leaf nodes work: O(k), worst case, k=N, means O(N)
#Internal nodes work: push/pop, O(1)
# #internal nodes: worst 2^N?
# #leaf nodes: 2^N
#Time Complexity: O(N*2^N+1*2^N)=O(N.2^N)

#Call Stack
#Space complexity: O(N)

from typing import List

''''
class Solution:
    def subProblem(inputNums: List[int], partial: List[int], k: int, index: int):
        if(len(partial)==k):    #back-tracking condition
            print(partial)
            return
        elif (index==len(inputNums)):   #filled the solution already
            return
        else:   #Not filled yet
            #Exclude call
            #include call
        return
    
    def combine(self, n: int, k: int) -> List[List[int]]:
        final=[]
        inputNums = [0:1:n]
        self.subProblem(inputNums,final,k,0)
        return
        
'''

debug = 0

class Solution:
    def subProblem(self, input:List[int], k:int, final: List[int],partial: List[int]):
        #BaseCase:reached k
        if(len(partial)==k):
            final.append(list(partial))
            if(debug==1):
                print(f"Base:partial={partial},final={final}")
            return
        #Else for each index push into partial
        for index in range(0,len(input)):
            #pick index and push
            if(debug==1):
                print(f"Start:index={index}:partial={partial},input={input},final={final}")
            #a=input.pop(index)
            a=input[index]
            partial.append(a)
            if(debug==1):
                print(f"Append:index={index}:partial={partial},input={input},final={final}")
            self.subProblem(input[index+1:],k,final,partial)
            a=partial.pop()
            #input.insert(index,a)
            if(debug==1):
                print(f"End:index={index}:partial={partial},input={input},final={final}")

    def combine(self, n: int, k: int) -> List[List[int]]:
        final=[]
        partial=[]
        input=list(range(1,n+1))
        #print(f"input={input[2:]}")
        self.subProblem(input,k,final,partial)
        return final
        

n=4
k=2
sol=Solution()
final=sol.combine(n,k)
print(f"final:{final}")

