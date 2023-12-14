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