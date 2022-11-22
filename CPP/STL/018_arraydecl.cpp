#include <iostream>
using namespace std;

int main()
{
    // These arrays are stored in stack
    int arr[] = {0,1,2,3,4};
    int arr1[] = {0};   // all elements are zero
    int arr2[5] = {20}; // only first element is 20, rest zero
    //int arr3[]{10,20,30};   // Doesnt work
    cout<<sizeof(arr)<<endl;  // size in number of bytes
    cout<<sizeof(arr)/sizeof(arr[0])<<endl; //number of elements in an array

    // This array is stored on heap
    int *arr3 = new int[n];

    //Dynamic array
    return 0;
}