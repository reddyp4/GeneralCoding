//import namespace std;

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::endl;
using std::sort;

void printarr(vector<int> arr)
{
    cout<<"array:";
    for(int i=0;i<arr.size();i++)
        cout<<arr[i];
    cout<<endl;
}

int main(void)
{
    vector<int> arr1(6);
    for(int i=0;i<6;i++)    arr1[i]=6-i;
    printarr(arr1);
    //sort(arr1.begin(),arr1.end());
    sort(arr1.begin(),arr1.begin()+2);
    cout<<"After sorting:";
    printarr(arr1);
    return 1;
}