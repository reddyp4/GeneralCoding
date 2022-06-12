''''
Implement Merge Sort
Given a list of numbers, sort it using the Merge Sort algorithm.

Example
{
"arr": [5, 8, 3, 9, 4, 1, 7]
}
Output:

[1, 3, 4, 5, 7, 8, 9]

Notes
Constraints:

1 <= length of the given list <= 105
-109 <= number in the list <= 109
'''

from typing import List

def swap(nums: List[int],i,j):
    c=nums[j]
    nums[j]=nums[i]
    nums[i]=c

def merge_sort(arr: List[int], start, end) -> List[int]:
    """
    Args:
     arr(list_int32)
    Returns:
     list_int32
    """
    # Write your code here.
    print(f"Entering merge_sort:start={start},end={end}")
    if(start==end):
        #length=1
        print(f"reached one elemtn,{arr[start]}")
        return (arr[start])
    pivot = (int)(start + (end-start)/2)
    #merge_sort on left first
    #merge_sort on right second
    final1=[]
    final2=[]
    final1 = merge_sort(arr,start,pivot)
    final2 = merge_sort(arr,pivot+1,end)
    if(start==pivot):
        size1=1
    else:
        size1=len(final1)
    if((pivot+1)==end):
        size2=1
    else:
        size2 = len(final2)
    print(f"final1={final1},size={size1}")
    print(f"final2={final2},size={size2}")
    left=0
    right=0
    print(f"Entering merge:{start},{end}")
    #Start merging the two partitions
    final=[]
    if((size1==1)&(size2==1)):
        print(f"final1={final1},final2={final2}")
        if(final1 < final2):
            final.append(final1)
            final.append(final2)
        else:
            final.append(final2)
            final.append(final1)
    else:
        while((left<=size1-1) & (right<=size2-1)):
            print(f"Merge:nums{final},left{left}/value={final1[left]},right{right}/value={final2[right]}")
            #Swap the two numbers
            if(final1[left]<final2[right]):
                final.append(final1[left])
                if(left==size1-1):
                    final.append(final2[right])
                left=left+1
            else:
                final.append(final2[right])
                if(right==size1-1):
                    final.append(final1[left])
                right=right+1
    print(f"final={final}")
    return final

arr= [5, 8, 3, 9, 4, 1, 7]
print(f"Befort sort:{arr}")
arr = merge_sort(arr,0,len(arr)-1)
print(f"After sort:{arr}")

