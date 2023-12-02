/*
27. Remove Element
Easy
1.6K
2.4K
company
Amazon
company
Adobe
company
Apple
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /* Choose two pointer approach */
        /* Left = element to be replaced, right stop at next unequal element */
        /* End until right reaches the end */
        int left=0, lenNums = nums.size()-1, right = lenNums;
        if(nums.size()==0)  return 0;
        if(lenNums==0 && nums[0]==val)  return 0;
        if(lenNums==0 && nums[0]!=val)  return 1;
        while ( left < right )
        {
            //left finds the equal
            while((left<right) && (nums[left]!=val))  left++;
            //right finds the unequal number
            while( (right>left) && (nums[right]==val) ) right--;
            //replace left with right, if value are as intended
            if( left<right && (nums[left]==val) && (nums[right]!=val) ) 
            {
                //Copy data from right to left, unequal to equal
                nums[left]=nums[right];
                nums[right]=val;
            }
            //move left
            if(left!=right) left++,right--;
        }
        //Special Cases, all unequal numbers
        if(left==right && left==lenNums && nums[left]!=val)    return lenNums+1;
        //Special case: all equal numbers
        if(left==right && left==0 && nums[left]==val)  return 0;
        //Reached beyond
        if(left==right && nums[left]!=val)    return left+1;
        return left;
    }
};