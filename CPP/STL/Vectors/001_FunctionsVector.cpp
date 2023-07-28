/*
Functions:
push_back(): add element at end
pop_back(): remove element at end

v.begin(): return first address
v.end(): return address after last element

front()
back()

insert(): insert element at a position, insert(begin()+number,element)
erase(): remove element at position, v.erase(iterator), v.erase()
erase(): remove elements from begin/end, v.erase(v.begin(),v.end()-1)
clear(): removes all elements of vector

resize(): resize vector to size, can be smaller/bigger than current size.
resize(): specify default while bigger, v.resize(8,100), size=8, value=100

empty(): check if vector is empty


*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v {10,5,20,14};
    //v.pop_back(); // remove last element
    //for(int i=0;i<v.size();i++)
    //    cout<<v.at(i)<<" ";
    //for(auto it=v.begin();it!=v.end();it++)
    //    cout << (*it) <<" ";
    // traverse and print every element
    //for(int x:v)
    //    cout << x << " ";
    //cout << endl;
    // front,v[0] and back
    cout<<v.front()<<endl;
    cout<<v.back()<<endl;

    //insert element at particular position, begin() return reference to front, add 100
    auto it = v.insert(v.begin(),100);
    cout<<v.front()<<endl;
    //insert at third element, begin()+2
    it = v.insert(v.begin()+2,200);
    for(int x:v)
        cout << x << " ";
    cout<<endl;
    return 0;
}