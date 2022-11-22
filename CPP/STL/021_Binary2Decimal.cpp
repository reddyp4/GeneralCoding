#include<iostream>
using namespace std;

int binary2dec(string s1)
{
    int dec=0,base=1;
    for(int i=s1.length()-1;i>=0;i--)
    {
        dec+=(((int)(s1[i]-'0'))*base);
        base*=2;
    }
    return dec;
}

int main()
{
    string s1 = "1100";
    cout<<binary2dec(s1)<<endl;
    return 0;
}