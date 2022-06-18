''''
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

#Method1: Create sets of two at bottom part of tree
# Each worker index (popped), check if sum matches
#InitialSet: Given set
#Each worker picks up key at index
#If ReducedSet size==1, check sum <-base case
#Otherwise call next worker to breakdown
#ReducedSet: InitialSet-Above element
#Check sum, proceed to recursive helper
#Pop

from typing import List

printvar =1

def subProblem(arr: List[int], partialList: List[int], reducedList: List[int], sum: int) -> int:
    #Base case, reached array size of two if target is met
    if(len(partialList)==2):
        if((partialList[0]+partialList[1])==sum):
            a=1
        else:
            a=0
        print(f"Len2: partialList={partialList},reducedList={reducedList},found={a}")
        return a
    #Pick index-val
    #pick element at index
    for index in range(0,len(reducedList)):
        #Make partialList, first element is at index
        #Second element call recursion
        print(f"For index={index}: partialList={partialList},reducedList={reducedList}")
        a=reducedList.pop(index)
        partialList.append(a)
        print(f"For index={index}: partialList={partialList},reducedList={reducedList}")
        found=subProblem(arr,partialList,reducedList,sum)
        print(f"Finished index={index}: partialList={partialList},reducedList={reducedList},found={found}")
        if(found==0): #keep moving up the tree
            print(f"For index={index}: partialList={partialList},reducedList={reducedList}")
            #returned, so pop and put back into array
            a=partialList.pop()
            reducedList.insert(index,a)
            print(f"For index={index}: partialList={partialList},reducedList={reducedList}")
        else:   #found so stop
            return found
    #Else, 

def check_if_sum_possible(arr, k):
    """
    Args:
     arr(list_int64)
     k(int64)
    Returns:
     bool
    """
    # Write your code here.
    partialList=[]
    reducedList=arr
    var = subProblem(arr,partialList,reducedList,k)
    return var

arr=[2, 4, 6]
k=6
var=check_if_sum_possible(arr,k)
print(f"var:{var}")
