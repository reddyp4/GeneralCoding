#include<iostream>
#include<vector>
using namespace std;

void vectorOp(vector<int> &vector)
{
    vector.push_back(25);
    vector.push_back(30);
}

void vectorPrint(vector<int> vector)
{
    for(int x:vector)
        cout<<x<<" ";
    cout<<endl;
}

int main()
{
    vector<int> v{10,5,20};
    vectorPrint(v);
    vectorOp(v);
    vectorPrint(v);
    return 0;
}