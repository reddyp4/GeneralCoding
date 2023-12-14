/*
912. Sort an Array
Medium
5.7K
724
company
Amazon
company
Yahoo
company
Microsoft
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104
*/

class Solution {
public:
    void merge(vector<int> &arr, int left, int mid, int right, vector<int> &tempArr)
    {
        int start1 = left;
        int start2 = mid+1;
        int end1 = mid-left+1;
        int end2 = right-mid;
        for(int i=0;i<end1;i++) tempArr[start1+i] = arr[start1+i];
        for(int i=0;i<end2;i++) tempArr[start2+i] = arr[start2+i];

        //Merge sub-arrays
        int i=0,j=0,k=left;
        while(i<end1 && j<end2)
        {
            if(tempArr[start1+i]<tempArr[start2+j])
            {
                arr[k]=tempArr[start1+i];
                i++;
            }
            else
            {
                arr[k]=tempArr[start2+j];
                j++;
            }
            k++;
        }
        while(i<end1)
        {
            arr[k]=tempArr[start1+i];
            i++,k++;
        }
        while(j<end2)
        {
            arr[k]=tempArr[start2+j];
            j++,k++;
        }
    }
    
    void mergeSort(vector<int> &arr, int left, int right, vector<int> &tempArr)
    {
        if(left>=right) return;
        //Get midpoint
        int mid = (left+right)/2;
        mergeSort(arr,left,mid,tempArr);
        mergeSort(arr,mid+1,right,tempArr);
        //Combine
        merge(arr,left,mid,right,tempArr);
    }

    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp1Array(nums.size());
        mergeSort(nums,0,nums.size()-1, temp1Array);    
        return nums;
    }
};