/*
80. Remove Duplicates from Sorted Array II
Medium
6.2K
1.2K
company
Adobe
company
Amazon
company
Apple
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

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

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /* In place, use left, right pointers starting from same end */
        /* x^x = 0, x^x^x = x, even number is 0, odd number is x */
        /* keep doing xor, result=right if(left==right) result^=right continue if result==0 until [right]>[left] */
        /* value to compare to changes depending on left or right */
        int left=0,right=0,lenNums=nums.size()-1;   //left is where values are copied
        /* Corner cases, no elements, 1 and 2 elements */
        if(lenNums==0)  return 1;
        if(lenNums==1)  return 2;
        int val = nums[left];   //value to compare to
        int count=1;
        while ( left<=lenNums && right<=lenNums )
        {
            val = nums[right],count=0;
            /* move right until next unequal element */
            while(right<=lenNums && nums[right]==val)    right++,count++;
            /* Depending on right-left, assign appropriate array */
            /* Single element, nothing to do */
            if(count==1)
            {
                nums[left++]=val;
                continue;
            }
            /* Two elements, nothing to do, move by two elements */
            if(count>=2)
            {
                nums[left++]=val;
                nums[left++]=val;
                continue;
            }
        }
        return left;
    }
};

/*
Time Analysis:
Single O(1), LC beats 100% of solutions
Space O(1), LC beats 27% of solutions
*/