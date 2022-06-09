#MergeSort
#Redo mergeSort again

from operator import le
from typing import List

class Solution:
    def swap(self,nums,i,j):
        c=nums[j]
        nums[j]=nums[i]
        nums[i]=c

    def mergeSort(self, nums: List[int],start, end) -> List[int]:
        print(f"Entering mergeSort:start={start},end={end}")
        if(start==end):
            #length=1
            print(f"reached one elemtn,{nums[start]}")
            return (nums[start])
        pivot = (int)(start + (end-start)/2)
        #MergeSort on left first
        #MergeSort on right second
        final1=[]
        final2=[]
        final1 = self.mergeSort(nums,start,pivot)
        final2 = self.mergeSort(nums,pivot+1,end)
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

#nums = [5,2,3,1]
nums = [12,11,13,5,6,7]
print(f"Unsorted: {nums}")
sol = Solution()
sorted = sol.mergeSort(nums,0,len(nums)-1)
print(f"Sorted: {sorted}")
