#include<iostream>
using namespace std;

int main()
{
    char str1[]="Geeks";
    char str2[]={'G','e','e','k','s'};
    cout<<sizeof(str1)/sizeof(str1[0])<<endl;
    cout<<sizeof(str2)/(sizeof(str2[0]))<<endl;
    return 0;
}
