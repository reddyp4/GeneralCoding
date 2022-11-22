#include<iostream>
using namespace std;

int main()
{
    int a=1, *b=&a, **c=&b;
    a=4;
    **c = 5;
    cout<<a;
    return 0;
}
