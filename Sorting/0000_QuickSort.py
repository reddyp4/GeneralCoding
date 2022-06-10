''''
Quick Sort
'''
class Solution:
    def swap(self,nums,i,j):
        c=nums[j]
        nums[j]=nums[i]
        nums[i]=c

    def quickSort(self, nums: List[int],start, end) -> List[int]:
        #Pick the pivot
        #Assign left & right pointers
        #Begin swap from 


#nums = [5,2,3,1]
nums = [12,11,13,5,6,7]
print(f"Unsorted: {nums}")
sol = Solution()
sorted = sol.mergeSort(nums,0,len(nums)-1)
print(f"Sorted: {sorted}")
