'''
219. Contains Duplicate II
Easy
5.7K
2.9K
company
Facebook
company
Adobe
company
Amazon
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
'''

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if(k<=1 and len(nums)==1):
            return False
        #M2: Hashtable, {}
        hashtable = {}
        #for each element push to hashtable, and store the most recent index alone
        for index, element in enumerate(nums):
            #check if element exists in hashtable and index-valuue in hash <= k, if not add
            if(element in hashtable) and (index-hashtable[element]<=k):
                return True
            else:
                hashtable[element]=index
        return False
        '''
        #Corner case: k>=length
        if(k>=len(nums)):
            k=len(nums)-1
            for j in nums:
                if(nums.count(j)>=2):
                    return True
        for i in range(len(nums)-k):
            newset = set()
            for j in range(i,i+k+1):
                if(nums[j] in newset):
                    return True
                newset.add(nums[j])
        return False
        #M1: Bruteforce - sliding Window for each element, and check count of element in every window: Time limit exceeded
        for i in range(len(nums)-k):
            #new array is nums[i,i+k], search if any element has count of 2 or more, time limit issue
            newlist = set(nums[i:i+k+1])
            if(len(newlist)!=len(nums[i:i+k+1])):
                return True
            #Time exceeded
            for j in range(k):
                if(newlist[j]==newlist[j+1]):
                    return True
            #new array is nums[i,i+k], search if any element has count of 2 or more, time limit issue
            for j in range(i,i+k+1):
                if(newlist.count(nums[j])>=2):
                    return True
        return False
        '''

'''
Hashtable is used to maintain the last index
Access of hashtable is O(1)
Space is O(n) since hashtable is needed

A bit of space can be saved by using set()

A very innovative solution without hashtable.
Get index of value at 0, check if that is less than k. remove that value, and continue until nums is empty!!!
'''