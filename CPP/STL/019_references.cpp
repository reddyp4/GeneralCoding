#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

// References allow modified the passed parameter to a function
// Reference avoids copy of large objects
void printV(vector<int> &p)
{
    for(auto x : p)   cout<<x<<" ";
    cout<<endl;
}

int main()
{
    vector<int> myV;
    for(int i=0;i<10;i++)   myV.push_back(i);
    printV(myV);
    return 0;
}