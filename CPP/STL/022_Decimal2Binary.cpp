#include<bitset>
#include<iostream>
using namespace std;

string dec2binary(int n)
{
    string s1;
    int div=0;
    while(n)
    {
        div=n%2;
        s1+=to_string(div);
        n/=2;
    }
    reverse(s1.begin(),s1.end());
    return s1;
}

int main()
{
    int n=12;
    cout<<dec2binary(n)<<endl;
    return 0;
}