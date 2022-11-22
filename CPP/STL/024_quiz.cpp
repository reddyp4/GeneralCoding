#include<iostream>
using namespace std;

int main()
{
    char *s[]={"knowledge","is","power"};
    char **p;
    p=s;
    cout<<++*p<<endl;
    cout<<*p++<<endl;
    cout<<++*p<<endl;
    return 0;
}