/*

Declaration: vector<type> name;
Declaration with elements: vector<int> v{10,5,10};
Declaration with same element: vector<int> v(size,elem);

Add element at end: v.push_back(elem)

Access like array: v[1] - doesnt check out of bounds
Access like array: v.at(1) - checks out of bounds

Modify elem: v[i]=5

Reference to address of first element: v.begin()
Reference to address after the last element: v.end()

Reverse referencing: address of last element: v.rend()
Reverse referencing: address before first element: v.rbegin() 
Increase the reference always

*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10);
    v.push_back(5);
    v.push_back(20);

    for(int i=0;i<v.size();i++)
        cout << v.at(i) <<" ";
    cout <<endl;

    // Change elem
    v[1] = 15;

    for(int i=0;i<v.size();i++)
        cout << v.at(i) <<" ";
    cout <<endl;

    int size1=3,elem=10;
    vector<int> v2(size1,elem);
    for(auto it=v2.begin();it!=v2.end();it++)
        cout << (*it) <<" ";
    cout<<endl;
    // declare from array
    int arr[] = {10,5,20};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v3(arr,arr+n);
    for(auto it=v3.rbegin();it!=v3.rend();it++)
        cout<<(*it)<<" ";
    cout<<endl;

    return 0;
}