'''
456. 132 Pattern
Attempted
Medium
Topics
Companies
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

 

Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
 

Constraints:

n == nums.length
1 <= n <= 2 * 105
-109 <= nums[i] <= 109
'''
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        #Approach1: Bruteforce: O(n3), checking k for every [i,j], when [j]>[i]
        #Approach2: Minstack, maintain a minstack and another stack consisting of variables more than min
        minStk,stk=[],[]
        len1=len(nums)
        if(len1<=2):
            return False
        minStk.append(nums[0])
        #Build the minstack
        for i in range(1,len1):
            minStk.append(min(minStk[-1],nums[i]))
        #Traverse from end, for every greater element and add to stack until 
        stk.append(nums[-1])
        #print("minStk:",minStk)
        for i in range(len1-2,-1,-1):
            #print("i:",i,"stk:",stk)
            if(nums[i]>minStk[i]):
                #condition 13 is satisfied, so check condition 32 
                if(len(stk)==0):
                    stk.append(nums[i])     #nothing to compare, just add this element
                elif(nums[i]<stk[-1]):
                    stk.append(nums[i])     #cannot meet 32 condition, just append to stack
                elif(nums[i]>stk[-1]):
                    #32 condition satisifed, now check 12 condition
                    #print("Satisfied 12")
                    if(minStk[i]<stk[-1]):
                        return True     #satisfies 12
                    else:
                        #keep popping until reached a value satisfying 12 or lower
                        #print("Checking:",minStk[i]," and ",stk[-1])
                        while(len(stk)!=0 and minStk[i]>=stk[-1]):
                            stk.pop()
                        if(len(stk)!=0 and minStk[i]<stk[-1] and nums[i]>stk[-1]):
                            #print("1:",minStk[i],"4:",nums[i],"3:",stk[-1])
                            return True
                        if(minStk[i]<nums[i]):
                            stk.append(nums[i])
                else:
                    #equal, i.e. like 33, so nothing to do
                    continue
            else:
                #condition 13 not satisfied, equal
                continue
        return False

'''
Two stacks: One minstack and other stack maintains greater than current element items

'''