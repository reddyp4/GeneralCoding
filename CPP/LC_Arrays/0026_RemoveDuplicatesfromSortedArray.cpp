/*
26. Remove Duplicates from Sorted Array
Easy
13.2K
17.4K
company
Amazon
company
Apple
company
Adobe
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.

Test cases:
[1,1,2,2,2,3,3,4,5,5]
[0,0,1,1,1,2,2,3,3,4]
[0]
[1]
[3,4,5]
[1,1,2,2,2,3,3,4,5,5,6,7,7,7,8,8,8,8,9,10,11,11,12,12,12,13,14,15,15,15,15,15,20,25,31,32]
[0,0,1,1,1,2,2,3,3,4]

*/

/*
Beats run-time for 46%
Beats 89% of memory
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* Use XOR, n^n = 0 */
        int left=0,right=1,val;
        if(nums.size()<2)   return 1;
        while( right<nums.size() & left<nums.size() ) 
        {
            val=nums[left];
            //right=left+1;
            while( right<nums.size() && (val==nums[right])) right++;
            left++;
            if(left==nums.size() || right==nums.size())
            {
                break;
            }
            else  nums[left]=nums[right];
        }
        // remove rest of elements from left+1 to end
        nums.erase(nums.begin()+left,nums.end());
        return(left);
    }
};