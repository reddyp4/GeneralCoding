#include<stdio.h>
#include<stdint.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void partition(int arr[],int low, int high)
{
    int pivot = arr[high];
    int i=low-1;
    //rearrange
    for(int j=low;j<high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    //move pivot
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quickSort(int* arr[], int low, int high)
{
    if(low<high)
    {
        //atleast two elements
        //pivot
        int pi = partition(arr, low, high);
        //quicksort left
        quickSort(arr, low, pivot-1);
        //quicksort right
        quickSort(arr, pivot+1, high);

    }
}

int main(void)
{
    int arr[10] = [5,9,7,0,3,2,4,7,8,3,1,3,5];
    int n = sizeof(arr)/sizeof(arr[0]);
    //quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}