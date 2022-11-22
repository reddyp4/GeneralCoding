#include<iostream>
using namespace std;

int main()
{
    string str = "gfg";
    cout<<str.length()<<endl;
    str=str+"xyz";
    cout<<str<<endl;
    cout<<str.substr(1,3)<<endl;    //sub-string from index 1 to 3
    cout<<str.find("fg")<<endl;     //return index of fg in string
    if(str.find("ae")==string::npos)
        cout<<"Not present!"<<endl;
    else
        cout<<"Present!"<<endl;

    string s1="abc",s2="ab";
    if(s1>s2)   cout<<"Greater"<<endl;
    else if(s1<s2)  cout<<"Lower!"<<endl;
    else    cout<<"Equal!"<<endl;

    return 0;
}